#pragma once
#include"Keyboard.h"
#include "MenuCastle.h"
#include "dxaudio.h"
#include "soundResources.h"

#define TIME_MENU_BLINK 100
class Menu :
	public MovableObject
{
private:
	int iTimeBlink;	// Thời gian còn lại trước khi chuyển qua scene mới kể từ khi nhấn Enter
	bool isEnable;	// Có nhấn Enter hay không
	bool _kEnter;	// Phím Enter
	static Menu* instance;
public:
	static Menu* GetInstance();
	Menu();
	void updateKey();
	void Run();
	void Draw();
	bool isFinish()
	{ return (iTimeBlink == 0) ? true : false; }
	~Menu();
};

