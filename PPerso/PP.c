#include"PP.h"
SDL_Surface *LOAD_IMG(char fileName[20])
{
    SDL_Surface *img=NULL;

    img=IMG_Load(fileName);
    if(img==NULL)
    {
        printf("ERROR :> %s\n",SDL_GetError());
    }
    return img;
}
void Init_PP(Hero *myHero)
{
    myHero->SRC.x=0;
    myHero->SRC.y=0;
    myHero->SRC.w=76;
    myHero->SRC.h=110;

    myHero->DST.x=0;
    myHero->DST.y=0;
    myHero->DST.w=76;
    myHero->DST.h=116;

    myHero->vie=100;
    myHero->score=1;
    myHero->direction=0;
    myHero->sprite=LOAD_IMG("Et.png");
}
void Draw_PP(Hero myHero, SDL_Surface *Screen)
{
    
    if(myHero.SRC.x<=860)
    {
        SDL_BlitSurface(myHero.sprite,&myHero.DST,Screen,&myHero.SRC);
        myHero.SRC.x+=172;
    }
        
    
}
void movment_PP(Hero *myHero)
{
    if(myHero->direction==1)
    {
        
        printf("perso.y==> %d\n",myHero->DST.y);
        myHero->SRC.y-=25;
    }
    if(myHero->direction==2)
    {
        printf("ANI HABET\n");
        myHero->SRC.y+=8;
    }
    if(myHero->direction==3)
    {
        printf("ANI mechi al imin\n");
        myHero->SRC.x+=8;
    }
    if(myHero->direction==4)
    {
        printf("ANI mechi al isar\n");
        myHero->SRC.x-=8;
    }
}

int CollisionBB(Hero *myHero, SDL_Rect entity)
{

    if(myHero->SRC.x+myHero->SRC.w > entity.x && myHero->SRC.x < entity.x+entity.w && myHero->SRC.y + myHero->SRC.h > entity.y && myHero->SRC.y < entity.y + entity.h)
    {
        // printf("wselt lel ground\n");
        return 1;
    }
    else
    {
        // printf("ma zelt ma wseltch lel ground \n");
        return 0;
    }
}

void Gravity(Hero *myHero, SDL_Rect entity, int keyZ)
{
    
    printf("keyZ=%d\n",keyZ);
    if(CollisionBB(myHero,entity)==0&&keyZ==0)
    {
        
        myHero->SRC.y++;
        
    }
    // else
    // {
    //     printf("fiwest el boucle\n");
    //     printf("perso.y==> %d\n",myHero->SRC.y);
    // }
}


int Jump_PP(Hero *myHero,int jumpmax)
{
    if(myHero->SRC.y<jumpmax)
    {
        
       return 1;
    }
    else 
        return 0;
}
