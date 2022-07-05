#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <windows.h>
#include "Coin.h"
namespace game_framework {
	Coin::Coin()
	{
	}
	void Coin::LoadBitmap()//���J�����ʵe
	{
		char* coinfiles[4] = { ".\\img\\coin1.bmp",".\\img\\coin2.bmp",".\\img\\coin3.bmp",".\\img\\coin4.bmp" };
		for (int i = 0; i < 4; i++)	// ���J�ʵe(��4�i�ϧκc��)
			coin.AddBitmap(coinfiles[i], RGB(255, 255, 255));	
	}
	bool Coin::hitplayer(int nx, int ny) {//�P�_�����I�쪱�a
		if (nx == px && ny == py) {
			return TRUE;
		}
		return FALSE;
	}
	void Coin::OnMove()//�������
	{
		coin.SetTopLeft(x, y);
		coin.OnMove();
	}
	bool Coin::hit(int nx, int ny) {//�P�_�����I��F��
		if (nx == px && ny == py) {
			return true;
		}
		else {
			return false;
		}
	}
	void Coin::Restart(int level)//�]�w������l��m
	{
		if (level == 1) {
			px = 5;
			py = 1;
			x = px * 70 + 315;
			y = py * 70 + 175;
		}
		else if (level == 2) {
			px = 5;
			py = 1;
			x = px * 70 + 315;
			y = py * 70 + 175;
		}
		else if (level >= 3 && level <8) {
			px = 1;
			py = 1;
			x = px * 70 + 315;
			y = py * 70 + 175;
		}
		else 
		{
			px = 2;
			py = 1;
			x = px * 70 + 315;
			y = py * 70 + 175;
		}
	}
	void Coin::SetXY()//�]�w������xy��
	{
		x = px * 70 + 295;
		y = py * 70 + 175;
	}
	void Coin::SetPos(int nx, int ny) {//�]�w�������y��
		px = nx;
		py = ny;
		x = px * 70 + 315;
		y = py * 70 + 175;
	}
	void Coin::OnShow()//���
	{
		coin.SetTopLeft(x, y);
		coin.OnShow();
	}
}