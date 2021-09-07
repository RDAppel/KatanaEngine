
#include "PCH.h"

namespace Test
{

	TestScreen::~TestScreen()
	{
		delete m_pComponents;
		delete m_pTheme;
		delete m_pEmitter;
	}

	void TestScreen::LoadContent(ResourceManager *pResourceManager)
	{
		m_pParticleManager->GenerateParticles(1000);
		m_pParticleManager->SetBlendState(BlendState::ADDITIVE);

		m_pParticleTextures[0] = pResourceManager->Load<Texture>("Textures\\Particle00.png");
		m_pParticleTextures[1] = pResourceManager->Load<Texture>("Textures\\Particle01.png");
		m_pParticleTextures[2] = pResourceManager->Load<Texture>("Textures\\Particle02.png");
		m_pParticleTextures[3] = pResourceManager->Load<Texture>("Textures\\Particle03.png");

		m_pEmitter = new ParticleEmitter(m_pParticleManager);
		m_pEmitter->SetParticlesPerSecond(100);
		m_pTemplate = ParticleTemplate::CreateSimpleTemplate();
		m_pTemplate->ClearRenderers();
		m_pTemplate->AddInitializer(new RandomLifespanInitializer(2));
		m_pTemplate->AddInitializer(new VelocityInitializer);
		m_pTemplate->AddInitializer(new RandomVelocityInitializer);
		m_pTemplate->AddInitializer(new RandomRotationInitializer);
		m_pTemplate->AddInitializer(new RandomAngularVelocityInitializer);
		m_pTemplate->AddUpdater(new AlphaUpdater);
		m_pTemplate->AddUpdater(new ColorUpdater(Color::CORNFLOWER));
		m_pTemplate->AddUpdater(new AngularVelocityUpdater);
		m_pTemplate->AddRenderer(new TextureRenderer(m_pParticleTextures[0]));
		m_pEmitter->SetParticleTemplate(m_pTemplate);

		m_pTheme = pResourceManager->Load<GUI::Theme>("GUI\\Theme01.thm");

		m_pComponents = new GUI::ComponentCollection();
		m_pComponents->SetTheme(m_pTheme);

		m_pPanel = new GUI::Panel(m_pComponents);
		m_pPanel->SetPosition(10, 10);
		m_pPanel->SetSize(220, 94);

		m_pToggle = new GUI::Toggle(m_pComponents);
		m_pToggle->SetPosition(10, 10);
		m_pToggle->SetSize(64, 32);
		m_pPanel->AddChild(m_pToggle);

		m_pSlider = new GUI::Slider(m_pComponents);
		m_pSlider->SetPosition(10, 10 + 32 + 10);
		m_pSlider->SetSize(200, 32);
		m_pPanel->AddChild(m_pSlider);

		m_line.Start.Set(325, 650);
		m_line.End.Set(1250, 275);

		resetSplines();

		m_selectionCircle.Radius = 16;
	}

	void TestScreen::resetSplines()
	{
		m_spline.P0.Set(300, 700);
		m_spline.P1.Set(800, 200);
		m_spline.P2.Set(800, 200);
		m_spline.P3.Set(1300, 700);

		m_spline2.P0.Set(300, 700);
		m_spline2.P1.Set(300, 200);
		m_spline2.P2.Set(1300, 200);
		m_spline2.P3.Set(1300, 700);
	}

