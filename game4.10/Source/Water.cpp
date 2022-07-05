#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Player.h"
#include <windows.h>
#include "Water.h"
namespace game_framework {
	Water::Water()
	{
		is_alive = true;
		x = y = px = py = 0;
	}
	void Water::SetIsAlive(bool alive)//�]�w�O�_�Q�}�a
	{
		is_alive = alive;
	}
	bool Water::HitBox(int nx, int ny) {//�c�l���
		if (!is_alive) {
			return false;
		}
		if (nx == px && ny == py) {
			is_alive = false;
			return true;
		}
		return false;
	}
	bool Water::HitPlayer(int nx, int ny) {//�I��F�����
		if (!is_alive) {
			return false;
		}
		if (nx == px && ny == py && is_alive) {
			return true;
		}
		return false;
	}
	void Water::SetPos(int nx, int ny) {//�]�w�y��
		px = nx;
		py = ny;
		x = px * 70 + 315;
		y = py * 70 + 195;
	}
	void Water::OnMove()//�Y�O���Q�}�a�h���
	{
		if (!is_alive) {
			return;
		}
		water.SetTopLeft(x, y);
		water.ShowBitmap();
	}
	int Water::GetPx() {//���opx�y��
		return px;
	}
	int Water::GetPy() {//���opy�y��
		return py;
	}
	void Water::OnShow()//�Y�O���Q�}�a�h���
	{
		if (is_alive) {
			water.SetTopLeft(x, y);
			water.ShowBitmap();
		}
	}
	void Water::LoadBitmap()//���J�Ϥ��귽
	{
		water.LoadBitmap(IDB_WATER, RGB(255, 255, 255));			
	}
}