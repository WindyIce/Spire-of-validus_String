#include<iostream>
#include<string>
#include<iomanip>
#include<conio.h>
#include<Windows.h>
#include"商店.h"
#include"地图.h"

using namespace std;

ceng::ceng(int NUM,int X,int Y)
{
	num = NUM;
	x = X;
	y = Y;
}

void ceng::music()
{
	int c = floor;
	switch (c)
	{
	case 1:
		PlaySound(TEXT("M.Graveyard - you.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	case 2:
		PlaySound(TEXT("DAISHI DANCE - Re...Japanesque.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	case 3:
		PlaySound(TEXT("V.A. - Sorrow.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	}
	return;
}

void ceng::posy()
{
	map[x][y] = -1;
}

void ceng::allSet()
{
	setData();
	posy();
}

void ceng::setMap()
{
	for (int i = 0; i <= 12; ++i)
	{
		for (int j = 0; j <= 12; ++j)
		{
			map[i][j] = firstMap[i][j];
		}
	}
}

int ceng::judgeMove(shop region)
{
	//music();
/*	if (floor = 1)
	{
		PlaySound(TEXT("M.Graveyard - you.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	else if (floor = 2)
	{
		PlaySound(TEXT("DAISHI DANCE - Re...Japanesque.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	else if (floor = 3)
	{
		PlaySound(TEXT("V.A. - Sorrow.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}*/
	display();
	char VV;
	VV = _getch();
	if(VV=='D'||VV=='d')
	{
		if (map[x][y + 1] ==0)
		{
			++y;
			map[x][y] = -1;
			map[x][y-1] = 0;
			judgeMove(region);
		}
		else if (map[x][y + 1] == -2)
			judgeMove(region);
		else if (map[x][y + 1] == -3)
		{
			up();
			judgeMove(region);
		}
		else if (map[x][y + 1] == -4)
		{
			down();
			judgeMove(region);
		}
		/*
		用返回整形的judgemove来判断上楼下楼.
		*/
		else
		{
			++y;
			fightBegin();
			map[x][y] = -1;
			map[x][y-1] = 0;
			judgeMove(region);
		}
	}
	else if (VV == 'A'||VV=='a')
	{
		if (map[x][y - 1] == 0)
		{
			--y;
			map[x][y] = -1;
			map[x][y+1] =0;
			judgeMove(region);
		}
		else if (map[x][y - 1] ==-2)
			judgeMove(region);
		else if (map[x][y - 1] ==-3)
		{
			up();
			judgeMove(region);
		}
		else if (map[x][y - 1] ==-4)
		{
			down();
			judgeMove(region);
		}
		/*
		用返回整形的judgemove来判断上楼下楼.
		*/
		else
		{
			--y;
			fightBegin();
			map[x][y] = -1;
			map[x][y+1] = 0;
			judgeMove(region);
		}
	}
	else if (VV == 'S'||VV=='s')
	{
		if (map[x + 1][y] == 0)
		{
			++x;
			map[x][y] =-1;
			map[x-1][y] =0;
			judgeMove(region);
		}
		else if (map[x + 1][y] == -2)
			judgeMove(region);
		else if (map[x + 1][y] == -3)
		{
			up();
			judgeMove(region);
		}
		else if (map[x + 1][y] == -4)
		{
			down();
			judgeMove(region);
		}
		/*
		用返回整形的judgemove来判断上楼下楼.
		*/
		else
		{
			++x;
			fightBegin();
			map[x][y] = -1;
			map[x-1][y] = 0;
			judgeMove(region);
		}
	}
	else if (VV == 'W'||VV=='w')
	{
		if (map[x - 1][y] == 0)
		{
			--x;
			map[x][y] =-1;
			map[x+1][y] = 0;
			judgeMove(region);
		}
		else if (map[x - 1][y] == -2)
			judgeMove(region);
		else if (map[x - 1][y] == -3)
		{
			up();
			judgeMove(region);
		}
		else if (map[x - 1][y] == -4)
		{
			down();
			judgeMove(region);
		}
		/*
		用返回整形的judgemove来判断上楼下楼.
		*/
		else
		{
			--x;
			fightBegin();
			map[x][y] = -1;
			map[x+1][y] = 0;
			judgeMove(region);
		}
	}
	else if (VV=='P'||VV=='p')
	{
		//PlaySound(TEXT("V.A. - 母港.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		int flag=region.judgeShop(life,attack,defense,money);
		if (flag == 1)
		{
			attack += 2;
			money -= 10;
		}
		else if (flag == 2)
		{
			defense += 2;
			money -= 10;
		}
		else if (flag == 3)
		{
			life += 20;
			money -= 10;
		}
		else
		{
			return 2;
		}
	}
	else if (VV == 'H' || VV == 'h')
	{
		monsterlib();
	}
	else
		judgeMove(region);
}
//上楼会返回1 下楼会返回0 

void ceng::setData()
{
	life = 1000;
	attack = 10;
	defense = 10;
	money = 100;
}

void ceng::getShop(shop Shop)
{
	life = Shop.lifeIn;
	attack = Shop.attackIn;
	defense = Shop.defenseIn;
	money = Shop.moneyIn;

}

void ceng::fightBegin()
{
	PlaySound(TEXT("阿保剛 - Gate of steiner.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("cls");
	cout << "Warning！！！！" << endl;
	int level;
	level = map[x][y];
	Fight(life,attack,defense,level);
	//PlaySound(TEXT("V.A. - Sorrow.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void ceng::Fight(int Life,int Attack,int Defense,int Level)
{
	int blood = Level * 100;
	int counter = 1;
	int att;
	int den;
	int lif;

	att = getmonsterattack(Level);
	den = getmonsterdefense(Level);
	lif = getmonsterlife(Level);
	cout << "你正在和";
	printname(Level);
	cout << "战斗！！！" << endl;
	Sleep(500);
	cout << endl;
	if (Attack <= den&&Defense >= att)
	{
		cout << "好吧，你们都不能击败对方。" << endl;
		cout << "怪物逃走了" << endl;
		Sleep(2000);
		switch (floor)
		{
		case 1:
			PlaySound(TEXT("M.Graveyard - you.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			break;
		case 2:
			PlaySound(TEXT("DAISHI DANCE - Re...Japanesque.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			break;
		case 3:
			PlaySound(TEXT("V.A. - Sorrow.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			break;
		}
		_getch();
		return;

	}
	else if (Attack > den&&Defense >= att)
	{
		cout << "这是你的绝对胜利！！" << endl;
		money += getmonstermoney(Level);
		Sleep(2000);
		switch (floor)
		{
		case 1:
			PlaySound(TEXT("M.Graveyard - you.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			break;
		case 2:
			PlaySound(TEXT("DAISHI DANCE - Re...Japanesque.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			break;
		case 3:
			PlaySound(TEXT("V.A. - Sorrow.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			break;
		}
		_getch();
		return;
	}
	else if (Attack <= den&&Defense < att)
	{
		cout << "你进行了一场必败的战斗." << endl;
		if (money >= 1000)
		{
			money -= 1000;
			cout << "你花费了1000金钱来打败怪物"<<endl;
			Sleep(1000);
			switch (floor)
			{
			case 1:
				PlaySound(TEXT("M.Graveyard - you.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				break;
			case 2:
				PlaySound(TEXT("DAISHI DANCE - Re...Japanesque.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				break;
			case 3:
				PlaySound(TEXT("V.A. - Sorrow.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				break;
			}
			_getch();
			return;
		}
		else
		{
			PlaySound(TEXT("高梨康治 - 宿命.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			cout << "失败" << endl;
			Sleep(10000);
			_getch();
			exit(0);
		}
	}
	else
	{
		life = Life;
		attack = Attack;
		defense = Defense;
		blood = lif;
		while (life > 0 && blood > 0)
		{
			cout << "回合:" << counter << endl;
			Sleep(300);
			life = life - (att - defense);
			blood = blood - (attack - den);
			if (life <= 0)
				life = 0;
			cout << "你的生命:" << life<<"     ";
			if (blood <= 0)
				blood = 0;
			cout << "怪物的生命:" << blood<<endl;
			cout << endl;
			Sleep(500);
			++counter;
		}
		if (life <= 0 && blood <= 0)
		{
			cout << "同归于尽." << endl;
			Sleep(500);
			if (money >= 250)
			{
				money -= 250;
				cout << "用250金钱复活" << endl;
				Sleep(2000);
				switch (floor)
				{
				case 1:
					PlaySound(TEXT("M.Graveyard - you.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
					break;
				case 2:
					PlaySound(TEXT("DAISHI DANCE - Re...Japanesque.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
					break;
				case 3:
					PlaySound(TEXT("V.A. - Sorrow.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
					break;
				}
				_getch();
				return;
			}
			else
			{
				PlaySound(TEXT("高梨康治 - 宿命.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				cout << "失败" << endl;
				Sleep(10000);
				_getch();
				exit(0);
			}
		}
		else if (life <= 0 && blood > 0)
		{
			if (money >= 500)
			{
				money -= 500;
				cout << "用500金钱复活" << endl;
				Sleep(500);
				Fight(Life, attack, defense, blood);
			}
			else
			{
				PlaySound(TEXT("高梨康治 - 宿命.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				cout << "失败" << endl;
				Sleep(10000);
				_getch();
				exit(0);
			}
		}
		else
		{
			cout << "你胜利" << endl;
			money += getmonstermoney(Level);
			Sleep(2000);
			switch (floor)
			{
			case 1:
				PlaySound(TEXT("M.Graveyard - you.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				break;
			case 2:
				PlaySound(TEXT("DAISHI DANCE - Re...Japanesque.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				break;
			case 3:
				PlaySound(TEXT("V.A. - Sorrow.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				break;
			}
			_getch();
			return;
		}
	}
}

void ceng::display()
{
	system("cls");
	cout << endl;
	for (int i = 0; i <= 12; ++i)
	{
		for (int j = 0; j <= 12; ++j)
		{
			if (map[i][j] == 0)
				cout << "   ";
			else if (map[i][j] == -1)
				cout << " * ";
			else if (map[i][j] == -2)
				cout << "###";
			else if (map[i][j] == -3)
				cout << "up!";
			else if (map[i][j] == -4)
				cout << "dow";
			else
				cout << "No" << map[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << "你的生命:" << life << endl;
	cout << "你的攻击:" << attack << endl;
	cout << "你的防御:" << defense << endl;
	cout << "你的金钱:" << money << endl;
	cout << endl;
	cout << "用WASD来控制人物行动" << endl;
	cout << "按P来打开商店" << endl;
	cout << "按H来打开怪物图鉴" << endl;
}

void ceng::monsterlib()
{
	PlaySound(TEXT("Leaf - 静かな冬の夜.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("cls");
	cout << "请输入你想查看的怪物No:" << endl;
	char VVV;
	VVV = getchar();
	switch (VVV)
	{
	case '1':
		cout << "名称：绿球怪" << endl;
		cout << "生命：50" << endl;
		cout << "攻击：20" << endl;
		cout << "防御：1" << endl;
		cout << "可获得金钱：2" << endl;
		break;

	case '2':
		cout << "名称：红球怪" << endl;
		cout << "生命：70" << endl;
		cout << "攻击：15" << endl;
		cout << "防御：2" << endl;
		cout << "可获得金钱：3" << endl;
		break;

	case '3':
		cout << "名称：骷髅怪" << endl;
		cout << "生命：110" << endl;
		cout << "攻击：25" << endl;
		cout << "防御：5" << endl;
		cout << "可获得金钱：6" << endl;
		break;

	case '4':
		cout << "名称：骷髅战士" << endl;
		cout << "生命：250" << endl;
		cout << "攻击：40" << endl;
		cout << "防御：20" << endl;
		cout << "可获得金钱：9" << endl;
		break;

	case '5':
		cout << "名称：黑球怪" << endl;
		cout << "生命：200" << endl;
		cout << "攻击：30" << endl;
		cout << "防御：10" << endl;
		cout << "可获得金钱：6" << endl;
		break;

	case '6':
		cout << "名称：蓝法师" << endl;
		cout << "生命：125" << endl;
		cout << "攻击：50" << endl;
		cout << "防御：25" << endl;
		cout << "可获得金钱：11" << endl;
		break;

	case '7':
		cout << "名称：小蝙蝠" << endl;
		cout << "生命：100" << endl;
		cout << "攻击：20" << endl;
		cout << "防御：5" << endl;
		cout << "可获得金钱：4" << endl;
		break;

	case '8':
		cout << "名称：半兽人" << endl;
		cout << "生命：300" << endl;
		cout << "攻击：75" << endl;
		cout << "防御：45" << endl;
		cout << "可获得金钱：14" << endl;
		break;
	}
	Sleep(2000);
	_getch();
	return;
}

void ceng::getmonsterlib()
{
	int memor[13][13];
	for (int i = 0; i <= 12; ++i)
	{
		for (int j = 0; j <= 12; ++j)
		{
			memor[i][j] = map[i][j];
		}
	}
}

void ceng::setx(int X)
{
	x = X;
}

void ceng::sety(int Y)
{
	y = Y;
}

void ceng::up()
{
	switch (floor)
	{
	case 1:
		for (int i = 0; i <= 12; ++i)
		{
			for (int j = 0; j <= 12; ++j)
			{
				ceng1[i][j] = map[i][j];
			}
		}
		setceng2();
		x = 11;
		y = 2;

		PlaySound(TEXT("DAISHI DANCE - Re...Japanesque.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	case 2:
		for (int i = 0; i <= 12; ++i)
		{
			for (int j = 0; j <= 12; ++j)
			{
				ceng2[i][j] = map[i][j];
			}
		}
		setceng3();
		x = 10;
		y = 11;

		PlaySound(TEXT("V.A. - Sorrow.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	}
	++floor;
}

void ceng::down()
{
	switch (floor)
	{
	case 2:
		for (int i = 0; i <= 12; ++i)
		{
			for (int j = 0; j <= 12; ++j)
			{
				ceng2[i][j] = map[i][j];
			}
		}
		setceng1();
		x = 1;
		y = 2;

		PlaySound(TEXT("M.Graveyard - you.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	case 3:
		for (int i = 0; i <= 12; ++i)
		{
			for (int j = 0; j <= 12; ++j)
			{
				ceng3[i][j] = map[i][j];
			}
		}
		setceng2();
		x = 10;
		y = 11;

		PlaySound(TEXT("DAISHI DANCE - Re...Japanesque.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		break;
	}
	--floor;
}

void ceng::setceng1()
{
	for (int i = 0; i <= 12; ++i)
	{
		for (int j = 0; j <= 12; ++j)
		{
			map[i][j] = ceng1[i][j];
		}
	}
}

void ceng::setceng2()
{
	for (int i = 0; i <= 12; ++i)
	{
		for (int j = 0; j <= 12; ++j)
		{
			map[i][j] = ceng2[i][j];
		}
	}
}

void ceng::setceng3()
{
	for (int i = 0; i <= 12; ++i)
	{
		for (int j = 0; j <= 12; ++j)
		{
			map[i][j] = ceng3[i][j];
		}
	}
}

void ceng::printname(int level)
{
	switch (level)
	{
	case 1:
		cout << "绿球怪";
		cout << endl;
		break;

	case 2:
		cout << "红球怪";
		cout << endl;
		break;
		
	case 3:
		cout << "骷髅怪";
		cout << endl;
		break;

	case 4:
		cout << "骷髅武士";
		cout << endl;
		break;

	case 5:
		cout << "黑球怪";
		cout << endl;
		break;

	case 6:
		cout << "蓝衣法师";
		cout << endl;
		break;

	case 7:
		cout << "小蝙蝠";
		cout << endl;
		break;

	case 8:
		cout << "半兽人";
		cout << endl;
		break;
	}
}

int ceng::getmonsterlife(int level)
{
	switch (level)
	{
	case 1:
		return 50;
		break;

	case 2:
		return 70;
		break;

	case 3:
		return 110;
		break;

	case 4:
		return 250;
		break;

	case 5:
		return 200;
		break;

	case 6:
		return 125;
		break;

	case 7:
		return 100;
		break;

	case 8:
		return 300;
		break;

	}
}

int ceng::getmonsterattack(int level)
{
	switch (level)
	{
	case 1:
		return 20;
		break;

	case 2:
		return 15;
		break;

	case 3:
		return 25;
		break;

	case 4:
		return 40;
		break;

	case 5:
		return 30;
		break;

	case 6:
		return 50;
		break;

	case 7:
		return 20;
		break;

	case 8:
		return 75;
		break;

	}
}

int ceng::getmonsterdefense(int level)
{
	switch (level)
	{
	case 1:
		return 1;
		break;

	case 2:
		return 2;
		break;

	case 3:
		return 5;
		break;

	case 4:
		return 20;
		break;

	case 5:
		return 10;
		break;

	case 6:
		return 25;
		break;

	case 7:
		return 5;
		break;

	case 8:
		return 45;
		break;

	}
}

int ceng::getmonstermoney(int level)
{
	switch (level)
	{
	case 1:
		return 2;
		break;

	case 2:
		return 3;
		break;

	case 3:
		return 6;
		break;

	case 4:
		return 9;
		break;

	case 5:
		return 6;
		break;

	case 6:
		return 11;
		break;

	case 7:
		return 4;
		break;

	case 8:
		return 14;
		break;
	}
}