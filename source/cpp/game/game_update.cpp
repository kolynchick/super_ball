#include "game.h"
//������� ��� ��������� �� ���������������� ������� �����
bool game::Update()
{
	if(hge->Input_GetEvent(&ev)) //���� � ������� ��� ������������ �������
	{
		if(ev.type == INPUT_KEYUP && ev.key == HGEK_ESCAPE) return true; //���� ������ ������� Escape, �� ������� �� ����
		if(ev.type == INPUT_KEYUP && ev.key == HGEK_P && select_win == false && select_lose == false)//���� ������ P
		{
			if(select_pause) select_pause = false;
			else select_pause = true;
		}
		if(ev.type == INPUT_MBUTTONDOWN && ev.key == HGEK_RBUTTON && select_pause == false && select_win == false && select_lose == false) //���� ������ ���
		{
			hge->Input_GetMousePos(&rmouse.x, &rmouse.y);//�������� ���������� �����
			for(int i = 0;i < int(position_level.size());i++)//��������� ����
			{
				for(int j = 0;j < int(position_level[i].size());j++)
				{	//���� ���������� ������ � �������������� ������
					if(player.Entry(rmouse.x-(width/2-player.GetPositionX()),rmouse.y-(height/2-player.GetPositionY()),46.f*(j-i),18.f*(j+i)+9,46.f*(j-i)-45,18.f*(j+i)-10,46.f*(j-i),18.f*(j+i)-28,46.f*(j-i)+45,18.f*(j+i)-10))
					{	//���� ��� ��� � �� ��������� ����� � ������
						if(position_level[i][j] == '#' && barrier_fuel == false && position_level[i-1][j] != 'V' && position_level[i][j-1] != 'G')
						{
							position_level[i][j] = '1';//������ ������
							build_level[j+i*position_level[i].size()].Create(hge->Texture_Load("obj/barrier.png"),0,0,100,102,50,92);//������� �������� �������
							barrier_fuel = true;//��� ������, ��� ������ ������ ������� ������
							break;//������
						}
						if(position_level[i][j] == '1')//���� ������
						{
							position_level[i][j] = '#';//������ ���
							build_level[j+i*position_level[i].size()].Create(hge->Texture_Load("obj/cell.png"),0,0,100,62,50,31);//������� �������� ����
							barrier_fuel = false;//������
						}
					}
				}
			}
		}
		if(ev.type == INPUT_MBUTTONDOWN && ev.key == HGEK_LBUTTON && select_pause == false && select_win == false && select_lose == false) //���� ������ ���
		{
			hge->Input_GetMousePos(&mouse.x, &mouse.y); //�������� ���������� �����
			player.Select(position_level,mouse.x-(width/2-player.GetPositionX()),mouse.y-(height/2-player.GetPositionY())); //�������� �� ������ �����, �������� �������� �� ��������� � �������
		}
	}
	if(select_pause != true && select_win != true && select_lose != true)//���� �� ��������� ������� �������
	{
		if(player.Update()){select_win = true; return false;}//��������� �� ������
		if(player.Thorns(position_level)){select_lose = true; return false;}//��������� �� ���������
		for(int i = 0;i < int(enemy_level.size());i++)
			if(enemy_level[i].Update(position_level,player.GetPositionX(),player.GetPositionY())){select_lose = true; return false;}//��������� �� ���������
		for(int i = 0;i < int(bullet_level.size());i++)
			if(bullet_level[i].Update(position_level,player.GetPositionX(),player.GetPositionY())){select_lose = true; return false;}//��������� �� ���������
	}
	return false;//���������� ��������� �������
}