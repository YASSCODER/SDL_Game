#include "miniMap.h"

int main()
{

    SDL_Surface *Screen, *perso, *roches;
    SDL_Event Event;
    SDL_Rect back , player, bloc, ground, ground1,player1, bloc1;
    Uint32 colorP,colorB;
    Map miniMap;
    int loop=1,timerE=0, direction=0;
    char repense[50];

    SDL_Init(SDL_INIT_AUDIO||SDL_INIT_VIDEO||SDL_INIT_TIMER);
    Screen=SDL_SetVideoMode(1600,800,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
    back.x=0;
    back.y=0;
    back.w=1600;
    back.h=800;

    perso=IMG_Load("perso.png");
    player.x=30;
    player.y=500;
    player.w=32;
    player.h=32;
    colorP=SDL_MapRGB(Screen->format,255,0,0);

    roches=IMG_Load("roches.png");
    bloc.x=100;
    bloc.y=500;
    bloc.w=80;
    bloc.h=150;
    colorB=SDL_MapRGB(Screen->format,0,0,255);

    ground.x=0;
    ground.y=600;
    ground.w=1200;
    ground.h=200;

    player1.x=player.x/4;
    player1.y=player.y/4;
    player1.w=player.w/4;
    player1.h=player.h/4;
    colorP=SDL_MapRGB(Screen->format,255,0,0);

    bloc1.x=bloc.x/4;
    bloc1.y=bloc.y/4;
    bloc1.w=bloc.w/4;
    bloc1.h=bloc.h/4;

    ground1.x=ground.x/4;
    ground1.y=ground.y/4;
    ground1.w=ground.w/4;
    ground1.h=ground.h/4;
    colorB=SDL_MapRGB(Screen->format,0,0,255);


    Init_miniMap(&miniMap);
    SDL_EnableKeyRepeat(60,60);

    do
    {
        gravity(&player,ground,direction);
        gravity(&player1,ground1,direction);
        miniMap.timer=SDL_GetTicks()/1000;
        SDL_FillRect(Screen,&back,0);
        SDL_FillRect(Screen,&player,colorP);
        SDL_FillRect(Screen,&bloc,colorB);//ground fil
        SDL_FillRect(Screen,&ground,colorB);//ground fil
                                            
        Draw_MiniMap(miniMap,Screen);
        
        SDL_FillRect(Screen,&player1,colorP);
        SDL_FillRect(Screen,&bloc1,colorB);//-> ground fil mini map
        SDL_FillRect(Screen,&ground1,colorB);//-> ground fil mini map
        SDL_Flip(Screen);
       
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
                    case SDLK_z:
                        direction=1;
                        player.y-=32;
                        player.x+=8;
                         MAJminiMap(&player1,player,direction); // player1.y-=8;
                        if(player.y<0)
                        {
                            printf("khrajt mel minimap\n");
                            player.y+=8;
                        }
                        if(player1.y<0)
                        {
                            printf("khrajt mel minimap\n");
                            player1.y+=2;
                        }
                        break;
                    
                    case SDLK_s:
                    direction=2;
                       player.y+=8;
                        MAJminiMap(&player1,player,direction);//player1.y+=2;
                       if(player.y+player.h>800)
                        {
                            printf("khrajt mel minimap\n");
                            player.y-=8;
                        }
                       if(player1.y+player1.h>miniMap.posMap.y+miniMap.posMap.h)
                        {
                            printf("khrajt mel minimap\n");
                            player1.y-=2;
                        }
                        break;

                        case SDLK_d:
                        direction=3;
                            player.x+=8;
                            MAJminiMap(&player1,player,direction);  //player1.x+=2; 
                        if(player.x+player.w>1600)
                        {
                            printf("khrajt mel minimap\n");
                            player.x-=8;
                        }
                        if(player1.x+player1.w>miniMap.posMap.x+miniMap.posMap.w)
                        {
                            printf("khrajt mel minimap\n");
                            player1.x-=2;
                        }
                        if(collisionBB(&player,bloc)!=0)
                            player.x-=8;
                        if(collisionBB(&player1,bloc1)!=0)
                            player1.x-=2;
                        break;

                        case SDLK_q:
                            direction=4;
                            player.x-=8;
                             MAJminiMap(&player1,player,direction);// player1.x-=2;
                            if(player.x<0)
                            {
                                printf("khrajt mel minimap\n");
                                player.x+=8;
                            }
                            if(player1.x<0)
                            {
                                printf("khrajt mel minimap\n");
                                player1.x+=2;
                            }
                            break;
                    }
                break;
                case SDL_KEYUP:
                    switch(Event.key.keysym.sym)
                    {
                    case SDLK_z:
                        direction=0;
                        break;
                    
                    default:
                        break;
                    }
                break;
            }
        }
        
        
    } while (loop!=0);
    printf("time in game = %d\n",miniMap.timer);
        SDL_FreeSurface(Screen);
        SDL_FreeSurface(miniMap.img);

    return 0;
}