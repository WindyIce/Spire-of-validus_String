#include<iostream>
#include<string>
#include<time.h>
#include<windows.h>
#include<conio.h>
#pragma comment(lib,"winmm.lib")
#include<stdio.h>
#include"玩家.h"
#include"地图.h"
#include"战斗.h"
#include"移动.h"
#include"商店.h"

using namespace std;



int main()
{
	PlaySound(TEXT("戸越まごめ - 汐.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	cout << "     魔塔zero" << endl;
	cout << endl;
	cout << "1.开始游戏" << endl;
	cout << "2.帮助" << endl;
	cout << "3.退出" << endl;
	cout << endl;
	cout << "注：请用英文输入法进行游戏！" << endl;
	char VV = _getch();
	switch (VV)
	{
	case '1':
		break;
	case'2':
		{
			cout << endl;
			cout << "  用WASD来控制人物行动" << endl;
			cout << "  遇到怪物，最好先查看图鉴清楚怪物的信息在选择是否战斗！" << endl;
			cout << "  每回合玩家和怪物血量的扣除都是敌方的攻击力减去己方的防御力." << endl;
			cout << "  " << endl;
			cout << "             按任意键开始游戏" << endl;
			_getch();
			break;
		}
	case'3':
		return 0;
	}
	int k;

	player player1;

	shop Shop;

	ceng MAP1(1,11,6);

	MAP1.setceng1();
	MAP1.allSet();
	Shop.getDataIn(MAP1);
	PlaySound(TEXT("M.Graveyard - you.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	while (1)
	{
		//PlaySound(TEXT("M.Graveyard - you.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		k=MAP1.judgeMove(Shop);
	/*	if (k = 1)
		{
			MAP1.setceng2();
			MAP1.setx(11);
			MAP1.sety(2);
			k = MAP1.judgeMove(Shop);
		}*/
	}
	
	
	
	
	
	
	
	
	
	system("pause");
	return 0;
	
}