#include<iostream>
#include<string>
#include<Windows.h>
#include<conio.h>
#include"��ͼ.h"
#include"�̵�.h"

using namespace std;

shop::shop() 
{

}

void shop::shopIn(int Life,int Attack,int Defense,int Money)
{
	judgeShop(Life, Attack, Defense, Money);
}

int shop::judgeShop(int Life,int Attack,int Defense,int Money)
{
	//getDataIn(region);
	lifeIn = Life;
	attackIn = Attack;
	defenseIn = Defense;
	moneyIn = Money;
	displayShop();
	int SS;
	SS = _getch();
	if (SS == 49&&moneyIn>=10)
	{
		attackIn += 2;
		moneyIn -= 10;
		displayShop();
		return 1;
	}
	else if (SS == 50&&moneyIn >= 10)
	{
		defenseIn += 2;
		moneyIn -= 10;
		displayShop();
		return 2;
	}
	else if (SS == 51&&moneyIn >= 10)
	{
		lifeIn += 20;
		moneyIn -= 10;
		displayShop();
		return 3;
	}
	else
		return 0;
}

void shop::displayShop()
{
	system("cls");
	cout << "��ʮ��Ǯ��" << endl;
	cout << "��1������2����" << endl;
	cout << "��2������2����" << endl;
	cout << "��3������20����" << endl;
	cout << endl;
	cout << "�������:"<<lifeIn<<endl;
	cout << "��Ĺ���:" << attackIn << endl;
	cout << "��ķ���:" << defenseIn << endl;
	cout << endl;
	cout << "���������˳��̵�" << endl;
}

void shop::getDataIn(ceng rigion)
{
	lifeIn = rigion.life;
	attackIn = rigion.attack;
	defenseIn = rigion.defense;
	moneyIn = rigion.money;
}