	void TestScreen::HandleInput(const InputState *pInput)
	{
		m_pComponents->HandleInput(pInput);
		Point mouse = pInput->GetMousePosition();

		if (pInput->IsNewMouseButtonRelease(MouseButton::LEFT))
		{
			pInput->GetMousePosition().Display();
			m_controlPoint = -1;
		}

		if (pInput->IsNewKeyPress(Key::RIGHT))
		{
			int i = (int)m_step + 1;
			if (i == (int)Demo::END) i = (int)Demo::END;
			m_step = (Demo)i;
		}

		if (pInput->IsNewKeyPress(Key::LEFT))
		{
			int i = (int)m_step;
			if (i > 0) m_step = (Demo)((int)m_step - 1);
		}

		if (pInput->IsNewMouseButtonPress(MouseButton::LEFT))
		{
			float distSq[4] = {
				Vector2::DistanceSquared(mouse, m_spline2.P0),
				Vector2::DistanceSquared(mouse, m_spline2.P1),
				Vector2::DistanceSquared(mouse, m_spline2.P2),
				Vector2::DistanceSquared(mouse, m_spline2.P3)
			};

			float rad = m_selectionCircle.Radius;
			float radSq = rad * rad;
			for (int i = 0; i < 4; i++)
			{
				if (distSq[i] < radSq)
				{
					m_controlPoint = i;
					break;
				}
			}
		}

		if (m_controlPoint == 0) m_spline2.P0 = mouse;
		if (m_controlPoint == 1) m_spline2.P1 = mouse;
		if (m_controlPoint == 2) m_spline2.P2 = mouse;
		if (m_controlPoint == 3) m_spline2.P3 = mouse;
		if (m_controlPoint >= 0) m_selectionCircle.Position = mouse;

		if (pInput->IsNewKeyPress(Key::SPACE))
		{
			m_pToggle->SetValue(!m_pToggle->GetValue());
		}

		if (pInput->IsNewKeyPress(Key::R))
		{
			resetSplines();
		}

		if (pInput->IsNewKeyPress(Key::NUM_0)) m_step = (Demo)0;
		if (pInput->IsNewKeyPress(Key::NUM_1)) m_step = (Demo)1;
		if (pInput->IsNewKeyPress(Key::NUM_2)) m_step = (Demo)2;
		if (pInput->IsNewKeyPress(Key::NUM_3)) m_step = (Demo)3;
		if (pInput->IsNewKeyPress(Key::NUM_4)) m_step = (Demo)4;
		if (pInput->IsNewKeyPress(Key::NUM_5)) m_step = (Demo)5;
		if (pInput->IsNewKeyPress(Key::NUM_6)) m_step = (Demo)6;
		if (pInput->IsNewKeyPress(Key::NUM_7)) m_step = (Demo)7;
		if (pInput->IsNewKeyPress(Key::NUM_8)) m_step = (Demo)8;
		if (pInput->IsNewKeyPress(Key::NUM_9)) m_step = (Demo)9;
	}

	void TestScreen::Update(const GameTime *pGameTime)
	{
		m_pComponents->Update(pGameTime);
		m_pEmitter->Update(pGameTime);
		m_pEmitter->SetPosition(m_spline2.Lerp(m_pSlider->GetValue()));

		if (m_pToggle->GetValue())
		{
			float value = m_pSlider->GetValue();
			float newValue = value + pGameTime->GetTimeElapsed() * 0.5;
			m_pSlider->SetValue(newValue);

			bool particles = (m_step == Demo::CUBIC_RM_LINES
				|| m_step == Demo::PARTICLES_ONLY);

			if (m_pSlider->GetValue() >= 1)
			{
				m_pSlider->SetValue(0);

				//if (particles) m_pEmitter->Emit(32, m_spline2.P3);
			}

			float output = particles ? 1 : 0;
			m_pEmitter->SetOutput(m_pSlider->GetValue() * output);
		}
	}

