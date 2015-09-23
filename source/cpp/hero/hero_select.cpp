#include "hero.h"
void hero::Select(vector<vector<char>> &mas ,float mouse_x,float mouse_y)//ћетод дл€ смещени€ на нужную позицию
{
	int st_x = 0,st_y = 0,fin_x = 0,fin_y = 0;//ѕеременные дл€ координат начала и конца пути
	for(int i = 0;i < int(mas.size());i++)
	{
		for(int j = 0;j < int(mas[i].size());j++)
		{
			if(Entry(position_x,position_y,46.f*(j-i),18.f*(j+i)+9,46.f*(j-i)-45,18.f*(j+i)-10,46.f*(j-i),18.f*(j+i)-28,46.f*(j-i)+45,18.f*(j+i)-10)) 
			{st_x = j; st_y = i;}
			if(Entry(mouse_x,mouse_y,46.f*(j-i),18.f*(j+i)+9,46.f*(j-i)-45,18.f*(j+i),46.f*(j-i),18.f*(j+i)-28,46.f*(j-i)+45,18.f*(j+i))) 
			{fin_x = j; fin_y = i;}
		}
	}
	//≈сли клик произошел в другую точку
	if(st_x != fin_x || st_y != fin_y)
	{
		if(lee(mas,st_x,st_y,fin_x,fin_y))//≈сли возможно добратьс€ до точки
		{
			count_route = 1;//“.к. перва€ точка - текущее положение игрока, перейдем к следующей
			finish_x = 46.f*(way_x[count_route] - way_y[count_route]);//«апишем координаты до следующей точки
			finish_y = 18.f*(way_x[count_route] + way_y[count_route]);
			dist = sqrt(pow(finish_x - position_x,2)+pow(finish_y - position_y,2));//»змерим путь
		}
	}
}