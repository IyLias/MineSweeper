#include "mine_sweeper.h"

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

int alphabet[27][25] = {

	{ 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0 },

	{ 1, 1, 1, 1, 1,
	1, 0, 0, 0, 1,
	1, 1, 1, 1, 1,
	1, 0, 0, 0, 1,
	1, 0, 0, 0, 1 },

	{ 1, 1, 1, 1, 1,
	1, 0, 0, 0, 1,
	1, 1, 1, 1, 1,
	1, 0, 0, 0, 1,
	1, 1, 1, 1, 1 },

	{ 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0,
	1, 0, 0, 0, 0,
	1, 0, 0, 0, 0,
	1, 1, 1, 1, 1 },

	{ 1, 1, 1, 1, 0,
	1, 0, 0, 0, 1,
	1, 0, 0, 0, 1,
	1, 0, 0, 0, 1,
	1, 1, 1, 1, 0 },

	{ 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0,
	1, 1, 1, 1, 1,
	1, 0, 0, 0, 0,
	1, 1, 1, 1, 1 },

	{ 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0,
	1, 1, 1, 1, 1,
	1, 0, 0, 0, 0,
	1, 0, 0, 0, 0 },

	{ 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0,
	1, 0, 1, 1, 1,
	1, 0, 0, 0, 1,
	1, 1, 1, 1, 1 },

	{ 1, 0, 0, 0, 1,
	1, 0, 0, 0, 1,
	1, 1, 1, 1, 1,
	1, 0, 0, 0, 1,
	1, 0, 0, 0, 1 },

	{ 0, 1, 1, 1, 0,
	0, 0, 1, 0, 0,
	0, 0, 1, 0, 0,
	0, 0, 1, 0, 0,
	0, 1, 1, 1, 0 },

	{ 0, 1, 1, 1, 0,
	0, 0, 1, 0, 0,
	1, 0, 1, 0, 0,
	0, 1, 1, 0, 0,
	0, 0, 1, 0, 0 },

	{ 1, 0, 0, 1, 0,
	1, 0, 1, 0, 0,
	1, 1, 0, 0, 0,
	1, 0, 1, 0, 0,
	1, 0, 0, 1, 0 },

	{ 1, 0, 0, 0, 0,
	1, 0, 0, 0, 0,
	1, 0, 0, 0, 0,
	1, 0, 0, 0, 0,
	1, 1, 1, 1, 1 },

	{ 1, 0, 0, 0, 1,
	1, 1, 0, 1, 1,
	1, 0, 1, 0, 1,
	1, 0, 0, 0, 1,
	1, 0, 0, 0, 1 },

	{ 1, 0, 0, 0, 1,
	1, 1, 0, 0, 1,
	1, 0, 1, 0, 1,
	1, 0, 0, 1, 1,
	1, 0, 0, 0, 1 },

	{ 0, 1, 1, 1, 0,
	1, 0, 0, 0, 1,
	1, 0, 0, 0, 1,
	1, 0, 0, 0, 1,
	0, 1, 1, 1, 0 },

	{ 1, 1, 1, 1, 1,
	1, 0, 0, 0, 1,
	1, 1, 1, 1, 1,
	1, 0, 0, 0, 0,
	1, 0, 0, 0, 0 },

	{ 1, 1, 1, 1, 1,
	1, 0, 0, 0, 1,
	1, 0, 1, 0, 1,
	1, 0, 0, 1, 1,
	1, 1, 1, 1, 1 },

	{ 1, 1, 1, 1, 1,
	1, 0, 0, 0, 1,
	1, 1, 1, 1, 1,
	1, 0, 0, 1, 0,
	1, 0, 0, 0, 1 },

	{ 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0,
	1, 1, 1, 1, 1,
	0, 0, 0, 0, 1,
	1, 1, 1, 1, 1 },

	{ 1, 1, 1, 1, 1,
	0, 0, 1, 0, 0,
	0, 0, 1, 0, 0,
	0, 0, 1, 0, 0,
	0, 0, 1, 0, 0 },

	{ 1, 0, 0, 0, 1,
	1, 0, 0, 0, 1,
	1, 0, 0, 0, 1,
	1, 0, 0, 0, 1,
	1, 1, 1, 1, 1 },

	{ 1, 0, 0, 0, 1,
	1, 0, 0, 0, 1,
	1, 0, 0, 0, 1,
	0, 1, 0, 1, 0,
	0, 0, 1, 0, 0 },

	{ 1, 0, 0, 0, 1,
	1, 0, 0, 0, 1,
	1, 0, 1, 0, 1,
	1, 1, 0, 1, 1,
	1, 0, 0, 0, 1 },

	{ 1, 0, 0, 0, 1,
	0, 1, 0, 1, 0,
	0, 0, 1, 0, 0,
	0, 1, 0, 1, 0,
	1, 0, 0, 0, 1 },

	{ 1, 0, 0, 0, 1,
	0, 1, 0, 1, 0,
	0, 0, 1, 0, 0,
	0, 0, 1, 0, 0,
	0, 0, 1, 0, 0 },

	{ 1, 1, 1, 1, 1,
	0, 0, 0, 1, 0,
	0, 0, 1, 0, 0,
	0, 1, 0, 0, 0,
	1, 1, 1, 1, 1 }

};

