#pragma once
#include <hge.h>
#include <hgesprite.h>
#include <hgefont.h>
#include <hgevector.h>
#include <hgestrings.h>
#include <fstream>
#include <string>
#include "enemy.h"
#include "bullet.h"
#include "hero.h"
#include "build.h"
#include <vector>
#include "menu.h"
using namespace std;
//�������� ����� ��� ����
class game
{
private:
	vector<vector<char>> position_level;//������ ��� �������� �����
	vector<build> build_level;//������ ��� �������� ������������ ���������
	vector<enemy> enemy_level;//������ ��� �������� �����������
	vector<bullet> bullet_level;//������ ��� �������� ����
	hero player;//����� �����
	hgeVector mouse;//��� ���
	hgeVector rmouse;//��� ���
	float width;//������ ����
	float height;//������ ����
	hgeInputEvent ev; //��������� ��� ��������� �������
	hgeSprite *cursor_sprite; //������ ��� �������
	hgeSprite *pause_sprite;//������ ��� �����
	hgeSprite *win_sprite;//������ ��� ������
	hgeSprite *lose_sprite;//������ ��� ���������
	hgeFont	*font; //���������� ��� ������ FPS
	bool barrier_fuel;//������ ����� ������������ ������ 1 ���
	bool select_pause;//�������� ��������� �����
	bool select_win;//�������� ��������� ������
	bool select_lose;//�������� ��������� ���������
	static game *c_game;//��������
public:
	HGE *hge;//�������� ���������� hge
	game(){c_game = this; select_pause = false; select_win = false; select_lose = false; barrier_fuel = false;}//�����������
	~game(){}//����������
	void Create(string,float,float);
	bool Update();
	bool Render();
	static bool Call_Update();
	static bool Call_Render();
};