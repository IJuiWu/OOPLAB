#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <windows.h>
#include "Door.h"
namespace game_framework {
	Door::Door()
	{
	}
	void Door::LoadBitmap()//���J�Ϥ�
	{
		door.LoadBitmap(IDB_DOOR, RGB(255, 255, 255));
	}
	bool Door::GetOpen() {//�^�ǬO�_�}��
		return open;
	};
	void Door::Open(bool b) {//�]�w�}��
		open = b;
	}
	bool Door::hit(int nx, int ny) {//�P�_���O�_���ۥB���F�輲�W�h
		if (nx == px && ny == py && !open) {
			return true;
		}
		return false;
	}
	void Door::OnMove()//��ܡA�Y�O�}���N�����
	{		
		door.SetTopLeft(x, y);
		if (!open) {
			door.ShowBitmap();
		}
		else {
			return;
		}
	}
	void Door::Restart(int level)//��l��
	{
		open = false;
	}
	void Door::SetXY()//�]�w������m
	{
		x = px * 70 + 315;
		y = py * 70 + 195;
	}
	void Door::SetPos(int nx, int ny) {//�]�w�����y��
		px = nx;
		py = ny;
		x = px * 70 + 315;
		y = py * 70 + 195;
	}
	void Door::OnShow()//��ܡA���Y���ۤ����
	{
		door.SetTopLeft(x, y);
		if (!open) {
			door.ShowBitmap();
		}
		else {
			return;
		}
	}
}