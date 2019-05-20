
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

				case FIRST_MENU: //ó�� �޴�ȭ��
					
					GM.Main_Menu_Fuct(); //���θ޴� ���� �Լ�
					break;

				case SECOND_MENU: //START ������

					GM.Select_Level_Fuct(); //���� ���� â �Լ�
					break;

				case THIRD_MENU: //���� ������ �°� ���� �÷���
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