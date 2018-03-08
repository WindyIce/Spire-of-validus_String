#pragma once
#include<iostream>
#include<string>

class story
{
	friend class ceng;
	friend class shop;

public:
	void beforegame();
	int addattack=0;
	int adddefense=0;
	int addlife=0;
	int addmoney=0;
};