void GameManager::GM_Init()
{

	num[0][0] = 1; num[0][1] = 1; num[0][2] = 1; num[0][3] = 1; num[0][4] = 1;
	num[0][5] = 1; num[0][6] = 0; num[0][7] = 0; num[0][8] = 0; num[0][9] = 1;
	num[0][10] = 1; num[0][11] = 0; num[0][12] = 0; num[0][13] = 0; num[0][14] = 1;
	num[0][15] = 1; num[0][16] = 0; num[0][17] = 0; num[0][18] = 0; num[0][19] = 1;
	num[0][20] = 1; num[0][21] = 1; num[0][22] = 1; num[0][23] = 1; num[0][24] = 1;

	num[1][0] = 0; num[1][1] = 0; num[1][2] = 1; num[1][3] = 0; num[1][4] = 0;
	num[1][5] = 0; num[1][6] = 1; num[1][7] = 1; num[1][8] = 0; num[1][9] = 0;
	num[1][10] = 0; num[1][11] = 0; num[1][12] = 1; num[1][13] = 0; num[1][14] = 0;
	num[1][15] = 0; num[1][16] = 0; num[1][17] = 1; num[1][18] = 0; num[1][19] = 0;
	num[1][20] = 0; num[1][21] = 1; num[1][22] = 1; num[1][23] = 1; num[1][24] = 0;

	num[2][0] = 1; num[2][1] = 1; num[2][2] = 1; num[2][3] = 1; num[2][4] = 1;
	num[2][5] = 0; num[2][6] = 0; num[2][7] = 0; num[2][8] = 0; num[2][9] = 1;
	num[2][10] = 1; num[2][11] = 1; num[2][12] = 1; num[2][13] = 1; num[2][14] = 1;
	num[2][15] = 1; num[2][16] = 0; num[2][17] = 0; num[2][18] = 0; num[2][19] = 0;
	num[2][20] = 1; num[2][21] = 1; num[2][22] = 1; num[2][23] = 1; num[2][24] = 1;

	num[3][0] = 1; num[3][1] = 1; num[3][2] = 1; num[3][3] = 1; num[3][4] = 1;
	num[3][5] = 0; num[3][6] = 0; num[3][7] = 0; num[3][8] = 0; num[3][9] = 1;
	num[3][10] = 0; num[3][11] = 1; num[3][12] = 1; num[3][13] = 1; num[3][14] = 1;
	num[3][15] = 0; num[3][16] = 0; num[3][17] = 0; num[3][18] = 0; num[3][19] = 1;
	num[3][20] = 1; num[3][21] = 1; num[3][22] = 1; num[3][23] = 1; num[3][24] = 1;

	num[4][0] = 1; num[4][1] = 0; num[4][2] = 0; num[4][3] = 0; num[4][4] = 1;
	num[4][5] = 1; num[4][6] = 0; num[4][7] = 0; num[4][8] = 0; num[4][9] = 1;
	num[4][10] = 1; num[4][11] = 1; num[4][12] = 1; num[4][13] = 1; num[4][14] = 1;
	num[4][15] = 0; num[4][16] = 0; num[4][17] = 0; num[4][18] = 0; num[4][19] = 1;
	num[4][20] = 0; num[4][21] = 0; num[4][22] = 0; num[4][23] = 0; num[4][24] = 1;

	num[5][0] = 1; num[5][1] = 1; num[5][2] = 1; num[5][3] = 1; num[5][4] = 1;
	num[5][5] = 1; num[5][6] = 0; num[5][7] = 0; num[5][8] = 0; num[5][9] = 0;
	num[5][10] = 1; num[5][11] = 1; num[5][12] = 1; num[5][13] = 1; num[5][14] = 1;
	num[5][15] = 0; num[5][16] = 0; num[5][17] = 0; num[5][18] = 0; num[5][19] = 1;
	num[5][20] = 1; num[5][21] = 1; num[5][22] = 1; num[5][23] = 1; num[5][24] = 1;

	num[6][0] = 1; num[6][1] = 1; num[6][2] = 1; num[6][3] = 1; num[6][4] = 1;
	num[6][5] = 1; num[6][6] = 0; num[6][7] = 0; num[6][8] = 0; num[6][9] = 0;
	num[6][10] = 1; num[6][11] = 1; num[6][12] = 1; num[6][13] = 1; num[6][14] = 1;
	num[6][15] = 1; num[6][16] = 0; num[6][17] = 0; num[6][18] = 0; num[6][19] = 1;
	num[6][20] = 1; num[6][21] = 1; num[6][22] = 1; num[6][23] = 1; num[6][24] = 1;

	num[7][0] = 1; num[7][1] = 1; num[7][2] = 1; num[7][3] = 1; num[7][4] = 1;
	num[7][5] = 1; num[7][6] = 0; num[7][7] = 0; num[7][8] = 0; num[7][9] = 1;
	num[7][10] = 1; num[7][11] = 0; num[7][12] = 0; num[7][13] = 0; num[7][14] = 1;
	num[7][15] = 0; num[7][16] = 0; num[7][17] = 0; num[7][18] = 0; num[7][19] = 1;
	num[7][20] = 0; num[7][21] = 0; num[7][22] = 0; num[7][23] = 0; num[7][24] = 1;

	num[8][0] = 1; num[8][1] = 1; num[8][2] = 1; num[8][3] = 1; num[8][4] = 1;
	num[8][5] = 1; num[8][6] = 0; num[8][7] = 0; num[8][8] = 0; num[8][9] = 1;
	num[8][10] = 1; num[8][11] = 1; num[8][12] = 1; num[8][13] = 1; num[8][14] = 1;
	num[8][15] = 1; num[8][16] = 0; num[8][17] = 0; num[8][18] = 0; num[8][19] = 1;
	num[8][20] = 1; num[8][21] = 1; num[8][22] = 1; num[8][23] = 1; num[8][24] = 1;

	num[9][0] = 1; num[9][1] = 1; num[9][2] = 1; num[9][3] = 1; num[9][4] = 1;
	num[9][5] = 1; num[9][6] = 0; num[9][7] = 0; num[9][8] = 0; num[9][9] = 1;
	num[9][10] = 1; num[9][11] = 1; num[9][12] = 1; num[9][13] = 1; num[9][14] = 1;
	num[9][15] = 0; num[9][16] = 0; num[9][17] = 0; num[9][18] = 0; num[9][19] = 1;
	num[9][20] = 1; num[9][21] = 1; num[9][22] = 1; num[9][23] = 1; num[9][24] = 1;


}

