#include<iostream>
#include<string>
#include<iomanip>
#include<conio.h>
#include<Windows.h>
#include"�̵�.h"
#include"��ͼ.h"

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
		�÷������ε�judgemove���ж���¥��¥.
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
		�÷������ε�judgemove���ж���¥��¥.
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
		�÷������ε�judgemove���ж���¥��¥.
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
		�÷������ε�judgemove���ж���¥��¥.
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
		//PlaySound(TEXT("V.A. - ĸ��.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
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
//��¥�᷵��1 ��¥�᷵��0 

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
	PlaySound(TEXT("������ - Gate of steiner.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("cls");
	cout << "Warning��������" << endl;
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
	cout << "�����ں�";
	printname(Level);
	cout << "ս��������" << endl;
	Sleep(500);
	cout << endl;
	if (Attack <= den&&Defense >= att)
	{
		cout << "�ðɣ����Ƕ����ܻ��ܶԷ���" << endl;
		cout << "����������" << endl;
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
		cout << "������ľ���ʤ������" << endl;
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
		cout << "�������һ���ذܵ�ս��." << endl;
		if (money >= 1000)
		{
			money -= 1000;
			cout << "�㻨����1000��Ǯ����ܹ���"<<endl;
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
			PlaySound(TEXT("���濵�� - ����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			cout << "ʧ��" << endl;
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
			cout << "�غ�:" << counter << endl;
			Sleep(300);
			life = life - (att - defense);
			blood = blood - (attack - den);
			if (life <= 0)
				life = 0;
			cout << "�������:" << life<<"     ";
			if (blood <= 0)
				blood = 0;
			cout << "���������:" << blood<<endl;
			cout << endl;
			Sleep(500);
			++counter;
		}
		if (life <= 0 && blood <= 0)
		{
			cout << "ͬ���ھ�." << endl;
			Sleep(500);
			if (money >= 250)
			{
				money -= 250;
				cout << "��250��Ǯ����" << endl;
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
				PlaySound(TEXT("���濵�� - ����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				cout << "ʧ��" << endl;
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
				cout << "��500��Ǯ����" << endl;
				Sleep(500);
				Fight(Life, attack, defense, blood);
			}
			else
			{
				PlaySound(TEXT("���濵�� - ����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				cout << "ʧ��" << endl;
				Sleep(10000);
				_getch();
				exit(0);
			}
		}
		else
		{
			cout << "��ʤ��" << endl;
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
	cout << "�������:" << life << endl;
	cout << "��Ĺ���:" << attack << endl;
	cout << "��ķ���:" << defense << endl;
	cout << "��Ľ�Ǯ:" << money << endl;
	cout << endl;
	cout << "��WASD�����������ж�" << endl;
	cout << "��P�����̵�" << endl;
	cout << "��H���򿪹���ͼ��" << endl;
}

void ceng::monsterlib()
{
	PlaySound(TEXT("Leaf - �����ʶ���ҹ.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("cls");
	cout << "����������鿴�Ĺ���No:" << endl;
	char VVV;
	VVV = getchar();
	switch (VVV)
	{
	case '1':
		cout << "���ƣ������" << endl;
		cout << "������50" << endl;
		cout << "������20" << endl;
		cout << "������1" << endl;
		cout << "�ɻ�ý�Ǯ��2" << endl;
		break;

	case '2':
		cout << "���ƣ������" << endl;
		cout << "������70" << endl;
		cout << "������15" << endl;
		cout << "������2" << endl;
		cout << "�ɻ�ý�Ǯ��3" << endl;
		break;

	case '3':
		cout << "���ƣ����ù�" << endl;
		cout << "������110" << endl;
		cout << "������25" << endl;
		cout << "������5" << endl;
		cout << "�ɻ�ý�Ǯ��6" << endl;
		break;

	case '4':
		cout << "���ƣ�����սʿ" << endl;
		cout << "������250" << endl;
		cout << "������40" << endl;
		cout << "������20" << endl;
		cout << "�ɻ�ý�Ǯ��9" << endl;
		break;

	case '5':
		cout << "���ƣ������" << endl;
		cout << "������200" << endl;
		cout << "������30" << endl;
		cout << "������10" << endl;
		cout << "�ɻ�ý�Ǯ��6" << endl;
		break;

	case '6':
		cout << "���ƣ�����ʦ" << endl;
		cout << "������125" << endl;
		cout << "������50" << endl;
		cout << "������25" << endl;
		cout << "�ɻ�ý�Ǯ��11" << endl;
		break;

	case '7':
		cout << "���ƣ�С����" << endl;
		cout << "������100" << endl;
		cout << "������20" << endl;
		cout << "������5" << endl;
		cout << "�ɻ�ý�Ǯ��4" << endl;
		break;

	case '8':
		cout << "���ƣ�������" << endl;
		cout << "������300" << endl;
		cout << "������75" << endl;
		cout << "������45" << endl;
		cout << "�ɻ�ý�Ǯ��14" << endl;
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
		cout << "�����";
		cout << endl;
		break;

	case 2:
		cout << "�����";
		cout << endl;
		break;
		
	case 3:
		cout << "���ù�";
		cout << endl;
		break;

	case 4:
		cout << "������ʿ";
		cout << endl;
		break;

	case 5:
		cout << "�����";
		cout << endl;
		break;

	case 6:
		cout << "���·�ʦ";
		cout << endl;
		break;

	case 7:
		cout << "С����";
		cout << endl;
		break;

	case 8:
		cout << "������";
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