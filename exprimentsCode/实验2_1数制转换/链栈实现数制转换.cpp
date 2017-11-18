#include<iostream>
#include<malloc.h>
using namespace std;
#define StackSize 50
typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node *next;
}StackNode;
typedef StackNode *LinkStack;

void push(LinkStack &top, DataType x)
{
	StackNode *s;
	s = (StackNode *)malloc(sizeof(StackNode));
	if(s == NULL)
		cout<<"����ռ�ʧ��!"<<endl;
	s -> data = x;
	s -> next = top -> next;
	top -> next = s;
}

void pop(LinkStack &top, DataType &x)
{
	StackNode *s;
	s = top -> next;
	if(s == NULL)
		cout<<"ջΪ��"<<endl;
	x = s -> data;
	top -> next = s -> next;
	free (s);
}

void conversion(int m , int n)
{
	StackNode *S;
	S = new StackNode;
	int e;
	S->next = NULL;
	//InitStack(S);
	while(m)
	{
		push(S, m % n);
		m /= n;
	}
	while(S -> next != NULL)
	{
		pop(S, e);
		if(e<10) 
			cout<<e;
		else
			cout<<(char)(e+55);
	}
	cout<<endl;
}

int main()
{
	StackNode *S;
	int m, n;
	cout<<"���뽫Ҫת������:";
	cin>>m;
	//cin>>n;
	//cout<<m<<"ת����"<<n<<"���ƽ��Ϊ:";
	//conversion(m,n);
	cout<<m<<"ת���ɶ������ǣ�";
	conversion(m, 2);
	cout<<m<<"ת���ɰ˽����ǣ�";
	conversion(m, 8);
	cout<<m<<"ת����ʮ�������ǣ�";
	conversion(m, 16);
	return 0;
}



/*typedef struct 
{
	DataType data[StackSize];
	int top;
}SeqStack;

void push(SeqStack &S, DataType x)
{
	if(S.top == StackSize - 1)
		cout<<"ջ����!"<<endl;
		//return false;
	else
	{
		S.top++;
		S.data[S.top] = x;
		//return true;
	}
}

void pop(SeqStack &S, DataType &x)
{
	if(S.top == -1)
		cout<<"ջΪ��!"<<endl;
	else 
	{
		x = S.data[S.top];
		S.top--;
	}
}

void InitStack(SeqStack &S)
{
	S.top = -1;
}

int StackEmpty(SeqStack &S)
{
	if(S.top == -1)
		return true;
	else 
		return false;
}

void conversion(int m , int n)
{
	SeqStack S;
	int e;
	InitStack(S);
	while(m)
	{
		push(S, m % n);
		m /= n;
	}
	while(!StackEmpty(S))
	{
		pop(S, e);
		if(e<10) 
			cout<<e;
		else
			cout<<(char)(e+55);
	}
	cout<<endl;
}

int main()
{
	SeqStack S;
	int m, n;
	cout<<"���뽫Ҫת��������ת���Ľ���:";
	cin>>m;
	//cin>>n;
	//cout<<m<<"ת����"<<n<<"���ƽ��Ϊ:";
	//conversion(m,n);
	cout<<m<<"ת���ɶ������ǣ�";
	conversion(m, 2);
	cout<<m<<"ת���ɰ˽����ǣ�";
	conversion(m, 8);
	cout<<m<<"ת����ʮ�������ǣ�";
	conversion(m, 16);
	return 0;
}*/