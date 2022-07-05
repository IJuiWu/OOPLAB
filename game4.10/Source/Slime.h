namespace game_framework {
	class Slime 
	{
	public:
		Slime();
		bool HitWater(Water* w,int heading);					// �O�_���J����
		void LoadBitmap();										// ���J�ϧ�
		void OnMove();											// ����
		void OnShow();											// �N�ϧζK��e��
		void SetXY(int nx, int ny);								// �]�w�Ϲ���m
		void SetIsAlive(bool alive);							// �]�w�O�_����		
		int FindPlayer(Player* player);							// �M�䪱�a��V
		void SetPos(int nx, int ny);							// �]�w����y��
		void Move(int dir);										// ����
		int GetX();												// �^��x�y��
		int GetY();												// �^��y�y��
		void Change_Color(string c);							// �ܴ��C��
		bool HitPlayer(Player* player);							// �O�_��Ĳ���a
		bool IsGreen();											// �O�_�����
		void Shock();											// �w�t�v�ܩi
		bool IsShock();											// �O�_���w�t���A
		bool IsAlive();											// �O�_�s��
	protected:
		CAnimation slime,redslime,blueslime ;
		CMovingBitmap num_shock1, num_shock2, num_shock3;
		int x, y;						
		bool is_alive;				
	private:
		int shock_count = 0;									// �w�t�˭p��
		bool is_shock = false;
		int px, py;
		string color = "green";
	};
}