void GameManager::load_minepic()
{
	minepic1 = loadTexture("repos//mine1.png", gRenderer);
	flagpic = loadTexture("repos//flag.jpg", gRenderer);
	Qpic = loadTexture("repos//Q.jpg", gRenderer);

}

void GameManager::render_minepic()
{
	SDL_Rect mine1_rect; 
	mine1_rect.x = 80, mine1_rect.y = 150;
	mine1_rect.w = 100, mine1_rect.h = 100;
	SDL_RenderCopy(gRenderer, minepic1, NULL, &mine1_rect);

	mine1_rect.x = 400, mine1_rect.y = 300;
	SDL_RenderCopy(gRenderer, minepic1, NULL, &mine1_rect);

}

void GameManager::Print_Num(int number, int start_xpos, int start_ypos, int r, int g, int b, int font_size) //인자로 받은 숫자 하나 출력
{
	int i;
	int x = start_xpos;
	Num_rect.w = font_size;
	Num_rect.h = font_size;

	for (i = 0; i < 25; i++)
	{
		if (i % 5 == 0)
			Num_rect.y = start_ypos + font_size * (i / 5);

		x = start_xpos + font_size * (i % 5);
		Num_rect.x = x;

		if (num[number][i])
		{
			SDL_SetRenderDrawColor(gRenderer, r, g, b, 255);
			SDL_RenderFillRect(gRenderer, &Num_rect);
		}

	}

	Num_rect.y = start_ypos;

}

void GameManager::Print_Score(int score, int start_xpos, int start_ypos, int r, int g, int b, int font_size)
{
	int i = 0, j = 1,tem=score;
	int arr[32] = { 0, }; //인자로 받은 숫자를 배열로 옮김
	Num_rect.y = start_ypos;
	Num_rect.w = font_size;
	Num_rect.h = font_size;

	while (tem)
	{
		arr[31 - i] = tem % 10;
		tem /= 10;
		i++;
	}


	if (!score) //스코어 0일 떄
	{
		Num_rect.x = start_xpos + font_size * 6;
		Print_Num(0, Num_rect.x, Num_rect.y, r, g, b, font_size);

	}
	else
	{
		if (score >= 10)
		{
			for (i=0; i < 32; i++)
				if (arr[i])
				{
					for (; i < 32; i++)
					{
						Num_rect.x = (start_xpos + (font_size * 6) * (j++));

						Print_Num(arr[i], Num_rect.x, Num_rect.y, r, g, b, font_size);

					}

					break;
				}
		}
		else//한자리 일떄
			Print_Num(score, start_xpos, start_ypos, r, g, b, font_size);

	}


}

void GameManager::Print_Alpha(int num, int start_xpos, int start_ypos, int r, int g, int b, int font_size)//인자로 받은 알파벳 하나 출력
{
	int i;
	int x = start_xpos;

	alpha_rect.w = font_size;
	alpha_rect.h = font_size;


	for (i = 0; i < 25; i++)
	{
		if (i % 5 == 0)
			alpha_rect.y = start_ypos + font_size * (i / 5);

		x = start_xpos + font_size * (i % 5);
		alpha_rect.x = x;

		if (alphabet[num][i])
		{
			SDL_SetRenderDrawColor(gRenderer, r, g, b, 255);
			SDL_RenderFillRect(gRenderer, &alpha_rect);
		}

	}


}


void GameManager::Print_Word(char * ptr, int start_xpos, int start_ypos, int r, int g, int b, int font_size) //단어 출력
{
	int i;
	int x;

	for (i = 0; ptr[i]; i++)
	{
		x = start_xpos + (font_size * 6) * i;

		Print_Alpha(ptr[i] + 1 - 'A', x, start_ypos, r, g, b, font_size);
	}

}


void GameManager::generate_mine(Map ** mmap) //마인 생성하는 함수
{
	int hx, yx,count=0;

	while (1)
	{
		hx = (rand() % hang) + 1;
		yx = (rand() % yeol) + 1;

		if (mmap[hx][yx].mine == 0)
		{
			mmap[hx][yx].mine = 1;
			count++;
		}

		if (count == minenum)
			break;

	}

}



