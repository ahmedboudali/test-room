#include <SDL/SDL.h>
#include "image.h"
#include <SDL/SDL_image.h>
//*****PLAY*****//
void initPlayer(Image *A)
{
    A->img = IMG_Load("/home/ahmedb/play_off.png"); 
          if(A->img== NULL) {
              return;
          }    
    A->pos1.x=920;
    A->pos1.y=280;
    A->pos1.w=10;
    A->pos1.h=A->img->h;
   
    A->pos2.x=193;
    A->pos2.y=0;
    A->pos2.w=100;
    A->pos2.h=A->img->h;
}
void initPlayer_s(Image *A)
{
    A->img = IMG_Load("/home/ahmedb/play_on.png");
          if(A->img== NULL) {
              return;
          }    
    A->pos1.x=920;
    A->pos1.y=280;
    A->pos1.w=10;
    A->pos1.h=A->img->h;
   
    A->pos2.x=193;
    A->pos2.y=0;
    A->pos2.w=100;
    A->pos2.h=A->img->h;
}


//*****SETTINGS*****//
void initsettings(Image *A)
{
    A->img = IMG_Load("/home/ahmedb/settings_off.png"); 
          if(A->img== NULL) {
              return;
          }    
    A->pos1.x=920; /*position par rapport l'ecran */
    A->pos1.y=380;
    A->pos1.w=10;
    A->pos1.h=A->img->h;
   
    A->pos2.x=193; /*crouper l'image*/
    A->pos2.y=0;
    A->pos2.w=100;
    A->pos2.h=A->img->h;
}
void initsettings_s(Image *A)
{
    A->img = IMG_Load("/home/ahmedb/settings_on.png");
          if(A->img== NULL) {
              return;
          }    
    A->pos1.x=920;
    A->pos1.y=380;
    A->pos1.w=10;
    A->pos1.h=A->img->h;
   
    A->pos2.x=193;
    A->pos2.y=0;
    A->pos2.w=100;
    A->pos2.h=A->img->h;
}


//*****EXIT*****//
void initexit(Image *A)
{
    A->img = IMG_Load("/home/ahmedb/exit_off.png");
          if(A->img== NULL) {
              return;
          }    
    A->pos1.x=920;
    A->pos1.y=480;
    A->pos1.w=10;
    A->pos1.h=A->img->h;
   
    A->pos2.x=193;
    A->pos2.y=0;
    A->pos2.w=100;
    A->pos2.h=A->img->h;
}
void initexit_s(Image *A)
{
    A->img = IMG_Load("/home/ahmedb/exit_on.png");
          if(A->img== NULL) {
              return;
          }    
    A->pos1.x=920;
    A->pos1.y=480;
    A->pos1.w=10;
    A->pos1.h=A->img->h;
   
    A->pos2.x=193;
    A->pos2.y=0;
    A->pos2.w=100;
    A->pos2.h=A->img->h;
}

//*****MINI BACKGROUND*****//
void initbg_settings(Image *Backg)
{
Backg->img= IMG_Load("/home/ahmedb/settings_stuff/settings_mini_finale.png");
      if (Backg->img == NULL) {
          printf("unable to load bitmap: %s\n" , SDL_GetError());
          return;
}              
        Backg->pos1.x=0;  
        Backg->pos1.y=0;  
        Backg->pos2.x=0;  
        Backg->pos2.y=0;    
        Backg->pos2.w=(1280);  
        Backg->pos1.h=(720);
}
void initBackground(Image *Backg)
{
Backg->img= IMG_Load("/home/ahmedb/Six Hands Black (2)/menu_mini.png");
     if (Backg->img == NULL) {
          printf("unable to load bitmap: %s\n" , SDL_GetError());
          return;
              }
        Backg->pos1.x=0;  
        Backg->pos1.y=0;  
        Backg->pos2.x=0;  
        Backg->pos2.y=0;    
        Backg->pos2.w=(1280);  
        Backg->pos1.h=(720);
}


void initBackground_play(Image *Backg)
{
Backg->img= IMG_Load("/home/ahmedb/gggggggggg.png");
     if (Backg->img == NULL) {
          printf("unable to load bitmap: %s\n" , SDL_GetError());
          return;
              }
        Backg->pos1.x=0;  
        Backg->pos1.y=0;  
        Backg->pos2.x=0;  
        Backg->pos2.y=0;    
        Backg->pos2.w=(1280);  
        Backg->pos1.h=(720);
}






void liberer(Image A)
{          
          SDL_FreeSurface(A.img); /*liberer l'espace memoire*/
}


void afficher(Image p,SDL_Surface *screen)
{
SDL_BlitSurface(p.img,NULL,screen,&p.pos1); /*coller l'image sur l'ecran*/
SDL_BlitSurface(p.img,NULL,screen,&p.pos1); 


}









