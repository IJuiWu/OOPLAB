#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <windows.h>
#include "Door.h"
#include "Water.h"
#include "Player.h"
#include "Slime.h"
#include "Key.h"
namespace game_framework {
	Key::Key()
	{
	}
	void Key::Link(Door* d)//�s���_�ͻP��
	{
		linked_door = d;
	}
	void Key::LoadBitmap()//���J�귽
	{
		key.LoadBitmap(IDB_KEY, RGB(255, 255, 255));
	}
	void Key::Release() {//��X�_��
		got = false;
	}
	int Key::Getpx() {//�^��px�y��
		return px;
	}
	void Key::Eaten(Slime* s) {//�P�_���S���Q�v�ܩi�Y���A�Y�O�v�ܩi���`�h�|�R�X��
		if (!is_eaten && s->IsAlive()) {
			eaten_slime = s;
			got = true;
			is_eaten = true;
			return;
		}
		else if(is_eaten){
			if (eaten_slime->IsAlive() == false) {
				is_eaten = false;
				got = false;
				return;
			}
		}
	};
	int Key::Getpy() {//���opy�y��
		return py;
	}
	bool Key::WasGotByPlayer() {
		return by_player;
	}
	bool Key::PlayerGet(int nx, int ny) {//���a���o�_��
		if (got && !is_eaten) {
			SetPos(nx, ny);
			return false;
		}
		if (!is_eaten && !got && nx == px && ny == py) {
			got = true;
			by_player = true;
			return TRUE;
		}
		if (is_eaten) {
			return FALSE;
		}
		return FALSE;
	}
	bool Key::WasGot() {//�^�ǬO�_���Q�ߨ�
		return got;
	}
	bool Key::SlimeRelease(Slime* s) {
		if (s->IsAlive() == false && s == eaten_slime) {
			return true;
		}
		else {
			return false;
		}
	}
	bool Key::SlimeGet(int nx, int ny, Slime* s) {//�v�ܩi���o�_��
		if (got && is_eaten && s == eaten_slime) {
			SetPos(nx, ny);
			return false;
		}
		if (nx == px && ny == py && !is_eaten && !got) {
			eaten_slime = s;
			got = true;
			TRACE("got:%d",got);
			return TRUE;
		}
		return FALSE;
	}
	void Key::OnMove()//��ܡA�Q�ߨ��N�����
	{
		if (!got) {
			key.SetTopLeft(x, y);
			key.ShowBitmap();
		}
	}
	void Key::Restart(int level)//���m�Ѽ�
	{
		got = false;
	}
	void Key::SetXY()//�]�wxy��
	{
		x = px * 70 + 315;
		y = py * 70 + 195;
	}
	void Key::SetPos(int nx, int ny) {//�]�w�y��
		px = nx;
		py = ny;
		x = px * 70 + 315;
		y = py * 70 + 195;
	}
	void Key::OnShow()//��ܡA�Q�ߨ������
	{
		if (!got) { 
			key.SetTopLeft(x, y);
			key.ShowBitmap();
		}
	}
}