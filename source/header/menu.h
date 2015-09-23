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
	HGE *hge;//Основная переменная hge
	hgeSprite *cursor;//Спрайт для хранения курсора
	hgeSprite *main;//Спрайт для основной картинки на главном меню
	hgeGUI *gui;//Для хранения объектов меню
	hgeFont *font;//Шрифт
	hgeVector point;//Вектор для взятия координат мыши
	hgeGUIButton *Button;//Для создания кнопок
	vector<string> save;//Вектор для хранения сохранений
	float width;//Ширина окна
	float height;//Высота окна
	static menu* c_menu;//Синглтон
	bool author_visible;//Переменная для проверки окна "автор"
	bool setting_visible;//Переменная для проверки окна "настройки"
	bool game_visible;//Переменная для проверки окна "игра"
	bool select_sound;//Переменная для проверки звука
	bool select_window;//Переменная для проверки режима окна
	HEFFECT Button_sound;//Звуковой эффект
	int select_level;//Выбор уровня
	int select_screen;//Выбор размера окна
	bool select_start;//Проверка для запуска игры
public:
	menu(){ hge = 0; c_menu = this; width = float(GetSystemMetrics(SM_CXSCREEN)); height = float(GetSystemMetrics(SM_CYSCREEN)); select_screen = 0; select_level = 0; select_sound = true;}
	~menu(){}
	void Start(bool);
	bool Update();
	bool Render();
	static bool Call_Update();
	static bool Call_Render();
};