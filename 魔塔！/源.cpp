#include<iostream>
#include<string>
#include<time.h>
#include<windows.h>
#include<conio.h>
#pragma comment(lib,"winmm.lib")
#include<stdio.h>
#include"���.h"
#include"��ͼ.h"
#include"ս��.h"
#include"�ƶ�.h"
#include"�̵�.h"

using namespace std;



int main()
{
	PlaySound(TEXT("��Խ�ޤ��� - ϫ.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	cout << "     ħ��zero" << endl;
	cout << endl;
	cout << "1.��ʼ��Ϸ" << endl;
	cout << "2.����" << endl;
	cout << "3.�˳�" << endl;
	cout << endl;
	cout << "ע������Ӣ�����뷨������Ϸ��" << endl;
	char VV = _getch();
	switch (VV)
	{
	case '1':
		break;
	case'2':
		{
			cout << endl;
			cout << "  ��WASD�����������ж�" << endl;
			cout << "  �����������Ȳ鿴ͼ������������Ϣ��ѡ���Ƿ�ս����" << endl;
			cout << "  ÿ�غ���Һ͹���Ѫ���Ŀ۳����ǵз��Ĺ�������ȥ�����ķ�����." << endl;
			cout << "  " << endl;
			cout << "             ���������ʼ��Ϸ" << endl;
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