#include "hero.h"
bool hero::Update()//Метод для обновления передвижения
{
	if (position_x != finish_x && position_y != finish_y && count_route != 0)//Если мы не на конечной позиции
	{
		finish_x = 46.f*(way_x[count_route] - way_y[count_route]);//Запишем координаты до следующей точки
		finish_y = 18.f*(way_x[count_route] + way_y[count_route]);

		position_x += (finish_x - position_x)/dist*speed;//Перемещаем игрока по X
		position_y += (finish_y - position_y)/dist*speed;//Перемещаем игрока по Y
		//Если мы дошли до текущей точки
		if(finish_x - position_x <= speed && position_x - finish_x <= speed && finish_y - position_y <= speed && position_y - finish_y <= speed)
		{		
			count_route++;//Переходим к следующей точки в маршруте
			if(count_route == way_x.size())//Если путь закончился
			{
				position_x = finish_x; position_y = finish_y; //Поставим точно в центр
				count_route = 0;//Обнулим счетчик путей
				way_x.clear();
				way_y.clear();
				return false;
			}	
			finish_x = 46.f*(way_x[count_route] - way_y[count_route]);//Запишем координаты до следующей точки
			finish_y = 18.f*(way_x[count_route] + way_y[count_route]);
			dist = sqrt(pow(finish_x - position_x,2)+pow(finish_y - position_y,2));//Измерим путь

		}//Т.к. игрок не сможет встать именно в нужную точку,необходимо помочь ему
	}
	if(position_x == win_x && position_y == win_y) return true;//Если находимся на победных координат
	return false;
}
