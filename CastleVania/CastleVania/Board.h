#pragma once
#include "MovableObject.h"
#include "Camera.h"
#include "SimonHealthBar.h"
#include "SimonCharacter.h"
#include"SubWeaponBar.h"
#include"Number.h"
#include"BossMedusa.h"
#include"BossHealthBar.h"
#include"MultipleShotBar.h"
class Board :
	public MovableObject
{
private:
	static Board* instance;
	Number *ScoreNumber, *HeartNumber, *LifeNumber, *StageNumber, *LevelNumber;
public:
	static Board* GetInstance();
	void Run();
	void Draw();
	Board();
	~Board();
};

