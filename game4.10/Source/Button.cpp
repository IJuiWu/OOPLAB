#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <windows.h>
#include "Trap.h"
#include "Button.h"
namespace game_framework {
	Button::Button()
	{
	}
	void Button::Link(Trap* t)//�j�w���s�γ���
	{
		linked_trap = t;
	}
	void Button::LoadBitmap()//���J�ϧ�
	{
		button.LoadBitmap(IDB_BUTTON, RGB(255, 255, 255));
	}
	bool Button::GetTrapT() {//���o����������
		return linked_trap->GetTrigger();
	}
	bool Button::trigger(int nx, int ny) {//�Y���F��b�W���NĲ�o
		if (nx == px && ny == py) {
			triggered = true;
			linked_trap->trigger(true);
			return TRUE;
		}
		triggered = false;
		linked_trap->trigger(false);
		return FALSE;
	}
	void Button::OnMove()//���
	{
		button.SetTopLeft(x, y);
		button.ShowBitmap();
	}
	void Button::Restart(int level)//�]�w��l��m
	{
		triggered = false;
		if (level == 4) {
			px = 6;
			py = 3;
			x = px * 70 + 315;
			y = py * 70 + 195;
		}
		if (level == 6) {
			px = 6;
			py = 3;
			x = px * 70 + 315;
			y = py * 70 + 195;
		}
		if (level == 8) {
			px = 6;
			py = 3;
			x = px * 70 + 315;
			y = py * 70 + 195;
		}
	}
	void Button::SetXY()//�]�wxy��
	{
		x = px * 70 + 315;
		y = py * 70 + 195;
	}
	void Button::SetPos(int nx, int ny) {//�]�w�L���y��
		px = nx;
		py = ny;
		x = px * 70 + 315;
		y = py * 70 + 195;

	}
	void Button::OnShow()//���
	{
		button.SetTopLeft(x, y);
		button.ShowBitmap();
	}
}