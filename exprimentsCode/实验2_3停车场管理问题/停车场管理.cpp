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

//������غ���
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

int RearNum(CirQueue Q)				//���ض�β�±꣬��Ϊ�����ڱ��ͣ��λ��
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

//ջ��غ���
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

int TopNum(SeqStack S)			//����ջ���±꣬��Ϊ������ͣ����ͣ��λ��
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
	cout<<"������ͣ�����������(/��)��ÿСʱͣ������(/Ԫ)��"<<endl;
	cin>>n>>p;
	cout<<"�����복��״̬(A����վ/D����վ/E���������)�����ƺź�ʱ��(��վʱ��/��վʱ��)��"<<endl;
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
						cout<<"���ƺ�Ϊ "<<num<<" �������ڱ���ϵ�λ���� "<<RearNum(q)<<endl;
					}
					else
					{
						Push(s, num, time);
						cout<<"���ƺ�Ϊ "<<num<<" ��������ͣ������λ���� "<<TopNum(s)<<endl;
					}
					break;
				}
			case 'D':
				{
					if(StackEmpty(s))
					{
						cout<<"ͣ����û�г���ͣ�ţ�"<<endl;
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
						cout<<"���ƺ�Ϊ "<<num<<" ��������ͣ����ͣ����ʱ���� "<<t<<" Сʱ�� �������� "<<p*t<<" Ԫ��"<<endl;
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
					cout<<"���������"<<endl;
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