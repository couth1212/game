#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define n 19
void gotoxy(int x,int y);
void printweizhi();
   
int q[n][n]={0};                //记录棋盘落子情况 
int player=1;                   //棋手变化变量  下面会使用playerturn函数实现棋手轮换 
struct stu
{
	int x;
	int y;
}weizhi;                        //定义棋盘 

void chess()                    //下棋函数 实现落子操作  q[n][n]保存落子的位置 
{
	player++;
	if(0==player%2)
	{		
		printf("请1号棋手落棋，格式为：行 列\n");      //提示棋手1输入落子位置  并将1棋手的落子在q[weizhi.x][weizhi.y]标记为1 
		scanf("%d%d",&weizhi.x,&weizhi.y);
		getchar();
		q[weizhi.x][weizhi.y]=1;
	}
	else
	{	
		printf("请2号棋手落棋，格式为：行 列\n");      //提示棋手2输入落子位置  并将棋手2的落子在q[weizhi.x][weizhi.y]标记为2 
		scanf("%d%d",&weizhi.x,&weizhi.y);
		getchar();
		q[weizhi.x][weizhi.y]=2;
	}		
}

void printweizhi()              //绘制棋盘
{
	int i,j;
	system("cls");
	for(i=0;i<n;i++)                                   //外层循环判定是在第几行输出 
	{
		for(j=0;j<n;j++)                               //内层循环判是在第几行具体的那个位置 输出 
		{
			if(0==q[weizhi.x][weizhi.y])               //如果q[weizhi.x][weizhi.y]二维数组中存储的数据是0，则输出棋盘图案* 
			{
				printf(" *");
				continue;
			}
			else
			{
				if(1==q[weizhi.x][weizhi.y])           //如果q[weizhi.x][weizhi.y]二维数组中存储的数据是1，则输出棋盘图案o 
				{
					gotoxy(weizhi.x,weizhi.y); 
					printf(" o");
				} 
				else
				{
					gotoxy(weizhi.x,weizhi.y);
					printf(" x");                       //如果q[weizhi.x][weizhi.y]二维数组中存储的数据是2，则输出棋盘图案x 
				}
			}
		}
		printf("\n");
	}
}

/*int playerturn()               //这个函数实现棋手交换下棋 
{
	player++;
	if(0==player%2)
		q[weizhi.x][weizhi.y]=1;
	else
		q[weizhi.x][weizhi.y]=2;	
} */

void gotoxy(int x,int y)                  //定位光标位置
{ 
	COORD c;
	c.X=2*x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void main()
{
	printweizhi();
	while(1)
	{
		chess();
		printweizhi();
	}
}
/*void printweizhi()              //绘制棋盘
{
	int i,j;
	system("cls");
	for(i=0;i<n;i++)                                   //外层循环判定是在第几行输出 
	{
		for(j=0;j<n;j++)                               //内层循环判是在第几行具体的那个位置 输出 
		{
			if(0==q[weizhi.x][weizhi.y])               //如果q[weizhi.x][weizhi.y]二维数组中存储的数据是0，则输出棋盘图案* 
			{
				printf(" *");
				continue;
			}
			else
			{
				if(1==q[weizhi.x][weizhi.y])           //如果q[weizhi.x][weizhi.y]二维数组中存储的数据是1，则输出棋盘图案o 
				{
					gotoxy(weizhi.x,weizhi.y); 
					printf(" o");
				} 
				else
				{
					gotoxy(weizhi.x,weizhi.y);
					printf(" x");                       //如果q[weizhi.x][weizhi.y]二维数组中存储的数据是2，则输出棋盘图案x 
				}
			}
		}
		printf("\n");
	}
}*/