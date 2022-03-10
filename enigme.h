#ifndef ENIGME_H
#define ENIGME_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define SCREEN_W 1280
#define SCREEN_H 720


void affichierEnfine(engime , SDL_Surface *screen );
void InitEngime(engime *e, char *nomfichier);
void animer (enigme *e);
void sauvegarder(personner p , background b, char* nomfichier)
void animer(engime *e);

#endif
