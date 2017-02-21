#include <SDL2/SDL.h>
#include <stdio.h>

#include"Menus.h"

void MenuPrincipal(SDL_Window* window,SDL_Surface* screenSurface){

    char NomImage[15]="hello_world.bmp";
    SDL_Surface* gHelloWorld = NULL;
    gHelloWorld = SDL_LoadBMP(NomImage);

    SDL_BlitSurface( gHelloWorld, NULL, screenSurface, NULL );
    SDL_UpdateWindowSurface( window );

    SDL_FreeSurface( gHelloWorld );
	gHelloWorld = NULL;
	SDL_Delay( 2000 );
}
