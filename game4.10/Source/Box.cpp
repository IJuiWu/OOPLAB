#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Water.h"
#include "Box.h"
namespace game_framework {
	Box::Box()//��l��
	{
		is_alive = true;
		isGrabbed = false;
		x = y = dx = dy = px = py = 0;
	}
	bool Box::NextToPlayer(int nx, int ny) {//�P�_�Ӧ�m�ϧ_���b�c�l���W�U���k
		if (!is_alive) {
			return FALSE;
		};
		if (nx == px && ny == py + 1) {
			return TRUE;
		}
		else if (nx == px && ny == py - 1) {
			return TRUE;
		}
		else if (nx == px + 1 && ny == py) {
			return TRUE;
		}
		else if (nx == px - 1 && ny == py) {
			return TRUE;
		}
		return FALSE;
	}
	void Box::GrabByPlayer() {//���a�߰_�c�l
		if (!isGrabbed) {
			isGrabbed = true;
		}
	}
	void Box::ThrowByPlayer() {//���a��X�c�l
		if (isGrabbed) {
			isGrabbed = false;
		}
	}
	bool Box::hitplayer(int nx, int ny) { //�Y���F��I��c�l�A�B�L�S���Q�߰_�өί}�a�A�N�^��true
		if(!is_alive || isGrabbed){
			return FALSE;
		};
		if (nx == px && ny == py) {
			return TRUE;
		}
		return FALSE;
	}
	int Box::GetPx() {//�^�ǽc�l���y��px
		return px;
	}
	int Box::GetPy() {//�^�ǽc�l���y��py
		return py;
	}
	bool Box::HitWater(Water* w,int heading)//�Y�O�c�l�Q���i���̡A�}�a���νc�l�A�æ^��true
	{	
		if (heading == 0) {
			if (w->HitBox(px-1, py)) {
				is_alive = false;
				w->SetIsAlive(false);
				return true;
			}
		}
		if (heading == 1) {
			if (w->HitBox(px+1, py)) {
				is_alive = false;
				w->SetIsAlive(false);
				return true;
			}
		}
		if (heading == 2) {
			if (w->HitBox(px, py - 1)) {
				is_alive = false;
				w->SetIsAlive(false);
				return true;
			}
		}
		if (heading == 3) {
			if (w->HitBox(px, py+1)) {
				is_alive = false;
				w->SetIsAlive(false);
				return true;
			}
		}
		return false;
	}
	bool Box::ThrowOnWater(Water* w) {//�Y�O�c�l�Q�����W�A�N�}�a���
		if (w->GetPx() == px && w->GetPy() == py) {
			is_alive = false;
			w->SetIsAlive(false);
			return true;
		}
		else {
			return false;
		}
	}
	bool Box::HitSTH(int nx, int ny) {//�P�_�c�l����m�O�_�P��J�����|
		if (nx == px && ny == py) {
			is_alive = false;
			return true;
		}
		return false;
	}
	void Box::SetPos(int nx, int ny) {//�]�w�c�l���y�СA���ഫ�������y��xy
		px = nx;
		py = ny;
		x = px * 70+315;
		y = py * 70+195;
	}
	bool Box::IsAlive()//���o�c�l�O�_���Q�}�a
	{
		return is_alive;
	}
	bool Box::IsGrabbed()//�^�ǬO�_���Q�쨫
	{
		return isGrabbed;
	}
	void Box::LoadBitmap()
	{
		box.LoadBitmap(IDB_BOX, RGB(255, 255, 255));			
	}

	void Box::OnMove()//�Y���Q�쨫�γQ�}�a�N�����
	{
		if (!is_alive || isGrabbed)
			return;
		box.SetTopLeft(x, y);
		box.ShowBitmap();
	}
	void Box::SetIsAlive(bool alive)//�]�w�c�l�O�_�Q�}�a
	{
		is_alive = alive;
	}
	void Box::SetXY(int nx, int ny)//�]�w�c�l��xy�y��
	{
		x = nx; y = ny;
	}
	void Box::OnShow()//�Y���Q�쨫�γQ�}�a�N�����
	{
		if (!is_alive || isGrabbed)
			return;
		box.SetTopLeft(x, y);
		box.ShowBitmap();
	}
}