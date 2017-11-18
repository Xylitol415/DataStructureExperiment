#include<iostream>
using namespace std;
#define maxlen 20
typedef struct{
	char ch[maxlen];
	int length;
}SString;

void StrAssign(SString &S, char cs[])
{
	int i;
	for(i = 0; cs[i] != '\0' && i < maxlen; i++)
		S.ch[i] = cs[i];
	S.length = (int)S.ch[0];
}

void StrInput(SString &S)
{
	int i = 0;
	//S.ch[0] = getchar();
	cin>>S.ch[0];
	S.length = (int)S.ch[0] -'0' + 1;
	for(i = 1; i < S.length; i++)
		cin>>S.ch[i];
}

void StrOutput(SString S)
{
	for(int i = 0; i < S.length; i++)
		cout<<S.ch[i];
	cout<<endl;
}

int StrCat(SString &S, SString T)
{
	int i, flag;
	if(S.length + T.length <= maxlen)	//���Ӻ󴮳�С��maxlen�����ض�
	{
		for(i = S.length; i < S.length + T.length; i++)
			S.ch[i] = T.ch[i - S.length + 1];
		S.length += T.length -1;
		flag = 1;
	}
	else if(S.length < maxlen)		//���Ӻ󴮳�����maxlen������S�ĳ���С��maxlen�������Ӻ�T�����ַ���������T���ֽض�
	{
		for(i = S.length; i < maxlen; i++)
			S.ch[i] = T.ch[i - S.length + 1];
		S.length = maxlen;
		flag = 0;
	}
	else
		flag = 0;	//��S�ĳ��ȵ���maxlen����T�������ӣ�Tȫ���ض�
	return flag;
}

int main()
{
	SString s1, s2;
	cout<<"�������ַ���s1:"<<endl;
	StrInput(s1);
	//StrOutput(s);
	cout<<"�������ַ���s2:"<<endl;
	StrInput(s2);
	//StrOutput(s);
    StrCat(s1,s2);
	StrOutput(s1);
	return 0;
}