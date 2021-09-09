
#include "PCH.h"

namespace Test
{

	TestScreen::~TestScreen()
	{
	}

	void TestScreen::LoadContent(ResourceManager *pResourceManager)
	{
		m_pCharacterTexture = pResourceManager->Load<Texture>("Textures\\Characters\\PC00.png");
		m_pCharacterAnimation = pResourceManager->Load<Animation>("Animations\\Character00_Walk_Down.anim");
		m_pCharacterAnimation->SetTexture(m_pCharacterTexture);
		m_pCharacterAnimation->Play();
	}

	void TestScreen::HandleInput(const InputState *pInput)
	{
	}

	void TestScreen::Update(const GameTime *pGameTime)
	{
		m_pCharacterAnimation->Update(pGameTime);
	}

	void TestScreen::Draw(SpriteBatch *pSpriteBatch)
	{
		pSpriteBatch->Begin(SpriteSortMode::DEFERRED, BlendState::ALPHA);
		pSpriteBatch->Draw(m_pCharacterAnimation, Vector2::UNIT_X * 300, Color::WHITE);

		al_draw_bitmap(m_pCharacterAnimation->GetTexture()->GetAllegroBitmap(), 400, 200, 0);
		pSpriteBatch->End();
	}
}
