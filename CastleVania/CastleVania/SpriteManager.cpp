#include "SpriteManager.h"

SpriteManager* SpriteManager::instance = 0;
SpriteManager::SpriteManager(DirectXGame* dx)
{
	count = 1;
	listAnimation = new Sprite*[count];
	AddMenu(dx);
	AddBoard(dx);
	AddSimon(dx);
	AddWhip(dx);
	AddSubWeapon(dx);
	AddEnemy(dx);
	AddDoor(dx);
	AddPaddle(dx);
	AddItem(dx);
	AddIntro(dx);
}

SpriteManager* SpriteManager::GetInstance(DirectXGame* dx)
{
	if (instance == 0)
	{
		instance = new SpriteManager(dx);
	}
	return instance;
}

void SpriteManager::AddSimon(DirectXGame* dx)
{
	listAnimation[SpriteSimon] = new Sprite(SIMON_ACTION_COUNT);
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Simon\\Simon_Stand.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 2, 6, "Data\\Sprite\\Simon\\Simon_Walk.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Simon\\Simon_Sit.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Simon\\Simon_Sit.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\Simon\\Simon_StandWhip.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\Simon\\Simon_SitWhip.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\Simon\\Simon_ClimbUpWhip.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\Simon\\Simon_ClimbDownWhip.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Simon\\Simon_ClimbUp.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Simon\\Simon_ClimbDown.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 2, 1, "Data\\Sprite\\Simon\\Simon_ClimbingUp.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 2, 1, "Data\\Sprite\\Simon\\Simon_ClimbingDown.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\Simon\\Simon_Die.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Simon\\Simon_Back.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Simon\\Simon_BeingAttacked.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSimon]->Add(new Animation(dx, 1, 2, 6, "Data\\Sprite\\Simon\\Simon_UpgradeWhip.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));



}

void SpriteManager::AddWhip(DirectXGame * dx)
{
	listAnimation[SpriteWhip] = new Sprite(WHIP_ACTION_COUNT);
	listAnimation[SpriteWhip]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\Whip\\1.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteWhip]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\Whip\\2.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteWhip]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Whip\\3_1.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteWhip]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Whip\\3_2.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteWhip]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Whip\\3_3.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
}

void SpriteManager::AddSubWeapon(DirectXGame * dx)
{
	listAnimation[SpriteSubWeapon] = new Sprite(SUBWEAPON_ACTION_COUNT);
	listAnimation[SpriteSubWeapon]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\SubWeapon\\Knife.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSubWeapon]->Add(new Animation(dx, 1, 4, 6, "Data\\Sprite\\SubWeapon\\Axe.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSubWeapon]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\SubWeapon\\HolyWater1.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSubWeapon]->Add(new Animation(dx, 1, 2, 6, "Data\\Sprite\\SubWeapon\\HolyWater2.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSubWeapon]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\SubWeapon\\StopWatch.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteSubWeapon]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\SubWeapon\\Cross.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
}

void SpriteManager::AddMenu(DirectXGame * dx)
{
	listAnimation[SpriteMenu] = new Sprite(MENU_ACTION_COUNT);
	listAnimation[SpriteMenu]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Menu\\Menu1_1.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMenu]->Add(new Animation(dx, 1, 2, 6, "Data\\Sprite\\Menu\\Menu1_2.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMenu]->Add(new Animation(dx, 1, 14, 6, "Data\\Sprite\\Menu\\Menu2_1.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteMenu]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\Menu\\Menu2_2.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
}

