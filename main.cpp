
#include <string>
#include <cmath>
#include "mine_sweeper.h"

#include <time.h>
#include <stdlib.h>
#include <Windows.h>

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Globally used font
TTF_Font *gFont = NULL;

LTexture gTextTexture;

Mix_Chunk * Move_Back_Sound=NULL;

Mix_Chunk * Move_START_Sound=NULL;

Mix_Chunk * Move_Select_Sound=NULL;

Mix_Chunk * Boom_Sound=NULL;

Mix_Chunk * Clear_Sound=NULL;


int main(int argc, char* args[])
{
	system("title minesweeper");

	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		    //Load media
		    loadMedia();
     		
			GameManager GM;
			srand((int)time(NULL));
			GM.load_minepic();
			GM.GM_Init();

			while (1)
			{
				switch (GM.Get_Menu_Level())
				{

				case FIRST_MENU: //처음 메뉴화면
					
					GM.Main_Menu_Fuct(); //메인메뉴 관리 함수
					break;

				case SECOND_MENU: //START 누른후

					GM.Select_Level_Fuct(); //레벨 선택 창 함수
					break;

				case THIRD_MENU: //이제 레벨에 맞게 게임 플레이
				    GM.Game_Play_Fuct();
					break;

				}

				if (GM.Get_EndFlag() == true)
					goto END;
			
			}


	}


	END:

	//Free resources and close SDL
	close();

	return 0;
}