void GameManager::Main_Menu_Fuct() //메인메뉴를 총괄하는 함수
{
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;
	SDL_Rect START_rect = { 150, 300 , 260, 50 };
	SDL_Rect QUIT_rect = { 170, 430 ,210, 50 };
	SDL_Rect Name_rect = { 30,50,100,25 };

	Color color_START = { 100,100,100 };
	Color color_QUIT = { 100,100,100 };
	SDL_Color color_Name = { 100,100,100 };

	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				EndFlag = true;
				quit = true;
			}
			else if (e.type == SDL_MOUSEMOTION)
			{
				color_START.r = Cursor_BOX_check(&START_rect) == 1 ? rand() % 255 : 100;
				color_START.g = Cursor_BOX_check(&START_rect) == 1 ? rand() % 255 : 100;
				color_START.b = Cursor_BOX_check(&START_rect) == 1 ? rand() % 255 : 100;

				color_QUIT.r = Cursor_BOX_check(&QUIT_rect) == 1 ? rand() % 255 : 100;
				color_QUIT.g = Cursor_BOX_check(&QUIT_rect) == 1 ? rand() % 255 : 100;
				color_QUIT.b = Cursor_BOX_check(&QUIT_rect) == 1 ? rand() % 255 : 100;


			}
			else if (e.button.button == SDL_BUTTON_LEFT)
			{

				if (e.type == SDL_MOUSEBUTTONDOWN && Cursor_BOX_check(&QUIT_rect) == 1)
				{
					EndFlag = true;
					//	//마우스 버튼이 QUIT 영역 안에 들어오고 그 영역 안에서 눌렸는지 체크해주는 함수
					quit = true;
				}

				if (e.type == SDL_MOUSEBUTTONDOWN && Cursor_BOX_check(&START_rect) == 1)
				{
					//	//마우스 버튼이 START 영역 안에 들어오고 그 영역 안에서 눌렸는지 체크해주는 함수
					Mix_PlayChannel(-1, Move_START_Sound, 0);
					Menu_Level = SECOND_MENU;
					return;

				}

			}

		}

		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x2E,0x2E,0x2E, 0xFF);
		SDL_RenderClear(gRenderer);

		Print_Word("MINE", Name_rect.x, Name_rect.y, color_Name.r, color_Name.g, color_Name.b, 7);
		Print_Word("SWEEPER", Name_rect.x+230, Name_rect.y, color_Name.r, color_Name.g, color_Name.b, 7);
		//gTextTexture.loadFromRenderedText("MINE SWEEPER", color_Name);
	    //gTextTexture.render(50, 50);

		render_minepic();

		Print_Word("START", START_rect.x, START_rect.y, color_START.r, color_START.g, color_START.b, 10);
		Print_Word("QUIT", QUIT_rect.x, QUIT_rect.y, color_QUIT.r, color_QUIT.g, color_QUIT.b, 10);

		Print_Word("MADE", 300, 100, 100, 100, 100, 3);
		Print_Word("BY", 380, 100, 100, 100, 100, 3);
		Print_Word("KYRIN", 450, 100, 100, 100, 100, 3);



		//Update screen
		SDL_RenderPresent(gRenderer);
	}



}


int GameManager::Cursor_BOX_check(SDL_Rect * BOX_rect) //커서가 BOX영역 안에 있는지 체크
{
	int x, y;

	SDL_GetMouseState(&x, &y);

	if (x >= BOX_rect->x && x <= BOX_rect->x + BOX_rect->w && y >= BOX_rect->y && y <= BOX_rect->y + BOX_rect->h)
		return 1;

	return 0;
}


