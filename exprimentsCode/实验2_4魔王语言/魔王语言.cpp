#include<iostream>
using namespace std;
#define StackSize 50
typedef char DataType;
#define maxsize 100
typedef struct 
{
	DataType data[StackSize];
	int top;
}SeqStack;


typedef struct 
{
	DataType data[maxsize];
	int front;
	int rear;
}CirQueue;

typedef struct Node
{
	DataType data;
	struct Node *next;
}LinkQueueNode;

//栈
void push(SeqStack &S, DataType x)
{
	if(S.top == StackSize - 1)
		cout<<"栈已满!"<<endl;
	else
	{
		S.top++;
		S.data[S.top] = x;
	}
}

void pop(SeqStack &S, DataType &x)
{
	if(S.top == -1)
		cout<<"栈为空!"<<endl;
	else 
	{
		x = S.data[S.top];
		S.top--;
	}
}

DataType GetTop(SeqStack &S)
{
	DataType x;
	if(S.top == -1)
	{
		cout<<"栈为空!"<<endl;
		return 0;
	}
	else 
	{
		x = S.data[S.top];
		S.top--;
		return x;
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
//队列
void InitCirQueue(CirQueue &Q)
{
	Q.front = Q.rear = 0;
}

int QueueEmpty(CirQueue Q)
{
	if(Q.rear == Q.front)
		return true;
	else 
		return false;
}

int QueueFull(CirQueue Q)
{
	if((Q.rear + 1) % maxsize == Q.front)
		return true;
	else 
		return false;
}

int QueueFront(CirQueue Q, DataType &x)
{
	if(Q.rear == Q.front)
		return false;
	else
	{
		x = Q.data[Q.front];
		return true;
	}
}

int InCirQueue(CirQueue &Q, DataType x)
{
	if((Q.rear + 1) % maxsize == Q.front)
		return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % maxsize;
	return true;
}

int DelCirQueue(CirQueue &Q, DataType &x)
{
	if(Q.front == Q.rear)
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % maxsize;
	return true;
}

void DemonLanguage(char s[])
{
	SeqStack S;
	CirQueue Q;
	int i = 0, j = 0;
	char ch, x, c;
	InitStack(S);
	InitCirQueue(Q);
	for(; s[i] != '\0'; i++)
	{
		if(s[i] == 'B')
		{
			InCirQueue(Q, 't');
			InCirQueue(Q, 's');
			InCirQueue(Q, 'a');
			InCirQueue(Q, 'e');
			InCirQueue(Q, 'd');
			InCirQueue(Q, 's');
			InCirQueue(Q, 'a');
			InCirQueue(Q, 'e');
		}
		if(s[i] == 'A')
		{
			InCirQueue(Q, 's');
			InCirQueue(Q, 'a');
			InCirQueue(Q, 'e');
		}
		if(s[i] == '(')
		{
			ch = s[i + 1];
			j = i + 2;
			while(s[j] != ')')
			{
				push(S, s[j]);
				j++;
			}
			while(!StackEmpty(S))
			{
				InCirQueue(Q, ch);
				InCirQueue(Q, GetTop(S));
			}
			if(StackEmpty(S))
				InCirQueue(Q, ch);
		}
	}
	while(!QueueEmpty(Q))
	{
		DelCirQueue(Q, c);
		switch(c)
		{
			case 't': cout<<"天";break;
			case 'd': cout<<"地";break;
			case 's': cout<<"上";break;
			case 'a': cout<<"一只";break;
			case 'e': cout<<"鹅";break;
			case 'z': cout<<"追";break;
			case 'g': cout<<"赶";break;
			case 'x': cout<<"下";break;
			case 'n': cout<<"蛋";break;
			case 'h': cout<<"恨";break;
			default: break;
		}
	}
	cout<<endl;
}

int main()
{
	char s[20];
	int i;
	for(i = 0; i < 20; i++)
		s[i] = '\0';
	cout<<"请输入魔王语言:";
	for(i =0; i < 10; i++)
		cin>>s[i];
	DemonLanguage(s);
	return 0;
}

//B(ehnxgz)B
