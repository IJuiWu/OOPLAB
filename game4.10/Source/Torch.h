namespace game_framework {
	class Torch
	{
	public:
		Torch();
		void LoadBitmap();										// ���J�ϧ�
		void OnMove();											// ����
		void OnShow();											// �N�ϧζK��e��
		void SetPos(int nx, int ny);							// �]�w���a�y��
	protected:
		CAnimation torch;
		int x, y;												// �Ϲ���m
	private:
		int px, py;												// ����y��
	};
}