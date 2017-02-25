

//这是封面


#include <stdio.h>
#define print printf("####################################################################\n")
#define prin print;print

void enter();
void exit();
void help();
void make();

void cover()
{
	char a;
	int i;
	prin;
	printf("                  这是一个猜数字的休闲小游戏\n");
	printf("                      （输入字母进入菜单）\n");
	printf("              y 进入游戏\t\tq 退出游戏\n");
	printf("              h 帮助\t\t\tm 制作人员\n");
	printf("请输入：\n");
	for(i=0;;i++)
	{
		scanf("%c",&a);
		switch(a)                               // 检测输入的字符 选择进程        
		{
			case'y':enter();break;
			case'q':exit();break;
			case'h':help();break;
			case'm':make();break;
			default:printf("您的输入有误，请重新输入：");
		}
	}
	prin;
}

void enter()                                    //进入游戏
{

}

void exit()                                     //退出游戏 结束进程
{

}


void help()                                     //显示帮助菜单
{


}

void make()                                     //显示制作名单
{



}
