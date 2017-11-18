#include <iostream>
using namespace std;
#define LISTSIZE 100
typedef int DataType;
typedef struct
{
	DataType data[LISTSIZE];
	int length;
}SeqList;

void input(SeqList &L)
{
	int i;
	for(i = 0; i < L.length; i++)
		cin>>L.data[i];
}

void output(SeqList L)
{
	int i;
	for(i = 0; i < L.length; i++)
	{
		cout<<L.data[i]<<" ";
	}
	cout<<endl;
}

void mergeList(SeqList la, SeqList lb, SeqList &lc)
{
	int i,j,k;
	i = 0; j = 0; k = 0;
	while(i < la.length  && j < lb.length)
	{
		if(la.data[i] <= lb.data[j])
		{
			lc.data[k] = la.data[i];
			i++;
			k++;
		}
		else
		{
			lc.data[k] = lb.data[j];
			j++;
			k++;
		}
	}
	while(i < la.length)
	{
		lc.data[k] = la.data[i];
		i++;
		k++;
	}
	while(j < lb.length)
	{
		lc.data[k] = lb.data[j];
		j++;
		k++;
	}
	lc.length = la.length + lb.length;
}

void main()
{
	SeqList La, Lb, Lc;
	cout<<"请输入La表的长度：";
	cin>>La.length;
	cout<<"请输入La表的值：";
	input(La);
	output(La);
	cout<<"请输入Lb表的长度：";
	cin>>Lb.length;
	cout<<"请输入Lb表的值：";
	input(Lb);
	mergeList(La, Lb, Lc);
	cout<<"合并后的表Lc的值：";
	output(Lc);
}