void SpriteManager::AddBoard(DirectXGame * dx)
{
	listAnimation[SpriteBoard] = new Sprite(6);
	listAnimation[SpriteBoard]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Board\\blackboard.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteBoard]->Add(new Animation(dx, 17, 1, 6, "Data\\Sprite\\Board\\BossHealthBar.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteBoard]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\Board\\ShotNumber.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteBoard]->Add(new Animation(dx, 17, 1, 6, "Data\\Sprite\\Board\\SimonHealthBar.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteBoard]->Add(new Animation(dx, 1, 6, 6, "Data\\Sprite\\Board\\SubWeapon.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteBoard]->Add(new Animation(dx, 1, 10, 6, "Data\\Sprite\\Board\\Number.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
}

void SpriteManager::AddEnemy(DirectXGame * dx)
{
	//Boss Medusa
	listAnimation[SpriteBossMedusa] = new Sprite(3);
	listAnimation[SpriteBossMedusa]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\Enemy\\Boss_Die.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteBossMedusa]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Enemy\\Medusa1.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteBossMedusa]->Add(new Animation(dx, 1, 4, 6, "Data\\Sprite\\Enemy\\Medusa2.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));

	//Boss Mummies
	listAnimation[SpriteBossMummies] = new Sprite(3);
	listAnimation[SpriteBossMummies]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\Enemy\\Enemy_Die.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteBossMummies]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Enemy\\Mummies1.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteBossMummies]->Add(new Animation(dx, 1, 2, 6, "Data\\Sprite\\Enemy\\Mummies2.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));

	//Bat
	listAnimation[SpriteEBat] = new Sprite(3);
	listAnimation[SpriteEBat]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\Enemy\\Enemy_Die.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteEBat]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Enemy\\Bat1.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteEBat]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\Enemy\\Bat2.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));

	//Spear Guard
	listAnimation[SpriteESpearGuard] = new Sprite(3);
	listAnimation[SpriteESpearGuard]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\Enemy\\Enemy_Die.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteESpearGuard]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Enemy\\Spear_Guard1.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteESpearGuard]->Add(new Animation(dx, 1, 2, 6, "Data\\Sprite\\Enemy\\Spear_Guard2.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));

	//Medusa Head
	listAnimation[SpriteEMedusaHead] = new Sprite(2);
	listAnimation[SpriteEMedusaHead]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\Enemy\\Enemy_Die.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteEMedusaHead]->Add(new Animation(dx, 1, 2, 6, "Data\\Sprite\\Enemy\\Medusa_Head.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));

	//Skeleton
	listAnimation[SpriteESkeleton] = new Sprite(3);
	listAnimation[SpriteESkeleton]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\Enemy\\Enemy_Die.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteESkeleton]->Add(new Animation(dx, 1, 2, 6, "Data\\Sprite\\Enemy\\Skeleton1.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteESkeleton]->Add(new Animation(dx, 1, 2, 6, "Data\\Sprite\\Enemy\\Skeleton2.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));

	//Bone Pillar
	listAnimation[SpriteEBonePillar] = new Sprite(2);
	listAnimation[SpriteEBonePillar]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\Enemy\\Enemy_Die.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteEBonePillar]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Enemy\\Bone_Pillar.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));

	//Ghost
	listAnimation[SpriteEGhost] = new Sprite(2);
	listAnimation[SpriteEGhost]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\Enemy\\Enemy_Die.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteEGhost]->Add(new Animation(dx, 1, 2, 6, "Data\\Sprite\\Enemy\\Ghost.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));

	//Bullet
	listAnimation[SpriteBullet] = new Sprite(1);
	listAnimation[SpriteBullet]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Enemy\\Bullet.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));

	//Snake
	listAnimation[SpriteESnake] = new Sprite(2);
	listAnimation[SpriteESnake]->Add(new Animation(dx, 1, 3, 6, "Data\\Sprite\\Enemy\\Enemy_Die.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteESnake]->Add(new Animation(dx, 1, 2, 6, "Data\\Sprite\\Enemy\\Snake.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));

}

void SpriteManager::AddDoor(DirectXGame * dx)
{
	listAnimation[SpriteDoor] = new Sprite(2);
	listAnimation[SpriteDoor]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Static\\Door1.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteDoor]->Add(new Animation(dx, 1, 2, 6, "Data\\Sprite\\Static\\Door2.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
}

void SpriteManager::AddPaddle(DirectXGame * dx)
{
	listAnimation[SpritePaddle] = new Sprite(1);
	listAnimation[SpritePaddle]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Static\\Paddle.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
}

void SpriteManager::AddItem(DirectXGame* dx)
{
	listAnimation[SpriteItem] = new Sprite(22);
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Item\\0.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Item\\1.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Item\\2.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Item\\3.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Item\\4.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Item\\5.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Item\\6.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Item\\7.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Item\\8.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Item\\9.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Item\\10.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Item\\11.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Item\\12.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Item\\13.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Item\\14.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Item\\15.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 2, 6, "Data\\Sprite\\Item\\16.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 2, 6, "Data\\Sprite\\Item\\17.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\Item\\18.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 2, 6, "Data\\Sprite\\Item\\19.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 2, 6, "Data\\Sprite\\Item\\candle.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteItem]->Add(new Animation(dx, 1, 2, 6, "Data\\Sprite\\Item\\Brick.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
}

void SpriteManager::AddIntro(DirectXGame * dx)
{
	listAnimation[SpriteIntro] = new Sprite(2);
	listAnimation[SpriteIntro]->Add(new Animation(dx, 1, 2, 6, "Data\\Sprite\\intro\\introBat.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
	listAnimation[SpriteIntro]->Add(new Animation(dx, 1, 1, 6, "Data\\Sprite\\intro\\introHelicopter.png", D3DCOLOR_XRGB(0, 255, 255), RIGHT));
}

SpriteManager::~SpriteManager()
{
}