	void TestScreen::Draw(SpriteBatch *pSpriteBatch)
	{
		pSpriteBatch->Begin(SpriteSortMode::TEXTURE, BlendState::ALPHA);

		Vector2 position = Vector2::ZERO;

		float tValue = m_pSlider->GetValue();
		std::string tText = std::to_string(tValue);
		Font *pFont = m_pTheme->GetFont();
	
		// render gui
		std::string advance = "Auto-Advance";
		m_pComponents->Draw(pSpriteBatch);
		float x = m_pToggle->GetPosition().X + m_pToggle->GetSize().X + 10;
		float y = m_pToggle->GetPosition().Y + 6;
		pSpriteBatch->DrawString(pFont, &advance, Vector2(x, y), Color::SALMON);

		// render demo

		Color c = Color::Lerp(Color::SALMON, Color::REBECCA_PURPLE, tValue);
		if (m_step == Demo::LINE)
		{
			position = m_line.Lerp(tValue);
			m_line.DrawPrimitive(Color::SALMON, 4);
			Circle(8, position).DrawPrimitive(Color::SALMON);
			position += Vector2(100, 0);
		}
		if (m_step == Demo::COLOR)
		{
			Rectangle(Vector2(500, 500), Vector2(550, 200)).DrawPrimitive(c);
			position.Set(1150, 450);
		}

		Line l1(m_spline.P0, m_spline.P1);
		Line l2(m_spline.P2, m_spline.P3);
		Vector2 p1 = l1.Lerp(tValue);
		Vector2 p2 = l2.Lerp(tValue);
		Line l3(p1, p2);

		if (m_step == Demo::TWO_LINE)
		{
			l1.DrawPrimitive(2);
			l2.DrawPrimitive(2);
			Circle(8, p1).DrawPrimitive();
			Circle(8, p2).DrawPrimitive();
			position = Vector2::Lerp(m_spline.P0, m_spline.P3, tValue)
				+ Vector2(0, 50);
		}

		if (m_step == Demo::THREE_LINE)
		{
			l1.DrawPrimitive(2);
			l2.DrawPrimitive(2);
			Circle(8, p1).DrawPrimitive();
			Circle(8, p2).DrawPrimitive();
			l3.DrawPrimitive(2);
			position = Vector2::Lerp(m_spline.P0, m_spline.P3, tValue)
				+ Vector2(0, 50);
		}

		if (m_step == Demo::THREE_LINE_WPT)
		{
			l1.DrawPrimitive(2);
			l2.DrawPrimitive(2);
			Circle(8, p1).DrawPrimitive();
			Circle(8, p2).DrawPrimitive();
			l3.DrawPrimitive(2);
			Circle(8, l3.Lerp(tValue)).DrawPrimitive();
			position = Vector2::Lerp(m_spline.P0, m_spline.P3, tValue)
				+ Vector2(0, 50);
		}

		if (m_step == Demo::QUADRATIC)
		{
			l1.DrawPrimitive(2);
			l2.DrawPrimitive(2);
			Circle(8, p1).DrawPrimitive();
			Circle(8, p2).DrawPrimitive();
			l3.DrawPrimitive(2);
			Circle(8, l3.Lerp(tValue)).DrawPrimitive();
			Color c2 = Color::Lerp(Color::TRANSPARENT, Color::SALMON, tValue);

			Vector2 prev = l1.Start;
			Vector2 next;
			for (float f = 0.01; f <= 1; f += 0.01)
			{
				next = Vector2::Lerp(l1.Lerp(f), l2.Lerp(f), f);
				Line(prev, next).DrawPrimitive(c2, 4);
				prev = next;
			}

			position = Vector2(800, 750);
		}

		Line ln1(m_spline2.P0, m_spline2.P1);
		Line ln2(m_spline2.P1, m_spline2.P2);
		Line ln3(m_spline2.P2, m_spline2.P3);
		Vector2 pt1 = ln1.Lerp(tValue);
		Vector2 pt2 = ln2.Lerp(tValue);
		Vector2 pt3 = ln3.Lerp(tValue);
		Line ln4(pt1, pt2);
		Line ln5(pt2, pt3);
		Vector2 pt4 = ln4.Lerp(tValue);
		Vector2 pt5 = ln5.Lerp(tValue);
		Line ln6(pt4, pt5);
		Vector2 pt6 = ln6.Lerp(tValue);

		if (m_step == Demo::FOUR_LINES)
		{
			if (m_controlPoint >= 0)
				m_selectionCircle.DrawPrimitive(Color::YELLOW, 2);

			ln1.DrawPrimitive(2);
			ln2.DrawPrimitive(2);
			ln3.DrawPrimitive(2);

			position = Vector2(800, 750);
		}

		if (m_step == Demo::FOUR_LINES_WPT)
		{
			if (m_controlPoint >= 0)
				m_selectionCircle.DrawPrimitive(Color::YELLOW, 2);

			ln1.DrawPrimitive(2);
			ln2.DrawPrimitive(2);
			ln3.DrawPrimitive(2);
			Circle(8, pt1).DrawPrimitive();
			Circle(8, pt2).DrawPrimitive();
			Circle(8, pt3).DrawPrimitive();

			position = Vector2(800, 750);
		}

		if (m_step == Demo::FOUR_LINES_W1LERP)
		{
			if (m_controlPoint >= 0)
				m_selectionCircle.DrawPrimitive(Color::YELLOW, 2);

			ln1.DrawPrimitive(2);
			ln2.DrawPrimitive(2);
			ln3.DrawPrimitive(2);
			Circle(8, pt1).DrawPrimitive();
			Circle(8, pt2).DrawPrimitive();
			Circle(8, pt3).DrawPrimitive();
			ln4.DrawPrimitive(2);
			ln5.DrawPrimitive(2);

			position = Vector2(800, 750);
		}

		if (m_step == Demo::FOUR_LINES_W1LERP_WPT)
		{
			if (m_controlPoint >= 0)
				m_selectionCircle.DrawPrimitive(Color::YELLOW, 2);

			ln1.DrawPrimitive(2);
			ln2.DrawPrimitive(2);
			ln3.DrawPrimitive(2);
			Circle(8, pt1).DrawPrimitive();
			Circle(8, pt2).DrawPrimitive();
			Circle(8, pt3).DrawPrimitive();
			ln4.DrawPrimitive(2);
			ln5.DrawPrimitive(2);
			Circle(8, pt4).DrawPrimitive();
			Circle(8, pt5).DrawPrimitive();

			position = Vector2(800, 750);
		}

		if (m_step == Demo::FOUR_LINES_W2LERP)
		{
			if (m_controlPoint >= 0)
				m_selectionCircle.DrawPrimitive(Color::YELLOW, 2);

			ln1.DrawPrimitive(2);
			ln2.DrawPrimitive(2);
			ln3.DrawPrimitive(2);
			Circle(8, pt1).DrawPrimitive();
			Circle(8, pt2).DrawPrimitive();
			Circle(8, pt3).DrawPrimitive();
			ln4.DrawPrimitive(2);
			ln5.DrawPrimitive(2);
			Circle(8, pt4).DrawPrimitive();
			Circle(8, pt5).DrawPrimitive();
			ln6.DrawPrimitive(2);

			position = Vector2(800, 750);
		}

		if (m_step == Demo::FOUR_LINES_W2LERP_WPT)
		{
			if (m_controlPoint >= 0)
				m_selectionCircle.DrawPrimitive(Color::YELLOW, 2);

			ln1.DrawPrimitive(2);
			ln2.DrawPrimitive(2);
			ln3.DrawPrimitive(2);
			Circle(8, pt1).DrawPrimitive();
			Circle(8, pt2).DrawPrimitive();
			Circle(8, pt3).DrawPrimitive();
			ln4.DrawPrimitive(2);
			ln5.DrawPrimitive(2);
			Circle(8, pt4).DrawPrimitive();
			Circle(8, pt5).DrawPrimitive();
			ln6.DrawPrimitive(2);
			Circle(8, pt6).DrawPrimitive();

			position = Vector2(800, 750);
		}

		if (m_step == Demo::CUBIC)
		{
			if (m_controlPoint >= 0)
				m_selectionCircle.DrawPrimitive(Color::YELLOW, 2);

			ln1.DrawPrimitive(2);
			ln2.DrawPrimitive(2);
			ln3.DrawPrimitive(2);
			Circle(8, pt1).DrawPrimitive();
			Circle(8, pt2).DrawPrimitive();
			Circle(8, pt3).DrawPrimitive();
			ln4.DrawPrimitive(2);
			ln5.DrawPrimitive(2);
			Circle(8, pt4).DrawPrimitive();
			Circle(8, pt5).DrawPrimitive();
			ln6.DrawPrimitive(2);
			m_spline2.DrawPrimitive(Color::REBECCA_PURPLE, 4);
			Circle(8, pt6).DrawPrimitive();

			position = Vector2(800, 750);
		}

		if (m_step == Demo::CUBIC_RM_LINES)
		{
			if (m_controlPoint >= 0)
				m_selectionCircle.DrawPrimitive(Color::YELLOW, 2);

			Color color = Color::WHITE * 0.1f;
			ln1.DrawPrimitive(color, 2);
			ln3.DrawPrimitive(color, 2);
			m_spline2.DrawPrimitive(Color::REBECCA_PURPLE, 4);
			Circle(8, pt6).DrawPrimitive();

			position = Vector2(800, 750);
		}

		if (!position.IsZero())
		{
			pSpriteBatch->DrawString(pFont, &tText, position, Color::WHITE, TextAlign::CENTER);
		}

		pSpriteBatch->End();
	}
}
