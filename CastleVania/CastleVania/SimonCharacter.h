#pragma once
#include "DXManager.h"
#include "GameTime.h"
#include"Animation.h"
#include"SpriteManager.h"
#include"MovableObject.h"
#include"Keyboard.h"
#include"Whip.h"
#include "SubWeapon.h"
#include "Menu.h"
#include "Stair.h"
#include "Door.h"
#include "Enemy.h"
#include "Paddle.h"
#include "ItemObject.h"
#include "dxaudio.h"
#include "soundResources.h"
#include "IntroBat.h"
#include "IntroHelicopter.h"

#pragma region Define Static Values
#define VX_GO 0.18
#define VX_SPEEDUP 0.2
#define VY_JUMP -0.21
#define COUNT_SPEEDING_FLYABLE 7
#define TIME_INDEX_CHANGE 0.3
#define TIME_TYPEUP 0.5
#define TIME_KICK 0.2
#define TIME_BLINK 50
#define TIME_JUMP 1
#define TIME_WHIP 18
#define TIME_STAND_INTRO 300
#define TIME_DELAY_CLIMB 10
#define TIME_UPGRADINGWHIP 50

#define TIME_KNIFE_ACTIVE 75
#define TIME_AXE_ACTIVE 60
#define TIME_HOLYWATER_ACTIVE 50
#define TIME_STOPWATCH_ACTIVE 1
#define TIME_CROSS_ACTIVE 200
#define TIME_DEAD 40
#pragma endregion

struct SimonFlag
{
	bool inIntro;				// đang trong game intro
	bool isBlink;				// thời gian nhấp nháy
	bool isJump;				// có đang nhảy
	bool isStand;				// có đang đứng yên
	bool isSit;					// có đang ngồi yên
	bool isSitBefore;			// Xác định hành động trước đó có phải là ngồi
	bool isStandBefore;			// Xác định hành động trước đó có phải là đứng yên trên đất
	bool isFall;				// có đang rơi
	bool isWhip;				// có đang quất roi
	bool isThrow;				// có đang sử dụng vũ khí phụ
	bool isDone;				// Xong Sprite SimonWhip
	bool isThrowDone;
	bool isClimb;
	bool isFinishClimb;
	bool isChangeStage;
	bool isCollStair;			// có va chạm với cầu thang
	bool onAction;				// đang hành động
	bool beingAttacked;			// có bị mất máu hay không
	bool moveWhileBeingAttacked;// có cho phép di chuyển khi bị mất máu hay không
	bool isEnteringDoor;
	bool isDead;
	bool _kLeft, _kRight, _kJump, _kUp, _kDown, _kMove, _kThrow, _kWhip;	//keyboard input
	bool isFinishLevel;
	bool isUpgradingWhip;
};

class SimonCharacter : public MovableObject
{
private:
	static SimonCharacter* instance;
protected:
	IntroBat *bat1, *bat2;
	IntroHelicopter* helicopter;
	SimonFlag flag;
	WhipType _whipType;			// Loại roi đang sử dụng
	Door* _curDoor;
	int iTimeWeapon;
	int iTimeStandIntro;
	int iTimeUpgradingWhip;
	int iTimeDead;
	float iTimeBlink;
	int iPreFrame;
	int _curSimonAction;		// Hành động hiện tại của Simon
	void setSimonAction(SimonSprite action); // thiết lập hành động Simon
public:
	int iHeart;
	int iLife;
	int iScore;
	bool doubleShot, tripleShot;
	SubWeaponType _weaponType;	// Loại vũ khí phụ đang sử dụng

	SimonCharacter();
	bool isIntro();
	static SimonCharacter* GetInstance();
	bool RunIntro();
	void Run(); //Runtime
	void OnCollision(BaseObject* obj, int nx, int ny);
	void ChangeAction();
	void ChangeDirection();
#pragma region Hành động của Simon
	void Move();
	void Jump();
	void Sit();
	void Attack();
	void Whip();
	void Throw();
	void Climb();
	void BeingAttacked();
	void Blink();
	void Dead();
	void EnterDoor();
	void collectItem(ItemObject* item);
	void finishLevel();
	void upgradingWhip();
#pragma endregion
	BaseObject* checkStair();
	void setCurDoor(Door* _door);
	void UpdateKey();
	void Draw();
	~SimonCharacter();
};

