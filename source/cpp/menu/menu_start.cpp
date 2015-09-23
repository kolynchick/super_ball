#include "menu.h"
menu* menu::c_menu = NULL;//�������� ��������
void menu::Start(bool restart)//���������, � ���� ����������� �������
{
	hge = hgeCreate(HGE_VERSION);//������� ������ ��� HGE
	hge->System_SetState(HGE_LOGFILE, "hge_log.log");//���������,��� ��� ������ ���� ���������, � ����� ��� �����
	hge->System_SetState(HGE_FRAMEFUNC,Call_Update);//��������� �������� ������� ��� ������� �����(���� ��������� �������)
	hge->System_SetState(HGE_RENDERFUNC,Call_Render);//��������� �������� ������� ��� ��������� �������
	hge->System_SetState(HGE_DONTSUSPEND, true);
	hge->System_SetState(HGE_TITLE, "Super Ball");//��������� ��������� ����
	hge->System_SetState(HGE_WINDOWED, select_window);//�������� � ������� �����
	hge->System_SetState(HGE_SCREENWIDTH, int(width));//��������� ������ ����
	hge->System_SetState(HGE_SCREENHEIGHT, int(height));//��������� ������ ����
	hge->System_SetState(HGE_SCREENBPP, 32);//��������� ������� ����� ������
	hge->System_SetState(HGE_FPS, 100);//������ ������� � ������� ����� ���������� ������� �����
	if(hge->System_Initiate()) //���� ������������� ������ �������
	{
		cursor = new hgeSprite(hge->Texture_Load("obj/cursor.png"),0,0,16,22);//������� ������
		main = new hgeSprite(hge->Texture_Load("obj/main.png"),0,0,300,200);//������� ������� �������� � ����
		main->SetHotSpot(150,100);//������������� �����
		gui = new hgeGUI();//������� ��� ��������
		gui->AddCtrl(new hgeGUIButton(1,width/2-150,height*0.4f,300,50,hge->Texture_Load("obj/game.png"),0,0));//��������� ������
		gui->AddCtrl(new hgeGUIButton(2,width/2-150,height*0.55f,300,50,hge->Texture_Load("obj/setting.png"),0,0));
		gui->AddCtrl(new hgeGUIButton(3,width/2-150,height*0.7f,300,50,hge->Texture_Load("obj/author.png"),0,0));
		gui->AddCtrl(new hgeGUIButton(4,width/2-150,height*0.85f,300,50,hge->Texture_Load("obj/exit.png"),0,0));
		gui->AddCtrl(new hgeGUIButton(5,width/2-150,height*0.85f,300,50,hge->Texture_Load("obj/back.png"),0,0));
		gui->AddCtrl(new hgeGUIButton(6,width/2-150,height*0.85f,300,50,hge->Texture_Load("obj/back.png"),0,0));
		gui->AddCtrl(new hgeGUIButton(7,width/2-30,height*0.45f,30,30,hge->Texture_Load("obj/left.png"),0,0));
		gui->AddCtrl(new hgeGUIButton(8,width/2+120,height*0.45f,30,30,hge->Texture_Load("obj/right.png"),0,0));
		Button = new hgeGUIButton(9,width/2-150,height*0.6f,40,30,hge->Texture_Load("obj/check.png"),0,0);//��� �� ������ ������, � �������������
		Button->SetMode(true);//���������, ��� ��� �� ������
		gui->AddCtrl(Button);//������ ��� ��������
		Button = new hgeGUIButton(10,width/2-150,height*0.7f,40,30,hge->Texture_Load("obj/check.png"),0,0);
		Button->SetMode(true);
		if(select_window) Button->SetState(true);
		gui->AddCtrl(Button);
		gui->AddCtrl(new hgeGUIButton(11,width/2-150,height*0.85f,300,50,hge->Texture_Load("obj/back.png"),0,0));//��������� ��������� ������
		gui->AddCtrl(new hgeGUIButton(12,width/2-150,height*0.7f,300,50,hge->Texture_Load("obj/load.png"),0,0));
		gui->AddCtrl(new hgeGUIButton(13,width/2-130,height*0.55f,30,30,hge->Texture_Load("obj/left.png"),0,0));
		gui->AddCtrl(new hgeGUIButton(14,width/2+100,height*0.55f,30,30,hge->Texture_Load("obj/right.png"),0,0));
		Button_sound = hge->Effect_Load("obj/menu.wav");//��������� �������� ������
		font = new hgeFont("font.fnt");//��������� �����
		font->SetColor(DWORD(0xFFE6E6FA));//������������� ����
		if(restart)//���� �������� ����������
		{
			for(int i = 1;i <= 5;i++)//���������� �������� � ����������
			{
			gui->EnableCtrl(i,false);//������������ ������
			gui->ShowCtrl(i,false);//�������� ������
			}
			for(int i = 11;i < 15;i++)
			{
			gui->EnableCtrl(i,false);//������������ ������
			gui->ShowCtrl(i,false);//�������� ������
			}
			}
		else
		{
		save.push_back(hge->Resource_EnumFiles("level/*.sav"));//��������� � ������ ��� ����� ������, ������� ����� ���������� .sav
		for(;;)//��������� ��������, ����� ������� ����� �� �����
		{
		char *filename = hge->Resource_EnumFiles(0);//���������� ����������
		if(filename != 0) save.push_back(filename);//���� �������� ���������, �� �������� � ���������� �������, ������� ���������� ������������� ���������
		else break;//���� ����� ����������� �������
		}
		for(int i = 5;i < 15;i++)//�������� �������
		{
			gui->EnableCtrl(i,false);//������������ ������
			gui->ShowCtrl(i,false);//�������� ������
		}
		}
		hge->System_Start();//��������� ������� 
	}
	else 
	{	//���� �� ����� �� �������� �� �������� ��������� �������, �� �������� ����
		MessageBoxA(NULL, hge->System_GetErrorMessage(), "Error", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);//������� ��������� �� ������
		hge->System_Shutdown();//����������� �������
		hge->Release();//����������� ��������� HGE
	}
	hge->System_Shutdown();//����������� �������
	hge->Release();//����������� ��������� HGE
	ExitProcess(0);
}
bool menu::Call_Update(void) {return c_menu->Update();}
bool menu::Call_Render(void) {return c_menu->Render();}