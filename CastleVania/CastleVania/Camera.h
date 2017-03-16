#pragma once
#include<d3dx9.h>
#include"BaseObject.h"
#include<vector>
#include"Collision.h"
#include"Rect.h"
#include<fstream>
using namespace std;

struct Stage
{
	int lvl;
	int id;
	int posX;
	int posY;
	int width;
	int height;
};

class Camera:public BaseObject
{
private:
	vector<Stage> listStage;
	Stage _curStage;
	static Camera* instance;
	BaseObject *player;
	Rect* rectMoveZone;
	vector<BaseObject*> ListObj;
	vector<BaseObject*> ListGround;
	vector<BaseObject*> ListStair;
	//vector<BaseObject*> ListEnemy;
public:
	vector<BaseObject*>* GetListObj();
	vector<BaseObject*>* GetListGround();
	vector<BaseObject*>* GetListStair();
	//vector<BaseObject*>* GetListEnemy();
	static Camera* GetInstance();
	bool canUp;
	int maxX;
	int maxY;
	void setMax(int _width, int _height);
	void loadStages();
	vector<Stage> getListStage();
	Stage getCurStage();
	void nextStage();
	void preStage();
	void setMoveZone(Rect* _rect);
	Rect* getMoveZone();
	void init(int, int, int, int);
	void initPlayer(BaseObject *p);
	RECT toRect();
	void updatePosition();
	void run();
	void ImportObject(vector<BaseObject*> listObj);
	void OnCollision(BaseObject* obj, int nx, int ny);
	void AddObjectToListCol();
	~Camera();
};

