#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<string>
#include<conio.h>

#include"故事.h"

using namespace std;

void story::beforegame()
{
	cout << "这是一个发生在魔塔前的小故事--" << endl;
	Sleep(2000);

	cout << "（故事会影响人物的初始数值）" << endl;
	Sleep(5000);
	system("cls");

	cout << "这是一座已经存在了成千上万年的塔," << endl;
	Sleep(2000);

	cout << "关于这座塔的本身，和他里面的东西，没有人知道." << endl;
	Sleep(2000);

	cout << "或许曾经有人进去探索过,但是却没有传出任何消息." << endl;
	Sleep(2000);

	cout << "人人都说，这是一座------" << endl;
	Sleep(2000);

	cout << endl;
	cout << "魔塔" << endl;
	Sleep(5000);
	system("cls");

	cout << "你是一名旅行者." << endl;
	Sleep(2000);

	cout << "你喜欢四处旅行，从山脉，到丛林，到海洋，每一处都遍历了你的足迹。"<<endl;
	Sleep(2000);

	cout << "一天，你跟着一个商队，继续着你的旅途" << endl;
	Sleep(2000);

	cout << "这时途中，突然下起了大雨."<<endl;
	Sleep(2000);

	cout << "商队的人对此早有应对措施，他们准备好了布来防雨." << endl;
	Sleep(2000);

	cout << "可是偏偏这次旅途，你对这一场大雨没有任何准备." << endl;
	Sleep(2000);

	cout << "这种情况下，你打算怎么做呢？" << endl;
	Sleep(2000);
	system("cls");

	cout << "1.向商队的人借白布来防雨." << endl;
	cout << "2.就这么淋着雨继续走" << endl;
	cout << "3.脱离商队，一个人跑向目的地."<<endl;

	char VV = _getch();
	if (VV == '1')
	{
		addattack += 1;
		cout << "商队的人借给了你一块白布，你用它来遮挡住自己的身子不受大雨的侵袭." << endl;
		Sleep(2000);

		cout << "雨点滴答滴答地打在你的身上，一步一步地走着，时间仿佛很快就过去了."<<endl;
		Sleep(2000);

		cout << "很快，就到了你和商队的分岔口，此时雨也停了。作了简短的告别之后，商队继续自己的路程，而你走向一片小树林." << endl;
		Sleep(2000);


	}
	else if (VV == '2')
	{
		adddefense += 1;
		cout << "你就这么淋着雨走着，低着头稍稍弯着腰的背影显得有些寂寥." << endl;
		Sleep(2000);

		cout << "时间就这样一分一秒地流逝过去，好不容易，雨才停了下来。" << endl;
		Sleep(2000);

		cout << "再走了一会，终于到了目标的小树林,你和商队打了个招呼就分别了." << endl;
		Sleep(2000);

		cout << "你进入了树林." << endl;
		Sleep(2000);
		
	}
	else if (VV == '3')
	{
		addmoney += 5;
		cout << "你跑着，很快就脱离了商队，一个人在路上跑" << endl;
		Sleep(2000);

		cout << "很快，你就一个人跑到了一片树林." << endl;
	}
}