namespace game_framework {
	class Pipe
	{
	public:
		Pipe();
		void LoadBitmap();										// ���J�ϧ�
		void OnMove();											// ����
		void OnShow();											// �N�ϧζK��e��
		void SetPos(int nx, int ny);							// �]�w���a�y��
	protected:
		CAnimation pipe;
		int x, y;												// �Ϲ���m
	private:
		int px, py;												// ����y��
	};
}