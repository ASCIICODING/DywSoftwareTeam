#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

LinkList* Create (LinkList *head)
{
	LinkList* tail, * q;
	int n, i;
	printf("��һ��ʹ�ã�������Ҫ¼�����ϵ������\n");
	scanf("%d", &n);
	head = NULL;
	for (i = 0;i < n;i++)
	{
		printf("�����������%dλ��ϵ�˵��������绰�������Ĺ�ϵ\n", i + 1);
		tail = (LinkList*)malloc(sizeof(LinkList));
		if (tail == NULL)
		{
			printf("�����ڴ�ʧ��");
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
			printf("�����ڴ�ʧ��");
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
	printf ("��������Ҫ��ӵ���ϵ�˵��������绰�������Ĺ�ϵ\n"); 
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
	printf ("������Ҫɾ������ϵ�˵������Ϣ������/���룩\n");
	scanf ("%s",&check);
	q = head;
	t = head->next;
	while (1)
	{
		if ((strcmp(head->data.name,check)==0)||(strcmp(head->data.number,check)==0))//ɾ��ͷλ�õ���ϵ�� 
		{
			printf ("������%s	�绰��%s	��ϵ��%s\n",head->data.name,head->data.number,head->data.relationship);
			printf ("��ȷ������λ��ϵ�ˣ�ȷ��������1,����������0\n");
			scanf ("%d",&flag);
			if (flag)
			{ 
				head = q->next;
				free (q);
				t = head->next;
				printf ("ɾ���ɹ�\n");
				break;
			}
		}
		else if ((strcmp(t->data.name,check)==0)||(strcmp(t->data.number,check)==0))
		{
			printf ("������%s	�绰��%s	��ϵ��%s\n",t->data.name,t->data.number,t->data.relationship);
			printf ("��ȷ������λ��ϵ�ˣ�ȷ��������1,����������0\n");
			scanf ("%d",&flag);
			if (flag)
			{
				q->next = t->next;
				free (t);
				t = q->next;
				printf ("ɾ���ɹ�\n");
				break;
			}
		}
		q = q->next;
		t = q->next;
		if (t==NULL)
		{
			printf ("����ϵ�˲�����\n");
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
	judge: printf ("��������Ҫ�޸ĵ���ϵ�˵�����/�绰\n");
	scanf ("%s",&a);
	t = head;
	while (t)
	{
		if (strcmp(t->data.name,a)==0||strcmp(t->data.number,a)==0)
		{
			printf ("������%s	�绰��%s	��ϵ��%s\n",t->data.name,t->data.number,t->data.relationship);
			printf ("�������λ��ϵ�ˣ�������1ȷ�ϣ�����������0\n");
			break;
		}
		t = t->next;
	}
	if (t==NULL)
	{
		printf ("����ϵ�˲�����\n");
		return head;
	}
	scanf ("%d",&flag);
	if (flag)
	{
		printf ("��Ҫ�޸ĸ���ϵ�˵���Ϣ�ǣ�������������1   �绰������2   ��ϵ������3\n");
		scanf ("%d",&flag);
		switch (flag)
		{
			case 1:
				printf ("���������ϵ���޸ĺ������\n");
				scanf ("%s",&t->data.name);
				return head;
				break; 
			case 2:
				printf ("���������ϵ���޸ĺ�ĵ绰\n");
				scanf ("%s",&t->data.number);
				return head;
				break; 
			case 3:
				printf ("���������ϵ���޸ĺ�Ĺ�ϵ\n");
				scanf ("%s",&t->data.relationship);
				head;
				break; 
		}
	}
	else
	{
		printf ("�Ƿ�����޸Ĳ�����������������1������������0\n");
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
	printf ("��������Ҫ��ѯ����ϵ�˵�����/�绰\n");
	scanf ("%s",&a);
	t = head;
	while (t)
	{
		if (strcmp(t->data.name,a)==0||strcmp(t->data.number,a)==0)
		{
			printf ("������%s	�绰��%s	��ϵ��%s\n",t->data.name,t->data.number,t->data.relationship);
			break;
		}
		t = t->next;
	}
	if (t==NULL)
	{
		printf ("����ϵ�˲�����\n");
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
		printf ("%d.������%s	���룺%s	��ϵ��%s\n",i,t->data.name,t->data.number,t->data.relationship);
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
