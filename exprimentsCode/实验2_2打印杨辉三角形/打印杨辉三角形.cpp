#include <iostream>
using namespace std;
typedef  int DataType;
#define MAX 100
typedef struct 
{
	DataType data[MAX];
	int front;
	int rear;
}CirQueue;
int InCirQueue(CirQueue &Q,DataType x)
{
	
	if((Q.rear+1)%MAX==Q.front)
		return false;
	Q.data[Q.rear]=x;
	Q.rear=(Q.rear+1)%MAX;
	return true;
}

int DelCirQueue(CirQueue &Q,DataType &x)
{
	if(Q.rear==Q.front)
		return false;
	x=Q.data[Q.front];
	Q.front=(Q.front+1)%MAX;
	return true;
}
void InitCirQueue(CirQueue &Q)
{
	Q.front=Q.rear=0;
}
void main()
{
	CirQueue Q;
	InitCirQueue(Q);
	int n;
	int s1,s2,s;
	cout<<"请输入要打印的杨辉三角的行数 :";
	cin>>n;
	for(int l=0;l<n-1;l++)
		cout<<" ";
	cout<<1<<endl;
	InCirQueue(Q,1);
	for(int i=2;i<=n;i++)
	{
		
		for(int j=0;j<n-i;j++)
			cout<<" ";
		s1=0;
		for(int k=1;k<=i-1;k++)
		{
			DelCirQueue(Q,s2);
			s=s1+s2;
			cout<<s<<" ";
			InCirQueue(Q,s);
			s1=s2;
		}
		cout<<1;
		InCirQueue(Q,1);
		cout<<endl;
	}
}

