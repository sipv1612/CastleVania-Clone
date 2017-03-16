#pragma once
#include<d3d9.h>
#include<d3dx9.h>
#include"Camera.h"
#include<dinput.h>
#define FULL_SCREEN								0		// 0: Window, 1: Full Screen
#define SCREEN_WIDTH							493
#define SCREEN_HEIGHT							400
#define GAME_TITLE								"Castle Vania"
#define OBJECT_WIDTH							50
#define OBJECT_HEIGHT							50
#define FRAME_NUMBER							120
class DirectXGame;
class DXSurface;
class DXTexture;
class DirectXGame
{
private:
	static LRESULT WINAPI WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
protected:
	HWND _hWnd;
	LPDIRECT3D9 _d3d;
	LPDIRECT3DDEVICE9 _d3dDevice;
	LPDIRECT3DSURFACE9 _backBuffer;
	LPDIRECT3DSURFACE9 _frameBuffer;
	LPD3DXSPRITE _spriteHandler;
	static DirectXGame* instance;
public:
	DirectXGame();
	static DirectXGame* GetInstance();
	bool Init_Window(HINSTANCE);
	bool Init_Direct3D();
	LPDIRECT3DDEVICE9 GetDevice();
	LPD3DXSPRITE GetSprite();
	LPDIRECT3DSURFACE9 GetBackBuffer();
	bool BeginScene();
	void Clear();
	void DrawSurface(DXSurface *, RECT * = NULL, RECT * = NULL);
	void SpriteHandler_Begin();
	void PrintText(char* str, int size, int x, int y, DWORD color);
	void DrawTexture(DXTexture *, D3DXVECTOR2 *, RECT * = NULL, D3DCOLOR = D3DCOLOR_XRGB(255, 255, 255));
	void SpriteHandler_End();
	LPDIRECT3DDEVICE9 getD3dDevice();
	void EndScene();
	void Present();
	void DeleteWindow();
	void DeleteDirect3D();
	~DirectXGame();
};
class DXSurface
{
private:
	LPDIRECT3DSURFACE9 _surface;
	D3DXIMAGE_INFO _info;
	DirectXGame* _dx;
public:
	DXSurface() {}
	DXSurface(DirectXGame*);
	bool LoadSurface(char *, D3DCOLOR = 0);
	LPDIRECT3DSURFACE9 GetSurface();
	void Draw();
	int GetWidth();
	int GetHeight();
	~DXSurface();
};
class DXTexture
{
protected:

	LPDIRECT3DTEXTURE9 _texture;
	D3DXIMAGE_INFO _info;
	int _width, _height;
public:
	DXTexture() {}
	DXTexture(DirectXGame*);
	DirectXGame _dxGame;
	bool LoadTexture(char *, float, float, D3DCOLOR = 0);
	bool LoadTexture(char *, D3DCOLOR = 0);
	LPDIRECT3DTEXTURE9 GetTexture();
	int GetWidth();
	int GetHeight();
	~DXTexture();
};

