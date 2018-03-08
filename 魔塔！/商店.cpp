#include<iostream>
#include<string>
#include<Windows.h>
#include<conio.h>
#include"地图.h"
#include"商店.h"

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
	cout << "用十块钱：" << endl;
	cout << "按1以增加2攻击" << endl;
	cout << "按2以增加2防御" << endl;
	cout << "按3以增加20生命" << endl;
	cout << endl;
	cout << "你的生命:"<<lifeIn<<endl;
	cout << "你的攻击:" << attackIn << endl;
	cout << "你的防御:" << defenseIn << endl;
	cout << endl;
	cout << "按其他键退出商店" << endl;
}

void shop::getDataIn(ceng rigion)
{
	lifeIn = rigion.life;
	attackIn = rigion.attack;
	defenseIn = rigion.defense;
	moneyIn = rigion.money;
}