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
	int Menu_Level; //현재 어느 메뉴에 위치한지 알려주는 변수
	int Game_Level; //선택한 게임레벨을 알려주는 변수
	int num[10][25]; //숫자를 담을 배열

	int success_count; // 지뢰확인 수를 담는 변수이고 이게 전체영역에서 지뢰를 뺸 수와 같아지면 게임클리어

	int first_click; //게임을 시작할 때 처음 클릭했을 때 무조건 0이 나오도록 하기위해 만든 변수

	bool End_Flag_Game_Play_Fuct; //game play fuct 함수를 탈출하기위한 플래그

	int hang;
	int yeol;
	int minenum;
	int game_time; //게임진행하면서 완료되기까지 경과된 시간을 담기

public:

	GameManager() { BackWard = false; EndFlag = false; Menu_Level = FIRST_MENU; End_Flag_Game_Play_Fuct = false; success_count = 0; first_click = 0; }

	void GM_Init();

	void load_minepic();

	void render_minepic();

	void Print_Word(char * ptr, int start_xpos, int start_ypos, int r, int g, int b, int font_size); //단어 출력

	void Print_Alpha(int num, int start_xpos, int start_ypos, int r, int g, int b, int font_size); //인자로 받은 알파벳 하나 출력

	void Print_Num(int num, int start_xpos, int start_ypos, int r, int g, int b, int font_size); //인자로 받은 숫자 하나 출력

	void Print_Score(int score, int start_xpos, int start_ypos, int r, int g, int b, int font_size);

	void Main_Menu_Fuct(); //메인메뉴를 총괄하는 함수

	void Select_Level_Fuct(); //START 누른 후 난이도 관리하는 함수

	void Game_Play_Fuct(); //게임 진행을 관리하는 함수

	void Input_Custo(); //커스터마이즈일 때 사용자에게 입력받는 함수

	int Cursor_BOX_check(SDL_Rect * BOX_rect); //커서가 BOX영역 안에 있는지 체크

	bool Get_BackWard() { return BackWard; }

	bool Get_EndFlag() { return EndFlag; }

	int Get_Menu_Level() { return Menu_Level; }

	int Get_Game_Level() { return Game_Level; }

	int Get_Hang() { return hang; }

	int Get_Yeol() { return yeol; }

	void generate_mine(Map ** mmap); //마인 생성하는 함수

	int mine_find(Map ** mmap,int hx,int yx); //커서가 위치하는 곳에 마인있는지 찾는 함수

	int count_around_num(Map ** mmap,int hx,int yx); //해당 맵 주변에 지뢰가 몇 개 있는지 찾는 함수

	void Game_End_Manage(Map ** mmap); //게임이 클리어되든 지뢰밟아서 끝나든 끝났을 때 다른 입력을 기다리는 함수


};

class Map
{
private:
	int xpos;
	int ypos;
	int mine; //그 단위 맵에 지뢰가 있는지 유무
	int check; //그 단위 맵을 체크했는지 유무
	int cursor_now; // 현재 단위 맵 위에 커서가 있는지 유무
	int flag;

	int mine_around_num; //자기 주변 지뢰개수 저장

	friend GameManager;
public:
	
	Map() 
	{
		mine = 0; check = 0; cursor_now = 0; flag = 0; mine_around_num = 0;
	}

	int Get_mine() { return mine; }

	int Get_check() { return check; }

};
