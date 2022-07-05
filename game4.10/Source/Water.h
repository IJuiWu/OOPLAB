namespace game_framework {
	class Water 
	{
	public:
		Water();
		void LoadBitmap();										// ���J�ϧ�
		void OnMove();											// ����
		void OnShow();											// �N�ϧζK��e��
		void SetPos(int nx, int ny);							// �]�w����y��
		bool HitBox(int nx, int ny);							// �O�_��Ĳ�c�l
		void SetIsAlive(bool alive);							// �O�_�s�b�a�ϤW
		int GetPx();											// �^��x�y��
		int GetPy();											// �^��y�y��
		bool HitPlayer(int nx, int ny);							// �O�_��Ĳ���a
	protected:
		CMovingBitmap water;
		bool is_alive;
	private:
		int px;
		int py;
		int x;
		int y;
	};
}