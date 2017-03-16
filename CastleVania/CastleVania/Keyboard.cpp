#include"Keyboard.h"
Keyboard* Keyboard::instance = 0;

Keyboard::Keyboard(HINSTANCE hInstance, HWND hWnd)
{
	_hWnd = hWnd;
	_hInstance = hInstance;
	DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&_di, NULL);
	_di->CreateDevice(GUID_SysKeyboard, &_keyboard, NULL);
	_keyboard->SetDataFormat(&c_dfDIKeyboard);
	_keyboard->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE);

	DIPROPDWORD dipdw;

	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = 1024;

	_keyboard->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
	_keyboard->Acquire();

	for (int i = 0; i < 256; i++)
	{
		_keyStates[i] = 0x00;
	}
}
Keyboard* Keyboard::getInstance()
{
	return instance;
}

void Keyboard::Create(HINSTANCE hInstance, HWND hWnd)
{
	instance = new Keyboard(hInstance, hWnd);
}
Keyboard::~Keyboard()
{
	if (_keyboard)
	{
		_keyboard->Unacquire();
		_keyboard->Release();
	}

	if (_di) _di->Release();
}


void Keyboard::PollKeyboard()
{
	_keyboard->Poll();
	if (FAILED(_keyboard->GetDeviceState(sizeof(_keyEvents), (LPVOID)&_keyEvents)))
	{
		_keyboard->Acquire();
		_keyboard->GetDeviceState(sizeof(_keyEvents), (LPVOID)&_keyEvents);
	}
	else
	{
		_keyboard->GetDeviceState(sizeof(_keyEvents), (LPVOID)&_keyEvents);
	}

}

void Keyboard::UpdateKeyboard()
{
	BYTE keys[256];
	_keyboard->GetDeviceState(256, keys);
	for (int i = 0; i < 256; i++)
	{
		_keyStates[i] = keys[i];
	}

}

bool Keyboard::IsKeyDown(BYTE keyCode)
{
	return (_keyStates[keyCode] & 0x80) > 0;
}

bool Keyboard::IsKeyUp(BYTE keyCode)
{
	return !((_keyStates[keyCode] & 0x80) > 0);
}

void Keyboard::DeleteKeyboard()
{
	if (_keyboard)
	{
		_keyboard->Unacquire();
		_keyboard->Release();
		_keyboard = NULL;

	}
	if (_di)
	{
		_di->Release();
		_di = 0;
	}
}