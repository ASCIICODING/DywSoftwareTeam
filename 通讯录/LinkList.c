#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

LinkList* Create (LinkList *head)
{
	LinkList* tail, * q;
	int n, i;
	printf("第一次使用，请输入要录入的联系人数量\n");
	scanf("%d", &n);
	head = NULL;
	for (i = 0;i < n;i++)
	{
		printf("请依次输入第%d位联系人的姓名、电话、与您的关系\n", i + 1);
		tail = (LinkList*)malloc(sizeof(LinkList));
		if (tail == NULL)
		{
			printf("分配内存失败");
			exit(-1);
		}
		scanf ("%s",&tail->data.name);
		scanf ("%s",&tail->data.number);
		scanf ("%s",&tail->data.relationship);
		tail->next = NULL;
		if (head == NULL)
			head = tail;
		else
			q->next = tail;
		q = tail;
	}
	return head;
}

LinkList* Read (LinkList *head)
{
	LinkList* tail, * q;
	int n, i;
	FILE *fp=fopen("MailList","r");
	fscanf(fp,"%d", &n);
	head = NULL;
	for (i = 0;i < n;i++)
	{
		tail = (LinkList*)malloc(sizeof(LinkList));
		if (tail == NULL)
		{
			printf("分配内存失败");
			exit(-1);
		}
		fscanf (fp,"%s",&tail->data.name);
		fscanf (fp,"%s",&tail->data.number);
		fscanf (fp,"%s",&tail->data.relationship);
		tail->next = NULL;
		if (head == NULL)
			head = tail;
		else
			q->next = tail;
		q = tail;
	}
	fclose (fp);
	return head;
}

LinkList* Insert (LinkList *head )
{
	printf ("请输入您要添加的联系人的姓名、电话、与您的关系\n"); 
	LinkList *p;
	p = (LinkList*)malloc (sizeof (LinkList));
	scanf ("%s",&p->data.name);
	scanf ("%s",&p->data.number);
	scanf ("%s",&p->data.relationship);
	p->next = head;
	head = p;
	return head;
}

LinkList* Delete (LinkList *head)
{
	LinkList *t,*q;
	int flag;
	char check[20];
	printf ("请输入要删除的联系人的相关信息（姓名/号码）\n");
	scanf ("%s",&check);
	q = head;
	t = head->next;
	while (1)
	{
		if ((strcmp(head->data.name,check)==0)||(strcmp(head->data.number,check)==0))//删除头位置的联系人 
		{
			printf ("姓名：%s	电话：%s	关系：%s\n",head->data.name,head->data.number,head->data.relationship);
			printf ("请确认是这位联系人，确认请输入1,不是请输入0\n");
			scanf ("%d",&flag);
			if (flag)
			{ 
				head = q->next;
				free (q);
				t = head->next;
				printf ("删除成功\n");
				break;
			}
		}
		else if ((strcmp(t->data.name,check)==0)||(strcmp(t->data.number,check)==0))
		{
			printf ("姓名：%s	电话：%s	关系：%s\n",t->data.name,t->data.number,t->data.relationship);
			printf ("请确认是这位联系人，确认请输入1,不是请输入0\n");
			scanf ("%d",&flag);
			if (flag)
			{
				q->next = t->next;
				free (t);
				t = q->next;
				printf ("删除成功\n");
				break;
			}
		}
		q = q->next;
		t = q->next;
		if (t==NULL)
		{
			printf ("该联系人不存在\n");
			break;
		}
	}
	return head;
}

LinkList* Modify (LinkList *head)
{
	char a[20];
	int flag;
	LinkList *t;
	judge: printf ("请输入你要修改的联系人的姓名/电话\n");
	scanf ("%s",&a);
	t = head;
	while (t)
	{
		if (strcmp(t->data.name,a)==0||strcmp(t->data.number,a)==0)
		{
			printf ("姓名：%s	电话：%s	关系：%s\n",t->data.name,t->data.number,t->data.relationship);
			printf ("如果是这位联系人，请输入1确认，不是请输入0\n");
			break;
		}
		t = t->next;
	}
	if (t==NULL)
	{
		printf ("该联系人不存在\n");
		return head;
	}
	scanf ("%d",&flag);
	if (flag)
	{
		printf ("您要修改该联系人的信息是：（姓名请输入1   电话请输入2   关系请输入3\n");
		scanf ("%d",&flag);
		switch (flag)
		{
			case 1:
				printf ("请输入该联系人修改后的姓名\n");
				scanf ("%s",&t->data.name);
				return head;
				break; 
			case 2:
				printf ("请输入该联系人修改后的电话\n");
				scanf ("%s",&t->data.number);
				return head;
				break; 
			case 3:
				printf ("请输入该联系人修改后的关系\n");
				scanf ("%s",&t->data.relationship);
				head;
				break; 
		}
	}
	else
	{
		printf ("是否继续修改操作，若继续请输入1，不是请输入0\n");
		scanf ("%d",&flag);
		if (flag)
		{
			goto judge;
		}
		else
			return head;
		
	}
}

void Check (LinkList *head)
{
	char a[20];
	LinkList *t;
	printf ("请输入您要查询的联系人的姓名/电话\n");
	scanf ("%s",&a);
	t = head;
	while (t)
	{
		if (strcmp(t->data.name,a)==0||strcmp(t->data.number,a)==0)
		{
			printf ("姓名：%s	电话：%s	关系：%s\n",t->data.name,t->data.number,t->data.relationship);
			break;
		}
		t = t->next;
	}
	if (t==NULL)
	{
		printf ("该联系人不存在\n");
	}
}

void Print (LinkList *head)
{
	LinkList *t;
	int i = 0;
	t = head;
	while (t)
	{
		i++;
		printf ("%d.姓名：%s	号码：%s	关系：%s\n",i,t->data.name,t->data.number,t->data.relationship);
		t = t->next;
	}
}

void Preserve (LinkList *head)
{
	LinkList *t;
	int i = 0;
	t = head;
	FILE *fp = fopen("MailList","w");
	while (t)
	{
		i++;
		t = t->next;
	}
	fprintf (fp,"%d\n",i);
	t = head;
	while(t)
	{
		fprintf(fp,"%s\n%s\n%s\n",t->data.name,t->data.number,t->data.relationship);
		t = t->next;
	}
	fclose (fp);
}