void GameManager::Select_Level_Fuct() //START 누른 후 난이도 관리하는 함수
{
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	SDL_Rect EASY_rect = {30,100,230,230};
	SDL_Rect NORMAL_rect = {320,100,230,230};
	SDL_Rect HARD_rect = {30,350,230,230};
	SDL_Rect CUSTO_rect = { 320,350,230,230 };


	Color color_EASY = { 100,100,100 };
	Color color_NORMAL = { 100,100,100 };
	Color color_HARD = { 100,100,100 };
	Color color_CUSTO = { 100,100,100 };


	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				EndFlag = true;
				quit = true;
			}
			else if (e.type == SDL_MOUSEMOTION)
			{
				color_EASY.r = Cursor_BOX_check(&EASY_rect) == 1 ? rand() % 255 : 100; color_EASY.g = Cursor_BOX_check(&EASY_rect) == 1 ? rand() % 255 : 100; color_EASY.b = Cursor_BOX_check(&EASY_rect) == 1 ? rand() % 255 : 100;

				color_NORMAL.r = Cursor_BOX_check(&NORMAL_rect) == 1 ? rand() % 255 : 100; color_NORMAL.g = Cursor_BOX_check(&NORMAL_rect) == 1 ? rand() % 255 : 100; color_NORMAL.b = Cursor_BOX_check(&NORMAL_rect) == 1 ? rand() % 255 : 100;

				color_HARD.r = Cursor_BOX_check(&HARD_rect) == 1 ? rand() % 255 : 100; color_HARD.g = Cursor_BOX_check(&HARD_rect) == 1 ? rand() % 255 : 100; color_HARD.b = Cursor_BOX_check(&HARD_rect) == 1 ? rand() % 255 : 100;

				color_CUSTO.r = Cursor_BOX_check(&CUSTO_rect) == 1 ? rand() % 255 : 100; color_CUSTO.g = Cursor_BOX_check(&CUSTO_rect) == 1 ? rand() % 255 : 100; color_CUSTO.b = Cursor_BOX_check(&CUSTO_rect) == 1 ? rand() % 255 : 100;

				//if (Cursor_BOX_check(&EASY_rect) == 1) Mix_PlayChannel(-1, Move_Select_Sound, 0);
				//if (Cursor_BOX_check(&NORMAL_rect) == 1) Mix_PlayChannel(-1, Move_Select_Sound, 0);
				//if (Cursor_BOX_check(&HARD_rect) == 1) Mix_PlayChannel(-1, Move_Select_Sound, 0);

			}
			else if (e.button.button == SDL_BUTTON_LEFT)
			{

				if (e.type == SDL_MOUSEBUTTONDOWN && Cursor_BOX_check(&EASY_rect) == 1)
				{
					Mix_PlayChannel(-1, Move_START_Sound, 0);
					Menu_Level = THIRD_MENU;
					Game_Level = EASY;
					hang = 10; yeol = 10; minenum = 10;
					return;
				}

				if (e.type == SDL_MOUSEBUTTONDOWN && Cursor_BOX_check(&NORMAL_rect) == 1)
				{
					Mix_PlayChannel(-1, Move_START_Sound, 0);
					Menu_Level = THIRD_MENU;
					Game_Level = NORMAL;
					hang = 15; yeol = 15; minenum = 40;

				    return;

				}

				if (e.type == SDL_MOUSEBUTTONDOWN && Cursor_BOX_check(&HARD_rect) == 1)
				{
					Mix_PlayChannel(-1, Move_START_Sound, 0);
					Menu_Level = THIRD_MENU;
					Game_Level = HARD;
					hang = 18; yeol = 20; minenum = 70;

					return;

				}
			
				if (e.type == SDL_MOUSEBUTTONDOWN && Cursor_BOX_check(&CUSTO_rect) == 1)
				{
					Mix_PlayChannel(-1, Move_START_Sound, 0);
					Menu_Level = THIRD_MENU;
					Game_Level = CUSTO;

					Input_Custo(); //커스터마이즈 일 경우 사용자로부터 행렬 지뢰개수를 입력받기

					return;

				}

			}
		       else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					Menu_Level = FIRST_MENU;
					Mix_PlayChannel(-1, Move_Back_Sound, 0);
					printf("back\n");

					return;
				}
			}

		}

		SDL_SetRenderDrawColor(gRenderer,0x58,0x58,0x58, 255);
		SDL_RenderClear(gRenderer);

		SDL_SetRenderDrawColor(gRenderer,100, 100, 100, 255);

		Print_Word("LEVEL", 160, 20, 42, 42, 42, 10);
		
		SDL_SetRenderDrawColor(gRenderer, 42, 42, 42, 255);
		SDL_RenderFillRect(gRenderer, &EASY_rect); // EASY
		
		Print_Word("EASY", 90, 250, color_EASY.r, color_EASY.g, color_EASY.b, 5);
		Print_Num(1, 40, 200, color_EASY.r, color_EASY.g, color_EASY.b, 5); Print_Num(0, 80, 200, color_EASY.r, color_EASY.g, color_EASY.b, 5);
		Print_Word("X", 130, 200, color_EASY.r, color_EASY.g, color_EASY.b, 5);
		Print_Num(1, 180, 200, color_EASY.r, color_EASY.g, color_EASY.b, 5); Print_Num(0, 220, 200, color_EASY.r, color_EASY.g, color_EASY.b, 5);

		SDL_SetRenderDrawColor(gRenderer, 42, 42, 42, 255); //NORMAL
 		SDL_RenderFillRect(gRenderer, &NORMAL_rect); Print_Word("NORMAL", 350, 250, color_NORMAL.r, color_NORMAL.g, color_NORMAL.b, 5);
		Print_Num(1, 330, 200, color_NORMAL.r, color_NORMAL.g, color_NORMAL.b, 5); Print_Num(5, 370, 200, color_NORMAL.r, color_NORMAL.g, color_NORMAL.b, 5);
		Print_Word("X", 420, 200, color_NORMAL.r, color_NORMAL.g, color_NORMAL.b, 5);
		Print_Num(1, 470, 200, color_NORMAL.r, color_NORMAL.g, color_NORMAL.b, 5); Print_Num(5, 510, 200, color_NORMAL.r, color_NORMAL.g, color_NORMAL.b, 5);

		SDL_SetRenderDrawColor(gRenderer, 42, 42, 42, 255); //HARD
		SDL_RenderFillRect(gRenderer, &HARD_rect); Print_Word("HARD", 90, 500, color_HARD.r, color_HARD.g, color_HARD.b, 5);
		Print_Num(1, 40, 430, color_HARD.r, color_HARD.g, color_HARD.b, 5); Print_Num(8, 80, 430, color_HARD.r, color_HARD.g, color_HARD.b, 5);
		Print_Word("X", 130, 430, color_HARD.r, color_HARD.g, color_HARD.b, 5);
		Print_Num(2, 180, 430, color_HARD.r, color_HARD.g, color_HARD.b, 5); Print_Num(0, 220, 430, color_HARD.r, color_HARD.g, color_HARD.b, 5);

		SDL_SetRenderDrawColor(gRenderer,42, 42, 42, 255); //CUSTOMIZE
		SDL_RenderFillRect(gRenderer, &CUSTO_rect); Print_Word("CUSTO", 360, 430, color_CUSTO.r, color_CUSTO.g, color_CUSTO.b, 5); Print_Word("MIZE", 370, 500, color_CUSTO.r, color_CUSTO.g, color_CUSTO.b, 5);


		SDL_RenderPresent(gRenderer);
	}


}


