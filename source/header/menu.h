#pragma once
#include <hge.h>
#include <hgesprite.h>
#include <hgeguictrls.h>
#include <hgegui.h>
#include <hgevector.h>
#include <hgefont.h>
#include <hgestrings.h>
#include <vector>
#include "game.h"
using namespace std;
class menu
{
private:
	HGE *hge;//�������� ���������� hge
	hgeSprite *cursor;//������ ��� �������� �������
	hgeSprite *main;//������ ��� �������� �������� �� ������� ����
	hgeGUI *gui;//��� �������� �������� ����
	hgeFont *font;//�����
	hgeVector point;//������ ��� ������ ��������� ����
	hgeGUIButton *Button;//��� �������� ������
	vector<string> save;//������ ��� �������� ����������
	float width;//������ ����
	float height;//������ ����
	static menu* c_menu;//��������
	bool author_visible;//���������� ��� �������� ���� "�����"
	bool setting_visible;//���������� ��� �������� ���� "���������"
	bool game_visible;//���������� ��� �������� ���� "����"
	bool select_sound;//���������� ��� �������� �����
	bool select_window;//���������� ��� �������� ������ ����
	HEFFECT Button_sound;//�������� ������
	int select_level;//����� ������
	int select_screen;//����� ������� ����
	bool select_start;//�������� ��� ������� ����
public:
	menu(){ hge = 0; c_menu = this; width = float(GetSystemMetrics(SM_CXSCREEN)); height = float(GetSystemMetrics(SM_CYSCREEN)); select_screen = 0; select_level = 0; select_sound = true;}
	~menu(){}
	void Start(bool);
	bool Update();
	bool Render();
	static bool Call_Update();
	static bool Call_Render();
};