#pragma once
#include"DXManager.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "Ground.h"
#include "Stair.h"
#include "Quadtree.h"
#include "SimonCharacter.h"
#include "SpearGuard.h"
#include "Bat.h"
#include "Door.h"
#include "Paddle.h"
#include "ItemObject.h"
#include "Brick.h"
#include "BonePillar.h"
#include "Ghost.h"
#include "MedusaHead.h"
#include "BossMedusa.h"
using namespace std;
enum ObjectType
{ 
	OBJGround
};

class Map
{
	DXSurface* bg;
	vector<BaseObject*> listObj;
	vector<Enemy*> listEnemy;
	vector<Door*> listDoor;
	vector<Paddle*> listPaddle;
	vector<ItemObject*> listCandle;
	vector<Brick*> listBrick;
	vector<ItemObject*> listHiddenObj;
	Quadtree* tree;
public:
	int width;
	int height;
	Map();
	Map(DirectXGame*);
	void loadResource(int index);
	void getMapInfo(char*path);
	void getDoor(char*path);
	void getPaddle(char*path);
	void getEnemies(char*path);
	void getCandle(char*path);
	void getBrick(char*path);
	vector<Enemy*> getListEnemy();
	void LoadQuadtreeFromFile(char* path);
	void CreateObjFromFile();
	void run();
	void draw();
	~Map();
};

