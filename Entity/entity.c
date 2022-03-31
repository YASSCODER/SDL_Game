#include"entity.h"

void init_Entity(Entity *ennemi)
{
    //init spritesheet :

    ennemi->Spritesheet=IMG_Load("spritesheet.png");

    //initialisation de la position de l'ennemi : 

    ennemi->position.x=1000;
    ennemi->position.y=600;
    ennemi->position.w=172;
    ennemi->position.h=183;

    //animation position :

    ennemi->animation.x=0;
    ennemi->animation.y=0;
    ennemi->animation.w=172;
    ennemi->animation.h=183;

    //init ennemi direction :

    ennemi->direction=1;     
}
void afficher_ennemi(SDL_Surface *Screen, Entity ennemi)
{
    SDL_BlitSurface(ennemi.Spritesheet,&ennemi.animation,Screen,&ennemi.position);
}
int collisionBB(Entity *ennemi, Player *hero)
{
    if(ennemi->position.x+ennemi->position.w > hero->position.x && ennemi->position.x < hero->position.x+hero->position.w && ennemi->position.y+ennemi->position.h > hero->position.y && ennemi->position.y < hero->position.y+hero->position.h)
        return 1;
    else
        return 0;
}
void movment(Entity *ennemie)
{
    if(ennemie->direction == 1)
    {
        ennemie->position.x +=1;
        if(ennemie->position.x + ennemie->position.w > 1500)
            ennemie->direction=0;
    }

    if(ennemie->direction==0)
    {
       ennemie->position.x-=1;
        if (ennemie->position.x < 985)
            ennemie->direction=1;
    }
}
void annimation( Entity *ennemi)
{
    ennemi->PrevTime=ennemi->curentTime;
    ennemi->curentTime=SDL_GetTicks()/1000.0f;
    ennemi->deltaT=(ennemi->curentTime-ennemi->PrevTime);

    ennemi->timeFrame+=ennemi->deltaT;
    if(ennemi->timeFrame>=0.08f)
    {
        ennemi->timeFrame=0;
        if(ennemi->direction==1)
        {
            ennemi->animation.x+=172;
            if(ennemi->animation.x>860)
                ennemi->animation.x=0;
        }

        if(ennemi->direction==0)    
        {
            ennemi->animation.y=183;
            ennemi->animation.x+=172;
            if(ennemi->animation.x>860)
                ennemi->animation.x=0;
        }
        
    }
}
//void AImovment(Entity *ennemi);