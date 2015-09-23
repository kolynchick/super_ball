#include "menu.h"
bool menu::Update()//������� ��������� �����
{
	float dt=hge->Timer_GetDelta();//����� ����� ������� ������
	if (hge->Input_GetKeyState(HGEK_ESCAPE)) {return true;} //���� ������ ������� Escape, �� ������� � ����
	int id = gui->Update(dt);//�������� id ������, ���� ��������� �������
	switch(id)//���������� �������
	{
	case 1: //���� ������ ������ "game"
		for(int i = 1;i < 5;i++)//�������� ������� ����
		{
			gui->EnableCtrl(i,false);
			gui->ShowCtrl(i,false);
		}
		for(int i = 11;i < 15;i++)//���������� ������ ����
		{
			gui->EnableCtrl(i,true);
			gui->ShowCtrl(i,true);
		}
		game_visible = true;//���������� � ���,��� �������, ��� ��������� ������
		if(select_sound) hge->Effect_Play(Button_sound);//������������� �������� ������
		break;//�������
	case 2: //���� ������ ������ "setting"
		for(int i = 1;i < 5;i++)//�������� ������� ����
		{
			gui->EnableCtrl(i,false);
			gui->ShowCtrl(i,false);
		}
		for(int i = 5;i <= 10;i++)//���������� ������ ����
		{
			gui->EnableCtrl(i,true);
			gui->ShowCtrl(i,true);
		}
		setting_visible = true;//���������� � ���,��� �������, ��� ��������� ������
		if(select_sound) hge->Effect_Play(Button_sound);//������������� �������� ������
		break;//�������
	case 3://���� ������ ������ "authors"
		for(int i = 1;i < 5;i++)//�������� ������� ����
			gui->ShowCtrl(i,false);
		gui->EnableCtrl(5,true);//���������� ������ ����
		gui->ShowCtrl(5,true);
		author_visible = true;//���������� � ���,��� �������, ��� ��������� ������
		if(select_sound) hge->Effect_Play(Button_sound);//������������� �������� ������
		break;//�������
	case 4://���� ������ ������ "exit"
		if(select_sound) hge->Effect_Play(Button_sound);//������������� �������� ������
		return true;//������� �� ����
	case 5://���� ������ ������ "back" � ���� �������
		for(int i = 1;i < 5;i++)//�������� ������� ����
			gui->ShowCtrl(i,true);
		gui->EnableCtrl(5,false);//���������� ������ ����
		gui->ShowCtrl(5,false);
		author_visible = false;//���������� � ���,��� �������, ��� ��������� ������
		if(select_sound) hge->Effect_Play(Button_sound);//������������� �������� ������
		break;//�������
	case 6://���� ������ ������ "back" � ���� ��������
		for(int i = 1;i < 5;i++)//�������� ������� ����
		{
			gui->EnableCtrl(i,true);
			gui->ShowCtrl(i,true);
		}
		for(int i = 5;i <= 10;i++)//���������� ������ ����
		{
			gui->EnableCtrl(i,false);
			gui->ShowCtrl(i,false);
		}
		setting_visible = false;//���������� � ���,��� �������, ��� ��������� ������
		if(select_sound) hge->Effect_Play(Button_sound);//������������� �������� ������
		break;//�������
	case 7://���� ������ ������ "left" � ���� ��������
		select_screen--;//�������������� 
		switch(select_screen)//�������� ������
		{
		case 0: width = float(GetSystemMetrics(SM_CXSCREEN)); height = float(GetSystemMetrics(SM_CYSCREEN)); break;
		case 1: width = 800; height = 600; break;
		case 2: width = 1024; height = 768; break;
		case 3: width = 1280; height = 720; break;
		case 4:	width = 1280; height = 1024; break;
		default: select_screen = 4; width = 1280; height = 1024; break;
		}
		if(select_sound) hge->Effect_Play(Button_sound);//������������� �������� ������
		hge->System_Shutdown();//����������� �������
		hge->Release();//����������� ��������� HGE
		Start(true);//�������
		break;//�������
	case 8://���� ������ ������ "right" � ���� ��������
		select_screen++;//��������������
		switch(select_screen)//�������� ������
		{
		case 0: width = float(GetSystemMetrics(SM_CXSCREEN)); height = float(GetSystemMetrics(SM_CYSCREEN)); break;
		case 1: width = 800; height = 600; break;
		case 2: width = 1024; height = 768; break;
		case 3: width = 1280; height = 720; break;
		case 4:	width = 1280; height = 1024; break;
		default: select_screen = 0; width = float(GetSystemMetrics(SM_CXSCREEN)); height = float(GetSystemMetrics(SM_CYSCREEN)); break;
		}
		if(select_sound) hge->Effect_Play(Button_sound);//������������� �������� ������
		hge->System_Shutdown();//����������� �������
		hge->Release();//����������� ��������� HGE
		Start(true);//�������
		break;//�������
	case 9://���� ����� ������������� ����� � ���� ��������
		if(select_sound){ hge->Effect_Play(Button_sound); select_sound = false;}//���� ���� �������, �� ���������
		else select_sound = true;//����� ��������
		break;//�������
	case 10://���� ����� ������������� ���� � ���� ��������
		if(select_window) select_window = false;//���� ������� ������������� �����, ��������� � �������
		else select_window = true;//����� � �������������
		if(select_sound) hge->Effect_Play(Button_sound);//������������� �������� ������
		hge->System_SetState(HGE_WINDOWED, select_window);//�������� � ������� �����
		break;//�������
	case 11://���� ������ ������ "back" � ���� ������ ������
		for(int i = 1;i < 5;i++)//�������� ������� ����
		{
			gui->EnableCtrl(i,true);
			gui->ShowCtrl(i,true);
		}
		for(int i = 11;i < 15;i++)//���������� ������ ����
		{
			gui->EnableCtrl(i,false);
			gui->ShowCtrl(i,false);
		}
		game_visible = false;//���������� � ���,��� �������, ��� ��������� ������
		if(select_sound) hge->Effect_Play(Button_sound);//������������� �������� ������
		break;//�������
	case 12:
		select_start = true;//���������� � ��� ��� ��������� � ����
		break;//�������
	case 13:
		select_level--;//��������������
		if(select_level < 0){select_level = save.size()-1;}//���� ������ 0, �� ������� � �����
		break;
	case 14:
		select_level++;//��������������
		if(select_level > int(save.size())-1){select_level = 0;}//���� ����� �� �������, �� ������� �������
		break;
	}
	if(select_start)//���� ���������� ������� � �������� ����
	{
		select_start = false;//����� ������� �� �����
		game start_game;//������� ��������� ������
		start_game.hge = hge;//�������� ���������
		start_game.Create(save[select_level],width,height);//���������, �������� ��� ������, ������ � ������ ������ ��� ������
	}
	return false;//����������� ������� false, ���� true, �� ���������� �����
}