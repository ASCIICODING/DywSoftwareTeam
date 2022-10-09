#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Information
{
	char name[20];
	char number[20];
	char relationship[20];
}DataType;

typedef struct node
{
	DataType data;
	struct node* next;
}LinkList;

LinkList* Create (LinkList *head); //��һ��ʹ��ʱ����ͨѶ¼ 

LinkList* Read (LinkList *head);   //���ļ��ж�ȡ�ϴα����ͨѶ¼ 

LinkList* Insert (LinkList *head );//�����µ���ϵ�˵�ͨѶ¼�� 

LinkList* Delete (LinkList *head); //ɾ��ͨѶ¼�е���ϵ�� 

LinkList* Modify (LinkList *head); //�޸�ͨѶ¼�е���ϵ�� 

void Check (LinkList *head);       //����ͨѶ·�е���ϵ�� 

void Print (LinkList *head);       //��ӡͨѶ¼����ϵ���б� 

void Preserve (LinkList *head);    //����ͨѶ¼
