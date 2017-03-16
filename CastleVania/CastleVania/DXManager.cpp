#include "DXManager.h"


DirectXGame::DirectXGame() {
	this->_d3d = NULL;
	this->_d3dDevice = NULL;
	this->_backBuffer = NULL;
}
DirectXGame* DirectXGame::instance = 0;

DirectXGame* DirectXGame::GetInstance()
{
	return instance;
}
LPDIRECT3DDEVICE9 DirectXGame::GetDevice()
{
	return _d3dDevice;
}
LPD3DXSPRITE DirectXGame::GetSprite()
{
	return _spriteHandler;
}

LRESULT WINAPI DirectXGame::WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}


bool DirectXGame::Init_Window(HINSTANCE hInstance)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)DirectXGame::WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = GAME_TITLE;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	DWORD style;
	if (FULL_SCREEN)
	{
		style = WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP;
	}
	else
	{
		style = WS_OVERLAPPEDWINDOW;
	}

	_hWnd = CreateWindow(
		GAME_TITLE,
		GAME_TITLE,
		style,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);
	if (!_hWnd)
	{
		return false;
	}

	ShowWindow(_hWnd, SW_SHOWDEFAULT);
	UpdateWindow(_hWnd);

	return true;
}

bool DirectXGame::Init_Direct3D()
{
	_d3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (_d3d == NULL)
	{
		return false;
	}

	D3DPRESENT_PARAMETERS pp;
	ZeroMemory(&pp, sizeof(pp));

	pp.Windowed = !FULL_SCREEN;
	pp.SwapEffect = D3DSWAPEFFECT_COPY;
	pp.BackBufferCount = 1;
	pp.BackBufferWidth = 256; //kich thuoc camera 256
	pp.BackBufferHeight = 208; // ```160
	pp.hDeviceWindow = _hWnd;
	pp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;

	_d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&pp,
		&_d3dDevice);

	if (_d3dDevice == NULL)
	{
		return false;
	}

	_d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);


	D3DXCreateSprite(_d3dDevice, &_spriteHandler);
	_d3dDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &_backBuffer);
	_d3dDevice->CreateOffscreenPlainSurface(SCREEN_WIDTH, SCREEN_HEIGHT, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &_frameBuffer, 0);

	return true;
}

void DirectXGame::Clear()
{
	_d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
}

LPDIRECT3DSURFACE9 DirectXGame::GetBackBuffer()
{
	return _backBuffer;
}
bool DirectXGame::BeginScene()
{
	_d3dDevice->BeginScene();
	return true;
}

void DirectXGame::DrawSurface(DXSurface *pSurface, RECT *pSourceRect, RECT *PDestRect)
{
	_d3dDevice->StretchRect(pSurface->GetSurface(), pSourceRect, _backBuffer, PDestRect, D3DTEXF_NONE);
}

void DirectXGame::SpriteHandler_Begin()
{
	_spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
}

void DirectXGame::DrawTexture(DXTexture *pTexture, D3DXVECTOR2 *pCenter, RECT *pSourceRect, D3DCOLOR color)
{
	_spriteHandler->Draw(pTexture->GetTexture(), pSourceRect, 0, &D3DXVECTOR3(pCenter->x, pCenter->y, 0), color);
}

void DirectXGame::PrintText(char* str, int size, int x, int y, DWORD color)
{
	ID3DXFont* dxfont;
	RECT textbox;
	SetRect(&textbox, x, y, 272, 272);
	D3DXCreateFont(_d3dDevice,    // the D3D Device
		size,    // font height
		0,    // default font width
		FW_NORMAL,    // font weight
		1,    // not using MipLevels
		false,    // italic font
		DEFAULT_CHARSET,    // default character set
		OUT_DEFAULT_PRECIS,    // default OutputPrecision,
		DEFAULT_QUALITY,    // default Quality
		DEFAULT_PITCH | FF_DONTCARE,    // default pitch and family
		"Arial",    // use Facename Arial
		&dxfont);    // the font object
	dxfont->DrawTextA(NULL,
		str,
		strlen(str),
		&textbox,
		DT_LEFT | DT_TOP,
		color);

	dxfont->Release();
}


