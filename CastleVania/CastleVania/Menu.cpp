#include "Menu.h"

Menu* Menu::instance = 0;

Menu * Menu::GetInstance()
{
	if (instance == 0)
	{
		instance = new Menu();
	}
	return instance;
}

Menu::Menu() : MovableObject()
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteMenu];
	position.X = 0;
	position.Y = 0;
	oldX = 0;
	oldY = 0;
	width = 256;
	height = 208;
	_direction = RIGHT;
	iTimeBlink = TIME_MENU_BLINK;
	isEnable = false;
	_kEnter = false;
	_curAction = Menu1_1;
	//delayIndexChange = new GameTime(1 / TIME_INDEX_CHANGE);
}

void Menu::updateKey()
{
	if (!isEnable)
		_kEnter = Keyboard::getInstance()->IsKeyDown(DIK_RETURN);
	else
		_kEnter = false;
}

void Menu::Run()
{
	if (MenuCastle::GetInstance()->isDone())
		updateKey();
	if (_kEnter)
	{
		setAction(Menu1_2);
		isEnable = true;
		PlaySound(intro);
	}
	if (isEnable)
	{
		iTimeBlink -= 1;
		if (iTimeBlink == 0)
			alive = false;
	}
}

void Menu::Draw()
{
	this->UpdateAnimation();
	MovableObject::Draw();
	MenuCastle::GetInstance()->Draw();
	
}


Menu::~Menu()
{
}
