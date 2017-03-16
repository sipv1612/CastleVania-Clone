#pragma once
#include "MovableObject.h"
class MenuCastle :
	public MovableObject
{
private:
	static MenuCastle* instance;
	bool _isDone;
public:
	static MenuCastle* GetInstance();
	MenuCastle();
	bool isDone();
	void Draw();
	~MenuCastle();
};

