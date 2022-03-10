#include "texte.h"
#include "image.h"
#include <SDL/SDL_mixer.h>

int main(int argc, char* argv)
{

	//******************//
	//***declaration***//
	//******************//



    TTF_Init(); /*initialisation text*/
    SDL_Init(SDL_INIT_VIDEO); /*initialisation video,audi,timing...*/


    SDL_Surface * screen; /*declaration de la surface (backgroung)*/
    
    int done = 0, i ;
    Image Hazar, Hazar1 ,Backg,  settings ,settings1, exit,  exit1,bg_st,Backg_play;
    SDL_Event event; /*declaration des evenements*/
    
    Text t;
    
    atexit(SDL_Quit); /*quitter le SDL*/
    
    screen = SDL_SetVideoMode(1280,720, 32, SDL_HWSURFACE | SDL_SRCALPHA);  /*creation d'une fenetre selon des criteres passés en parametres*/
   
	//******************//
	//***espace audio***//
	//******************//

	Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,3403052); //initialisation des fonctions audio du SDL_mixer

	if(Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,3403052)==-1)
	{
	printf("%s", Mix_GetError());
	}


      //*music background :
	
	Mix_Music *music; /*chargement de la musique*/
	music = Mix_LoadMUS("civilization-v-carthage-war-theme-tribute-flaganthem.mp3"); /*importation musique*/
	Mix_PlayMusic(music, -1); /*jouer la musique*/



     //*button son effet :
	Mix_Chunk * son; /*chargement de son effet*/
	son= Mix_LoadWAV( "Menu Game Button Click Sound Effect.wav" ); /*importation musique*/





    if( !screen)
    {
        printf("Unable to set 1280*720 video : %s\n", SDL_GetError());
        return 1;
    }
 
    //**INISIALITATION PHOTO***//
    initBackground_play(&Backg_play);

 initbg_settings(&bg_st);
 initBackground(&Backg);
 initPlayer_s(&Hazar1);
 initPlayer(&Hazar);


  initsettings_s(&settings1);
  initsettings(&settings);
    
    initexit(&exit);
    initexit_s(&exit1);
     
    initText(&t);
    
        //******************//
	//***boucle while***//
	//******************//
   
    while(!done)
    {  
			    
			    

			     	    /* affichier(Backg_play,screen);*/
				     afficher(Backg,screen);
				     afficher(Hazar, screen); 
				     afficher(settings,screen);
				     afficher(exit, screen);
				     displayText(t,screen);

				     SDL_PollEvent(&event);
			 
			 switch(event.type)
			 {
					 case SDL_QUIT:
					       done = 1;
						break;
						       
//********BUTTONS LIGHT	
				     case SDL_KEYDOWN:
						   if(event.key.keysym.sym ==SDLK_p)
						   {
							afficher(Hazar1,screen);
							
							SDL_Flip(screen);
							Mix_PlayChannel(-1, son, 0); 
						   }
						   
						   if(event.key.keysym.sym ==SDLK_s)
						   {
							Mix_PlayChannel(-1, son, 0);
							afficher(settings1,screen);
							SDL_Flip(screen); /*mise à jour mtaa l ecran (rafraichissement)*/
						   }
						   
						   if(event.key.keysym.sym ==SDLK_e)
						   {
						        Mix_PlayChannel(-1, son, 0); 
							afficher(exit1,screen);
							done = 1;
							
						   }
//********FULL/MINI SCREEN						   		
						   if(event.key.keysym.sym ==SDLK_f)
						   {
							screen = SDL_SetVideoMode(1900, 1069, 32, SDL_HWSURFACE | SDL_SRCALPHA);
						   }
						   
						   if(event.key.keysym.sym ==SDLK_m)
						   {    
						   
							screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_SRCALPHA);
						   } 
						   break;
						   
						SDL_Flip(screen);
						
						
						
//********SETTINGS / GAME BACGROUND						
					     case SDL_KEYUP : 
							
					      
							  if(event.key.keysym.sym ==SDLK_s)
							  {
									while (event.key.keysym.sym !=SDLK_ESCAPE)
									{		
										afficher(bg_st, screen);   
										SDL_Flip(screen);


										SDL_PollEvent(&event);
										 
										 switch(event.type)
										{
										case SDL_KEYDOWN:
											if (event.key.keysym.sym ==SDLK_ESCAPE)
											 {
											
											afficher(Backg,screen);
											afficher(Hazar, screen); 
											afficher(settings,screen);
											afficher(exit, screen);
											displayText(t,screen);
											SDL_Flip(screen);
											 }
											 
											if(event.key.keysym.sym ==SDLK_w)
											 {
												 Mix_VolumeMusic(MIX_MAX_VOLUME/6);
											  }
										       if(event.key.keysym.sym ==SDLK_v)
											 {
												 Mix_VolumeMusic(MIX_MAX_VOLUME);
											 }
											  if(event.key.keysym.sym ==SDLK_f) //*****************
											   {
											      screen = SDL_SetVideoMode(1900,1069, 32, SDL_HWSURFACE | SDL_SRCALPHA);
											   }
												   
										      if(event.key.keysym.sym ==SDLK_m)
										     	 {
											    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_SRCALPHA);
											 } 
											break;
										
									       }       
									}
									/*  liberer(bg_st); */
				 
							  }
							  
									if(event.key.keysym.sym ==SDLK_p)
									{
										while (event.key.keysym.sym !=SDLK_ESCAPE)
												{		
													afficher(Backg_play,screen);
													SDL_Flip(screen);
											
													SDL_PollEvent(&event);
													 
													 switch(event.type)
													{
													case SDL_KEYDOWN:
														if (event.key.keysym.sym ==SDLK_ESCAPE)
														 {
														Mix_PlayChannel(-1, son, 0); 
														afficher(Backg,screen);
														afficher(Hazar, screen); 
														afficher(settings,screen);
														afficher(exit, screen);
														displayText(t,screen);
														SDL_Flip(screen);
														 }
														 
														
														    if(event.key.keysym.sym ==SDLK_f) //*****************
														   {
														      screen = SDL_SetVideoMode(1900,1069, 32, SDL_HWSURFACE | SDL_SRCALPHA);
														   }
															   
													      if(event.key.keysym.sym ==SDLK_m)
													     	 {
														    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_SRCALPHA);
														 } 
														break;
													
												       }       
												}
									
									
									
									
									
									}
							
						break;
					 SDL_Flip(screen);
							
					 case SDL_MOUSEMOTION: 
							if(event.motion.x>=921 && event.motion.x<=921+174 && event.motion.y>=280 && event.motion.y<=280+35) /*play button*/
							{
							Mix_PlayChannel(-1, son, 0); 
							   afficher(Hazar1,screen);
							   
							}
							if(event.motion.x>=921 && event.motion.x<=921+174 && event.motion.y>=380 && event.motion.y<=380+35)/*settings button*/
							{
							Mix_PlayChannel(-1, son, 0); 
							   afficher(settings1,screen);
							
							  
							}
							if(event.motion.x>=921 && event.motion.x<=921+174 && event.motion.y>=480 && event.motion.y<=480+35)/*exit button*/
							{
							 Mix_PlayChannel(-1, son, 0); 
							   afficher(exit1,screen);
							   
							}
							   break;
						    SDL_Flip(screen);
						    
						    
						    
				  case SDL_MOUSEBUTTONDOWN:
							if(event.motion.x>=921 && event.motion.x<=921+174 && event.motion.y>=480 && event.motion.y<=480+35) /*exit button*/
							{
							 Mix_PlayChannel(-1, son, 0);
							 done = 1;
							  
							}
							/*if(event.motion.x>=921 && event.motion.x<=921+174 && event.motion.y>=380 && event.motion.y<=380+35) //settings
							{
							   afficher(bg_st, screen);
							}*
							if(event.key.keysym.sym ==SDLK_w)
							   {
								Mix_VolumeMusic(MIX_MAX_VOLUME/8);
							   }
							   if(event.key.keysym.sym ==SDLK_v)
							   {
							Mix_VolumeMusic(MIX_MAX_VOLUME);
							   }*/
							   break;
							   
							   
				case SDL_MOUSEBUTTONUP:
				
				if(event.motion.x>=921 && event.motion.x<=921+174 && event.motion.y>=380 && event.motion.y<=380+35)
							{
							
							 while (event.key.keysym.sym !=SDLK_ESCAPE)
									{	
									 	
										afficher(bg_st, screen);   
										SDL_Flip(screen);
								
										SDL_PollEvent(&event);
										 
										 switch(event.type)
										{
										case SDL_KEYDOWN:
											if (event.key.keysym.sym ==SDLK_ESCAPE)
											 {
											Mix_PlayChannel(-1, son, 0); 
											afficher(Backg,screen);
											afficher(Hazar, screen); 
											afficher(settings,screen);
											afficher(exit, screen);
											displayText(t,screen);
											SDL_Flip(screen);
											 }
											 
											if(event.key.keysym.sym ==SDLK_w)
											 {
											 Mix_VolumeMusic(MIX_MAX_VOLUME/6);
											  }
										       if(event.key.keysym.sym ==SDLK_v)
											 {
											 Mix_VolumeMusic(MIX_MAX_VOLUME);
											 }
											    if(event.key.keysym.sym ==SDLK_f) //*****************
											   {
											      screen = SDL_SetVideoMode(1900,1069, 32, SDL_HWSURFACE | SDL_SRCALPHA);
											   }
												   
										      if(event.key.keysym.sym ==SDLK_m)
										     	 {
											    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_SRCALPHA);
											 } 
											break;
										}
							  	}
						}
				
				
				
				
				
						
					 if(event.motion.x>=921 && event.motion.x<=921+174 && event.motion.y>=280 && event.motion.y<=280+35) /*play button*/
							{while (event.key.keysym.sym !=SDLK_ESCAPE)
									{	
									     
										afficher(Backg_play,screen);
										SDL_Flip(screen);
								
										SDL_PollEvent(&event);
										 
										 switch(event.type)
										{
										case SDL_KEYDOWN:
											if (event.key.keysym.sym ==SDLK_ESCAPE)
											 {
											    
											Mix_PlayChannel(-1, son, 0); 
											afficher(Backg,screen);
											afficher(Hazar, screen); 
											afficher(settings,screen);
											afficher(exit, screen);
											displayText(t,screen);
											SDL_Flip(screen);
											 }
											 
											
											    if(event.key.keysym.sym ==SDLK_f) 
											   {
											      screen = SDL_SetVideoMode(1900,1069, 32, SDL_HWSURFACE | SDL_SRCALPHA);
											   }
													   
											   if(event.key.keysym.sym ==SDLK_m)
											    {
												 screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_SRCALPHA);
											     } 
											break;
										}
							 		 }
							  
							}
					
							   break;
							 SDL_Flip(screen);
							  
			}/*switch*/
			SDL_Flip(screen); //mise à jour de l'ecran
}/*while*/
   liberer(Backg_play);
    liberer(Backg); /*libere l'espace mémoire*/
    liberer(Hazar1);
    liberer(settings1);
    liberer(exit1);
    Mix_FreeChunk(son);
    freeText(t);
    Mix_FreeMusic(music);
    TTF_CloseFont(t.font);
    TTF_Quit();
    return 0;
}

