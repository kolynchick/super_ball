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
//Основной класс для игры
class game
{
private:
	vector<vector<char>> position_level;//Вектор для хранения карты
	vector<build> build_level;//Вектор для хранения строительных элементов
	vector<enemy> enemy_level;//Вектор для хранения противников
	vector<bullet> bullet_level;//Вектор для хранения пуль
	hero player;//Класс героя
	hgeVector mouse;//Для ЛКМ
	hgeVector rmouse;//Для ПКМ
	float width;//Ширина окна
	float height;//Высота окна
	hgeInputEvent ev; //Структура для обработки событий
	hgeSprite *cursor_sprite; //Спрайт для курсора
	hgeSprite *pause_sprite;//Спрайт для паузы
	hgeSprite *win_sprite;//Спрайт для победы
	hgeSprite *lose_sprite;//Спрайт для поражения
	hgeFont	*font; //Переменная для вывода FPS
	bool barrier_fuel;//Барьер можно использовать только 1 раз
	bool select_pause;//Хранение состоянии паузы
	bool select_win;//Хранение состоянии победы
	bool select_lose;//Хранение состоянии поражения
	static game *c_game;//Синглтон
public:
	HGE *hge;//Основная переменная hge
	game(){c_game = this; select_pause = false; select_win = false; select_lose = false; barrier_fuel = false;}//Конструктор
	~game(){}//Деструктор
	void Create(string,float,float);
	bool Update();
	bool Render();
	static bool Call_Update();
	static bool Call_Render();
};