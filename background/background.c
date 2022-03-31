#include"background.h"

void init_background1(background *BK)
{
    BK->img=IMG_Load("backgjeux1.jpg");

    BK->src.x=0;
    BK->src.y=0;
    BK->src.w=1200;
    BK->src.h=800;
    BK->music=Mix_LoadMUS("BGmusic.mp3");
	Mix_PlayMusic(BK->music,-1);
    BK->dist.x=0;
    BK->dist.y=0;
    BK->dist.w=1200;
    BK->dist.h=800;
}
void init_background2(background *BK)
{
    BK->img=IMG_Load("index.jpeg");

    BK->src.x=0;
    BK->src.y=0;
    BK->src.w=1200;
    BK->src.h=800;
    BK->music=Mix_LoadMUS("BGmusic.mp3");
	Mix_PlayMusic(BK->music,-1);
    BK->dist.x=0;
    BK->dist.y=0;
    BK->dist.w=1200;
    BK->dist.h=800;
}
void init_background3(background *BK)
{
    BK->img=IMG_Load("");

    BK->src.x=0;
    BK->src.y=0;
    BK->src.w=1200;
    BK->src.h=800;
    BK->music=Mix_LoadMUS("BGmusic.mp3");
	Mix_PlayMusic(BK->music,-1);
    BK->dist.x=0;
    BK->dist.y=0;
    BK->dist.w=1200;
    BK->dist.h=800;
}
void Afficher_Background(background BK, SDL_Surface *screen)
{
    SDL_BlitSurface(BK.img,&BK.src,screen,&BK.dist);
}
void scrolling(background *BK, int direction, int keyD, int keyQ)
{
    if(direction==1&&keyD!=0)
    {
    	BK->src.x++;
    	if(BK->src.x + BK->src.w > 4000)
    		BK->src.x=0;
    }
    
    if(direction==2&&keyQ!=0)
    {
    	BK->src.x--;
    	if(BK->src.x < 0)
    		BK->src.x=0;
    }
      
}
int collisionPP(SDL_Rect perso,SDL_Rect maske1)
{
    if(perso.x + perso.w > maske1.x && perso.x < maske1.x + maske1.w && perso.y + perso.h > maske1.y && perso.y < maske1.y + maske1.h)
    {
        printf("famma colision\n");
        return 1;
    }
    else
    {
        printf("ma fammech colision\n");
        return 0;
    }
}