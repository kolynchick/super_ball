#include "hgesprite.h"
#include "general.h"
//Класс описывающий синий мяч, т.е. главного героя
class hero: public general
{
private:
	float win_x, win_y;//Переменная для хранения победных координат
	float dist, speed;// Переменная для вычисления длины вектора и скорость передвижения
	vector<int> way_x;
	vector<int> way_y;
	int count_route;//Счетчик пути
public:
	hero()//Конструктор класса, обнуляем переменные
	{
		win_x = 0.f; win_y = 0.f;
		position_x = 0.f; position_y = 0.f;
		finish_x = 0.f; finish_y = 0.f;
		count_route = 0;
		speed = 3.0f;
	}
	virtual ~hero(){}//Деструктор класса, в нем удаляем спрайт
	void SetPosition(float x,float y){position_x = x; position_y = y; finish_x = x; finish_y = y;}//Устанавливаем позицию игрока
	bool Thorns(vector<vector<char>>&);
	void Select(vector<vector<char>>&,float,float);//Метод для смещения на нужную позицию
	void Win (float x,float y){win_x = x; win_y = y;}//Заносим победные координаты
	bool Update();//Метод для обновления передвижения
	bool lee(vector<vector<char>>&,int,int,int,int by);//Алгоритм Ли для поиска пути из ячейки (ax, ay) в ячейку (bx, by)
};