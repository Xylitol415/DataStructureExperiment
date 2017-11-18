#include<iostream>
using namespace std;
#define StackSize 50
typedef int DataType;
typedef struct 
{
	DataType data[StackSize];
	int top;
}SeqStack;

void push(SeqStack &S, DataType x)
{
	if(S.top == StackSize - 1)
		cout<<"ջ����!"<<endl;
	else
	{
		S.top++;
		S.data[S.top] = x;
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
	cout<<"���뽫Ҫת������:";
	cin>>m;
	cout<<m<<"ת���ɶ������ǣ�";
	conversion(m, 2);
	cout<<m<<"ת���ɰ˽����ǣ�";
	conversion(m, 8);
	cout<<m<<"ת����ʮ�������ǣ�";
	conversion(m, 16);
	return 0;
}