#include "GameTime.h"



GameTime::GameTime()
{
}

void GameTime::init(float fps)
{
	m_timePerFrame = 1000.0 / fps;
	m_deltaTime = 0;
	m_starttime = GetTickCount();
	access = false;
}

void GameTime::tick()
{
	m_starttime = GetTickCount();
	access = true;
}

GameTime::GameTime(int fps)
{
	init(fps);
}

bool GameTime::canCreatNewFrame()
{
	m_now = GetTickCount();
	m_deltaTime = m_now - m_starttime;
	if (m_deltaTime >= m_timePerFrame)
	{
		if (m_deltaTime < 2 * m_timePerFrame)
		{
			m_deltaTimePrevious = m_deltaTime;
		}
		else
		{
			m_deltaTime = m_deltaTimePrevious;
		}
		m_starttime = m_now;
		return true;
	}
	else
		return false;
}

DWORD GameTime::getDeltaTime()
{
	return m_deltaTime;
}

DWORD GameTime::getGameTime()
{
	return 0;
}

DWORD GameTime::getTickPerFrame()
{
	return m_timePerFrame;
}

void GameTime::release()
{
}
GameTime* GameTime::instance = 0;
GameTime * GameTime::getInstance(float fps)
{
	if (!instance)
		instance = create(fps);
	return instance;
}


GameTime * GameTime::create(float fps)
{
	GameTime* gt = new GameTime();
	gt->init(fps);
	return gt;
}

GameTime::~GameTime()
{
}
