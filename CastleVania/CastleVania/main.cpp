#include "CastleVania.h"

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	 lpCmdLine,
	int		 nCmdShow)
{
	CastleVania*_game = new CastleVania();
	_game->init(hInstance);
	_game->run();
	return 1;
}