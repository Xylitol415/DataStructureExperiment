#include<iostream>
using namespace std;
#define MaxNode 20
typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void CreateBiTree(BiTree &T)
{
	char ch;
	cin>>ch;
	if(ch == '#') 
		T = NULL;
	else
	{
		T = new BiTNode;
		T -> data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

void PreOrder(BiTree bt)
{
	if(bt == NULL)
		return;
	cout<<bt -> data<<" ";
	PreOrder(bt->lchild);
	PreOrder(bt->rchild);
}

void InOrder(BiTree bt)
{
	if(bt == NULL)
		return;
	InOrder(bt->lchild);
	cout<<bt -> data<<" ";
	InOrder(bt->rchild);
}

void PostOrder(BiTree bt)
{
	if(bt == NULL)
		return;
	PostOrder(bt->lchild);
	PostOrder(bt->rchild);
	cout<<bt -> data<<" ";
}

void LevelOrder(BiTree bt)
{
	BiTree queue[MaxNode];
	int front,rear;
	if(bt == NULL)
		return;
	front = -1;
	rear = 0;
	queue[rear] = bt;
	while(front != rear)
	{
		front++;
		cout<<queue[front] -> data<<" ";
		if(queue[front]->lchild != NULL)
		{
			rear++;
			queue[rear] = queue[front] -> lchild;
		}
		if(queue[front]->rchild != NULL)
		{
			rear++;
			queue[rear] = queue[front] -> rchild;
		}
	}
}

int main()
{
	BiTree t;
	cout<<"������Ҫ�����Ķ�����(�����������˳������)��"<<endl;
	CreateBiTree(t);
	cout<<"���������������";
	PreOrder(t);
	cout<<endl;
	cout<<"���������������";
	InOrder(t);
	cout<<endl;
	cout<<"���������������";
	PostOrder(t);
	cout<<endl;
	cout<<"��α�����������";
	LevelOrder(t);
	cout<<endl;
	return 0;
}

