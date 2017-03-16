#include "Board.h"

Board*Board::instance = 0;

Board * Board::GetInstance()
{
	if (instance == 0)
	{
		instance = new Board();
	}
	return instance;
}

void Board::Run()
{
	if (!SimonCharacter::GetInstance()->doubleShot)
	{
		if (!SimonCharacter::GetInstance()->tripleShot)
			MultipleShotBar::GetInstance()->Run(0, position.X + 120, position.Y + 13);
		else
			MultipleShotBar::GetInstance()->Run(2, position.X + 120, position.Y + 13);
	}
	else
		MultipleShotBar::GetInstance()->Run(1, position.X + 120, position.Y + 13);
	position.X = Camera::GetInstance()->position.X;
	position.Y = Camera::GetInstance()->position.Y;
	if (BossMedusa::GetInstance() != 0)
		BossHealthBar::GetInstance()->Run(BossMedusa::GetInstance()->iHealth, position.X + 40, position.Y + 23);
	SimonHealthBar::GetInstance()->Run(SimonCharacter::GetInstance()->iHealth, position.X + 40, position.Y + 13);
	SubWeaponBar::GetInstance()->Run(SimonCharacter::GetInstance()->_weaponType, position.X + 162, position.Y + 16);
	StageNumber->Run(Camera::GetInstance()->getCurStage().id, position.X + 70, position.Y + 2);
	LevelNumber->Run(Camera::GetInstance()->getCurStage().lvl, position.X + 122, position.Y + 2);
	ScoreNumber->Run(SimonCharacter::GetInstance()->iScore, position.X + 175, position.Y + 2);
	HeartNumber->Run(SimonCharacter::GetInstance()->iHeart, position.X + 205, position.Y + 17);
	LifeNumber->Run(SimonCharacter::GetInstance()->iLife, position.X + 205, position.Y + 25);
}

void Board::Draw()
{
	MovableObject::Draw();
	SimonHealthBar::GetInstance()->Draw();
	BossHealthBar::GetInstance()->Draw();
	SubWeaponBar::GetInstance()->Draw();
	MultipleShotBar::GetInstance()->Draw();
	StageNumber->Draw();
	LevelNumber->Draw();
	ScoreNumber->Draw();
	HeartNumber->Draw();
	LifeNumber->Draw();
}

Board::Board():MovableObject()
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteBoard];
	setAction(BlackBoard_Board);
	position.X = Camera::GetInstance()->position.X;
	position.Y = Camera::GetInstance()->position.Y;
	width = 256;
	height = 39;
	_direction = RIGHT;
	alive = true;

	//Initilize Numbers
	StageNumber = new Number(1);
	LevelNumber = new Number(1);
	ScoreNumber = new Number(6);
	HeartNumber = new Number(2);
	LifeNumber = new Number(2);
}


Board::~Board()
{
}