void GameManager::Input_Custo() //커스터마이즈일 때 사용자에게 입력받는 함수
{
	while (1)
	{
		printf("input hang(5<=hang<=18):");
		scanf("%d", &hang);

		if (hang >= 5 && hang <= 18) break;
	}

	printf("\n\n");

	while (1)
	{
		printf("input yeol(5<=yeol<=20):");
		scanf("%d", &yeol);

		if (yeol >= 5 && yeol <= 20) break;
	}
	
	printf("\n\n");

	while (1)
	{
		printf("input minenum(5<=minenum<= hang*yeol/4 ):");
		scanf("%d", &minenum);

		if (minenum >= 5 && minenum <= hang*yeol/4) break;
	}

}

void GameManager::Game_Play_Fuct() //게임 진행을 관리하는 함수
{
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	time_t start_time = clock();
	time_t end_time;
	SDL_Rect box_rect;
	SDL_Rect flag_rect;
	SDL_Rect boom_rect;
	SDL_Rect Q_rect;
	Color color_box = { 100,100,100 };
	int time=0,i,j,tem_x,tem_y;
	int mouse_x, mouse_y;
	int this_game_minenum = minenum; //이 게임에서 사용할 마인개수 대입


	Map ** map = new Map*[hang + 2];

	for (i = 0; i < hang + 2; i++)
		map[i] = new Map[yeol + 2];

	generate_mine(map); //마인생성


	box_rect.w = 25, box_rect.h = 25;
	flag_rect.w = 20; flag_rect.h = 20;
	boom_rect.w = 20; boom_rect.h = 20;
	Q_rect.w = 20; Q_rect.h = 20;  //사진크기 설정


	box_rect.x = yeol <= 10 ? 130 : (yeol <= 15 ? 80 : 20);
	tem_x = box_rect.x;

	box_rect.y = hang <= 10 ? 150 : (hang <= 15 ? 100 : 80);
	tem_y = box_rect.y;  //상자 크기 설정

	End_Flag_Game_Play_Fuct = false;
	success_count = 0;

	if (first_click == 2)
		goto FIRST;

	first_click = 0;
	
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				EndFlag = true;
				quit = true;

				for (i = 0; i < hang+2; i++)
					delete[] map[i];

				delete[] map;

				return;
			}


			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					Menu_Level = SECOND_MENU;
					Mix_PlayChannel(-1, Move_Back_Sound, 0);
					printf("back\n");

					for (i = 0; i < hang+2; i++)
						delete[] map[i];

					delete[] map;
					
					return;

				case SDLK_r:
					Menu_Level = THIRD_MENU;
					Mix_PlayChannel(-1, Move_Select_Sound, 0);
					printf("restart\n");

					for (i = 0; i < hang+2; i++)
						delete[] map[i];

					delete[] map;
					
					return;

				}
			}
			else if (e.type == SDL_MOUSEMOTION) //단위 map에 들어가면 그 map은 색깔을 좀 더 진하게
			{

				SDL_GetMouseState(&mouse_x, &mouse_y);

				for (i = 0; i <= hang; i++)
					for (j = 0; j <= yeol; j++)
						map[i][j].cursor_now = 0;

				if (mouse_x > tem_x && mouse_y > tem_y && mouse_x < tem_x + (box_rect.w + 3)*yeol && mouse_y < tem_y + (box_rect.h + 3)*hang)
					map[((mouse_y - tem_y) / (box_rect.h + 3)) + 1][((mouse_x - tem_x) / (box_rect.w + 3)) + 1].cursor_now = 1;


			}
			else if (e.button.button == SDL_BUTTON_LEFT) // 단위 map에 들어간 상태로 좌클릭 시 지뢰체크
			{
				if (e.type == SDL_MOUSEBUTTONDOWN)
				{
					SDL_GetMouseState(&mouse_x, &mouse_y);

					if (mouse_x > tem_x && mouse_y > tem_y && mouse_x < tem_x + (box_rect.w + 3)*yeol && mouse_y < tem_y + (box_rect.h + 3)*hang) //마우스가 영역전체안에 있을 때
					{

						if (map[((mouse_y - tem_y) / (box_rect.h + 3)) + 1][((mouse_x - tem_x) / (box_rect.w + 3)) + 1].check == 0 && map[((mouse_y - tem_y) / (box_rect.h + 3)) + 1][((mouse_x - tem_x) / (box_rect.w + 3)) + 1].flag == 0)
						{

							if (first_click == 0) //처음 클릭할 때
							{
							
			FIRST: //0이 나올 때까지 여기서 진행

								SDL_GetMouseState(&mouse_x, &mouse_y);

								if (mine_find(map, ((mouse_y - tem_y) / (box_rect.h + 3)) + 1, ((mouse_x - tem_x) / (box_rect.w + 3)) + 1) == 2) //해당영역이 0이 나오면
									first_click = 1;
								else //해당영역이 0이 아니면 다시 맵 바꿔서
								{
									first_click = 2;

									for (i = 0; i < hang + 2; i++)
										delete[] map[i];

									delete[] map;

									return;
								}

							}
							else
							{
								if (mine_find(map, ((mouse_y - tem_y) / (box_rect.h + 3)) + 1, ((mouse_x - tem_x) / (box_rect.w + 3)) + 1) == 1) // 지뢰를 찾는 함수
								{

									for (i = 1; i <= hang; i++)
									{
										box_rect.y = tem_y + (box_rect.h + 3)*(i - 1);
										box_rect.x = tem_x;

										for (j = 1; j <= yeol; j++)
										{
											box_rect.x = tem_x + (box_rect.w + 3)*(j - 1);

											if (map[i][j].mine == 1)
											{
												if (map[i][j].flag == 0)
												{
													boom_rect.x = box_rect.x + 3;
													boom_rect.y = box_rect.y + 3;

													SDL_RenderCopy(gRenderer, minepic1, NULL, &boom_rect);
												}
												else
												{

													boom_rect.x = box_rect.x + 3;
													boom_rect.y = box_rect.y + 3;

													SDL_SetRenderDrawColor(gRenderer, 100, 100, 100, 255);
													SDL_RenderFillRect(gRenderer, &box_rect);
													SDL_RenderCopy(gRenderer, minepic1, NULL, &boom_rect);

												}



											}

										}
									}

									//mine find 의 리턴이 1이면 게임오버이다
									Print_Word("GAME", 100, 200, 19,189,198, 7);
									Print_Word("OVER", 300, 200, 19, 189, 198, 7);

									SDL_RenderPresent(gRenderer);

									Game_End_Manage(map);

								}


								if (End_Flag_Game_Play_Fuct == true)
									return;


							}

						}

					}


				}
			}
			else if (e.button.button == SDL_BUTTON_RIGHT) //우클릭 시 깃발
			{
				if (e.type == SDL_MOUSEBUTTONDOWN)
				{
					SDL_GetMouseState(&mouse_x, &mouse_y);

					if (mouse_x > tem_x && mouse_y > tem_y && mouse_x < tem_x + (box_rect.w + 3)*yeol && mouse_y < tem_y + (box_rect.h + 3)*hang)
					{
						if(map[((mouse_y - tem_y) / (box_rect.h + 3)) + 1][((mouse_x - tem_x) / (box_rect.w + 3)) + 1].check == 0)
						map[((mouse_y - tem_y) / (box_rect.h + 3)) + 1][((mouse_x - tem_x) / (box_rect.w + 3)) + 1].flag = (map[((mouse_y - tem_y) / (box_rect.h + 3)) + 1][((mouse_x - tem_x) / (box_rect.w + 3)) + 1].flag + 1) % 3;


					}

				}

			}

		}

		this_game_minenum = minenum;

		for (i = 1; i <= hang; i++)
			for (j = 1; j <= yeol; j++)
				if (map[i][j].flag == 1)
					if (--this_game_minenum <= 0)
						this_game_minenum = 0;

		SDL_SetRenderDrawColor(gRenderer, 10, 20, 30, 255);
		SDL_RenderClear(gRenderer);

		Print_Word("R", 20, 20, 100, 100, 100, 2); Print_Word("RESTART", 40, 20, 100, 100, 100, 2);
		Print_Word("ESC", 140, 20, 100, 100, 100, 2); Print_Word("MENU", 180, 20, 100, 100, 100, 2);

		Print_Word("MINE", 100, 50, 100, 100, 100, 3);
		Print_Score(this_game_minenum, 180, 50, 100, 100, 100, 3);

		Print_Word("TIME", 360, 50, 100, 100, 100, 3);
		Print_Score(time, 440, 50, 100, 100, 100, 3);


		for (i = 1; i <= hang; i++)
		{
			box_rect.y = tem_y + (box_rect.h+3)*(i-1);
			box_rect.x = tem_x;

			for (j = 1; j <= yeol; j++)
			{
				box_rect.x = tem_x + (box_rect.w + 3)*(j-1);

				if (map[i][j].check == 0) //지뢰 확인을 안했을 때
				{
					if (map[i][j].flag == 0) //깃발이 없을 때
					{
						if (map[i][j].cursor_now == 1)
						{
							color_box.r = 70;
							color_box.g = 70;
							color_box.b = 70;
						}
						else
						{
							color_box.r = 100;
							color_box.g = 100;
							color_box.b = 100;
						}

						SDL_SetRenderDrawColor(gRenderer, color_box.r, color_box.g, color_box.b, 255);
						SDL_RenderFillRect(gRenderer, &box_rect);

					}
					else if(map[i][j].flag == 1)//깃발이 있을 때
					{
						flag_rect.x = box_rect.x+3;
						flag_rect.y = box_rect.y+3;

						SDL_RenderDrawRect(gRenderer, &box_rect);
						SDL_RenderCopy(gRenderer, flagpic, NULL, &flag_rect);
					}
					else //물음표 일 때
					{
						Q_rect.x = box_rect.x + 3;
						Q_rect.y = box_rect.y + 3;

						SDL_RenderDrawRect(gRenderer, &box_rect);
						SDL_RenderCopy(gRenderer, Qpic, NULL, &Q_rect);
					}

				}
				else
				{
					Print_Num(map[i][j].mine_around_num, box_rect.x + 5, box_rect.y + 5, 200, 200, 200, 3);

					SDL_RenderDrawRect(gRenderer, &box_rect);
				}


			}

		}

		if (success_count == hang * yeol - minenum)
		{
			Mix_PlayChannel(-1, Clear_Sound, 0);

			// 그 중에서 게임 클리어 조건을 만족하면 .. 
			Print_Word("GAME", 100, 200, 19, 189, 198, 7);
			Print_Word("CLEAR", 300, 200, 19, 189, 198, 7);

			SDL_RenderPresent(gRenderer);

			Game_End_Manage(map);

			if (End_Flag_Game_Play_Fuct == true)
				return;
		}


		SDL_RenderPresent(gRenderer);

		end_time = clock();

		if ((end_time - start_time) / CLOCKS_PER_SEC >= 1)
		{
			time++;
			start_time = clock();
		}

	}


}


