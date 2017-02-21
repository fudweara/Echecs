#include <SDL2/SDL.h>
#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

#include "main.h"

//Dimension de l'écran
const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=480;

int main(int argc, char* args[])
{

    SDL_Window* window = NULL; //Déclaration fenetre
    SDL_Surface* screenSurface = NULL; //Surface contenue par l'écran

    if(InitSDL(window,screenSurface)==1){
        CreationFenetre(window, screenSurface);
    }
    else{
        printf("Le programme n'a pas pu se lancer au moment de l'initialisation de la SDL."); //AH
    }

    SDL_Delay( 2000 );

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


bool InitSDL(SDL_Window* window,SDL_Surface* screenSurface){

	bool Succes=true;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf("SDL n'a pas reussi à se lancer. SDL_Error: %s\n", SDL_GetError());
		Succes=false;
	}
	else{
        printf("Init SDL : ok.");
    }
    return Succes;
}

void CreationFenetre(SDL_Window* window,SDL_Surface* screenSurface){
    window = SDL_CreateWindow("Echecs", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if( window == NULL ){
        printf("La fenetre n'a pas pu être créee. SDL_Error: %s\n",SDL_GetError());
    }
    else{
        screenSurface = SDL_GetWindowSurface(window);

        //Mettre couleur de fond
        SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format,51,51,51));

        //Màj fenetre
        SDL_UpdateWindowSurface(window);

        MenuPrincipal(window, screenSurface); //Passage Menus.c
    }
}

