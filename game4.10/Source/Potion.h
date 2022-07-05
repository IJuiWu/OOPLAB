namespace game_framework {
	class Potion
	{
	public:
		Potion();
		bool IsAlive();											// �O�_�s�b�a�ϤW
		void LoadBitmap();										// ���J�ϧ�
		void OnMove();											// ����
		void OnShow();											// �N�ϧζK��e��
		void SetXY(int nx, int ny);											// �]�w�Ϲ���m
		void SetIsAlive(bool alive);							// �]�w�O�_����
		void SetPos(int nx, int ny);							// �]�w���a�y��
		bool hitplayer(int nx, int ny);							// �O�_��Ĳ���a
		bool hitslime(int nx, int ny,Slime* s);					// �O�_��Ĳ�v�ܩi
		int GetPx();											// �^��x�y��
		int GetPy();											// �^��y�y��
		void Release();											// �����Ĥ�
		bool isGrabbed();										// �O�_�Q�֦�
	protected:
		CMovingBitmap potion;			
		int x, y;				
		bool is_alive;											// �O�_�s�b�a�ϤW
		bool is_got;											// �O�_�Q�֦�
	private:
		int px, py;												// ����y��
		Slime* slime_eaten;
	};
}