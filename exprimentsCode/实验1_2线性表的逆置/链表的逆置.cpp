#include<iostream.h>
#include<stdio.h>
typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node * next;
}Node, *LinkList;

Node *CreatList(void)
{
	int i;
	Node *head, *p, *q;

	head = NULL;
	printf("���������е�Ԫ��(��0Ϊ��ֹ�����־):\n");
	cin>>i;
	while(i != 0)
	{
		p = new Node;
		p->data = i;
		if(head == NULL)
			q = head = p;
		else
		 q->next = p;
		 q = p;
		cin>>i;
	}
	p->next = NULL;
	return head;
}

Node *ReverseList(Node *head)
{
 Node *p, *q, *r;

 p = head;
 q=r=NULL;

 while(p)
 {
  q = p->next;
  p->next = r;
  r = p;
  p = q;
 }
 return r;
}

void PrintList(Node *head)
{
	Node *p;
 
	p = head;
	while(p)
	{
		 cout<<p ->data<<" ";
		 p = p->next;
	}
}

int main()
{
	
	Node *L;
	L = CreatList();
	cout<<"��L��ֵΪ��";
	PrintList(L);
	L = ReverseList(L);
	cout<<"\n���ú�ı�L��ֵΪ��";
	PrintList(L);
	cout<<endl;
	return 0;
}
