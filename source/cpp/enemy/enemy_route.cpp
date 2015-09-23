#include "enemy.h"
void enemy::Route(float x1,float y1,float x2,float y2,int str,int s,int f)//Метод для составление маршрута
{	//Заносим начальные и конечные координаты маршрута
	start_x = x1;
	start_y = y1;
	finish_x = x2;
	finish_y = y2;
	line = str;
	start = s;
	finish = f;
}