#include "hero.h"
bool hero::Thorns(vector<vector<char>> &mas)//Проверка на вхождение в шипы
{
	for(int i = 0;i < int(mas.size());i++)
		for(int j = 0;j < int(mas[i].size());j++)
			if(mas[i][j] == 'T') {if(Entry(position_x,position_y,46.f*(j-i),18.f*(j+i)+9,46.f*(j-i)-45,18.f*(j+i)-10,46.f*(j-i),18.f*(j+i)-28,46.f*(j-i)+45,18.f*(j+i)-10)) return true;}
	return false;
}