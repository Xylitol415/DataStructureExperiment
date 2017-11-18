#include<iostream>
using namespace std;
#define MaxSize 50
typedef struct
{
	int num[MaxSize];
	int time[MaxSize];
	int top;
}SeqStack;
typedef struct
{
	int num[MaxSize];
	int time[MaxSize];
	int front;
	int rear;
}CirQueue;

//队列相关函数
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

int RearNum(CirQueue Q)				//返回队尾下标，作为车辆在便道停放位置
{
	if(Q.rear == Q.front)
		return false;
	else
		return Q.rear;
}

int InCirQueue(CirQueue &Q, int a, int b)
{
	if((Q.rear + 1) % MaxSize == Q.front)
		return false;
	Q.num[Q.rear] = a;
	Q.time[Q.rear] = b;
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}

int DelCirQueue(CirQueue &Q, int &a, int &b)
{
	if(Q.front == Q.rear)
		return false;
	a = Q.num[Q.front];
	b = Q.time[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}

//栈相关函数
void InitStack(SeqStack &S)
{
	S.top = -1;
}

bool StackEmpty(SeqStack &S)
{
	if(S.top == -1)
		return true;
	else
		return false;
}

int Push(SeqStack &S, int a, int b)
{
	if(S.top == MaxSize - 1)
		return false;
	else
	{
		S.top++;
		S.num[S.top]= a;
		S.time[S.top] = b;
		return true;
	}
}

int Pop(SeqStack &S, int &a, int &b)
{
	if(S.top == - 1)
		return false;
	else
	{
		a = S.num[S.top];
		b = S.time[S.top];
		S.top--;
		return true;
	}
}

int TopNum(SeqStack S)			//返回栈顶下标，作为车辆在停车场停放位置
{
	if(S.top == - 1)
		return false;
	else
		return S.top + 1;
}

void ParkingManager()
{
	SeqStack s, s1;
	CirQueue q;
	int n, p, t, num, time, num1 = 0, time1 = 0, flag = 1;
	char action;
	InitCirQueue(q);
	InitStack(s);
	InitStack(s1);
	cout<<"请输入停车场最大容量(/辆)和每小时停车费用(/元)："<<endl;
	cin>>n>>p;
	cout<<"请输入车的状态(A、进站/D、出站/E、输入结束)、车牌号和时间(进站时间/出站时间)："<<endl;
	while(flag)
	{
		cin>>action>>num>>time;
		switch(action)
		{
			case 'A':
				{
					if(s.top == n-1)
					{
						InCirQueue(q, num, time);
						cout<<"车牌号为 "<<num<<" 的汽车在便道上的位置是 "<<RearNum(q)<<endl;
					}
					else
					{
						Push(s, num, time);
						cout<<"车牌号为 "<<num<<" 的汽车在停车场的位置是 "<<TopNum(s)<<endl;
					}
					break;
				}
			case 'D':
				{
					if(StackEmpty(s))
					{
						cout<<"停车场没有车辆停放！"<<endl;
						break;
					}
					else
					{
						Pop(s, num1, time1);
						while(num != num1)
						{	
							Push(s1, num1, time1);
							Pop(s, num1, time1);
							
						}
						t = time - time1;
						cout<<"车牌号为 "<<num<<" 的汽车在停车场停留的时间是 "<<t<<" 小时， 共花费了 "<<p*t<<" 元。"<<endl;
						while(!StackEmpty(s1))
						{
							Pop(s1, num1, time1);
							Push(s, num1, time1);
						}
						while(s.top != n && !QueueEmpty(q))	
						{
							DelCirQueue(q, num1, time1);
							Push(s, num1, time1);
						}
					}
					break;
				}
			case 'E':
				{
					flag = 0;
					cout<<"输入结束！"<<endl;
					break;
				}
			default: break;
		}
	}
}

int main()
{

	ParkingManager();
	return 0;
}