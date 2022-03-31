#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "entity.h"

int main()
{
    SDL_Surface *screen;
    SDL_Event Event;

    SDL_Surface *Sprite, *sprite_repos, *spritegauche, *sprite_saut;
    SDL_Rect src,dst,back;

    Entity entity;
    int numFrame,FPS=60,loop=1, frameWeidth, frameHeight;
    float deltaTime = 0,timeFrame=0,prevtime=0,currentTime=0;

    SDL_Init(SDL_INIT_AUDIO||SDL_INIT_VIDEO);
    screen=SDL_SetVideoMode(1400,700,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
    Sprite=IMG_Load("spritesheet.png");
    frameWeidth = 172; // 860 / 5 = 172,..
    frameHeight = 182; // 366/2
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
                    dst.x+=8.1;
                    SDL_BlitSurface(Sprite,&src,screen,&dst); 
                    break;

                case SDLK_q:
                    dst.x-=8.1;
                    
                    break;
                }
            break;
            }
        }
        timeFrame+=deltaTime;
        if(timeFrame >=0.08f)
        {
            timeFrame=0;
            src.x+=frameWeidth;
            if(src.x>860)
                src.x=0;
        }
            SDL_BlitSurface(Sprite,&src,screen,&dst);
            SDL_Flip(screen);   
        printf("time = %0.00fs\n",deltaTime);
    } while (loop!=0);
    SDL_FreeSurface(entity.spritesheet);
    SDL_Quit();
    return 0;
}


/*


void annimation(entity *ennemi)
{
        ennemi->prevtime=ennemi->currentTime;
        ennemi->currentTime=SDL_GetTicks()/1000.0f;
        ennemi->deltaTime=(ennemi->currentTime-ennemi->prevtime);
        ennemi->timeFrame+=ennemi->deltaTime;

        if(ennemi->timeFrame >=0.08f&&ennemi->direction==1)
        {
            timeFrame=0;
            ennemi->rectAnimation.x+=frameWeidth;
            if(ennemi->rectAnimation.x>860)
                src.x=0;
        }

        if(ennemi->timeFrame >=0.08f&&ennemi->direction==0)
        {
            ennemi->timeFrame=0;
            ennemi->rectAnimation.y=183
            ennemi->rectAnimation.x+=frameWeidth;
            if(ennemi->rectAnimation.x>860)
            ennemi->rectAnimation.x=0;
        }
}


void DrawEntity(Entity *ennemi, SDL_Surface *screen)
{
    if(ennemi.direction==1)
    {
        annimation(ennemi);
        SDL_BlitSurface(ennemi->sprite,&ennemi->rectAnnimation,screen,&ennemi->rectPOS);
    }
    if(ennemi.direction==0)
    {
        annimation(ennemi);
        SDL_BlitSurface(ennemi->sprite,&ennemi->rectAnnimation,screen,&ennemi->rectPOS);
    }

}





















*/
