#include "Water.h"
#include "Box.h"
#include "Player.h"
#include "Coin.h"
#include "Slime.h"
#include "Trap.h"
#include "Button.h"
#include "Door.h"
#include "Key.h"
#include "Potion.h"
#include "Pipe.h"
#include "Torch.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////
	enum AUDIO_ID {				// �w�q�U�ح��Ī��s��
		AUDIO_BGM,				// 0
		AUDIO_DING,				// 1
		AUDIO_WATER,			// 2
		AUDIO_BOX,				// 3
		AUDIO_EAT,
		AUDIO_COIN,
		AUDIO_PASS,
		AUDIO_FAIL,
		AUDIO_TRAP_OPEN,
		AUDIO_TRAP_CLOSE,
		AUDIO_DOOR,
		AUDIO_THROW
	};
	struct position 
	{
		int x;
		int y;
	};
	static bool sound = false;
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C���}�Y�e������
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////
	class CGameMap {
	public:
		CGameMap();
		void SetLevel(int level);						// �]�w��e���d����
		void LoadBitmap();								// ���J�ϧ�
		void LoadMap();									// ���J�a��
		void OnShow();									// ��ܹϧ�
		int GetMap(int x, int y);						// Ū���a�Ϥ��e
		int map[6][8];									// �]�w�a��
		int GetLv();									// Ū����e���d����
	protected:
		CMovingBitmap floor1, floor2, water, wall1, wall2, wall3, wall4, wall5, wall6, wall7, \
			wall8, wall9, wall10, wall11, wall12, wall13, wall14, corner1, corner2, corner3, corner4, black;
		int Level1_Map[6][8] = { {20,8,8,8,13,8,8,18},{5,2,1,1,17,1,2,6},{17,1,1,1,10,1,1,17},{6,1,4,1,1,1,1,17},{17,2,6,1,1,1,2,6},{19,7,14,8,9,8,8,21} };
		int Level2_Map[6][8] = { {20,9,8,13,9,8,9,18},{17,2,1,17,1,1,2,17},{17,1,1,10,1,1,1,5},{5,1,1,1,1,1,1,17},{17,2,1,2,1,1,2,5},{19,8,9,8,8,8,7,21} };
		int Level3_Map[6][8] = { {20,9,8,13,8,9,8,18},{17,1,1,6,2,1,1,17},{17,1,8, 21,1,1,1,17},{5,1,1,1,2,1,1,5},{17,1,1,4,1,2,1,17},{19,8,9,14,8,8,8,21} };
		int Level4_Map[6][8] = { {20,9,8,13,8,9,8,18},{17,1,1,6,2,1,1,17},{17,1,8, 21,1,1,1,17},{5,1,1,1,2,1,1,5},{17,1,1,4,1,2,1,17},{19,8,9,14,8,8,8,21} };
		int Level5_Map[6][8] = { {20,9,8,13,8,9,8,18},{17,1,1,6,2,1,1,17},{17,1,8, 21,1,1,1,17},{5,1,1,1,2,1,1,5},{17,1,1,4,1,2,1,17},{19,8,9,14,8,8,8,21} };
		int Level6_Map[6][8] = { {20,9,8,13,8,9,8,18},{17,1,1,6,2,1,1,17},{17,1,8, 21,1,1,1,17},{5,1,1,1,2,1,1,5},{17,1,1,4,1,2,1,17},{19,8,9,14,8,8,8,21} };
		int Level7_Map[6][8] = { {20,9,8,13,8,9,8,18},{17,1,1,6,2,1,1,17},{17,1,8, 21,1,1,1,17},{5,1,1,1,2,1,1,5},{17,1,1,4,1,2,1,17},{19,8,9,14,8,8,8,21} };
		int Level8_Map[6][8] = { {20,9,8,13,8,9,8,18},{17,1,1,6,2,1,1,17},{17,1,8, 21,1,1,1,17},{5,1,1,1,2,1,1,5},{17,1,1,4,1,2,1,17},{19,8,9,14,8,8,8,21} };
		int Level = 1;
		const int X, Y;
		const int MW, MH;
	};
	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnKeyUp(UINT, UINT, UINT); 				// �B�z��LUp���ʧ@
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnLButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
	protected:
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMovingBitmap logo;								
		CMovingBitmap mainmenu, sound_off, about;
		CMovingBitmap levels, l2, l3, l4, l5, l6, l7, l8;
		CMovingBitmap intro;
		CMovingBitmap btn_play;
		CMovingBitmap btn_levels;
		CMovingBitmap btn_credits;
		CAnimation	  charactor;
		CAnimation	  slime;
		CGameMap gamemap = CGameMap();
		bool		in_intro, in_about;					// �O�_�bintro/about������
	};
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////
	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnKeyDown(UINT, UINT, UINT);				// �B�z��L���ʧ@
		void OnKeyUp(UINT, UINT, UINT);					// �B�z��L���ʧ@
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnLButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
		void OnMouseMove(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@ 
		void OnRButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnRButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
		void Reset(int level);							// ���]���d
		void OnCharacterMove(int dir);					// ���a����
		bool MapCheck(int dir, int x, int y, Slime* s); // �v�ܩi����
		void ButtonCheck();								// ���s����
		void TrapCheck();								// ��������
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		bool pflag = false;
		bool fflag = false;
		int countdown = 0;
		int Boxesnum[8] =	{ 0,1,1,2,0,2,2,3 };		// �]�m�C���c�l�ƶq
		int Waternum[8] =	{ 0,3,4,0,0,1,1,3 };		// �]�m�C�����|�ƶq
		int Slimenum[8] =	{ 0,0,1,1,0,1,2,2 };		// �]�m�C���v�ܩi�ƶq
		int Trapnum[8] =	{ 0,0,0,1,0,1,0,0 };		// �]�m�C�������ƶq
		int Doornum[8] =	{ 0,0,0,0,2,1,1,2 };		// �]�m�C���������ƶq
		int Buttonnum[8] =	{ 0,0,0,1,0,1,0,0 };		// �]�m�C�����s�ƶq
		int Potionnum[8] =	{ 0,0,0,0,0,1,1,2 };		// �]�m�C���Ĥ��ƶq
		int Torchnum =   0;
		int Pipenum =    0;
		int LV1BoxPos[1][2] = { {-999,-999} };			// �]�m���d�c�l�y��
		int LV2BoxPos[1][2] = { {2,2} };
		int LV3BoxPos[1][2] = { {5,2} };
		int LV4BoxPos[2][2] = { {5,2},{5,3} };
		int LV5BoxPos[2][2] = { {5,2},{5,3} };
		int LV6BoxPos[2][2] = { {5,2},{5,3} };
		int LV7BoxPos[2][2] = { {5,2},{4,2} };
		int LV8BoxPos[3][2] = { {5,2},{4,2},{6,2} };
		int LV1WaterPos[1][2] = { {-999,-999} };		// �]�m���d���|�y��
		int LV2WaterPos[3][2] = { {4,2} ,{5,2} ,{6,2} };
		int LV3WaterPos[4][2] = { {1,3},{1,4},{2,3},{2,4} };
		int LV6WaterPos[1][2] = { {1,3} };
		int LV7WaterPos[1][2] = { {5,4} };
		int LV8WaterPos[3][2] = { {4,4},{5,3},{6,4} };
		int LV3SlimePos[1][2] = { {3,3} };				// �]�m���d�v�ܩi�y��
		int LV4SlimePos[1][2] = { {2,3} };
		int LV5SlimePos[1][2] = { {2,3} };
		int LV6SlimePos[1][2] = { {2,3}  };
		int LV7SlimePos[2][2] = { {2,3} ,{1,3} };
		int LV8SlimePos[2][2] = { {1,3},{3,3}};
		int LV6PotionPos[1][2] = { {6,2} };				// �]�m���d�Ĥ��y��
		int LV7PotionPos[1][2] = { {4,1} };
		int LV8PotionPos[2][2] = { {6,1},{4,1} };
		int LV5KeyPos[2][2] = { {5,2},{5,3} };			// �]�m���d�_�ͮy��
		int LV6KeyPos[1][2] = { {4,3} };
		int LV7KeyPos[1][2] = { {3,3} };
		int LV8KeyPos[2][2] = { {2,3},{5,4} };
		int LV5DoorPos[2][2] = { {1,2},{3,3} };			// �]�m���d�������y��
		int LV6DoorPos[1][2] = { {1,2} };
		int LV7DoorPos[1][2] = { {1,2} };
		int LV8DoorPos[2][2] = { {1,2}, {1,1} };
		int coinpos[8][2] = { {5,1},{5,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1} };	// �]�m���d�����y��
		Box* box;
		Water* water;
		Coin coin;
		Player player = Player();
		Slime* slime;
		CMovingBitmap logo, hint[8], banner, sound_on, sound_off, fail_logo, pass_logo, potion_num, key_num;
		CMovingBitmap levels, l2, l3, l4, l5, l6, l7, l8;
		CGameMap gamemap = CGameMap();
		Trap* trap;
		Button* button;
		Door* door;
		Key* key;
		Key* key_logo;
		Potion* potion;
		Torch* torch;
		Pipe* pipe;
		int nums[3] = { IDB_num0 , IDB_num1 ,IDB_num2};
		int key_get = 0;								// �֦��_�ͼƶq
		int potion_get = 0;								// �֦��Ĥ��ƶq
	};
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A(Game Over)
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////
	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		int counter;	// �˼Ƥ��p�ƾ�
		CMovingBitmap ending;
	};
}