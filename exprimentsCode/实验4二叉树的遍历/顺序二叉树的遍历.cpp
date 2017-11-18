#include<iostream>
using namespace std;
#define max_node 100
typedef char ElemType;
typedef ElemType SeqBiTree[max_node];

 void CreatBiTree(SeqBiTree &bt)
 {
	 ElemType ch;
	 int i = 0, flag = 1;
	 cout<<"�밴���˳������������н���ֵ(��^Ϊ������)��\n";
	 while(flag)
	 {
		cin>>ch;
		bt[i++] = ch;
		if(ch == '^')
		{	
			flag = 0;
			break;
		}
	 }	 
 }

void PreOrder(SeqBiTree bt, int i)
{
	if(bt[i] != '#')
	{
		cout<<bt[i]<<" ";
		PreOrder(bt, 2*i+1);
		PreOrder(bt, 2*(i+1));
	}
}

void InOrder(SeqBiTree bt, int i)
{
	if(bt[i] != '#')
	{
		InOrder(bt, 2*i+1);
		cout<<bt[i]<<" ";
		InOrder(bt, 2*(i+1));
	}
}

void PostOrder(SeqBiTree bt, int i)
{
	if(bt[i] != '#')
	{
		PostOrder(bt, 2*i+1);
		PostOrder(bt, 2*(i+1));
		cout<<bt[i]<<" ";
	}
}

void LevelOrder(SeqBiTree bt)
{
	int i =0;
	while(bt[i] != '^')
	{
		if(bt[i]!= '#')
			cout<<bt[i]<<" ";
		i++;
	}
	cout<<endl;
}

int main()
{
	SeqBiTree bt;
	CreatBiTree(bt);
	cout<<"���������������";
	PreOrder(bt, 0);
	cout<<"\n���������������";
	InOrder(bt, 0);
	cout<<"\n���������������";
	PostOrder(bt, 0);
	cout<<"\n��α�����������";
	LevelOrder(bt);
}