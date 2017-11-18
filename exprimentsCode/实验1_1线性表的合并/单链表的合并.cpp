#include<iostream.h>
#include<stdio.h>
typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node, *LinkList;

void CreatListH(LinkList &L)	//头插法建立链表
{
	Node *s;
	DataType x;
	L = new  Node;
	L->next = NULL;
	cin>>x;
	while(x)
	{
		s = new Node;
		s->data = x;
		s -> next = L -> next;
		L -> next = s;
		cin>>x;
	}
}

void PrintList(LinkList L)
{
	Node *p;
	p = L -> next;
	if(L->next == NULL)
		cout<<"链表为空";
	else
	{
		cout<<"head->";
		while(p)
		{
			cout<<p -> data<<"->";
			p = p -> next;
		}
		cout<<"end"<<endl;
	}
}

void MergeLinkList(LinkList La, LinkList Lb, LinkList &Lc)
{
	Node *pa, *pb, *pc;
	pa = La -> next;
	pb = Lb -> next;
	Lc = La;
	pc = Lc;
	while(pa != NULL && pb != NULL)
	{
		if(pa->data <= pb->data)
		{	pc->next = pa; pc = pa; pa = pa->next;	 }
		else
		{	pc->next = pb; pc = pb; pb = pb->next;	 } 
	}
	if(pa)
		{	pc->next = pa; pc = pa; pa = pa->next;	 }
	if(pb)
		{	pc->next = pb; pc = pb; pb = pb->next;	 }
	delete(Lb);
}

int main()
{
	LinkList L1, L2, L3;
	CreatListH(L1);
	CreatListH(L2);
	MergeLinkList(L1, L2, L3);
	PrintList(L3);
	return 0;
}