#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"
int main()
{
	LinkList *head;
	int menu;
	printf ("\n");
	printf ("                通讯录                 \n");
	printf ("=======================================\n");
	FILE *fp = fopen("MailList","r");
	if (fp==NULL)
	{
		fclose (fp);
		head = Create (head);
		Preserve (head);
		judge: 
		printf ("\n");
		printf ("请输入对应编号，操作通讯录\n");
		printf ("0.关闭通讯录程序\n");
		printf ("1.添加联系人\n");
		printf ("2.修改联系人信息\n");
		printf ("3.查找联系人\n");
		printf ("4.删除联系人\n");
		scanf ("%d",&menu);
		system ("cls");
		switch (menu)
		{
			case 0:
				return 0;
			case 1:
				head = Insert (head);
				Preserve (head);
				break;
			case 2:
				Print (head);
				head = Modify (head);
				Preserve (head);
				break;
			case 3:
				Check (head);
				break;
			case 4:
				Print (head);
				head = Delete (head);
				Preserve (head);
				break;
		}
		goto judge;
	} 
	else
	{
		head = Read(head);
		jump: 
		Print (head);
		printf ("\n");
		printf ("请输入对应编号，操作通讯录\n");
		printf ("0.关闭通讯录程序\n");
		printf ("1.添加联系人\n");
		printf ("2.修改联系人信息\n");
		printf ("3.查找联系人\n");
		printf ("4.删除联系人\n");
		scanf ("%d",&menu);
		system ("cls");
		switch (menu)
		{
			case 0:
				return 0;
			case 1:
				head = Insert (head);
				Preserve (head);
				break;
			case 2:
				Print (head);
				head = Modify (head);
				Preserve (head);
				break;
			case 3:
				Check (head);
				break;
			case 4:
				Print (head);
				head = Delete (head);
				Preserve (head);
				break;
		}
		goto jump;
	}
	head = Create (head);
	Preserve (head);
	return 0;
}



