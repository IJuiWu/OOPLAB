#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <windows.h>
#include "Trap.h"
namespace game_framework {
	Trap::Trap()
	{
	}
	void Trap::LoadBitmap()//���J�Ϥ��귽�A�����}���������
	{
		trap[0].LoadBitmap(IDB_TRAP1, RGB(255, 255, 255));
		trap[1].LoadBitmap(IDB_TRAP2, RGB(255, 255, 255));
	}
	bool Trap::GetTrigger() {//�^�ǬO�_�Q�E��
		return triggered;
	};
	void Trap::trigger(bool b) {//�E������
		triggered = b;
	}
	bool Trap::hit(int nx, int ny) {//�P�_�O�_���I��
		if (nx == px && ny == py && !triggered) {
			return true;
		}
		return false;
	}
	void Trap::OnMove()//�ھڲ{�b�����A��ܥL���}��
	{
		trap[1].SetTopLeft(x, y);
		trap[0].SetTopLeft(x, y);
		if (triggered) {
			trap[1].ShowBitmap();
		}
		else {
			trap[0].ShowBitmap();
		}
	}
	void Trap::Restart(int level)//���]�Ѽ�
	{
		triggered = false;
		if (level == 4) {
			SetPos(3,3);
		}
		if (level == 6) {
			SetPos(3, 3);
		}
		if (level == 8) {
			SetPos(3, 3);
		}
	}
	void Trap::SetXY()//�]�w������xy
	{
		x = px * 70 + 315;
		y = py * 70 + 195;
	}
	void Trap::SetPos(int nx, int ny) {//�]�w�������y��
		px = nx;
		py = ny;
		x = px * 70 + 315;
		y = py * 70 + 195;
	}
	void Trap::OnShow()//�ھڲ{�b�����A��ܥL���}��
	{
		trap[1].SetTopLeft(x, y);
		trap[0].SetTopLeft(x, y);
		if (triggered) {
			trap[1].ShowBitmap();
		}
		else {
			trap[0].ShowBitmap();
		}
	}
}