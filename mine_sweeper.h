#include "init.h"

#define FIRST_MENU  1
#define SECOND_MENU 2
#define THIRD_MENU  3

#define EASY   1
#define NORMAL 2
#define HARD   3
#define CUSTO  4

class Map;

class GameManager
{
private:
	SDL_Texture * minepic1;
	SDL_Texture * flagpic;
	SDL_Texture * Qpic;
	SDL_Rect alpha_rect;
	SDL_Rect Num_rect;
	bool BackWard;
	bool EndFlag;
	int Menu_Level; //���� ��� �޴��� ��ġ���� �˷��ִ� ����
	int Game_Level; //������ ���ӷ����� �˷��ִ� ����
	int num[10][25]; //���ڸ� ���� �迭

	int success_count; // ����Ȯ�� ���� ��� �����̰� �̰� ��ü�������� ���ڸ� �A ���� �������� ����Ŭ����

	int first_click; //������ ������ �� ó�� Ŭ������ �� ������ 0�� �������� �ϱ����� ���� ����

	bool End_Flag_Game_Play_Fuct; //game play fuct �Լ��� Ż���ϱ����� �÷���

	int hang;
	int yeol;
	int minenum;
	int game_time; //���������ϸ鼭 �Ϸ�Ǳ���� ����� �ð��� ���

public:

	GameManager() { BackWard = false; EndFlag = false; Menu_Level = FIRST_MENU; End_Flag_Game_Play_Fuct = false; success_count = 0; first_click = 0; }

	void GM_Init();

	void load_minepic();

	void render_minepic();

	void Print_Word(char * ptr, int start_xpos, int start_ypos, int r, int g, int b, int font_size); //�ܾ� ���

	void Print_Alpha(int num, int start_xpos, int start_ypos, int r, int g, int b, int font_size); //���ڷ� ���� ���ĺ� �ϳ� ���

	void Print_Num(int num, int start_xpos, int start_ypos, int r, int g, int b, int font_size); //���ڷ� ���� ���� �ϳ� ���

	void Print_Score(int score, int start_xpos, int start_ypos, int r, int g, int b, int font_size);

	void Main_Menu_Fuct(); //���θ޴��� �Ѱ��ϴ� �Լ�

	void Select_Level_Fuct(); //START ���� �� ���̵� �����ϴ� �Լ�

	void Game_Play_Fuct(); //���� ������ �����ϴ� �Լ�

	void Input_Custo(); //Ŀ���͸������� �� ����ڿ��� �Է¹޴� �Լ�

	int Cursor_BOX_check(SDL_Rect * BOX_rect); //Ŀ���� BOX���� �ȿ� �ִ��� üũ

	bool Get_BackWard() { return BackWard; }

	bool Get_EndFlag() { return EndFlag; }

	int Get_Menu_Level() { return Menu_Level; }

	int Get_Game_Level() { return Game_Level; }

	int Get_Hang() { return hang; }

	int Get_Yeol() { return yeol; }

	void generate_mine(Map ** mmap); //���� �����ϴ� �Լ�

	int mine_find(Map ** mmap,int hx,int yx); //Ŀ���� ��ġ�ϴ� ���� �����ִ��� ã�� �Լ�

	int count_around_num(Map ** mmap,int hx,int yx); //�ش� �� �ֺ��� ���ڰ� �� �� �ִ��� ã�� �Լ�

	void Game_End_Manage(Map ** mmap); //������ Ŭ����ǵ� ���ڹ�Ƽ� ������ ������ �� �ٸ� �Է��� ��ٸ��� �Լ�


};

class Map
{
private:
	int xpos;
	int ypos;
	int mine; //�� ���� �ʿ� ���ڰ� �ִ��� ����
	int check; //�� ���� ���� üũ�ߴ��� ����
	int cursor_now; // ���� ���� �� ���� Ŀ���� �ִ��� ����
	int flag;

	int mine_around_num; //�ڱ� �ֺ� ���ڰ��� ����

	friend GameManager;
public:
	
	Map() 
	{
		mine = 0; check = 0; cursor_now = 0; flag = 0; mine_around_num = 0;
	}

	int Get_mine() { return mine; }

	int Get_check() { return check; }

};
