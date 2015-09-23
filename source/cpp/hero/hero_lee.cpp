#include "hero.h"
bool hero::lee(vector<vector<char>> &mas,int ax, int ay, int bx, int by)   //Алгоритм Ли для поиска пути из ячейки (ax, ay) в ячейку (bx, by)
{
	const int WALL   = -1;         //Непроходимая ячейка
	const int BLANK  = -2;         //Свободная непомеченная ячейка
	int len;                       //Длина пути
	vector<vector<int>> grid;
	for(int i = 0; i < int(mas.size());i++)
	{
		grid.resize(grid.size()+1);
		for(int j = 0; j < int(mas[i].size());j++)
		{
			if(mas[i][j] == '#' || mas[i][j] == 'S' || mas[i][j] == 'F' || mas[i][j] == 'T') grid[i].push_back(-2);
			else grid[i].push_back(-1);
		}
	}
	int dx[4] = {1, 0, -1, 0};   //Смещения, соответствующие соседям ячейки
	int dy[4] = {0, 1, 0, -1};   //Справа, снизу, слева и сверху
	int d, x, y, k;
	bool stop;

	if (grid[ay][ax] == WALL || grid[by][bx] == WALL) return false;//Ячейка (ax, ay) или (bx, by) - стена

	//Распространение волны
	d = 0;
	grid[ay][ax] = 0;            //Стартовая ячейка помечена 0
	do 
	{
		stop = true;               //Предполагаем, что все свободные клетки уже помечены
		for ( y = 0; y < int(grid.size()); ++y )
		for ( x = 0; x < int(grid[y].size()); ++x )
			if ( grid[y][x] == d )                         //Ячейка (x, y) помечена числом d
			{
				for ( k = 0; k < 4; ++k )                    //Проходим по всем непомеченным соседям
				{
					int iy=y + dy[k], ix = x + dx[k];
					if ( iy >= 0 && iy < int(grid.size()) && ix >= 0 && ix < int(grid[y].size()) && grid[iy][ix] == BLANK )
					{
					stop = false;              //Найдены непомеченные клетки
					grid[iy][ix] = d + 1;      //Распространяем волну
				}
			}
    }
		d++;
	}while ( !stop && grid[by][bx] == BLANK );

	if (grid[by][bx] == BLANK) return false;  //Путь не найден

	//Восстановление пути
	len = grid[by][bx];            //Длина кратчайшего пути из (ax, ay) в (bx, by)
	x = bx;
	y = by;
	d = len;
	way_x.resize(d+1);
	way_y.resize(d+1);
	while ( d > 0 )
	{
		way_x[d] = x;
		way_y[d] = y;//Записываем ячейку (x, y) в путь
		d--;
		for (k = 0; k < 4; ++k)
		{
			int iy=y + dy[k], ix = x + dx[k];
			if ( iy >= 0 && iy < int(grid.size()) && ix >= 0 && ix < int(grid[0].size()) && grid[iy][ix] == d)
			{
				x = x + dx[k];
				y = y + dy[k];           //Переходим в ячейку, которая на 1 ближе к старту
				break;
		}
	}
	}
	way_x[0] = ax;
	way_y[0] = ay;  
	return true;
}