#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


int main()
{
    SDL_Surface *screen;
    SDL_Event Event;

    SDL_Surface *Sprite, *sprite_repos1, *sprite_repos2, *spritegauche, *sprite_shift,*Sprite_jump;
    SDL_Rect src,dst,back;

  
    int numFrame,FPS=60,loop=1, frameWeidth, frameHeight;
    float deltaTime = 0,timeFrame=0,prevtime=0,currentTime=0;

    SDL_Init(SDL_INIT_AUDIO||SDL_INIT_VIDEO);
    screen=SDL_SetVideoMode(1400,700,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
    Sprite=IMG_Load("spritesheetm2.jpg");
    frameWeidth = 200;
    frameHeight = 150;
    src.x=src.y=0;
    src.w=frameWeidth;
    src.h=frameHeight;

    dst.x=dst.y=100;
    dst.w=frameWeidth;
    dst.h=frameHeight;

    back.x=0;
    back.y=0;
    back.w=1400;
    back.h=700;
    spritegauche=IMG_Load("spritesheetg2.jpg");
    sprite_repos1=IMG_Load("spritesheetr3.jpg");
    sprite_repos2=IMG_Load("spritesheetr.jpg");
    sprite_shift=IMG_Load("sh.jpg");
    Sprite_jump=IMG_Load("jumpj.jpg");
    SDL_EnableKeyRepeat(60,60);
    do
    {
        prevtime=currentTime;
        currentTime=SDL_GetTicks()/1000.0f;
        deltaTime=(currentTime-prevtime);
        while (SDL_PollEvent(&Event))
        {
            switch (Event.type)
            {
            case SDL_QUIT:
                loop=0;
                break;
            case SDL_KEYDOWN:
                switch (Event.key.keysym.sym)
                {
                case SDLK_d:
                    dst.x+=7.1;
                    SDL_BlitSurface(Sprite,&src,screen,&dst); 
                    SDL_Flip(Sprite);
                    break;

                case SDLK_q:
                    dst.x-=7.1;
                    SDL_BlitSurface(spritegauche,&src,screen,&dst);
                    SDL_Flip(spritegauche);
                    break;
                case SDLK_s:
                    SDL_BlitSurface(sprite_shift,&src,screen,&dst);
                    SDL_Flip(sprite_shift);
                    break;
                case SDLK_SPACE:
                          
                	   SDL_BlitSurface(Sprite_jump,&src,screen,&dst);
                   	   SDL_Flip(Sprite_jump);
                   	   break;
                }
                
            break;
            case SDL_KEYUP:
            switch (Event.key.keysym.sym)
                {
                case SDLK_d:
                 dst.x+=7.1;
                 SDL_BlitSurface(sprite_repos1,&src,screen,&dst);
                 SDL_Flip(sprite_repos1);
                  break;
                  case SDLK_q:
                    dst.x-=7.1;
                    SDL_BlitSurface(sprite_repos2,&src,screen,&dst);
                    SDL_Flip(sprite_repos2);
                    break;
		  case SDLK_s:
			SDL_BlitSurface(sprite_repos1,&src,screen,&dst);
                 	SDL_Flip(sprite_repos1);
                    break;
                     case SDLK_SPACE:
                	  SDL_BlitSurface(sprite_repos1,&src,screen,&dst);
                 	  SDL_Flip(sprite_repos1);
                   	   break;
                }
            }
        }
        timeFrame+=deltaTime;
        printf("timefrime:%d\n",timeFrame);
        if(timeFrame >=0.15f)
        {
            timeFrame=0;
            src.x+=frameWeidth;
            if(src.x>800)
                src.x=0;
        }
            SDL_Flip(screen);   
            //printf("time = %0.00fs\n",deltaTime);
    } while (loop!=0);

    SDL_Quit();
    return 0;
}
