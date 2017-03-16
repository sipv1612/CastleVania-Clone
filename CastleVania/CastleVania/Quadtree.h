#pragma once
#include "QuadNode.h"
#include "Camera.h"
#include "BaseObject.h"
#include "Collision.h"
#include <vector>
#include <fstream>
#include <list>
#include <iostream>

using namespace std;
class Quadtree
{
	RECT rec;
	vector<BaseObject *> list_Obj;
	vector<QuadNode*> listNode_inView;
	vector<BaseObject *> listobj_inView;
	QuadNode* root_node;
	vector<BaseObject * > _listObj;
public:

	void getListObject(vector<BaseObject * > _listObj);
	Quadtree();
	Quadtree(RECT rec);
	QuadNode* getRootNode();
	void FindNodeInView(QuadNode* node);


	~Quadtree(); 
};