void DirectXGame::SpriteHandler_End()
{
	_spriteHandler->End();
}
LPDIRECT3DDEVICE9 DirectXGame::getD3dDevice()
{
	return _d3dDevice;
}
void DirectXGame::EndScene()
{
	_d3dDevice->EndScene();
}

void DirectXGame::Present()
{
	_d3dDevice->Present(NULL, NULL, NULL, NULL);
}

void DirectXGame::DeleteWindow()
{
	if (_hWnd)
	{
		DestroyWindow(_hWnd);
	}
}

void DirectXGame::DeleteDirect3D()
{
	if (_backBuffer != NULL)
	{
		_backBuffer->Release();
		_backBuffer = NULL;
	}

	if (_d3dDevice != NULL)
	{
		_d3dDevice->Release();
		_d3dDevice = NULL;
	}

	if (_d3d != NULL)
	{
		//_d3d->Release();
		//_d3d = NULL;
	}
}

DirectXGame::~DirectXGame()
{
	DeleteDirect3D();
	DeleteWindow();
}

DXSurface::DXSurface(DirectXGame* dx)
{
	_dx = dx;
	//this->_d3dDevice = device;
	this->_surface = NULL;
}

void DXSurface::Draw()
{
	_dx->DrawSurface(this, &Camera::GetInstance()->toRect(), 0);
}

bool DXSurface::LoadSurface(char *filename, D3DCOLOR color)
{
	HRESULT result;

	result = D3DXGetImageInfoFromFile(filename, &_info);
	if (result != D3D_OK)
	{
		return false;
	}

	result = _dx->getD3dDevice()->CreateOffscreenPlainSurface(
		_info.Width,
		_info.Height,
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&_surface,
		NULL);
	if (result != D3D_OK)
	{
		return false;
	}

	result = D3DXLoadSurfaceFromFile(
		_surface,
		NULL,
		NULL,
		filename,
		NULL,
		D3DX_DEFAULT,
		color,
		NULL);
	if (result != D3D_OK)
	{
		return false;
	}

	return true;
}

LPDIRECT3DSURFACE9 DXSurface::GetSurface()
{
	return this->_surface;
}

int DXSurface::GetWidth()
{
	return _info.Width;
}

int DXSurface::GetHeight()
{
	return _info.Height;
}

DXSurface::~DXSurface()
{
	if (_surface != NULL)
	{
		_surface->Release();
		_surface = NULL;
	}
}

DXTexture::DXTexture(DirectXGame* dx)
{
	this->_dxGame = *dx;
	this->_texture = NULL;
}

bool DXTexture::LoadTexture(char *filename, float nHorizontal, float nVertical, D3DCOLOR color)
{
	HRESULT result;

	result = D3DXGetImageInfoFromFile(filename, &_info);
	if (result != D3D_OK)
	{
		return false;
	}

	_width = (int)(nHorizontal * (float)OBJECT_WIDTH);
	_height = (int)(nVertical * (float)OBJECT_HEIGHT);
	result = D3DXCreateTextureFromFileEx(
		_dxGame.GetDevice(),
		filename,
		_width,
		_height,
		1,
		D3DPOOL_DEFAULT,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		color,
		&_info,
		NULL,
		&_texture);
	if (result != D3D_OK)
	{
		_texture = NULL;
		return false;
	}

	return true;
}

bool DXTexture::LoadTexture(char *filename, D3DCOLOR color)
{
	HRESULT result;

	result = D3DXGetImageInfoFromFile(filename, &_info);
	if (result != D3D_OK)
	{
		return false;
	}

	_width = _info.Width;
	_height = _info.Height;
	result = D3DXCreateTextureFromFileEx(
		_dxGame.GetDevice(),
		filename,
		_info.Width,
		_info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		//D3DPOOL_DEFAULT,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		color,
		&_info,
		NULL,
		&_texture);
	if (result != D3D_OK)
	{
		_texture = NULL;
		return false;
	}

	return true;
}

LPDIRECT3DTEXTURE9 DXTexture::GetTexture()
{
	return this->_texture;
}

int DXTexture::GetWidth()
{
	return _width;
}

int DXTexture::GetHeight()
{
	return _height;
}

DXTexture::~DXTexture()
{
	if (_texture != NULL)
	{
		_texture->Release();
		_texture = NULL;
	}
}
