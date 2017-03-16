#pragma once
#include "DXManager.h"
#include "GameTime.h"
#include"MovableObject.h"
#include"Whip.h"
#include"SubWeapon.h"
#include"dxaudio.h"

#define TIME_DENY_DAMAGE 10	//thời gian không nhận thêm sát thương nữa
#define TIME_ENEMY_BLINK 18

enum EnemyStatus
{
	EnemyNormal,
	EnemyOutOfHealth
};

class Enemy :
	public MovableObject
{
protected:
	EnemyStatus _status;	//Trạng thái của enemy (bình thường hay hết máu)
	int _curEnemyAction;	//Biến xác định sprite của enemy (dùng cho hàm ChangeAction())
	int iTimeDenyDamage;	//Thời gian còn lại để không nhận thêm sát thương kể từ lần cuối bị sát thương
	int iPoints;				//Điểm nhận được khi tiêu diệt
	bool isAttack;			//Có đang tấn công hay không
	bool isDisableGravity;
	GameTime *delayIndexChange;
	Point createPosition;
	int defaultHealth;
public:
	void Run(); //Runtime
	virtual void runAI();
	virtual void OnCollision(BaseObject* obj, int nx, int ny);
	void beingAttacked();
	void ChangeAction();
	//void ChangeDirection();
	void Draw();
	virtual void reLoad();
	EnemyStatus getStatus() { return _status; }
	bool isDied();
	Enemy();
	~Enemy();
};

