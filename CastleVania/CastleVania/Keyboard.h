#pragma once
#include"DXManager.h"
#include<dinput.h>
class Keyboard
{
	HWND _hWnd;
	HINSTANCE _hInstance;
	LPDIRECTINPUT8       _di;
	LPDIRECTINPUTDEVICE8 _keyboard;
	DIDEVICEOBJECTDATA _keyEvents[256];

	BYTE  _keyStates[256];
	
	static Keyboard* instance;
public:
	Keyboard(HINSTANCE hInstance, HWND hWnd);
	static Keyboard* getInstance();
	static void Create(HINSTANCE hInstance, HWND hWnd);
	~Keyboard();
	void UpdateKeyboard();
	void PollKeyboard();
	bool IsKeyDown(BYTE keyCode);
	bool IsKeyUp(BYTE keyCode);
	void DeleteKeyboard();
};