int GameManager::mine_find(Map ** mmap,int hx, int yx) //커서가 위치하는 곳에 마인있는지 찾는 함수
{
	if (mmap[hx][yx].mine == 1) //지뢰 눌렀을 때
	{
		if (first_click == 1) //첫클릭 시도 이후부터만 게임오버코드가 적용됨
		{
			printf("bang!\n");
			Mix_PlayChannel(-1, Boom_Sound, 0);
		}

		return 1;
	}
	else
	{
		if (hx >= 1 && hx <= hang && yx >= 1 && yx <= yeol)
		{
			success_count++;

			if (count_around_num(mmap, hx, yx) == 0) //주변 지뢰 개수가 0일 때
			{
				mmap[hx][yx].check = 1;
				mmap[hx][yx].mine_around_num = 0;

				if (mmap[hx - 1][yx - 1].check == 0) mine_find(mmap, hx - 1, yx - 1);
				if (mmap[hx - 1][yx].check == 0) mine_find(mmap, hx - 1, yx);
				if (mmap[hx - 1][yx + 1].check == 0) mine_find(mmap, hx - 1, yx + 1);
				if (mmap[hx][yx + 1].check == 0) mine_find(mmap, hx, yx + 1);
				if (mmap[hx + 1][yx + 1].check == 0) mine_find(mmap, hx + 1, yx + 1);
				if (mmap[hx + 1][yx].check == 0) mine_find(mmap, hx + 1, yx);
				if (mmap[hx + 1][yx - 1].check == 0) mine_find(mmap, hx + 1, yx - 1);
				if (mmap[hx][yx - 1].check == 0) mine_find(mmap, hx, yx - 1);

				return 2;

			}
			else
			{
				mmap[hx][yx].check = 1;
				mmap[hx][yx].mine_around_num = count_around_num(mmap, hx, yx);

			}

		}

	}

	return 0;
}


