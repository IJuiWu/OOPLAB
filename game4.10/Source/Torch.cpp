#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <windows.h>
#include "Torch.h"
namespace game_framework {
	Torch::Torch()//��l��
	{
		x = y = px = py = 0;
		torch.SetDelayCount(5);
	}
	void Torch::LoadBitmap()//���J�Ϥ��귽
	{
		char* torchfiles[3] = { ".\\img\\torch1.bmp",".\\img\\torch2.bmp",".\\img\\torch3.bmp" };
		for (int i = 0; i < 3; i++)	// ���J�ʵe(��3�i�ϧκc��)
			torch.AddBitmap(torchfiles[i], RGB(255, 255, 255));
	}
	void Torch::OnMove()//����ʵe
	{
		torch.SetTopLeft(x, y);
		torch.OnMove();
	}
	void Torch::SetPos(int nx, int ny) {//�]�w�y��
		px = nx;
		py = ny;
		x = px * 70 + 315;
		y = py * 70 + 190;
	}
	void Torch::OnShow()//�ھڪ��a��V���񤣦P�ʵe
	{
		torch.SetTopLeft(x, y);
		torch.OnShow();
	}
}