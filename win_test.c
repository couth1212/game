#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define n 19
void gotoxy(int x,int y);
void printweizhi();
   
int q[n][n]={0};                //��¼����������� 
int player=1;                   //���ֱ仯����  �����ʹ��playerturn����ʵ�������ֻ� 
struct stu
{
	int x;
	int y;
}weizhi;                        //�������� 

void chess()                    //���庯�� ʵ�����Ӳ���  q[n][n]�������ӵ�λ�� 
{
	player++;
	if(0==player%2)
	{		
		printf("��1���������壬��ʽΪ���� ��\n");      //��ʾ����1��������λ��  ����1���ֵ�������q[weizhi.x][weizhi.y]���Ϊ1 
		scanf("%d%d",&weizhi.x,&weizhi.y);
		getchar();
		q[weizhi.x][weizhi.y]=1;
	}
	else
	{	
		printf("��2���������壬��ʽΪ���� ��\n");      //��ʾ����2��������λ��  ��������2��������q[weizhi.x][weizhi.y]���Ϊ2 
		scanf("%d%d",&weizhi.x,&weizhi.y);
		getchar();
		q[weizhi.x][weizhi.y]=2;
	}		
}

void printweizhi()              //��������
{
	int i,j;
	system("cls");
	for(i=0;i<n;i++)                                   //���ѭ���ж����ڵڼ������ 
	{
		for(j=0;j<n;j++)                               //�ڲ�ѭ�������ڵڼ��о�����Ǹ�λ�� ��� 
		{
			if(0==q[weizhi.x][weizhi.y])               //���q[weizhi.x][weizhi.y]��ά�����д洢��������0�����������ͼ��* 
			{
				printf(" *");
				continue;
			}
			else
			{
				if(1==q[weizhi.x][weizhi.y])           //���q[weizhi.x][weizhi.y]��ά�����д洢��������1�����������ͼ��o 
				{
					gotoxy(weizhi.x,weizhi.y); 
					printf(" o");
				} 
				else
				{
					gotoxy(weizhi.x,weizhi.y);
					printf(" x");                       //���q[weizhi.x][weizhi.y]��ά�����д洢��������2�����������ͼ��x 
				}
			}
		}
		printf("\n");
	}
}

/*int playerturn()               //�������ʵ�����ֽ������� 
{
	player++;
	if(0==player%2)
		q[weizhi.x][weizhi.y]=1;
	else
		q[weizhi.x][weizhi.y]=2;	
} */

void gotoxy(int x,int y)                  //��λ���λ��
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
/*void printweizhi()              //��������
{
	int i,j;
	system("cls");
	for(i=0;i<n;i++)                                   //���ѭ���ж����ڵڼ������ 
	{
		for(j=0;j<n;j++)                               //�ڲ�ѭ�������ڵڼ��о�����Ǹ�λ�� ��� 
		{
			if(0==q[weizhi.x][weizhi.y])               //���q[weizhi.x][weizhi.y]��ά�����д洢��������0�����������ͼ��* 
			{
				printf(" *");
				continue;
			}
			else
			{
				if(1==q[weizhi.x][weizhi.y])           //���q[weizhi.x][weizhi.y]��ά�����д洢��������1�����������ͼ��o 
				{
					gotoxy(weizhi.x,weizhi.y); 
					printf(" o");
				} 
				else
				{
					gotoxy(weizhi.x,weizhi.y);
					printf(" x");                       //���q[weizhi.x][weizhi.y]��ά�����д洢��������2�����������ͼ��x 
				}
			}
		}
		printf("\n");
	}
}*/