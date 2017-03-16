#pragma once
#include"Map.h"
#include"Board.h"
#include "soundResources.h"
#include "dxaudio.h"
class CastleVania:public DirectXGame 
{
	Map *map;
	bool isFinishInitGame;
	bool inIntro;
	HINSTANCE instance;
public:
	CastleVania();
	bool init(HINSTANCE);
	void initMenu();
	void initGame();
	void initIntro();
	bool isIntro();
	void run();
	void end();
	void update();
	void draw();
	~CastleVania();
};

