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

LinkList* Create (LinkList *head); //第一次使用时创建通讯录 

LinkList* Read (LinkList *head);   //从文件中读取上次保存的通讯录 

LinkList* Insert (LinkList *head );//插入新的联系人到通讯录中 

LinkList* Delete (LinkList *head); //删除通讯录中的联系人 

LinkList* Modify (LinkList *head); //修改通讯录中的联系人 

void Check (LinkList *head);       //查找通讯路中的联系人 

void Print (LinkList *head);       //打印通讯录的联系人列表 

void Preserve (LinkList *head);    //保存通讯录
