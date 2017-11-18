#include<iostream>
using namespace std;
#define maxnum 50
typedef struct player
{
	int evenum;
	int schnum;
	int rank;
	int score;
	char name[20];
}P;
int k = 0;
P p1[maxnum];

void input()
{
	int i = 0, j, s, flag = 1, evetype, evenum;
	while(flag)
	{
		cout<<"请输入项目编号和类型符(1、前五/2、前三)：";
		cin>>evenum>>evetype;
		if(evetype == 1)
		{
			s = 1;
			for(j = k; j < k + 5; j++)
			{
				p1[j].evenum = evenum;
				p1[j].rank = s;
				cout<<"请输入运动员姓名：";
				cin>>p1[j].name;
				cout<<"请输入运动员校名：";
				cin>>p1[j].schnum;
				switch(s)
				{
					case 1: p1[j].score = 7;break;
					case 2: p1[j].score = 5;break;
					case 3: p1[j].score = 3;break;
					case 4: p1[j].score = 2;break;
					case 5: p1[j].score = 1;break;
					default: break;
				}
				s++;
			}
			k = j + 1;
		}
		else
		{
			s = 1;
			for(j = k; j < k + 3; j++)
			{
				p1[j].evenum = evenum;
				p1[j].rank = s;
				cout<<"请输入运动员姓名：";
				cin>>p1[j].name;
				cout<<"请输入运动员校名：";
				cin>>p1[j].schnum;
				switch(s)
				{
					case 1: p1[j].score = 5;break;
					case 2: p1[j].score = 3;break;
					case 3: p1[j].score = 2;break;
					default:break;
				}
				s++;
			}
			k = j +1;
		}
		cout<<"是否继续输入(1.是/0.否)？";
		cin>>flag;
		i++;
	}

}


void schdisplay(int n, int m, int w)
{
	int num, i, j, ms, ws, ss;
	cout<<"\n\t\t****************各 学 校 成 绩 表****************\n";
	for(num = 1; num <= n; num++)
	{
		cout<<"\n\t\t##学校"<<num<<"的成绩##\n";
		j = 0;
		ms = 0;
		ws = 0;
		ss = 0;
		for(i = 0; i < k; i++)
		{
			if(p1[i].schnum == num)	
			{
				j++;
				cout<<"\t\t>>第"<<j<<"个运动员的信息："<<endl;
				cout<<"\t\t*项目："<<p1[i].evenum<<endl;
				cout<<"\t\t*排名："<<p1[i].rank<<endl;
				cout<<"\t\t*姓名："<<p1[i].name<<endl;
				cout<<"\t\t*得分："<<p1[i].score<<endl;
				ss += p1[i].score;
				if(p1[i].evenum <= m)
					ms += p1[i].score;
				else
					ws += p1[i].score;
			}
		}
		cout<<"\t\t\t>>学校人数"<<j<<endl;
		cout<<"\t\t\t>>学校团体总分"<<ss<<endl;
		cout<<"\t\t\t>>学校男团分数"<<ms<<endl;
		cout<<"\t\t\t>>学校女团分数"<<ws<<endl;
	}
}

void sumdisplay(int n, int m, int w)
{
	int i, num, ss[4] = {0}, ms[4] = {0}, ws[4] = {0};
	cout<<"\n\t\t****************团 体 总 分 报 表****************\n";
	cout<<"\t\t\t校名\t男团分数    女团分数    团体总分\n";
	for(num = 0; num < n; num++)
	{
		for(i = 0; i < k; i++)
		{
			if(p1[i].schnum == num +1)
			{
				ss[num] += p1[i].score;
				if(p1[i].evenum <= m)
					ms[num] += p1[i].score;
				else
					ws[num] += p1[i].score;
			}
		}
		cout<<"\t\t\t"<<num+1<<"\t  "<<ms[num]<<"\t\t"<<ws[num]<<"\t  "<<ss[num]<<endl;
	}
}

int main()
{
	input();
	schdisplay(4, 2, 1);
	sumdisplay(4, 2, 1);
	return 0;
}



