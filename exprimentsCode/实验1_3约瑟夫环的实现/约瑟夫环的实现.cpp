#include <iostream>
using namespace std;
#define LISTSIZE 100
typedef int DataType;
typedef struct
{
	DataType data[LISTSIZE];
	int length;
}SeqList;

int main()
{
	SeqList L;
	int i, n, m, j, k, s;
		cin>>n>>m;
	L.length = n;
	for(i = 0; i < L.length; i++)
		L.data[i] = i + 1;
	k = 0;
	j = 0;
	for(i = 0; n > 0; i++)
	{
		while(L.data[i] == 0)
			i++;
		if(i == L.length)
			i = 0;
		j++;
		if(j == m)
		{
			j = 0;
			//outnum[k] = L.data[i];
			cout<<L.data[i]<<" ";
			L.data[i] = 0;
			k++;
			n--;
		}
	}
	cout<<endl;
	return 0;
}
