#include<iostream.h>
#include<stdio.h>
#define LISTSIZE 100
typedef int DataType;
typedef struct SeqList
{
	DataType data[LISTSIZE];
	int length;
}Seq;

void reverse(Seq &L)
{
	int mid = 0, i, j;
	DataType t;
	if(L.length % 2 == 0)
	{
		mid = L.length/2;
		for(i = 0,j = L.length-1; i < mid, j > mid-1; i++,j--)
		{ t =L.data[i]; L.data[i] = L.data[j]; L.data[j] = t; }
	}
	else
	{
		mid = (L.length - 1)/2;
		for(i = 0,j = L.length-1; i < mid,j > mid; i++,j--)
		{ t =L.data[i]; L.data[i] = L.data[j]; L.data[j] = t; }
	}
}

int main()
{
	int i;
	Seq L;
	cout<<"请输入表L的长度：";
	cin>>L.length;
	cout<<"请输入表L的值：";
	for(i = 0; i < L.length; i++)
		cin>>L.data[i];
	cout<<"表L的值为：";
	for(i = 0; i < L.length; i++)
		cout<<L.data[i]<<" ";
	reverse(L);
	cout<<"\n逆置后的表L的值为：";
	for(i = 0; i < L.length; i++)
		cout<<L.data[i]<<" ";
	cout<<endl;
	return 0;
}
