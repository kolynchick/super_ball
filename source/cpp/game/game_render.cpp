#include "game.h"
bool game::Render()//������� ��� ��������� �������
{
	hge->Gfx_BeginScene();//�������� ����� �������
	hge->Gfx_Clear(0);//������ ����
	hge->Gfx_SetTransform(0,0,width/2-player.GetPositionX(),height/2-player.GetPositionY(),0,1,1);//������� ������

	for(int i = 0;i < int(position_level.size());i++)//���������� ��������� ��������
	{
		for(int j = 0;j < int(position_level[i].size());j++)
		{
			if(position_level[i][j] == '#' || position_level[i][j] == 'S' || position_level[i][j] == 'F' || position_level[i][j] == 'T') build_level[j+i*position_level[i].size()].Render();
			if(player.Entry(player.GetPositionX(),player.GetPositionY(),46.f*(j-i),18.f*(j+i)-10,46.f*(j-i)-45,18.f*(j+i)-10,46.f*(j-i),18.f*(j+i)-28,46.f*(j-i)+45,18.f*(j+i)-10)) player.Render();
			for(int k = 0;k < int(enemy_level.size());k++)
				if(enemy_level[k].Entry(enemy_level[k].GetPositionX(),enemy_level[k].GetPositionY(),46.f*(j-i),18.f*(j+i)-10,46.f*(j-i)-45,18.f*(j+i)-10,46.f*(j-i),18.f*(j+i)-28,46.f*(j-i)+45,18.f*(j+i)-10)) enemy_level[k].Render();
			for(int k = 0;k < int(bullet_level.size());k++)
				if(bullet_level[k].Entry(bullet_level[k].GetPositionX(),bullet_level[k].GetPositionY()+22,46.f*(j-i),18.f*(j+i)-10,46.f*(j-i)-45,18.f*(j+i)-10,46.f*(j-i),18.f*(j+i)-28,46.f*(j-i)+45,18.f*(j+i)-10)) bullet_level[k].Render();

			if(player.Entry(player.GetPositionX(),player.GetPositionY(),46.f*(j-i),18.f*(j+i)+9,46.f*(j-i)-45,18.f*(j+i)-10,46.f*(j-i),18.f*(j+i)-10,46.f*(j-i)+45,18.f*(j+i)-10)) player.Render();
			for(int k = 0;k < int(enemy_level.size());k++)
				if(enemy_level[k].Entry(enemy_level[k].GetPositionX(),enemy_level[k].GetPositionY(),46.f*(j-i),18.f*(j+i)+9,46.f*(j-i)-45,18.f*(j+i)-10,46.f*(j-i),18.f*(j+i)-10,46.f*(j-i)+45,18.f*(j+i)-10)) enemy_level[k].Render();
			for(int k = 0;k < int(bullet_level.size());k++)
				if(bullet_level[k].Entry(bullet_level[k].GetPositionX(),bullet_level[k].GetPositionY()+22,46.f*(j-i),18.f*(j+i)+9,46.f*(j-i)-45,18.f*(j+i)-10,46.f*(j-i),18.f*(j+i)-10,46.f*(j-i)+45,18.f*(j+i)-10)) bullet_level[k].Render();
			
			if(position_level[i][j] == '%' || position_level[i][j] == 'V' || position_level[i][j] == 'G' || position_level[i][j] == '1') build_level[j+i*position_level[i].size()].Render();
		}
	}

	font->printf(player.GetPositionX()-width/2+5,player.GetPositionY()-height/2+5, HGETEXT_LEFT, "FPS: %d", hge->Timer_GetFPS());//������� �� ����� ���������� ������ � �������
	if(select_pause) pause_sprite->Render(player.GetPositionX(),player.GetPositionY());//���� �����, �� ������ ��������
	if(select_win) win_sprite->Render(player.GetPositionX(),player.GetPositionY());//���� ������, �� ������ ��������
	if(select_lose) lose_sprite->Render(player.GetPositionX(),player.GetPositionY());//���� ���������, �� ������ ��������

	hge->Input_GetMousePos(&mouse.x, &mouse.y);//�������� ���������� ����
	cursor_sprite->Render(mouse.x-(width/2-player.GetPositionX()), mouse.y-(height/2-player.GetPositionY())); //������ ������

	hge->Gfx_EndScene();//����������� ����� �������
	return false;
}