#include "CastleVania.h"



CastleVania::CastleVania()
{
}

bool CastleVania::init(HINSTANCE hInstance)
{
	if (!Init_Window(hInstance))
		return false;
	else if (!Init_Direct3D())
		return false;
	Keyboard::Create(hInstance, _hWnd);
	initMenu();
	DirectSound_Init(_hWnd);
	initSound();
	instance = hInstance;
	return true;
}

void CastleVania::initMenu()
{
	SpriteManager::GetInstance(this);
}

void CastleVania::initGame()
{
	Camera::GetInstance()->init(1792, 640, 256, 208);
	Camera::GetInstance()->oldX = 1792;
	Camera::GetInstance()->oldY = 640;
	Camera::GetInstance()->loadStages();
	Camera::GetInstance()->nextStage();
	SimonCharacter::GetInstance()->position.X = 1840;
	SimonCharacter::GetInstance()->position.Y = 735;
	SimonCharacter::GetInstance()->oldX = 1840;
	SimonCharacter::GetInstance()->oldY = 735;
	Camera::GetInstance()->initPlayer(SimonCharacter::GetInstance());
	map = new Map(this);
	map->loadResource(1);
	Camera::GetInstance()->setMax(map->width, map->height);
	isFinishInitGame = true;
	LoopSound(lv2_bg);
}

void CastleVania::initIntro()
{
	Camera::GetInstance()->init(0, 16, 256, 208);
	Camera::GetInstance()->oldX = 0;
	Camera::GetInstance()->oldY = 16;
	Camera::GetInstance()->initPlayer(SimonCharacter::GetInstance());
	map = new Map(this);
	map->loadResource(0);
	Camera::GetInstance()->setMax(map->width, map->height);
	inIntro = true;
}

bool CastleVania::isIntro()
{
	return inIntro;
}

void CastleVania::run()
{
	MSG msg;
	PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE);
	while(msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		Keyboard::getInstance()->PollKeyboard();
		Keyboard::getInstance()->UpdateKeyboard();
		update();
		if (Menu::GetInstance()->isFinish() && !inIntro)	// Khi xong phần menu
			initIntro();
		if (this->BeginScene())
		{
		
			this->SpriteHandler_Begin();

			this->Clear();

			draw();

			this->SpriteHandler_End();
			this->EndScene();
		}
		this->Present();
	}
}

void CastleVania::end()
{
}

void CastleVania::update()
{
	if (!Menu::GetInstance()->isFinish())
	{
		Menu::GetInstance()->Run();
	}
	else
	{
		//if (inIntro)	//Đang trong intro
		//{
		//	inIntro = SimonCharacter::GetInstance()->RunIntro();
		//	map->run();
		//	SimonCharacter::GetInstance()->UpdatePosition();
		//	return;
		//}
		//if (!isFinishInitGame)
		//	initGame();
		//SimonCharacter::GetInstance()->Run();
		//map->run();
		//SimonCharacter::GetInstance()->UpdatePosition();
		//Camera::GetInstance()->run();
		//Camera::GetInstance()->updatePosition();
		if (SimonCharacter::GetInstance()->RunIntro())
		{
				map->run();
				SimonCharacter::GetInstance()->UpdatePosition();
				return;
		}
		else
		{
			if (!isFinishInitGame)
				initGame();
			SimonCharacter::GetInstance()->Run();
			map->run();
			Board::GetInstance()->Run();
			SimonCharacter::GetInstance()->UpdatePosition();
			//for each (Enemy* obj in map->getListEnemy())
			//	obj->Run();
			Camera::GetInstance()->run();
			//Camera::GetInstance()->updatePosition();
		}
	}
}

void CastleVania::draw()
{
	if (!Menu::GetInstance()->isFinish())
		Menu::GetInstance()->Draw();
	else
	{
		if (isFinishInitGame)
			Board::GetInstance()->Draw();
		map->draw();
		SimonCharacter::GetInstance()->Draw();
		//for each (Enemy* obj in map->getListEnemy())
		//	obj->Draw();
		Whip::GetInstance()->Draw();
		SubWeapon::GetInstance()->Draw();
	}
}


CastleVania::~CastleVania()
{
}
