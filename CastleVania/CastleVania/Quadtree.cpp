#include "Quadtree.h"


Quadtree::Quadtree()
{
	root_node = new QuadNode();
}

Quadtree::Quadtree(RECT r)
{
	rec = r;
}
void Quadtree::getListObject(vector<BaseObject * > listObj)
{
	_listObj = listObj;
}



void Quadtree::FindNodeInView(QuadNode* node)
{
	if (node == NULL)
		return;
	if (node->GetRect() && !Collision::checkAABB(Camera::GetInstance(), node->GetRect()))
		return;

	if (node->GetNum_Node() == 4)
	{
		FindNodeInView(node->tl);
		FindNodeInView(node->tr);
		FindNodeInView(node->bl);
		FindNodeInView(node->br);
		return;
	}
	if (node->getListObjInNode().size() == 0)
		return;
	Camera::GetInstance()->ImportObject(node->getListObjInNode());
}

QuadNode* Quadtree::getRootNode()
{
	return root_node;
}

Quadtree::~Quadtree()
{
}
