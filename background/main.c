#include"background.h"

int main()
{
    SDL_Surface *Screen;
    background BK1,BK2,BK3;
    SDL_Event event;
    SDL_Rect perso,maske,maske1,maske2,maske3,maske4,maske5,maske6;
    Uint32 colorP,colorM;
    int loop, lvl=0, score=0, acceleration=5, direction=0, keyD=0,keyQ=0;

    SDL_Init(SDL_INIT_AUDIO||SDL_INIT_VIDEO);
    Screen=SDL_SetVideoMode(1200,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
		printf("%s",Mix_GetError());
	}
    loop=1;

    init_background1(&BK1);
    init_background2(&BK2);
    init_background3(&BK3);

  

    perso.x=50;
    perso.y=150;
    perso.w=32;
    perso.h=32;
    colorP=SDL_MapRGB(Screen->format,255,0,0);

    
    colorM=SDL_MapRGB(Screen->format,5,10,5);
    SDL_EnableKeyRepeat(60,60);
    do
    {
        scrolling(&BK1,direction,keyD,keyQ);
        printf("src = %d\n",BK1.src.x);
        if(lvl==0)
        {
            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                    case SDL_QUIT:
                    loop=0;
                    break;

                    case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                        {
                            case SDLK_d:
                                keyD=1;
                                direction=1;
                                perso.x+=5;
                                printf("cordonne ===>%d\n",perso.x);
                                if(perso.x+perso.w>1200)
                                    perso.x-=5;
                                if(collisionPP(perso,maske)!=0)
                                {
                                    lvl=1;
                                    perso.x=200;
                                    perso.y=150;
                                }
                            break;

                            case SDLK_q:
                                keyQ=1;
                                direction=2;
                                perso.x-=5;
                                printf("cordonne ===>%d\n",perso.x);
                                if(perso.x<0)
                                    perso.x+=5;
                                if(collisionPP(perso,maske)!=0)
                                {
                                    lvl=1;
                                    perso.x=200;
                                    perso.y=150;
                                }
                            break;
                            case SDLK_z:
                                perso.y-=5;
                                printf("cordonne ===>%d\n",perso.y);
                                
                                if(collisionPP(perso,maske)!=0)
                                {
                                    lvl=1;
                                    perso.x=200;
                                    perso.y=150;
                                }
                            break;
                            case SDLK_s:
                                perso.y+=5;
                                printf("cordonne ===>%d\n",perso.y);
                                
                                if(collisionPP(perso,maske)!=0)
                                {
                                    lvl=1;
                                    perso.x=200;
                                    perso.y=150;
                                }
                            break;
                        }
                    break;
                    case SDL_KEYUP:
                        switch(event.key.keysym.sym)
                        {
                        case SDLK_d:
                            keyD=0;
                            break;
                        
                        case SDLK_q:
                            keyQ=0;
                            break;
                        }
                    break;
                }
            }
            Afficher_Background(BK1,Screen);
            SDL_FillRect(Screen,&perso,colorP);
            SDL_FillRect(Screen,&maske,colorM);
            
            SDL_Flip(Screen);
        }

        else if(lvl==1)
        {
            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                    case SDL_QUIT:
                    loop=0;
                    break;

                    case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                        {
                            case SDLK_d:
                                perso.x+=5;
                                printf("cordonne ===>%d\n",perso.x);
                                if(perso.x+perso.w>1200)
                                    perso.x-=5;
                                if(collisionPP(perso,maske)!=0)
                                {
                                    lvl=2;
                                    perso.x=200;
                                    perso.y=150;
                                }
                            break;

                            case SDLK_q:
                                direction=2;
                                perso.x+=5;
                                printf("cordonne ===>%d\n",perso.x);
                                if(perso.x<0)
                                    perso.x+=5;
                                if(collisionPP(perso,maske)!=0)
                                {
                                    lvl=2;
                                    perso.x=200;
                                    perso.y=150;
                                }
                            break;

                            case SDLK_z:
                                perso.y-=5;
                                printf("cordonne ===>%d\n",perso.y);
                                
                                if(collisionPP(perso,maske)!=0)
                                {
                                    lvl=2;
                                    perso.x=200;
                                    perso.y=150;
                                }
                            break;

                            case SDLK_s:
                                perso.y+=5;
                                printf("cordonne ===>%d\n",perso.y);
                                
                                if(collisionPP(perso,maske)!=0)
                                {
                                    lvl=2;
                                    perso.x=200;
                                    perso.y=150;
                                }
                            break;
                        }
                    break;
                }
            }
            Afficher_Background(BK2,Screen);
            SDL_FillRect(Screen,&perso,colorP);
            SDL_FillRect(Screen,&maske,colorM);
            
            SDL_Flip(Screen);
        }

        else
        {
            printf("gameover!\n");
            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                    case SDL_QUIT:
                    loop=0;
                    break;
                    case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_ESCAPE:
                                lvl=0;
                            break;
                        }
                    break;
                }
                    
            }
        } 
    }while(loop!=0);
    
    SDL_FreeSurface(Screen);
    SDL_FreeSurface(BK1.img);
    SDL_FreeSurface(BK2.img);
    SDL_FreeSurface(BK3.img);
    
    SDL_Quit();
    return 0;
}