#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"
int main()
{
	LinkList *head;
	int menu;
	printf ("\n");
	printf ("                ͨѶ¼                 \n");
	printf ("=======================================\n");
	FILE *fp = fopen("MailList","r");
	if (fp==NULL)
	{
		fclose (fp);
		head = Create (head);
		Preserve (head);
		judge: 
		printf ("\n");
		printf ("�������Ӧ��ţ�����ͨѶ¼\n");
		printf ("0.�ر�ͨѶ¼����\n");
		printf ("1.�����ϵ��\n");
		printf ("2.�޸���ϵ����Ϣ\n");
		printf ("3.������ϵ��\n");
		printf ("4.ɾ����ϵ��\n");
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
		printf ("�������Ӧ��ţ�����ͨѶ¼\n");
		printf ("0.�ر�ͨѶ¼����\n");
		printf ("1.�����ϵ��\n");
		printf ("2.�޸���ϵ����Ϣ\n");
		printf ("3.������ϵ��\n");
		printf ("4.ɾ����ϵ��\n");
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



