#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Water.h"
#include "Player.h"
#include "Slime.h"
#include "Potion.h"
namespace game_framework {
	Potion::Potion()//��l��
	{
		is_alive = true;
		is_got = false;
		x = y = px = py = 0;
	}
	bool Potion::isGrabbed() {//�^���Ĥ����S���Q����
		return is_got;
	}
	bool Potion::hitplayer(int nx, int ny) {//�I�쪱�a��
		if (!is_alive||is_got) {
			return FALSE;
		};
		if (nx == px && ny == py) {
			return TRUE;
		}
		return FALSE;
	}
	bool Potion::hitslime(int nx, int ny, Slime* s) {//�J��Ǫ��ɡA�|�Q�Y��
		if (is_got && slime_eaten == s) {
			px = x;
			py = y;
			return TRUE;
		};
		if (nx == px && ny == py) {
			is_got = true;
			slime_eaten = s;
			return TRUE;
		}
		return FALSE;
	}
	void Potion::Release() {//�Ǫ�����|���Ĥ�
		is_got = false;
	}
	int Potion::GetPx() {//�^���Ĥ���px��
		return px;
	}
	int Potion::GetPy() {//�^���Ĥ���py��
		return py;
	}
	void Potion::SetPos(int nx, int ny) {//�]�w�Ĥ�����m
		px = nx;
		py = ny;
		x = px * 70 + 315;
		y = py * 70 + 195;
	}
	bool Potion::IsAlive()//�^���Ĥ��O�_���Q�α�
	{
		return is_alive;
	}
	void Potion::LoadBitmap()//���J�귽
	{
		potion.LoadBitmap(IDB_POTION, RGB(255, 255, 255));		
	}
	void Potion::OnMove()//�Ĥ��Y�Q�α��γQ�ߨ��A�h�����
	{
		if (!is_alive||is_got)
			return;
		potion.SetTopLeft(x, y);
		potion.ShowBitmap();
	}
	void Potion::SetIsAlive(bool alive)//�]�w�Ĥ��O�_���Q�α�
	{
		is_alive = alive;
	}

	void Potion::SetXY(int nx, int ny)//�]�w�Ĥ���xy��
	{
		x = nx; y = ny;
	}
	void Potion::OnShow()//�Ĥ��Y�Q�α��γQ�ߨ��A�h�����
	{
		if (!is_alive||is_got)
			return;
		potion.SetTopLeft(x, y);
		potion.ShowBitmap();
	}
}