
#include "PCH.h"

namespace Test
{

	TestScreen::~TestScreen()
	{
		delete m_pComponents;
		delete m_pTheme;
		delete m_pTexture;
	}

	void TestScreen::LoadContent(ResourceManager * pResourceManager)
	{
		m_pTheme = pResourceManager->Load<GUI::Theme>("GUI\\Theme01.thm");

		m_pComponents = new GUI::ComponentCollection(GetGame());
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
	}

	void TestScreen::UnloadContent()
	{

	}

	void TestScreen::HandleInput(const InputState *pInput)
	{
		m_pComponents->HandleInput(pInput);
	}

	void TestScreen::Update(const GameTime *pGameTime)
	{
		m_pComponents->Update(pGameTime);

		if (m_pToggle->GetValue())
		{
			float value = m_pSlider->GetValue();
			float newValue = value + pGameTime->GetTimeElapsed() * 0.5;
			m_pSlider->SetValue(newValue);
			if (m_pSlider->GetValue() >= 1) m_pSlider->SetValue(0);
		}

		/*
		Color start = Color(0.6f, 0.6f, 0.62f);
		Color end = Color(0.176f, 0.176f, 0.196f);
		Color clearColor = Color::Lerp(start, end, m_pSlider->GetValue());
		clearColor.Display();
		GetGame()->SetClearColor(clearColor);
		*/
	}

	void TestScreen::Draw(SpriteBatch *pSpriteBatch)
	{
		std::string text = "Auto-Advance";

		pSpriteBatch->Begin();
		m_pComponents->Draw(pSpriteBatch);

		float x = m_pToggle->GetPosition().X + m_pToggle->GetSize().X + 10;
		float y = m_pToggle->GetPosition().Y + 6;
		pSpriteBatch->DrawString(m_pTheme->GetFont(), &text, Vector2(x, y), Color::SALMON);

		pSpriteBatch->End();
	}
}
