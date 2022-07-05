#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Player.h"
#include <windows.h>
namespace game_framework {
	Player::Player()//��l��
	{
		is_alive = true;
		x = y = 0;
		heading = 0;
	}
	bool Player::IsAlive()//�^�Ǫ��a�O�_����
	{
		return is_alive;
	}
	void Player::LoadBitmap()//���J�Ϥ��귽
	{
		char* leftfiles[4] = { ".\\img\\player_alive_left_1.bmp",".\\img\\player_alive_left_2.bmp",".\\img\\player_alive_left_3.bmp",".\\img\\player_alive_left_4.bmp" };
		char* rightfiles[4] = { ".\\img\\player_alive_right_1.bmp",".\\img\\player_alive_right_2.bmp",".\\img\\player_alive_right_3.bmp",".\\img\\player_alive_right_4.bmp" };
		char* upfiles[2] = { ".\\img\\player_alive_up_1.bmp",".\\img\\player_alive_up_2.bmp"};
		for (int i = 0; i < 4; i++)	// ���J�ʵe(��4�i�ϧκc��)
			left.AddBitmap(leftfiles[i], RGB(255, 255, 255));
		for (int i = 0; i < 4; i++)	// ���J�ʵe(��4�i�ϧκc��)
			right.AddBitmap(rightfiles[i], RGB(255, 255, 255));
		for (int i = 0; i < 2; i++)	// ���J�ʵe(��4�i�ϧκc��)
			up.AddBitmap(upfiles[i], RGB(255, 255, 255));
		die.LoadBitmap(IDB_PLAYER_DEAD_LEFT, RGB(255, 255, 255));
	}
	void Player::SetHeading(int h) {//�]�w��V
		heading = h;
	}
	bool Player::HitMonster(int nx,int ny) {//�P�_���a�O�_�I��Ǫ�
		if (nx == px && ny == py) {
			is_alive = false;
			return true;
		}
		return false;
	}
	void Player::OnMove()//�̷Ӫ��a����V����ʵe
	{
		if (!is_alive) {
			die.SetTopLeft(x, y);
			die.ShowBitmap();
			return;
		}
		if (heading == 0) {
			left.SetTopLeft(x,y);
			left.OnMove();
		}
		else if (heading == 2) {
			up.SetTopLeft(x, y);
			up.OnMove();
		}
		else {
			right.SetTopLeft(x, y);
			right.OnMove();
		}
	}
	void Player::SetDelay(int d)//�]�w���a�ʵe�t��
	{
		delay = d;
	}
	int Player::GetX()//���o���a��x��
	{
		return  px;
	}
	int Player::GetY()//�������a��y��
	{
		return  py;
	}
	void Player::SetIsAlive(bool alive)//�]�w���a�O�_���`
	{
		is_alive = alive;
	}
	void Player::SetXY()//�]�w���a��xy�y��
	{
		if (!is_alive) {
			return;
		}
		x = px * 70 + 315; 
		y = py * 70 + 175;
	}
	void Player::SetPos(int nx, int ny) {//�]�w���a���y��
		if (!is_alive) {
			return;
		}
		px = nx ;
		py = ny ;
		x = px * 70 + 315;
		y = py * 70 + 175;
	}
	void Player::Restart(int level)//�]�w���a�_�l��m
	{
		heading = 0;
		is_alive = true;
		if (level == 1) {
			px = 1;
			py = 3;
			x = px * 70 + 315;
			y = py * 70 + 175;
		}
		else if (level == 2) {
			px = 1;
			py = 3;
			x = px * 70 + 315;
			y = py * 70 + 175;
		}
		else if (level >= 3) {
			px = 5;
			py = 1;
			x = px * 70 + 315;
			y = py * 70 + 175;
		}
	}
	void Player::Reset()//�]�w���a����l��
	{
		is_alive = true;
		x = y = px = py = 0;
		heading = 0;
		left.SetDelayCount(5);
		right.SetDelayCount(5);
		up.SetDelayCount(5);
	}
	void Player::OnShow()//�ھڪ��a��V���񤣦P�ʵe
	{
		if (!is_alive){
			die.SetTopLeft(x, y);
			die.ShowBitmap();
			return;
		}
		if(heading == 0) {
			left.SetTopLeft(x, y);
			left.OnShow();
		}
		else if (heading == 2) {
			up.SetTopLeft(x, y);
			up.OnShow();
		}
		else {
			right.SetTopLeft(x, y);
			right.OnShow();
		}
	}
}