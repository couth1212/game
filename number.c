

//这是一个猜数字的小游戏

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cover.h"
#define n 10

int num();                            //随机数函数 
void judge(int x);                    //判断函数

int main(int b)
{
	cover();
	num();
	int a;
	a=num();
	judge(a);                                            //将随机函数值传给判断函数
}



int num()                                 
{
	int a;
	srand((unsigned)time(NULL));                         //time()函数获取系统时间作为srand()函数初始化随机数发生器的种子
                                                         //srand()函数作为rand()伪随机数函数的种子
	a=rand()%100;                                        //循环利用rand函数产生在0～100的随机整数
	return a;                                            //返回随机函数值
}


void judge(int x)
{
	int a,i;
	printf("请输入您猜得整数：\n");
	scanf("%d",&a);
	if(a<0||a>100)                                    //判断输入的数有没有越界 当a<0或a>100时报错
	{
		printf("您的输入的数有误，请再次输入\n");
		scanf("%d",&a);
	}
	else
	{
		for(i=0;i<n;i++)
			{
				if(a==x)
				{
						printf("恭喜你猜对了！！！\n");
						break;
				}
				else if(a<x)
				{
						printf("小了，你还有%d次机会，请继续：",n-1-i);
						scanf("%d",&a);
				}
				else
				{
						printf("大了，你还有%d次机会，请继续：",n-i-1);
						scanf("%d",&a);
				}
			}
	}
}