int GameManager::count_around_num(Map ** mmap,int hx, int yx) //해당 맵 주변에 지뢰가 몇 개 있는지 찾는 함수
{
	int count = 0;

	if (mmap[hx - 1][yx - 1].mine == 1) count++;
	if (mmap[hx - 1][yx].mine == 1) count++;
	if (mmap[hx - 1][yx + 1].mine == 1) count++;
	if (mmap[hx][yx + 1].mine == 1) count++;
	if (mmap[hx + 1][yx + 1].mine == 1) count++;
	if (mmap[hx + 1][yx].mine == 1) count++;
	if (mmap[hx + 1][yx - 1].mine == 1) count++;
	if (mmap[hx][yx - 1].mine == 1) count++;

	return count;
}


void GameManager::Game_End_Manage(Map ** mmap) //게임이 클리어되든 지뢰밟아서 끝나든 끝났을 때 다른 입력을 기다리는 함수
{
	int i;
	bool quit = false;

	SDL_Event e;

			while (1)
			{	//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						EndFlag = true;
						quit = true;
						End_Flag_Game_Play_Fuct = true;

						for (i = 0; i < hang + 2; i++)
							delete[] mmap[i];

						delete[] mmap;

						return;
					}


					else if (e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym)
						{
						case SDLK_ESCAPE:
							Menu_Level = SECOND_MENU;
							Mix_PlayChannel(-1, Move_Back_Sound, 0);
							printf("back\n");
							
							End_Flag_Game_Play_Fuct = true;

							for (i = 0; i < hang + 2; i++)
								delete[] mmap[i];

							delete[] mmap;

							return;

						case SDLK_r:
							Menu_Level = THIRD_MENU;
							Mix_PlayChannel(-1, Move_Select_Sound, 0);
							printf("restart\n");

							End_Flag_Game_Play_Fuct = true;

							for (i = 0; i < hang + 2; i++)
								delete[] mmap[i];

							delete[] mmap;

							return;

						}
					}

				}

			}


}