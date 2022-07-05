#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <windows.h>
#include "Pipe.h"
namespace game_framework {
	Pipe::Pipe()//��l��
	{
		x = y = px = py =  0;
		pipe.SetDelayCount(4);
	}
	void Pipe::LoadBitmap()//���J�Ϥ��귽
	{
		char* pipefiles[5] = { ".\\img\\pipe1.bmp",".\\img\\pipe2.bmp",".\\img\\pipe3.bmp",".\\img\\pipe4.bmp",".\\img\\pipe5.bmp" };
		for (int i = 0; i < 5; i++)	// ���J�ʵe(��5�i�ϧκc��)
			pipe.AddBitmap(pipefiles[i], RGB(255, 255, 255));
	}
	void Pipe::OnMove()//����ʵe
	{
		pipe.SetTopLeft(x, y);
		pipe.OnMove();
	}
	void Pipe::SetPos(int nx, int ny) {//�]�w�y��
		px = nx;
		py = ny;
		x = px * 70 + 315;
		y = py * 70 + 240;
	}
	void Pipe::OnShow()//�ھڪ��a��V���񤣦P�ʵe
	{
		pipe.SetTopLeft(x, y);
		pipe.OnShow();
	}
}