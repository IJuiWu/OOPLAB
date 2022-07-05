#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"
#include <map>
#include <array>
#include <string>
#include <iostream>
#include <random>       
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C���}�Y�e������
	/////////////////////////////////////////////////////////////////////////////
	CGameStateInit::CGameStateInit(CGame* g)
		: CGameState(g)
	{
	}
	int unlock_level;//�{�b�w���ꪺ���d
	CGameMap::CGameMap()//�a�Ϫ�class
		: X(315), Y(195), MW(70), MH(70)
	{
	}
	int CGameMap::GetMap(int x, int y) { //�ήy��������d�a��
		return map[y][x];
	}
	int CGameMap::GetLv() { //����{�b�����d����
		return Level;
	}
	void CGameMap::LoadMap() { //���J�C���a��

		if (Level == 1) { //�Ĥ@��
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					map[i][j] = Level1_Map[i][j];
				}
			}
		}
		else if (Level == 2) {//�ĤG��
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					map[i][j] = Level2_Map[i][j];
				}
			}
		}
		else if (Level == 3) {//�ĤT��
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					map[i][j] = Level3_Map[i][j];
				}
			}
		}
		else if (Level == 4) {//�ĥ|��
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					map[i][j] = Level4_Map[i][j];
				}
			}
		}
		else if (Level == 5) {//�Ĥ���
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					map[i][j] = Level5_Map[i][j];
				}
			}
		}
		else if (Level == 6) {//�Ĥ���
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					map[i][j] = Level6_Map[i][j];
				}
			}
		}
		else if (Level == 7) {//�ĤC��
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					map[i][j] = Level7_Map[i][j];
				}
			}
		}
		else if (Level == 8) {//�ĤK��
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					map[i][j] = Level8_Map[i][j];
				}
			}
		}
	}
	void CGameMap::SetLevel(int level)//�]�w���d����
	{
		Level = level;
	}
	void CGameMap::LoadBitmap() {//���J�a�ϸ귽
		floor1.LoadBitmap(IDB_FLOOR1);
		floor2.LoadBitmap(IDB_FLOOR2);
		water.LoadBitmap(IDB_WATER);
		wall1.LoadBitmap(IDB_WALL1);
		wall2.LoadBitmap(IDB_WALL2);
		wall3.LoadBitmap(IDB_WALL3);
		wall4.LoadBitmap(IDB_WALL4);
		wall5.LoadBitmap(IDB_WALL5);
		wall6.LoadBitmap(IDB_WALL6);
		wall7.LoadBitmap(IDB_WALL7);
		wall8.LoadBitmap(IDB_WALL8);
		wall9.LoadBitmap(IDB_WALL9);
		wall10.LoadBitmap(IDB_WALL10);
		wall11.LoadBitmap(IDB_WALL11);
		wall12.LoadBitmap(IDB_WALL12);
		wall13.LoadBitmap(IDB_WALL13);
		wall14.LoadBitmap(IDB_WALL14);
		corner1.LoadBitmap(IDB_CORNER1);
		corner2.LoadBitmap(IDB_CORNER2);
		corner3.LoadBitmap(IDB_CORNER3);
		corner4.LoadBitmap(IDB_CORNER4);
		black.LoadBitmap(IDB_BLACK);
	}
	void CGameMap::OnShow() { //��a�ϥήy�жK��Ӧ�m�A�@��21�ئa��
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 6; j++) {
				switch (map[j][i]) {
				case 0:
					black.SetTopLeft(X + MW * i, Y + MH * j);
					black.ShowBitmap();
					break;
				case 1:
					floor1.SetTopLeft(X + MW * i, Y + MH * j);
					floor1.ShowBitmap();
					break;
				case 2:
					floor2.SetTopLeft(X + MW * i, Y + MH * j);
					floor2.ShowBitmap();
					break;
				case 3:
					water.SetTopLeft(X + MW * i, Y + MH * j);
					water.ShowBitmap();
					break;
				case 4:
					wall1.SetTopLeft(X + MW * i, Y + MH * j);
					wall1.ShowBitmap();
					break;
				case 5:
					wall2.SetTopLeft(X + MW * i, Y + MH * j);
					wall2.ShowBitmap();
					break;
				case 6:
					wall3.SetTopLeft(X + MW * i, Y + MH * j);
					wall3.ShowBitmap();
					break;
				case 7:
					wall4.SetTopLeft(X + MW * i, Y + MH * j);
					wall4.ShowBitmap();
					break;
				case 8:
					wall5.SetTopLeft(X + MW * i, Y + MH * j);
					wall5.ShowBitmap();
					break;
				case 9:
					wall6.SetTopLeft(X + MW * i, Y + MH * j);
					wall6.ShowBitmap();
					break;
				case 10:
					wall7.SetTopLeft(X + MW * i, Y + MH * j);
					wall7.ShowBitmap();
					break;
				case 11:
					wall8.SetTopLeft(X + MW * i, Y + MH * j);
					wall8.ShowBitmap();
					break;
				case 12:
					wall9.SetTopLeft(X + MW * i, Y + MH * j);
					wall9.ShowBitmap();
					break;
				case 13:
					wall10.SetTopLeft(X + MW * i, Y + MH * j);
					wall10.ShowBitmap();
					break;
				case 14:
					wall11.SetTopLeft(X + MW * i, Y + MH * j);
					wall11.ShowBitmap();
					break;
				case 15:
					wall12.SetTopLeft(X + MW * i, Y + MH * j);
					wall12.ShowBitmap();
					break;
				case 16:
					wall13.SetTopLeft(X + MW * i, Y + MH * j);
					wall13.ShowBitmap();
					break;
				case 17:
					wall14.SetTopLeft(X + MW * i, Y + MH * j);
					wall14.ShowBitmap();
					break;
				case 18:
					corner1.SetTopLeft(X + MW * i, Y + MH * j);
					corner1.ShowBitmap();
					break;
				case 19:
					corner2.SetTopLeft(X + MW * i, Y + MH * j);
					corner2.ShowBitmap();
					break;
				case 20:
					corner3.SetTopLeft(X + MW * i, Y + MH * j);
					corner3.ShowBitmap();
					break;
				case 21:
					corner4.SetTopLeft(X + MW * i, Y + MH * j);
					corner4.ShowBitmap();
					break;
				default:
					ASSERT(1);
				}
			}
		}
	}
	void CGameStateInit::OnInit()
	{
		in_intro = false;
		in_about = false;
		sound = true;
		logo.LoadBitmap(IDB_NEWLOGO); //�K�W�C��logo
		mainmenu.LoadBitmapA(IDB_MAINMENU);//�D�e��
		levels.LoadBitmapA(IDB_LEVELS);//�����d���e��
		l2.LoadBitmapA(IDB_L2);//�L�ĤG����������e��
		l3.LoadBitmapA(IDB_L3);//�L�ĤT����������e��
		l4.LoadBitmapA(IDB_L4);//�L�ĥ|����������e��
		l5.LoadBitmapA(IDB_L5);//�L�Ĥ�����������e��
		l6.LoadBitmapA(IDB_L6);//�L�Ĥ�����������e��
		l7.LoadBitmapA(IDB_L7);//�L�ĤC����������e��
		l8.LoadBitmapA(IDB_L8);//�L�ĤK����������e��
		intro.LoadBitmapA(IDB_INTRO);//�C�����Ъ��e��
		about.LoadBitmap(IDB_ABOUT);//���󪺵e��
		sound_off.LoadBitmapA(IDB_SOUND_OFF);//�����C���n�������s
		sound_off.SetTopLeft(0, -100);//�����C���n���]�w��l��m
		charactor.AddBitmap(IDB_PLAYER_ALIVE_RIGHT_1, RGB(255, 255, 255));//�D�e������ʵe1
		charactor.AddBitmap(IDB_PLAYER_ALIVE_RIGHT_2, RGB(255, 255, 255));//�D�e������ʵe2
		charactor.AddBitmap(IDB_PLAYER_ALIVE_RIGHT_3, RGB(255, 255, 255));//�D�e������ʵe3
		charactor.AddBitmap(IDB_PLAYER_ALIVE_RIGHT_4, RGB(255, 255, 255));//�D�e������ʵe4
		slime.AddBitmap(IDB_SLIME1, RGB(255, 255, 255));//�D�e���Ǫ��ʵe1
		slime.AddBitmap(IDB_SLIME2, RGB(255, 255, 255));//�D�e���Ǫ��ʵe2
		slime.AddBitmap(IDB_SLIME3, RGB(255, 255, 255));//�D�e���Ǫ��ʵe3
		CAudio::Instance()->Load(AUDIO_BGM, "sounds\\bgm.wav");//�I������
		CAudio::Instance()->Play(AUDIO_BGM, true);
	}
	void CGameStateInit::OnBeginState()
	{
	}
	void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_ESC = 27;						// ������GAME_STATE_RUN
		if (nChar == KEY_ESC)								// Demo �����C������k
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// �����C��
	}
	void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
	{
		if (!in_levels && !in_intro) {//�P�_�Ҧb���e��
			if (point.x >= 500 && point.x <= 700 && point.y >= 195 && point.y <= 285 && !in_about && !in_intro) { //�P�_�I����m�Y�O�}�l
				GotoGameState(GAME_STATE_RUN);
			}
			else if (point.x >= 500 && point.x <= 700 && point.y >= 360 && point.y <= 450 && !in_about && !in_intro) { //�P�_�I����m�Y�O����
				ax = 0;
				in_about = true;
			}
			else if (point.x >= 500 && point.x <= 700 && point.y >= 525 && point.y <= 615 && !in_about && !in_intro) { //�P�_�I����m�Y�O����
				ix = 0;
				in_intro = true;
			}
		}
		else if (in_intro && point.x >= 495 && point.x <= 705 && point.y >= 626 && point.y <= 734) { //�P�_�Y�O�b���󪺵e���B�I����m�O�^��D�e��
			ix = 1500;
			in_intro = false;
		}
	}
	void CGameStateInit::OnLButtonUp(UINT nFlags, CPoint point)
	{
		if (in_about && point.x >= 495 && point.x <= 705 && point.y >= 626 && point.y <= 734) {//�P�_�Y�O�b���Ъ��e���B�I����m�O�^��D�e��
			ax = 1198;
			in_about = false;
		}
		else if (point.x >= 1103 && point.x <= 1183 && point.y >= 13 && point.y <= 93) {//�P�_�Y�O�I���ֶ}��
			if (sound) {//�}�ҭ���
				CAudio::Instance()->Stop(AUDIO_BGM);
				sound = false;
				sound_off.SetTopLeft(1103, 13);
			}
			else if (!sound) {//��������
				CAudio::Instance()->Play(AUDIO_BGM, true);
				sound = true;
				sound_off.SetTopLeft(0, -100);
			}
		}
	}
	void CGameStateInit::OnShow()
	{
		mainmenu.SetTopLeft(0, 0);//�D�e����m�]�w
		mainmenu.ShowBitmap();//��ܥD�e��
		if (!sound) {
			sound_off.SetTopLeft(1103, 13);
		}
		sound_off.ShowBitmap();//��ܭ��֫��s
		charactor.SetTopLeft(200, 400);//�D�e�������m
		charactor.OnMove();//�D�e������ʵe
		charactor.OnShow();
		slime.SetTopLeft(800, 400);//�D�e���Ǫ���m
		slime.OnMove();//�D�e���Ǫ��ʵe
		slime.OnShow();
		if (unlock_level == 1)//�P�_�q�������d�Ƭ���A�ç���������d���K�W�h
		{
			levels.SetTopLeft(lx, 0);
			levels.ShowBitmap();
		}
		else if (unlock_level == 2) {
			l2.SetTopLeft(lx, 0);
			l2.ShowBitmap();
		}
		else if (unlock_level == 3) {

			l3.SetTopLeft(lx, 0);
			l3.ShowBitmap();
		}
		else if (unlock_level == 4) {
			l4.SetTopLeft(lx, 0);
			l4.ShowBitmap();
		}
		else if (unlock_level == 5) {
			l5.SetTopLeft(lx, 0);
			l5.ShowBitmap();
		}
		else if (unlock_level == 6) {
			l6.SetTopLeft(lx, 0);
			l6.ShowBitmap();
		}
		else if (unlock_level == 7) {
			l7.SetTopLeft(lx, 0);
			l7.ShowBitmap();
		}
		else if (unlock_level == 8) {
			l8.SetTopLeft(lx, 0);
			l8.ShowBitmap();
		}
		intro.SetTopLeft(ix, 0);
		intro.ShowBitmap();
		about.SetTopLeft(ax, 0);
		about.ShowBitmap();
	}
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A(Game Over)
	/////////////////////////////////////////////////////////////////////////////
	CGameStateOver::CGameStateOver(CGame* g)
		: CGameState(g)
	{
	}
	void CGameStateOver::OnMove()
	{
		counter--;
		if (counter < 0)
			GotoGameState(GAME_STATE_INIT);
	}
	void CGameStateOver::OnBeginState()
	{
		counter = 30 * 2; // 5 seconds
	}
	void CGameStateOver::OnInit()
	{
		unlock_level = 1;
		ending.LoadBitmap(IDB_ENDING);//���J�q���e��
		ending.SetTopLeft(0, 0);//�]�w�q���e����m
	}
	void CGameStateOver::OnShow()
	{
		ending.ShowBitmap();//��ܳq���e��
	}
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
	/////////////////////////////////////////////////////////////////////////////
	CGameStateRun::CGameStateRun(CGame* g)
		: CGameState(g)
	{
		pipe = new Pipe[Pipenum];
		torch = new Torch[Torchnum];
		box = new Box[Boxesnum[gamemap.GetLv() - 1]];//init
		water = new Water[Waternum[gamemap.GetLv() - 1]];
		slime = new Slime[Slimenum[gamemap.GetLv() - 1]];
		trap = new Trap[Trapnum[gamemap.GetLv() - 1]];
		button = new Button[Buttonnum[gamemap.GetLv() - 1]];
		door = new Door[Doornum[gamemap.GetLv() - 1]];
		key = new Key[Doornum[gamemap.GetLv() - 1]];
		potion = new Potion[Potionnum[gamemap.GetLv() - 1]];

	}
	CGameStateRun::~CGameStateRun()
	{
		delete[] box; //����memory leak�R���Χ����귽
		delete[] water;
		delete[] slime;
		delete[] trap;
		delete[] button;
		delete[] potion;
		delete[] door;
		delete[] key;
		delete[] torch;
		delete[] pipe;
	}
	void CGameStateRun::OnBeginState()
	{
		sound_off.SetTopLeft(0, -100);//�վ㭵�ֶ}�������s��m
		sound_on.SetTopLeft(1103, 13);//�վ㭵�ֶ}�������s��m
		logo.SetTopLeft(25, 25);//�]�w�C��logo��m
		banner.SetTopLeft(385, 0);//�]�w�W�����m
		fail_logo.SetTopLeft(-1198, 0);//�]�w���Ѵ��ܦ�m
		pass_logo.SetTopLeft(-1198, 0);//�]�w�q�L���ܦ�m
	}
	void CGameStateRun::OnMove()							// ���ʹC������
	{
		
		for (int i = 0; i < Torchnum; i++)
			torch[i].OnMove();
		for (int i = 0; i < Pipenum; i++)
			pipe[i].OnMove();
		for (int i = 0; i < Boxesnum[gamemap.GetLv() - 1]; i++)
			box[i].OnMove();
		for (int i = 0; i < Waternum[gamemap.GetLv() - 1]; i++)
			water[i].OnMove();

		for (int i = 0; i < Slimenum[gamemap.GetLv() - 1]; i++)
			slime[i].OnMove();
		coin.OnMove();

		for (int i = 0; i < Doornum[gamemap.GetLv() - 1]; i++) {
			key[i].OnMove();
			door[i].OnMove();
		}
		for (int i = 0; i < Potionnum[gamemap.GetLv() - 1]; i++) {
			potion[i].OnMove();
		}
		potion_num.ShowBitmap();
		key_num.ShowBitmap();
		player.OnMove();
		fail_logo.ShowBitmap();
		pass_logo.ShowBitmap();
	}
	void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
	{
		potion_num.LoadBitmap(nums[potion_get]); //���J�Ĥ��ƶq
		key_num.LoadBitmap(nums[key_get]); //���J�_�ͼƶq
		potion_num.SetTopLeft(930, 55);//�]�w�ƶq��m
		key_num.SetTopLeft(930, 5);//�]�w�ƶq��m
		int h[8] = { IDB_HINT1, IDB_HINT2, IDB_HINT3, IDB_HINT4, IDB_HINT5, IDB_HINT6, IDB_HINT7, IDB_HINT8};//���J����
		for (int i = 0; i < 8; i++) {
			hint[i].LoadBitmap(h[i]);
			hint[i].SetTopLeft(0, 100);
		}
		for (int i = 0; i < Torchnum; i++)
			torch[i].LoadBitmap();
		for (int i = 0; i < Pipenum; i++)
			pipe[i].LoadBitmap();
		for (int i = 0; i < Boxesnum[gamemap.GetLv() - 1]; i++)//���J�c�l
			box[i].LoadBitmap();
		for (int i = 0; i < Waternum[gamemap.GetLv() - 1]; i++)//���J���|
			water[i].LoadBitmap();
		for (int i = 0; i < Slimenum[gamemap.GetLv() - 1]; i++)//���J�Ǫ�
			slime[i].LoadBitmap();
		for (int i = 0; i < Trapnum[gamemap.GetLv() - 1]; i++)//���J����
			trap[i].LoadBitmap();
		for (int i = 0; i < Buttonnum[gamemap.GetLv() - 1]; i++)//���J���s
			button[i].LoadBitmap();
		for (int i = 0; i < Potionnum[gamemap.GetLv() - 1]; i++)//���J�Ĥ�
			potion[i].LoadBitmap();
		sound_off.LoadBitmapA(IDB_SOUND_OFF);//���J������ 
		sound_on.LoadBitmapA(IDB_SOUND_ON);//���J���ֶ}
		logo.LoadBitmapA(IDB_NEWLOGO);//���J�C��logo
		banner.LoadBitmapA(IDB_BANNER);//���J�W�����
		gamemap.LoadBitmap();//���J�C���a��
		gamemap.LoadMap();
		player.Restart(1);//���a��l��
		player.LoadBitmap();//���a�ʵe���J
		coin.Restart(1);//������l��
		coin.LoadBitmap();//�������J
		fail_logo.LoadBitmap(IDB_FAIL);//���Ѵ��ܸ��J
		pass_logo.LoadBitmap(IDB_PASS);//�q�����ܸ��J
		//�����d�e�����J
		levels.LoadBitmap(IDB_LEVELS);
		l2.LoadBitmapA(IDB_L2);
		l3.LoadBitmapA(IDB_L3);
		l4.LoadBitmapA(IDB_L4);
		l5.LoadBitmapA(IDB_L5);
		l6.LoadBitmapA(IDB_L6);
		l7.LoadBitmapA(IDB_L7);
		l8.LoadBitmapA(IDB_L8);
		//���J����
		CAudio::Instance()->Load(AUDIO_DING, "sounds\\ding.wav");
		CAudio::Instance()->Load(AUDIO_WATER, "sounds\\water.mp3");
		CAudio::Instance()->Load(AUDIO_BOX, "sounds\\box_move.mp3");
		CAudio::Instance()->Load(AUDIO_EAT, "sounds\\eat.mp3");
		CAudio::Instance()->Load(AUDIO_COIN, "sounds\\coin.mp3");
		CAudio::Instance()->Load(AUDIO_PASS, "sounds\\pass.mp3");
		CAudio::Instance()->Load(AUDIO_FAIL, "sounds\\fail.mp3");
		CAudio::Instance()->Load(AUDIO_TRAP_OPEN, "sounds\\trap_open.mp3");
		CAudio::Instance()->Load(AUDIO_TRAP_CLOSE, "sounds\\trap_close.mp3");
		CAudio::Instance()->Load(AUDIO_DOOR, "sounds\\door.mp3");
		CAudio::Instance()->Load(AUDIO_THROW, "sounds\\throw.mp3");
		in_levels = false;
		Reset(1);
	}
	void CGameStateRun::Reset(int level) { //���d���m
		//�R���귽
		delete[] box;
		delete[] water;
		delete[] slime;
		delete[] trap;
		delete[] pipe;
		delete[] torch;
		delete[] button;
		delete[] potion;
		//�Ѽƪ�l��
		key_get = 0;
		Torchnum = rand() % 5;
		Pipenum = rand() % 5;
		key_num = CMovingBitmap();
		key_num.LoadBitmap(nums[key_get]);
		key_num.SetTopLeft(930, 5);
		potion_get = 0;
		potion_num = CMovingBitmap();
		potion_num.LoadBitmap(nums[potion_get]);
		potion_num.SetTopLeft(930, 55);
		gamemap.SetLevel(level);
		gamemap.LoadMap();
		player.Restart(level);
		coin.Restart(level);
		box = new Box[Boxesnum[level - 1]];
		water = new Water[Waternum[level - 1]];
		slime = new Slime[Slimenum[level - 1]];
		trap = new Trap[Trapnum[level - 1]];
		button = new Button[Buttonnum[level - 1]];
		door = new Door[Doornum[level - 1]];
		key = new Key[Doornum[level - 1]];
		potion = new Potion[Potionnum[level - 1]];
		pipe = new Pipe[Pipenum];
		torch = new Torch[Torchnum];
		//�̷����d���ų]�w���P��m
		std::vector<position> clear;
		array<int,6> wall = { 7,8,9,10,11,14 };
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 6; j++) {
				if (find(std::begin(wall), std::end(wall),gamemap.GetMap(i, j)) != std::end(wall)) {
					clear.push_back({ i,j });
				}
			}
		}
		random_shuffle(clear.begin(), clear.end());
		
		
		for (int i = 0; i < Torchnum; i++) {
			torch[i].LoadBitmap();
			TRACE("error:(%d,%d)", clear[clear.size() - 1].x, clear[clear.size() - 1].y);
			torch[i].SetPos(clear[clear.size()-1].x, clear[clear.size() - 1].y);
			clear.pop_back();
		}
			
		for (int i = 0; i < Pipenum; i++) {
			pipe[i].LoadBitmap();
			pipe[i].SetPos(clear[clear.size() - 1].x, clear[clear.size() - 1].y);
			clear.pop_back();
		}
			
				
		if (level == 1) {
		}
		else if (level == 2) {
			for (int i = 0; i < Boxesnum[level - 1]; i++) {
				box[i].LoadBitmap();
				box[i].SetPos(LV2BoxPos[i][0], LV2BoxPos[i][1]);
				box[i].SetIsAlive(true);
			}
			for (int i = 0; i < Waternum[level - 1]; i++) {
				water[i].LoadBitmap();
				water[i].SetPos(LV2WaterPos[i][0], LV2WaterPos[i][1]);
				water[i].SetIsAlive(true);
			}
		}
		else if (level == 3) {
			for (int i = 0; i < Boxesnum[level - 1]; i++) {
				box[i].LoadBitmap();
				box[i].SetPos(LV3BoxPos[i][0], LV3BoxPos[i][1]);
				box[i].SetIsAlive(true);
			}
			for (int i = 0; i < Waternum[level - 1]; i++) {
				water[i].LoadBitmap();
				water[i].SetPos(LV3WaterPos[i][0], LV3WaterPos[i][1]);
				water[i].SetIsAlive(true);
			}
			for (int i = 0; i < Slimenum[level - 1]; i++) {
				slime[i].LoadBitmap();
				slime[i].SetPos(LV3SlimePos[i][0], LV3SlimePos[i][1]);
				slime[i].SetIsAlive(true);
			}
		}
		else if (level == 4) {
			for (int i = 0; i < Boxesnum[level - 1]; i++) {
				box[i].LoadBitmap();
				box[i].SetPos(LV4BoxPos[i][0], LV4BoxPos[i][1]);
				box[i].SetIsAlive(true);
			}
			for (int i = 0; i < Trapnum[gamemap.GetLv() - 1]; i++) {
				trap[i].LoadBitmap();
				trap[i].Restart(4);
			}

			for (int i = 0; i < Buttonnum[gamemap.GetLv() - 1]; i++) {
				button[i].LoadBitmap();
				button[i].Restart(4);
				button[i].Link(&trap[i]);
			}
			for (int i = 0; i < Slimenum[level - 1]; i++) {
				slime[i].LoadBitmap();
				slime[i].SetPos(LV4SlimePos[i][0], LV4SlimePos[i][1]);
				slime[i].SetIsAlive(true);
			}
		}
		else if (level == 5) {
			for (int i = 0; i < Boxesnum[level - 1]; i++) {
				box[i].LoadBitmap();
				box[i].SetPos(LV5BoxPos[i][0], LV5BoxPos[i][1]);
				box[i].SetIsAlive(true);
			}
			for (int i = 0; i < Trapnum[gamemap.GetLv() - 1]; i++) {
				trap[i].LoadBitmap();
				trap[i].Restart(5);
			}
			for (int i = 0; i < Buttonnum[gamemap.GetLv() - 1]; i++) {
				button[i].LoadBitmap();
				button[i].Restart(5);
				button[i].Link(&trap[i]);
			}
			for (int i = 0; i < Slimenum[level - 1]; i++) {
				slime[i].LoadBitmap();
				slime[i].SetPos(LV5SlimePos[i][0], LV5SlimePos[i][1]);
				slime[i].SetIsAlive(true);
			}
			for (int i = 0; i < Doornum[level - 1]; i++) {
				door[i].LoadBitmap();
				key[i].LoadBitmap();
				key[i].Link(&door[i]);
				door[i].SetPos(LV5DoorPos[i][0], LV5DoorPos[i][1]);
				key[i].SetPos(LV5KeyPos[i][0], LV5KeyPos[i][1]);
			}
		}
		else if (level == 6) {
			for (int i = 0; i < Waternum[level - 1]; i++) {
				water[i].LoadBitmap();
				water[i].SetPos(LV6WaterPos[i][0], LV6WaterPos[i][1]);
				water[i].SetIsAlive(true);
			}
			for (int i = 0; i < Boxesnum[level - 1]; i++) {
				box[i].LoadBitmap();
				box[i].SetPos(LV6BoxPos[i][0], LV6BoxPos[i][1]);
				box[i].SetIsAlive(true);
			}
			for (int i = 0; i < Trapnum[gamemap.GetLv() - 1]; i++) {
				trap[i].LoadBitmap();
				trap[i].Restart(6);
			}
			for (int i = 0; i < Buttonnum[gamemap.GetLv() - 1]; i++) {
				button[i].LoadBitmap();
				button[i].Restart(6);
				button[i].Link(&trap[i]);
			}
			for (int i = 0; i < Slimenum[level - 1]; i++) {
				slime[i].LoadBitmap();
				slime[i].SetPos(LV6SlimePos[i][0], LV6SlimePos[i][1]);
				slime[i].SetIsAlive(true);
			}
			for (int i = 0; i < Doornum[level - 1]; i++) {
				door[i].LoadBitmap();
				key[i].LoadBitmap();
				key[i].Link(&door[i]);
				door[i].SetPos(LV6DoorPos[i][0], LV6DoorPos[i][1]);
				key[i].SetPos(LV6KeyPos[i][0], LV6KeyPos[i][1]);
			}
			for (int i = 0; i < Potionnum[level - 1]; i++) {
				potion[i].LoadBitmap();
				potion[i].SetPos(LV6PotionPos[i][0], LV6PotionPos[i][1]);
				potion[i].SetIsAlive(true);
			}
		}
		else if (level == 7) {

			for (int i = 0; i < Boxesnum[level - 1]; i++) {
				box[i].LoadBitmap();
				box[i].SetPos(LV7BoxPos[i][0], LV7BoxPos[i][1]);
				box[i].SetIsAlive(true);
			}


			for (int i = 0; i < Waternum[level - 1]; i++) {
				water[i].LoadBitmap();
				water[i].SetPos(LV7WaterPos[i][0], LV7WaterPos[i][1]);
				water[i].SetIsAlive(true);
			}

			for (int i = 0; i < Slimenum[level - 1]; i++) {
				slime[i].LoadBitmap();
				slime[i].SetPos(LV7SlimePos[i][0], LV7SlimePos[i][1]);
				slime[i].SetIsAlive(true);
			}

			for (int i = 0; i < Doornum[level - 1]; i++) {
				door[i].LoadBitmap();
				key[i].LoadBitmap();
				key[i].Link(&door[i]);
				door[i].SetPos(LV7DoorPos[i][0], LV7DoorPos[i][1]);
				key[i].SetPos(LV7KeyPos[i][0], LV7KeyPos[i][1]);
			}
			for (int i = 0; i < Potionnum[level - 1]; i++) {
				potion[i].LoadBitmap();
				potion[i].SetPos(LV7PotionPos[i][0], LV7PotionPos[i][1]);
				potion[i].SetIsAlive(true);
			}
		}
		else if (level == 8) {
			for (int i = 0; i < Waternum[level - 1]; i++) {
				water[i].LoadBitmap();
				water[i].SetPos(LV8WaterPos[i][0], LV8WaterPos[i][1]);
				water[i].SetIsAlive(true);
			}
			for (int i = 0; i < Boxesnum[level - 1]; i++) {
				box[i].LoadBitmap();
				box[i].SetPos(LV8BoxPos[i][0], LV8BoxPos[i][1]);
				box[i].SetIsAlive(true);
			}
			for (int i = 0; i < Trapnum[gamemap.GetLv() - 1]; i++) {
				trap[i].LoadBitmap();
				trap[i].Restart(8);
			}
			for (int i = 0; i < Buttonnum[gamemap.GetLv() - 1]; i++) {
				button[i].LoadBitmap();
				button[i].Restart(8);
				button[i].Link(&trap[i]);
			}
			for (int i = 0; i < Slimenum[level - 1]; i++) {
				slime[i].LoadBitmap();
				slime[i].SetPos(LV8SlimePos[i][0], LV8SlimePos[i][1]);
				slime[i].SetIsAlive(true);
			}
			for (int i = 0; i < Doornum[level - 1]; i++) {
				door[i].LoadBitmap();
				key[i].LoadBitmap();
				key[i].Link(&door[i]);
				door[i].SetPos(LV8DoorPos[i][0], LV8DoorPos[i][1]);
				key[i].SetPos(LV8KeyPos[i][0], LV8KeyPos[i][1]);
			}
			for (int i = 0; i < Potionnum[level - 1]; i++) {
				potion[i].LoadBitmap();
				potion[i].SetPos(LV8PotionPos[i][0], LV8PotionPos[i][1]);
				potion[i].SetIsAlive(true);
			}
		}
	};
	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char R = 0x52;
		const char N = 0x4E;
		const char KEY_ESC = 27;						// ������GAME_STATE_RUN
		//�K��R ���s�}�l���d
		if (nChar == R) {
			Reset(gamemap.GetLv());
		}
		//�K��N ���U�@��
		if (nChar == N) {
			if (gamemap.GetLv() == unlock_level && unlock_level != 8) {
				unlock_level += 1;
				Reset(gamemap.GetLv() + 1);
			}
			else if (gamemap.GetLv() == 8) {//last level
				Reset(1);
				GotoGameState(GAME_STATE_OVER);
				return;
			}
		}
		if (nChar == KEY_ESC)								// Demo �����C������k
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// �����C��
	}
	void CGameStateRun::OnCharacterMove(int dir) { //���Ⲿ�ʤθI���P�_
		player.SetHeading(dir); //���a�]�w��V
		TrapCheck(); //�����ˬd
		//�ؼЦ�m
		int px = 0; 
		int py = 0; 
		//�ؼЪ��U�@�Ӧ�m
		int pnx = 0;
		int pny = 0;
		//�ؼЪ��U�U�@�Ӧ�m
		int wx = 0;
		int wy = 0;
		if (dir == 0) {
			px = player.GetX() - 1;
			py = pny = wy = player.GetY();
			pnx = player.GetX() - 2;
			wx = player.GetX() - 3;
		}
		else if (dir == 1) {
			px = player.GetX() + 1;
			py = pny = wy = player.GetY();
			pnx = player.GetX() + 2;
			wx = player.GetX() + 3;
		}
		else if (dir == 2) {
			px = pnx = wx = player.GetX();
			py = player.GetY() - 1;
			pny = player.GetY() - 2;
			wy = player.GetY() - 3;
		}
		else {
			px = pnx = wx = player.GetX();
			py = player.GetY() + 1;
			pny = player.GetY() + 2;
			wy = player.GetY() + 3;
		}
		if (coin.hitplayer(px, py)) { //Ĳ�I������q��		
			if (sound) {
				CAudio::Instance()->Play(AUDIO_COIN, false);
			}
			if (gamemap.GetLv() == unlock_level && unlock_level != 8) {
				unlock_level += 1;
				Reset(gamemap.GetLv() + 1);
			}
			else if (gamemap.GetLv() == 8) {//last level
				GotoGameState(GAME_STATE_OVER);
				Reset(1);
				return;
			}
			else if (unlock_level <= 8) {
				if (gamemap.GetLv() != 8) {
					Reset(gamemap.GetLv() + 1);
				}
			}
			
			pflag = true;
			Sleep(100);
			return;
		}
		for (int i = 0; i < Potionnum[gamemap.GetLv() - 1]; i++) { //�I���Ĥ�
			if (potion[i].hitplayer(px, py)) {
				potion[i].SetIsAlive(false);
				if (sound) {
					CAudio::Instance()->Play(AUDIO_DING, false);
				}
				potion_get += 1;
				potion_num = CMovingBitmap();
				potion_num.LoadBitmap(nums[potion_get]);
				potion_num.SetTopLeft(930, 55);
			}
		}
		for (int i = 0; i < Doornum[gamemap.GetLv() - 1]; i++) {
			if (door[i].hit(px, py)) { //�p�G�H�I���
				if (key[i].WasGotByPlayer()) {
					if (sound) {
						CAudio::Instance()->Play(AUDIO_DOOR, false);
					}
					door[i].Open(true);
					key_num = CMovingBitmap();
					key_get -= 1;
					key_num.LoadBitmap(nums[key_get]);
					key_num.SetTopLeft(930, 5);
				}
				ButtonCheck();
				return;
			}
		}
		for (int i = 0; i < Doornum[gamemap.GetLv() - 1]; i++) {
			if (key[i].PlayerGet(px, py)) { //�p�G�H�I���_��
				if (sound) {
					CAudio::Instance()->Play(AUDIO_DING, false);
				}
				key_num = CMovingBitmap();
				key_get += 1;
				key_num.LoadBitmap(nums[key_get]);
				key_num.SetTopLeft(930, 5);
			}
		}
		for (int j = 0; j < Waternum[gamemap.GetLv() - 1]; j++) {
			if (water[j].HitPlayer(px, py)) //�P�_�H�I���
			{
				ButtonCheck();
				Sleep(100);
				return;
			}
		}
		for (int i = 0; i < Boxesnum[gamemap.GetLv() - 1]; i++) {
			if (box[i].hitplayer(px, py)) { //�P�_�H�I��c�l
				if (coin.hitplayer(pnx, pny)) //�p�G�c�l�e���������N������
				{
					if (sound) {
						CAudio::Instance()->Play(AUDIO_COIN, false);
					}
					if (gamemap.GetLv() == unlock_level && unlock_level != 8) {
						unlock_level += 1;
						Reset(gamemap.GetLv() + 1);
					}
					else if (gamemap.GetLv() == 8) {//last level
						GotoGameState(GAME_STATE_OVER);
						Reset(1);
						return;
					}
					else if (unlock_level == 8) {
						if (gamemap.GetLv() != 8) {
							Reset(gamemap.GetLv() + 1);
						}
					}
					ButtonCheck();
					Sleep(100);
					return;
				}
				for (int j = 0; j < Potionnum[gamemap.GetLv() - 1]; j++) {
					if (potion[j].GetPx() == pnx && potion[j].GetPy() == pny && (potion[j].IsAlive() && !potion[j].isGrabbed())) //�p�G�c�l�e���O�Ĥ��N����
					{
						ButtonCheck();
						Sleep(100);
						return;
					}
				}
				for (int j = 0; j < Waternum[gamemap.GetLv() - 1]; j++) {
					if (box[i].HitWater(&water[j], dir)) //�p�G�c�l�e���O���N���
					{
						if (sound) {
							CAudio::Instance()->Play(AUDIO_WATER, false);
						}
						player.SetPos(px, py);
						ButtonCheck();
						Sleep(100);
						return;
					}
				}
				for (int j = 0; j < Boxesnum[gamemap.GetLv() - 1]; j++)				{
					if (box[j].hitplayer(pnx, pny)) {//�p�G�c�l�e���٦��@�ӽc�l�N������
						ButtonCheck();
						Sleep(100);
						return;
					}
				}
				for (int j = 0; j < Trapnum[gamemap.GetLv() - 1]; j++) {
					if (trap[j].hit(pnx, pny)) {  //�p�G�c�l�e��������
						ButtonCheck();
						Sleep(100);
						return;
					}
				}
				for (int j = 0; j < Doornum[gamemap.GetLv() - 1]; j++) {
					if (door[j].hit(pnx, pny)) { //�p�G�c�l�e������
						ButtonCheck();
						return;
					}
					if (key[j].Getpx() == pnx && key[j].Getpy() == pny && !key[j].WasGot()) {
						ButtonCheck();
						return;
					}
				}
				for (int j = 0; j < Slimenum[gamemap.GetLv() - 1]; j++)				{

					if (slime[j].GetX() == pnx && slime[j].GetY() == pny && slime[j].IsAlive()) {//�p�G�c�l�e�����@�ӥv�ܩi
						for (int k = 0; k < Slimenum[gamemap.GetLv() - 1]; k++) {
							if (slime[k].GetX() == wx && slime[k].GetY() == wy) {//�p�G�v�ܩi�e���٦��@�ӥv�ܩi�N������
								ButtonCheck();
								Sleep(100);
								return;
							}
						}
						for (int k = 0; k < Trapnum[gamemap.GetLv() - 1]; k++) {
							if (trap[k].hit(wx, wy)) {  //�p�G�v�ܩi�e��������
								ButtonCheck();
								Sleep(100);
								return;
							}
						}
						for (int k = 0; k < Doornum[gamemap.GetLv() - 1]; k++) {
							if (door[k].hit(wx, wy)) { //�p�G�v�ܩi�e������
								return;
							}
						}
						for (int k = 0; k < Waternum[gamemap.GetLv() - 1]; k++)	{
							if (slime[j].HitWater(&water[k], dir)) {//�p�G�v�ܩi���
								if (sound) {
									CAudio::Instance()->Play(AUDIO_WATER, false);
								}
								box[i].SetPos(pnx, pny);
								player.SetPos(px, py);
								for (int l = 0; l < Doornum[gamemap.GetLv() - 1]; l++) { //�P�_���S���_�ͳQ�Y��
									if (key[l].SlimeRelease(&slime[j])) {
										key[l].SetPos(wx, wy);
										key[l].Eaten(&slime[j]);
									}
								}
								for (int l = 0; l < Potionnum[gamemap.GetLv() - 1]; l++) { //�P�_���S���Ĥ��Q�Y��
									if (potion[l].GetPx() == slime[j].GetX() && potion[l].GetPy() == slime[j].GetY()) {
										potion[l].Release();
									}
								}
								ButtonCheck();
								Sleep(100);
								return;
							}
						}
						if (!MapCheck(dir, slime[j].GetX(), slime[j].GetY(), &slime[j])) { // ���ʤ�V�I���P�_
							ButtonCheck();
							Sleep(100);
							return;
						}
						if (sound) {
							CAudio::Instance()->Play(AUDIO_BOX, false);
						}
						//�W�z���󳣨S�o�ʹN���v�ܩi�e�i
						box[i].SetPos(pnx, pny);
						player.SetPos(px, py);
						slime[j].SetPos(wx, wy);
						ButtonCheck();
						Sleep(100);
						return;
					}
				}				
				if (gamemap.GetMap(pnx, pny) == 1 || gamemap.GetMap(pnx, pny) == 2) {//�p�G�c�l�e���S���F��N��
					if (sound) {
						CAudio::Instance()->Play(AUDIO_BOX, false);
					}
					box[i].SetPos(pnx, pny);
					player.SetPos(px, py);
					ButtonCheck();
					Sleep(100);
					return;
				}
				ButtonCheck();
				Sleep(100);
				return;
			}
		}
		
		if (gamemap.GetMap(px, py) == 1 || gamemap.GetMap(px, py) == 2) {//�p�G�H�e���S���F��N�e�i
			for (int j = 0; j < Trapnum[gamemap.GetLv() - 1]; j++) {
				if (trap[j].hit(px, py)) {
					ButtonCheck();
					Sleep(100);
					return;
				}
			}
			player.SetPos(px, py);
			ButtonCheck();
			Sleep(100);
		}
	}
	void CGameStateRun::ButtonCheck() {//�ˬd���S���F��Ĳ�o���s
		for (int i = 0; i < Buttonnum[gamemap.GetLv() - 1]; i++) {
			bool flag = false;
			bool TrapT = button[i].GetTrapT();
			for (int j = 0; j < Slimenum[gamemap.GetLv() - 1]; j++) { //�ˬd�v�ܩiĲ�o
				flag = button[i].trigger(slime[j].GetX(), slime[j].GetY());
				if (flag == true) {
					if (TrapT != button[i].GetTrapT() && sound) {
						CAudio::Instance()->Play(AUDIO_TRAP_OPEN, false);
					}
					break;
				}
			}
			if (flag == true) {
				continue;
			}
			for (int j = 0; j < Boxesnum[gamemap.GetLv() - 1]; j++) {//�ˬd�c�lĲ�o
				flag = button[i].trigger(box[j].GetPx(), box[j].GetPy());
				if (flag == true) {
					if (TrapT != button[i].GetTrapT() && sound) {
						CAudio::Instance()->Play(AUDIO_TRAP_OPEN, false);
					}
					break;
				}
			}
			if (flag == true) {
				continue;
			}
			if (button[i].trigger(player.GetX(), player.GetY())) { ///�ˬd�HĲ�o
				if (TrapT != button[i].GetTrapT() && sound) {
					CAudio::Instance()->Play(AUDIO_TRAP_OPEN, false);
				}
				continue;
			}
			if (TrapT != button[i].GetTrapT() && sound) {
				CAudio::Instance()->Play(AUDIO_TRAP_CLOSE, false);
			}
		}
		TrapCheck();
	}
	void CGameStateRun::TrapCheck() {//�����ˬd
		for (int i = 0; i < Trapnum[gamemap.GetLv() - 1]; i++) {
			if (trap[i].GetTrigger()) {//�����}�۴N�S��
				continue;
			}
			for (int j = 0; j < Boxesnum[gamemap.GetLv() - 1]; j++) {//�����W���c�l�N�}�a
				if (trap[i].hit(box[j].GetPx(), box[j].GetPy())) {
					box[j].SetIsAlive(false);
				}
			}
			for (int j = 0; j < Slimenum[gamemap.GetLv() - 1]; j++) {//�����W���v�ܩi�N����
				if (trap[i].hit(slime[j].GetX(), slime[j].GetY())) {
					slime[j].SetIsAlive(false);
					for (int k = 0; k < Doornum[gamemap.GetLv() - 1]; k++) {//�P�_���S���_�ͳQ�Y��
						key[k].Eaten(&slime[j]);
					}
					for (int l = 0; l < Potionnum[gamemap.GetLv() - 1]; l++) { //�P�_���S���Ĥ��Q�Y��
						if (potion[l].GetPx() == slime[j].GetX() && potion[l].GetPy() == slime[j].GetY()) {
							potion[l].Release();
						}
					}
				}
			}
			if (trap[i].hit(player.GetX(), player.GetY())) {//����Ĳ�I��H
				player.SetIsAlive(false);
				fflag = true;
			}
		}
	}
	bool CGameStateRun::MapCheck(int dir, int x, int y, Slime* s) {//�v�ܩi�I���ˬd
		//�Y�O�Q�w�t�N�S��
		if (s->IsShock()) {
			s->Move(dir);
			fflag = s->HitPlayer(&player);
			if (fflag && sound) {
				CAudio::Instance()->Play(AUDIO_EAT, false);
			}
			return false;
		}
		if (dir == 0) {
			x = x - 1;
		}
		else if (dir == 1) {
			x = x + 1;
		}
		else if (dir == 2) {
			y = y - 1;
		}
		else if (dir == 3) {
			y = y + 1;
		}
		else {
			return false;
		}
		for (int i = 0; i < Boxesnum[gamemap.GetLv() - 1]; i++)
		{
			if (box[i].hitplayer(x, y)) {//�p�G�e�����@�ӽc�l
				return false;
			}
		}
		for (int j = 0; j < Trapnum[gamemap.GetLv() - 1]; j++) {
			if (trap[j].hit(x, y)) {  //�p�G�e��������
				ButtonCheck();
				return false;
			}
		}
		for (int i = 0; i < Slimenum[gamemap.GetLv() - 1]; i++) {//�e���٦��@���v�ܩi
			if (slime[i].GetX() == x && slime[i].GetY() == y && slime[i].IsAlive()) {
				if (!MapCheck(dir, x, y, &slime[i]))
				{
					return false;
				}
			}
		}
		for (int j = 0; j < Doornum[gamemap.GetLv() - 1]; j++) {
			if (door[j].hit(x, y)) {  //�p�G�e������
				ButtonCheck();
				return false;
			}
			if (key[j].SlimeGet(x, y,s)) {//�Y���_���ܦ�
				s->Change_Color("blue");
				key[j].Eaten(s);
				ButtonCheck();
			}
		}
		for (int i = 0; i < Potionnum[gamemap.GetLv() - 1]; i++) {//�Y���Ĥ��ܦ�
			if (potion[i].hitslime(x, y, s)) {
				s->Change_Color("red");
			}
		}
		for (int i = 0; i < Waternum[gamemap.GetLv() - 1]; i++) {//�I���
			if (water[i].HitPlayer(x,y)) {
				return false;
			}
		}
		if (gamemap.GetMap(x, y) == 1 || gamemap.GetMap(x, y) == 2) {//�e���O��
			return true;
		}
		return false;
	}
	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		if (countdown > 0) {
			return;
		}
		const char KEY_LEFT = 0x25; // keyboard���b�Y
		const char KEY_UP = 0x26; // keyboard�W�b�Y
		const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
		const char KEY_DOWN = 0x28; // keyboard�U�b�Y
		const char A = 0x41;
		const char W = 0x57;
		const char D = 0x44;
		const char S = 0x53;
		if (nChar == KEY_LEFT || nChar == A) {//��V�䥪��A�����V��
			OnCharacterMove(0);
		}
		if (nChar == KEY_RIGHT || nChar == D) {//��V��k��D�����V�k
			OnCharacterMove(1);
		}
		if (nChar == KEY_UP || nChar == W) {//��V��W��W�����V�W
			OnCharacterMove(2);
		}
		if (nChar == KEY_DOWN || nChar == S) {//��V��U��S�����V�U
			OnCharacterMove(3);
		}
		for (int i = 0; i < Slimenum[gamemap.GetLv() - 1]; i++) {
			ButtonCheck();
			int dirs = slime[i].FindPlayer(&player);//�v�ܩi���o����۹�o����V
			if (dirs == -2) {//-2 �N�O���|
				fflag = true;
				if (fflag && sound) {
					CAudio::Instance()->Play(AUDIO_EAT, false);
				}
				return;
			}
			//�ˬd�a��
			if (MapCheck(dirs, slime[i].GetX(), slime[i].GetY(), &slime[i])) {

				slime[i].Move(dirs);
				fflag = slime[i].HitPlayer(&player);
				if (fflag && sound) {
					CAudio::Instance()->Play(AUDIO_EAT, false);
				}
				if (fflag) {
					countdown = 5;
					fflag = false;
					fail_logo.SetTopLeft(310, 250);
					Reset(gamemap.GetLv());
					if (sound) {
						CAudio::Instance()->Play(AUDIO_FAIL, false);
					}
				}
			}
		}
	}

	void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
	{

		//�}������
		if (sound && point.x >= 1103 && point.x <= 1183 && point.y >= 13 && point.y <= 93) {
			CAudio::Instance()->Stop(AUDIO_BGM);
			sound = false;
			sound_off.SetTopLeft(1103, 13);
		}
		else if (!sound && point.x >= 1103 && point.x <= 1183 && point.y >= 13 && point.y <= 93) {
			CAudio::Instance()->Play(AUDIO_BGM, true);
			sound = true;
			sound_off.SetTopLeft(0, -100);
		}
		//�W����
		else if (point.x >= 383 && point.x <= 533 && point.y >= 22 && point.y <= 100) {//restart
			Reset(gamemap.GetLv());
		}
		else if (!in_levels && point.x >= 666 && point.x <= 815 && point.y >= 22 && point.y <= 100) {//choose levels
			lx = 0;
			in_levels = true;
		}
		//�����d�e���A�̷ӫ�����m������d
		else if (in_levels) {
			if (point.x >= 107 && point.x <= 219 && point.y >= 134 && point.y <= 211) {
				lx = -1198;
				in_levels = false;
				gamemap.SetLevel(1);
				Reset(gamemap.GetLv());
			}
			else if (point.x >= 230 && point.x <= 342 && point.y >= 134 && point.y <= 211 && unlock_level >= 2) {
				lx = -1198;
				in_levels = false;
				gamemap.SetLevel(2);
				Reset(gamemap.GetLv());
			}
			else if (point.x >= 353 && point.x <= 465 && point.y >= 134 && point.y <= 211 && unlock_level >= 3) {
				lx = -1198;
				in_levels = false;
				gamemap.SetLevel(3);
				Reset(gamemap.GetLv());
			}
			else if (point.x >= 476 && point.x <= 588 && point.y >= 134 && point.y <= 211 && unlock_level >= 4) {
				lx = -1198;
				in_levels = false;
				gamemap.SetLevel(4);
				Reset(gamemap.GetLv());
			}
			else if (point.x >= 599 && point.x <= 711 && point.y >= 134 && point.y <= 211 && unlock_level >= 5) {
				lx = -1198;
				in_levels = false;
				gamemap.SetLevel(5);
				Reset(gamemap.GetLv());
			}
			else if (point.x >= 722 && point.x <= 834 && point.y >= 134 && point.y <= 211 && unlock_level >= 6) {
				lx = -1198;
				in_levels = false;
				gamemap.SetLevel(6);
				Reset(gamemap.GetLv());
			}
			else if (point.x >= 845 && point.x <= 967 && point.y >= 134 && point.y <= 211 && unlock_level >= 7) {
				lx = -1198;
				in_levels = false;
				gamemap.SetLevel(7);
				Reset(gamemap.GetLv());
			}
			else if (point.x >= 977 && point.x <= 1089 && point.y >= 134 && point.y <= 211 && unlock_level >= 8) {
				lx = -1198;
				in_levels = false;
				gamemap.SetLevel(8);
				Reset(gamemap.GetLv());
			}
		}
		else if (int((point.x - 315) / 70) > 0 && int((point.y - 195) / 70) > 0) { //�I���a�Ϥ�
			for (int i = 0; i < Boxesnum[gamemap.GetLv() - 1]; i++) {
				//�p�G�I���a�観�c�l�B�b���a���W�U���k�A�B���a�����Ĥ��A�N�|�����Ĥ��߰_�c�l
				if (potion_get > 0 && box[i].GetPx() == int((point.x - 315) / 70) && box[i].GetPy() == int((point.y - 195) / 70) && box[i].NextToPlayer(player.GetX(), player.GetY())) {
					box[i].GrabByPlayer();
					if (sound) {
						CAudio::Instance()->Play(AUDIO_EAT, false);
					}
					potion_get -= 1;
					potion_num = CMovingBitmap();
					potion_num.LoadBitmap(nums[potion_get]);
					potion_num.SetTopLeft(930, 55);
					return;
				}
			}
			//�Y�O�I����m�b�a�Ϥ��A�|�h�P�_��c�l.
			if (point.x >= player.GetX() * 70 + 315 && point.x <= player.GetX() * 70 + 385 && point.y >= 70 + 195 && point.y <= 5 * 70 + 195) {//�P�_������m�Ωҿ��m�O�_����ê��
				for (int i = 0; i < Boxesnum[gamemap.GetLv() - 1]; i++) {
					if (box[i].IsGrabbed() && (gamemap.GetMap(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70))) == 1 || gamemap.GetMap(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70))) == 2)) {
						for (int j = 0; j < Boxesnum[gamemap.GetLv() - 1]; j++) {
							if (box[j].GetPx() == int(floor((point.x - 315) / 70)) && box[j].GetPy() == int(floor((point.y - 195) / 70)) && box[j].IsAlive() && !box[j].IsGrabbed()) {//�Q�c�l�צ�
								return;
							}
						}
						for (int j = 0; j < Doornum[gamemap.GetLv() - 1]; j++) {//�Q�����_�;צ�
							if (door[j].hit(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70)))) {
								return;
							}
							if (key[j].Getpx() == int(floor((point.x - 315) / 70)) && key[j].Getpy() == int(floor((point.y - 195) / 70)) && !key[j].WasGot()) {
								return;
							}
						}
						for (int j = 0; j < Potionnum[gamemap.GetLv() - 1]; j++) {//�Q�Ĥ��צ�
							if (potion[j].hitplayer(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70)))) {
								return;
							}
						}
						if (coin.hit(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70)))) {//�Q�����צ�
							return;
						}
						box[i].SetPos(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70)));
						box[i].ThrowByPlayer();
						ButtonCheck();
						if (sound) {
							CAudio::Instance()->Play(AUDIO_THROW, false);
						}
						for (int j = 0; j < Slimenum[gamemap.GetLv() - 1]; j++) {//�P�_���S�����v�ܩi
							if (slime[j].GetX() == box[i].GetPx() && slime[j].GetY() == box[i].GetPy() && slime[j].IsAlive()) {
								slime[j].Shock(); //�w�t�α����v�ܩi 
								box[i].SetIsAlive(false); //�����c�l
								if (!slime[j].IsAlive()) //�p�G�����v�ܩi�A�N�⥦�Y�����S��D��R�X��
								{
									for (int k = 0; k < Doornum[gamemap.GetLv() - 1]; k++) {
										key[k].Eaten(&slime[j]);
									}
									for (int k = 0; k < Potionnum[gamemap.GetLv() - 1]; k++) {
										if (potion[k].GetPx() == slime[j].GetX() && potion[k].GetPy() == slime[j].GetY()) {
											potion[k].Release();
										}
									}
								}
							}
						}
						for (int j = 0; j < Waternum[gamemap.GetLv() - 1]; j++) {
							if (box[i].ThrowOnWater(&water[j])) //�p�G�����N���
							{
								if (sound) {
									CAudio::Instance()->Play(AUDIO_WATER, false);
								}
								Sleep(100);
								return;
							}
						}
						ButtonCheck();
					}
				}
			}
			else if (point.x >= 70 + 315 && point.x <= 6 * 70 + 385 && point.y >= player.GetY() * 70 + 195 && point.y <= player.GetY() * 70 + 265) {//��W���@�˨B�J�A�u�O�P�_�O��V�O������
				for (int i = 0; i < Boxesnum[gamemap.GetLv() - 1]; i++) {
					if (box[i].IsGrabbed() && (gamemap.GetMap(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70))) == 1 || gamemap.GetMap(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70))) == 2)) {
						for (int j = 0; j < Boxesnum[gamemap.GetLv() - 1]; j++) {
							if (box[j].GetPx() == int(floor((point.x - 315) / 70)) && box[j].GetPy() == int(floor((point.y - 195) / 70)) && box[j].IsAlive() && !box[j].IsGrabbed()) {
								return;
							}
						}
						for (int j = 0; j < Doornum[gamemap.GetLv() - 1]; j++) {
							if (door[j].hit(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70)))) {
								return;
							}
							if (key[j].Getpx() == int(floor((point.x - 315) / 70)) && key[j].Getpy() == int(floor((point.y - 195) / 70)) && !key[j].WasGot()) {
								return;
							}
						}
						for (int j = 0; j < Potionnum[gamemap.GetLv() - 1]; j++) {
							if (potion[j].hitplayer(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70)))) {
								return;
							}
						}
						if (coin.hit(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70)))) {
							return;
						}
						box[i].SetPos(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70)));
						box[i].ThrowByPlayer();
						ButtonCheck();
						if (sound) {
							CAudio::Instance()->Play(AUDIO_THROW, false);
						}
						for (int j = 0; j < Slimenum[gamemap.GetLv() - 1]; j++) {
							if (slime[j].GetX() == box[i].GetPx() && slime[j].GetY() == box[i].GetPy() && slime[j].IsAlive()) {
								slime[j].Shock();
								box[i].SetIsAlive(false);
								if (!slime[j].IsAlive()) {
									for (int k = 0; k < Doornum[gamemap.GetLv() - 1]; k++) {
										key[k].Eaten(&slime[j]);
									}
									for (int k = 0; k < Potionnum[gamemap.GetLv() - 1]; k++) {
										if (potion[k].GetPx() == slime[j].GetX() && potion[k].GetPy() == slime[j].GetY()) {
											potion[k].Release();
										}
									}
								}
							}
						}
						for (int j = 0; j < Waternum[gamemap.GetLv() - 1]; j++) {
							if (box[i].ThrowOnWater(&water[j]))
							{
								if (sound) {
									CAudio::Instance()->Play(AUDIO_WATER, false);
								}
								Sleep(100);
								return;
							}
						}
						ButtonCheck();
					}
				}
			}
		}
	}
	void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
	{
		
	}
	void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
	{
	}
	void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
	{
	}
	void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
	{
	}
	void CGameStateRun::OnShow()
	{
		//�p�G���ѴN�|�K�@�ӥ��Ѫ�����+�񭵮�
		if (fflag) {
			countdown = 5;
			fflag = false;
			fail_logo.SetTopLeft(310, 250);
			Reset(gamemap.GetLv());
			if (sound) {
				CAudio::Instance()->Play(AUDIO_FAIL, false);
			}
		}
		//�p�G���\�N�|�K�@�Ӧ��\������+�񭵮�
		if (pflag) {
			countdown = 5;
			pflag = false;
			pass_logo.SetTopLeft(310, 250);
			if (sound) {
				CAudio::Instance()->Play(AUDIO_PASS, false);
			}
		}
		//�˼�
		if (countdown > 0) {
			Sleep(500);
			countdown--;
			if (countdown == 0) {
				fail_logo.SetTopLeft(-1198, 0);
				pass_logo.SetTopLeft(-1198, 0);
			}
		}
		//���U�O�Ҧ��ϧΪ����
		
		banner.ShowBitmap();
		hint[gamemap.GetLv() - 1].ShowBitmap();
		logo.ShowBitmap();
		gamemap.OnShow();
		
		
		for (int i = 0; i < Waternum[gamemap.GetLv() - 1]; i++) {
			water[i].OnShow();
		}
		for (int i = 0; i < Torchnum; i++) {
			torch[i].OnShow();
		}
		for (int i = 0; i < Pipenum; i++) {
			pipe[i].OnShow();
		}
		for (int i = 0; i < Buttonnum[gamemap.GetLv() - 1]; i++) {
			button[i].OnShow();
		}
		for (int i = 0; i < Potionnum[gamemap.GetLv() - 1]; i++) {
			potion[i].OnShow();
		}
		for (int i = 0; i < Trapnum[gamemap.GetLv() - 1]; i++) {
			trap[i].OnShow();
		}
		for (int i = 0; i < Boxesnum[gamemap.GetLv() - 1]; i++) {
			box[i].OnShow();
		}
		for (int i = 0; i < Slimenum[gamemap.GetLv() - 1]; i++) {
			slime[i].OnShow();
		}
		for (int i = 0; i < Doornum[gamemap.GetLv() - 1]; i++) {
			door[i].OnShow();
			key[i].OnShow();
		}
		coin.OnShow();
		potion_num.ShowBitmap();
		key_num.ShowBitmap();
		player.OnShow();
		fail_logo.ShowBitmap();
		pass_logo.ShowBitmap();
		if (unlock_level == 1) {
			levels.SetTopLeft(lx, 0);
			levels.ShowBitmap();
		}
		else if (unlock_level == 2) {
			l2.SetTopLeft(lx, 0);
			l2.ShowBitmap();
		}
		else if (unlock_level == 3) {
			l3.SetTopLeft(lx, 0);
			l3.ShowBitmap();
		}
		else if (unlock_level == 4) {
			l4.SetTopLeft(lx, 0);
			l4.ShowBitmap();
		}
		else if (unlock_level == 5) {
			l5.SetTopLeft(lx, 0);
			l5.ShowBitmap();
		}
		else if (unlock_level == 6) {
			l6.SetTopLeft(lx, 0);
			l6.ShowBitmap();
		}
		else if (unlock_level == 7) {
			l7.SetTopLeft(lx, 0);
			l7.ShowBitmap();
		}
		else if (unlock_level == 8) {
			l8.SetTopLeft(lx, 0);
			l8.ShowBitmap();
		}
		if (!sound) {
			sound_off.SetTopLeft(1103, 13);
		}
		sound_on.ShowBitmap();
		sound_off.ShowBitmap();
	}
}