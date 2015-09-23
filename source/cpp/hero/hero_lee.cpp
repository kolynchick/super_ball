#include "hero.h"
bool hero::lee(vector<vector<char>> &mas,int ax, int ay, int bx, int by)   //�������� �� ��� ������ ���� �� ������ (ax, ay) � ������ (bx, by)
{
	const int WALL   = -1;         //������������ ������
	const int BLANK  = -2;         //��������� ������������ ������
	int len;                       //����� ����
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
	int dx[4] = {1, 0, -1, 0};   //��������, ��������������� ������� ������
	int dy[4] = {0, 1, 0, -1};   //������, �����, ����� � ������
	int d, x, y, k;
	bool stop;

	if (grid[ay][ax] == WALL || grid[by][bx] == WALL) return false;//������ (ax, ay) ��� (bx, by) - �����

	//��������������� �����
	d = 0;
	grid[ay][ax] = 0;            //��������� ������ �������� 0
	do 
	{
		stop = true;               //������������, ��� ��� ��������� ������ ��� ��������
		for ( y = 0; y < int(grid.size()); ++y )
		for ( x = 0; x < int(grid[y].size()); ++x )
			if ( grid[y][x] == d )                         //������ (x, y) �������� ������ d
			{
				for ( k = 0; k < 4; ++k )                    //�������� �� ���� ������������ �������
				{
					int iy=y + dy[k], ix = x + dx[k];
					if ( iy >= 0 && iy < int(grid.size()) && ix >= 0 && ix < int(grid[y].size()) && grid[iy][ix] == BLANK )
					{
					stop = false;              //������� ������������ ������
					grid[iy][ix] = d + 1;      //�������������� �����
				}
			}
    }
		d++;
	}while ( !stop && grid[by][bx] == BLANK );

	if (grid[by][bx] == BLANK) return false;  //���� �� ������

	//�������������� ����
	len = grid[by][bx];            //����� ����������� ���� �� (ax, ay) � (bx, by)
	x = bx;
	y = by;
	d = len;
	way_x.resize(d+1);
	way_y.resize(d+1);
	while ( d > 0 )
	{
		way_x[d] = x;
		way_y[d] = y;//���������� ������ (x, y) � ����
		d--;
		for (k = 0; k < 4; ++k)
		{
			int iy=y + dy[k], ix = x + dx[k];
			if ( iy >= 0 && iy < int(grid.size()) && ix >= 0 && ix < int(grid[0].size()) && grid[iy][ix] == d)
			{
				x = x + dx[k];
				y = y + dy[k];           //��������� � ������, ������� �� 1 ����� � ������
				break;
		}
	}
	}
	way_x[0] = ax;
	way_y[0] = ay;  
	return true;
}