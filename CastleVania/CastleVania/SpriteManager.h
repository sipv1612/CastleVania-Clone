#pragma once
#include "Sprite.h"
#define SIMON_ACTION_COUNT 16
#define WHIP_ACTION_COUNT 5
#define SUBWEAPON_ACTION_COUNT 6
#define MENU_ACTION_COUNT 4

enum SpriteType
{
	SpriteMenu,
	SpriteIntro,
	SpriteBoard,
	SpriteSimon,
	SpriteWhip,
	SpriteSubWeapon,
	SpriteBossMedusa,
	SpriteBossMummies,
	SpriteEBat,
	SpriteESpearGuard,
	SpriteEMedusaHead,
	SpriteESkeleton,
	SpriteEBonePillar,
	SpriteEGhost,
	SpriteESnake,
	SpriteBullet,
	SpriteDoor,
	SpritePaddle,
	SpriteBat,
	SpriteItem,
	SpriteWeapon,
	SpriteMorningStar,
	SpriteFallingCastle
};

enum SimonSprite
{
	SimonStand,
	SimonWalk,
	SimonJump,
	SimonSit,
	SimonStandWhip,
	SimonSitWhip,
	SimonClimbUpWhip,
	SimonClimbDownWhip,
	SimonClimbUp,
	SimonClimbDown,
	SimonClimbingUp,
	SimonClimbingDown,
	SimonDie,
	SimonBack,
	SimonBeingAttacked,
	SimonUpgradeWhip
};

enum WhipType
{
	Vampire_Killer,
	Chain_Whip,
	Morning_Star
};

enum ItemType
{
	ItemSmallHeart,
	ItemBigHeart,
	ItemCross,
	ItemAxe,
	ItemKnife,
	ItemWhip,
	ItemRoast,
	ItemHolyWater,
	ItemStopWatch,
	ItemDoubleShot,
	ItemTripleShot,
	ItemRosary,
	ItemLife,
	ItemMoney1,
	ItemMoney2,
	ItemMoney3,
	ItemMoney4,
	ItemMoney5,
	ItemPotion,
	ItemSpiritBall,
	ItemCandle,
	ItemBrick
};

enum SubWeaponType
{
	WeaponNone,
	WeaponKnife,
	WeaponAxe,
	WeaponHolyWater,
	WeaponStopWatch,
	WeaponCross
};

enum WhipSprite
{
	state1,
	state2,
	state3_1,
	state3_2,
	state3_3
};

enum SubWeaponSprite
{
	Knife,
	Axe,
	HolyWater1,
	HolyWater2,
	StopWatch,
	Cross
};

enum MenuSprite
{
	Menu1_1,
	Menu1_2,
	Menu2_1,
	Menu2_2
};

enum SpearGuardSprite
{
	SpearGuardDied,
	SpearGuardStand,
	SpearGuardWalk
};

enum BatSprite
{
	BatDied,
	BatOnTheWall,
	BatFly
};

enum BonePillarSprite
{
	BonePillarDied,
	BonePillarNormal
};

enum GhostSprite
{
	GhostDied,
	GhostNormal
};

enum MedusaHeadSprite
{
	MedusaHeadDied,
	MedusaHeadNormal
};

enum BossMedusaSprite
{
	BossMedusaDied,
	BossMedusaOnTheWall,
	BossMedusaFly
};

enum BoardSprite
{
	BlackBoard_Board,
	Boss_Board,
	ShotNumber_Board,
	Simon_Board,
	SubWeapon_Board,
	Number_Board
};

enum IntroSprite
{
	introBat,
	introHelicopter
};

class SpriteManager
{
private:
	static SpriteManager* instance;
public:
	bool isWeaponMax;
	bool isDoubleShot;
	bool isTripleShot;
	Sprite** listAnimation;
	int count;
	static SpriteManager* GetInstance(DirectXGame* dx = 0);
	SpriteManager(DirectXGame* dx);
	void AddSimon(DirectXGame* dx);
	void AddWhip(DirectXGame* dx);
	void AddSubWeapon(DirectXGame* dx);
	void AddMenu(DirectXGame* dx);
	void AddBoard(DirectXGame* dx);
	void AddEnemy(DirectXGame* dx);
	void AddDoor(DirectXGame* dx);
	void AddPaddle(DirectXGame* dx);
	void AddItem(DirectXGame* dx);
	void AddIntro(DirectXGame* dx);
	~SpriteManager();
};

