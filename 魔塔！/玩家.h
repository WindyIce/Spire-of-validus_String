#pragma once

class player
{
	friend class map;
public:
	void setData();
	void setPass();
private:
	int life;
	int attack;
	int defense;
	int money;
	int pass[3];
};