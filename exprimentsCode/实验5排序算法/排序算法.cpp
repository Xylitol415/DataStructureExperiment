#include<iostream>
using namespace std;
#include<stdlib.h>
#include<time.h>
#define MaxNum 2000
int num[MaxNum+1];

void output()
{
	int i;
	for(i=0;i<MaxNum;i++)
		if((i+1)%20==0) 
			cout<<num[i]<<endl;
		else 
			cout<<num[i]<<" ";
}

void BubbleSort()
{
	int i,j,t;
	for(i=1;i<MaxNum;i++)
		for(j=0;j<MaxNum-i;j++)
		{
			if(num[j]>num[j+1])
			{
				t=num[j];
				num[j]=num[j+1];
				num[j+1]=t;
			}
		}
}

int main()
{
	srand((unsigned)time(NULL));
	int i;
	double t1,t2;
	for(i=0;i<MaxNum;i++)
		num[i]=rand()%2000;
	cout<<"生成随机数："<<endl;
	output();
	t1=clock();
	cout<<"冒泡排序结果："<<endl;
	BubbleSort();
	output();
	t2=clock();
	cout<<"冒泡排序耗时："<<t2-t1<<endl;
	return 0;
}
