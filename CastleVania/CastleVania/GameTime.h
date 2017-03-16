#pragma once
#include<Windows.h>
#include<time.h>
class GameTime
{
	DWORD m_deltaTimePrevious;
	DWORD m_starttime;
	DWORD m_now;
	DWORD m_deltaTime;
	DWORD m_timePerFrame;
public:
	static GameTime* instance;
	bool access;
	GameTime();
	void init(float fps);
	void tick();
	GameTime(int fps);
	bool canCreatNewFrame();
	DWORD getDeltaTime();
	DWORD getGameTime();
	DWORD getTickPerFrame();
	void release();
	static GameTime* getInstance(float fps = 0);


	static GameTime *create(float fps);

	~GameTime();
};

