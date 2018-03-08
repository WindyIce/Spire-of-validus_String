#pragma once


class shop
{
	friend class ceng;
	friend class shopLogic;
public:
	shop();
	void shopIn(int,int,int,int);
	int judgeShop(int,int,int,int);
	void displayShop();
	void getDataIn(ceng);
private:
	int lifeIn;
	int attackIn;
	int defenseIn;
	int moneyIn;
};