#include <stdio.h>
#include <windows.h>
int klcf(int date, int month, int year)//基姆拉尔森计算公式
{
    int week;
    week = (date + 1 + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
    return week;
}
void color(short x)//改变字体颜色 
{
    if (x >= 0 && x <= 15)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
}
int main()
{
    int a[6][7],i,j,year,month,date,week,day,total;
    printf("请输入要查询的日期：（格式：年 月 日）\n");
    scanf ("%d %d %d", &year,&month,&date);
    judge:if (month > 12)  //合理性检验 
    {
        printf("一年只有12个月，请重新输入：（格式：年 月 日）\n");
        scanf ("%d %d %d", &year, &month, &date);
        goto judge;
    }
    else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && date > 31)
    {
        printf("%d年%d月只有31天，请重新输入：（格式：年 月 日）\n",year,month);
        scanf ("%d %d %d", &year, &month, &date);
        goto judge;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && date > 30)
    {
        printf("%d年%d月只有30天，请重新输入：（格式：年 月 日）\n", year, month);
        scanf ("%d %d %d", &year, &month, &date);
        goto judge;
    }
    else if ((((year % 100 != 0) && (year % 4 == 0)) || ((year % 100 == 0) && (year % 400 == 0)))&&month==2 && date>29)
    {
        printf("%d年%d月只有29天，请重新输入：（格式：年 月 日）\n",year,month);
        scanf ("%d %d %d", &year, &month, &date);
        goto judge;
    }
    else if ((year%4!=0 ||(year%100==0&&year%400!=0)) && month==2 && date > 28)
    {
        printf("%d年%d月只有28天，请重新输入：（格式：年 月 日）\n", year, month);
        scanf ("%d %d %d", &year, &month, &date);
        goto judge;
    }
    
    printf ("============================\n");
    printf (" 一  二  三  四  五  六  七\n");
    if (month == 2)//判断是否为闰年
    {
        if (((year % 100 != 0) && (year % 4 == 0)) || ((year % 100 == 0) && (year % 400 == 0)))
        {
            total = 29;
        }
        else
        {
            total = 28;
        }
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        total = 31;
    }
    else
    {
        total = 30;
    }
    if (month==2 && date==29)//测试时发现该公式处理二月有错误，需单独处理 
    {
		week = klcf(1, 3, year);
		if (week==0)
		{
			week = 6;
		}
		else if (week==1)
		{
			week = 0;
		}
		else
		{
			week = week-1;
		}
	}
	else if (month==2&&date==28)
	{
		week = klcf(1, 3, year);
	}
	else
	{
		week = klcf(1, month, year);
	}
    day = 1;
	if (week==0)//每月第一天在周日时公式得出0，需单独处理 
	{
		for (j=0;j<6;j++)
		{
			a[0][j] = 0;
		}
		a[0][6] = 1;
		day++;
	}
	else
	{
		for (j = 0;j < week-1;j++)
	    {
			a[0][j] = 0;
	    }
	    for (j = week - 1;j <= 6;j++)
	    {
	        a[0][j] = day;
	        day++;
	    }
	}
    for (i = 1;i < 6;i++)
    {
        for (j = 0;j < 7;j++)
        {
            a[i][j] = day;
            day++;
        }
    }
    for (i = 4;i < 6;i++)
    {
        for (j = 0;j < 7;j++)
        {
            if (a[i][j] > total)
            {
                a[i][j] = 0;
            }
        }
    }
    for (i = 0;i < 6;i++)
    {
        for (j = 0;j < 7;j++)
        {
            if (a[i][j] == date && date < 10)
            {
                color(12);
                printf(" *%d*", a[i][j]);
                continue;
            }
            else if (a[i][j] == date && date >= 10)
            {
                color(12);
                printf("*%d*", a[i][j]);
                continue;
            }
            if (a[i][j] == 0)
            {
                color(7);
                printf("    ");
            }
            else if (a[i][j]<10)
            {
                color(7);
                printf("  %d ", a[i][j]);
            }
            else
            {
                color(7);
                printf(" %d ", a[i][j]);
            }
        }
        printf("\n");
        printf("\n");
    }
    printf("============================\n");
    return 0;
}

