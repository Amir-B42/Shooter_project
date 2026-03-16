#include "allshit.h"

typedef struct Monster {int name; int hp; int atk;} Monster;

typedef struct Weapon {int name; int atk; int atk_spd; char* desc;} Weapon;

typedef struct Player {int hp; Weapon weapon; int atk; int atk_speed; int state;} Player; //+ def, +skills, espérons
//0 is neutral, 1 is i-frame, 2 is special, the queen is dead

typedef enum DIR {N,O,E,S,NO,NE,SO,SE} DIR; 

typedef struct projectile {DIR dir; int dmg; int x_pos; int y_pos;} Projectile;

int yrow = 40;
int ycol = 140;
char yboard[40][140];  //Might become une matrice de char* pour l'esthétique
char select_boost[35][15];
char hp_bar[15];
char exp_bar[100];


//pos variables
int ypos = 25; //pos de son oreille gauche
int xpos = 25;

int iframes = 0;

//enemies variable
int max_on_screen_ennemies = 5;
int on_screen_ennemies = 0;
int max_proj_in_play = 15;
int proj_in_play = 0;
Projectile** projectiles_in_play[15];
DIR aim = E;

void sprite_player(int s, DIR aim){ //s for state
    switch(s){
        case 0:
            yboard[xpos][ypos] = '('; yboard[xpos][ypos+1] = '\\'; yboard[xpos][ypos+2] = '_'; yboard[xpos][ypos+3] = '/';yboard[xpos][ypos+4] = ')';
            yboard[xpos+1][ypos] = '('; yboard[xpos+1][ypos+1] = 'o'; yboard[xpos+1][ypos+2] = 'v'; yboard[xpos+1][ypos+3] = 'o';yboard[xpos+1][ypos+4] = ')';
            yboard[xpos+2][ypos] = '/'; yboard[xpos+2][ypos+1] = '>'; yboard[xpos+2][ypos+2] = 'D'; yboard[xpos+2][ypos+3] = '=';yboard[xpos+2][ypos+4] = '>';
            break;
        case 95:
            yboard[xpos][ypos] = '(';yboard[xpos][ypos+1] = '\\';yboard[xpos][ypos+2] = '(';yboard[xpos][ypos+3] = '\\';
            yboard[xpos+1][ypos] = '(';yboard[xpos+1][ypos+1] = '-';yboard[xpos+1][ypos+2] = '.';yboard[xpos+1][ypos+3] = '-';yboard[xpos+1][ypos+4] = ')';
            yboard[xpos+2][ypos-1] = '(';yboard[xpos+2][ypos+1] = '>';yboard[xpos+2][ypos+2] = 'D';yboard[xpos+2][ypos+3] = '=';yboard[xpos+2][ypos+4] = '>';
            break;
        case 1:
            yboard[xpos][ypos] = '(';yboard[xpos][ypos+1] = '\\';yboard[xpos][ypos+2] = '_';yboard[xpos][ypos+3] = '/';yboard[xpos][ypos+4] = ')';
            yboard[xpos+1][ypos] = '(';yboard[xpos+1][ypos+1] = 'o';yboard[xpos+1][ypos+2] = 'v';yboard[xpos+1][ypos+3] = 'o';yboard[xpos+1][ypos+4] = ')';
            yboard[xpos+2][ypos] = '/';yboard[xpos+2][ypos+1] = '>';yboard[xpos+2][ypos+2] = 'D';yboard[xpos+2][ypos+3] = '=';yboard[xpos+2][ypos+4] = '>';
            break;
        case 2:
            yboard[xpos][ypos] = '(';yboard[xpos][ypos+1] = '\\';yboard[xpos][ypos+2] = '_';yboard[xpos][ypos+3] = '/';yboard[xpos][ypos+4] = ')';
            yboard[xpos+1][ypos] = '(';yboard[xpos+1][ypos+1] = 'o';yboard[xpos+1][ypos+2] = 'v';yboard[xpos+1][ypos+3] = 'o';yboard[xpos+1][ypos+4] = ')';
            yboard[xpos+2][ypos] = '/';yboard[xpos+2][ypos+1] = '>';yboard[xpos+2][ypos+2] = 'D';yboard[xpos+2][ypos+3] = '=';yboard[xpos+2][ypos+4] = '>';
            break;
    }
    switch(aim){
        case 2: yboard[xpos+1][ypos+5] = '>';break;
        case 0: yboard[xpos-1][ypos+2] = '^';break;
        case 1: yboard[xpos+1][ypos-1] = '<';break;
        case 3: yboard[xpos+3][ypos+2] = 'v';break;
    }
}

void init_yellowboard(int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(j==0||i==0||j==col-1||i==row-1) yboard[i][j] = '#';
            else yboard[i][j] = ' ';
        }
    }
    sprite_player(0,E);
}

void suppr_fleches(){
    yboard[xpos+1][ypos+5] = ' ';//suppr les fleches
    yboard[xpos-1][ypos+2] = ' ';
    yboard[xpos+1][ypos-1] = ' ';
    yboard[xpos+3][ypos+2] = ' ';
}

void init_ennemy(char* name, int x_pos, int y_pos){
    Monster* dude = malloc(sizeof(Monster));
}

void shoot(Weapon* weapon, DIR aim,int atk){
    switch(weapon->name){
        case 0 : 
            switch(aim){
                case N : yboard[xpos-2][ypos+2] = 'O';
                    Projectile* new_p = malloc(sizeof(Projectile));
                    new_p -> dir = N; new_p-> dmg = atk+weapon->atk;
                    append(projectiles_in_play,new_p);
                    break;
                case O : yboard[xpos+1][ypos-2] = 'O';
                    break;
                case E : yboard[xpos+1][ypos+6] = 'O';
                    break;
                case S : yboard[xpos+4][ypos+2] = 'O';
                    break;
            }
    }
}

void move_proj(){
    for(int i=0;i<max_proj_in_play;i++){
        switch(projectiles_in_play[i]->dir){
            case N :
                yboard[projectiles_in_play[i]->y_pos][projectiles_in_play[i]->x_pos]
        }
    }
}

void view_weapon(Weapon* weapon, DIR aim){
    switch(weapon->name){
        case 0:
            printf("Description : %s \nAtk : %d \nAtk speed : %ds \n", weapon->desc,weapon->atk,weapon->atk_spd);
    }
}

void weapon_list(){ 
    printf("Voici toutes les armes que ce stupide jeu a à vous offrir : \n 1- Regular gun \n 2- 3-barrel regular gun \n 3- Shotgun \n 4- Nodachi \n 5- Rapier \n 6- Master sword \n 7- 2 Boomerangs "); fflush(stdout);
}

void ennemy_list(){
    
}

void menu_yellowbuster();

///Fonction maîtresse
void yellowbuster(){ //10 minutes
    long refresh_time = 100000;
    Player* player = malloc(sizeof(Player)); // Aim avec ZQSD, mouv with OKLM, tir avec  ,
    player->hp = 15;
    player-> atk = 1;
    player->state = 0;
    bool is_ded = false;
    unsigned long timer = 0;
    printf("Mainteant, choisissez");fflush(stdout);
    printf("Great choice ! \nMaintenant, choisissez la durée (approximative vu que j'ai juste fait des approximations du nombre de ticks par secondes) de la partie : \n 1- 60 segments (THat's literally just for me and my test, stp respecte mon jeu) \n 2- 200 segments (ça fait 3min20, ok duration) \n 3- 5 minutes (compte le nb de segments j'ai la flemme) \n 4- 950 segmments \n 5- 600 segments \n 6- Finalement non \nInput : "); fflush(stdout);
    fflush(stdout);
    unsigned long seg = 1000000; //(1 million, 10**6)ticks
    int n = getchar() -48;
    last_refresh = clock();
    switch(n){
        case 6 : 
            printf("Alright bye"); fflush(stdout); sleep(1); menu_yellowbuster();break;
        case 1 : timer = 60*seg; break;
        case 2 : timer = 200*seg; break;
        case 3 : timer = 300*seg; break;
        case 4 : timer = 950*seg; break;
        case 5 : timer = 600*seg; break;
    }
    init_yellowboard(yrow,ycol);
    while(!is_ded && timer >= 0){
        now = clock();
        int inp = getch()-96;
            switch(inp){
                case 26 : //z
                    if(xpos != 1) { 
                        yboard[xpos+2][ypos] = ' ';
                        yboard[xpos+2][ypos+1] = ' ';
                        yboard[xpos+2][ypos+2] = ' ';
                        yboard[xpos+2][ypos+3] = ' ';
                        yboard[xpos+2][ypos+4] = ' ';
                        yboard[xpos+1][ypos+5] = ' ';//suppr les fleches
                        yboard[xpos-1][ypos+2] = ' ';
                        yboard[xpos+1][ypos-1] = ' ';
                        yboard[xpos+3][ypos+2] = ' ';
                        xpos--;
                        break;
                    }
                    
                case 17 : //q
                    if(ypos != 1) {
                        yboard[xpos][ypos+4] = ' ';
                        yboard[xpos+1][ypos+4] = ' ';
                        yboard[xpos+2][ypos+4] = ' ';
                        suppr_fleches();
                        ypos--;
                        break;
                    }
                case 19 : //s
                    if(xpos != yrow-2-3) {
                        yboard[xpos][ypos] = ' ';
                        yboard[xpos][ypos+1] = ' ';
                        yboard[xpos][ypos+2] = ' ';
                        yboard[xpos][ypos+3] = ' ';
                        yboard[xpos][ypos+4] = ' ';
                        suppr_fleches();
                        xpos++;
                        break;
                    }
                case 4 :  //d
                    if(ypos != ycol-2-5) { 
                        yboard[xpos][ypos] = ' ';
                        yboard[xpos+1][ypos] = ' ';
                        yboard[xpos+2][ypos] = ' ';
                        yboard[xpos+3][ypos] = ' ';
                        yboard[xpos+4][ypos] = ' ';
                        suppr_fleches();
                        ypos++;
                        break;
                    }
                    
                case 15 : //o
                    aim = N; suppr_fleches(); break;
                case 11 : //k
                    aim = O; suppr_fleches(); break;
                case 12 : //l
                    aim = S; suppr_fleches(); break;
                case 13 : //m
                    aim = E; suppr_fleches(); break;
                case -64:
                    shoot(&player->weapon,aim); break;
            }
        if(now-last_refresh > refresh_time){
            last_refresh = now;
            sprite_player(player->state,aim);
            print_board(yrow,ycol,yboard);
        }
    }
}

void menu_yellowbuster(){
    clear();
    printf("\t YELLOWBUSTER (still a terrible name mais j'avais zéro inspi) \nWelcome to this beautiful game of my own creation (wasn't my own creation at all)\n But anyway, with one further ado before you choose, le jeu a été fait pour être joué avec une grande fenêtre, mais genre vraiment grande, genre le max possible qui recouvre tout l'écran en mode plein écran, just so you know. \nNow you may choose : \n 1- Jouer \n 2- Collection d'armes \n 3- Listes des ennemis (you might really wanna check that out (Or you a manly man and learn on the brawl, respect for that))\n 4- Revenir au menu principal principal \n Input : "); fflush(stdout);
    int n = getchar() -48;
    clear_buffer();
    //bool here = true;
    switch(n){
        case 1: yellowbuster(); break;
        case 4: printf("Buh-bye loser"); fflush(stdout); sleep(1); menu(); break;
    }
}




/* Design drafts :

The guy (Or girl, depends how you look at it) :

 (\_/)
 (ovo) neutral
 />D=>    <- (that's his gun btw)
 
 (\_/)
 (O~O) damaged (while i-frames (and blinking too, normalement j'ai assez de frames pour ça))
 />D=>
 
 (\_/)
 (oOo) shooketh  (When he finds a crazy upgrade or idk, sera sûrement un cool easter egg in later developpement period)
 />D=>
 
  (\(\
  (-.-)
 O(_(")(") eepy (aka ded)

Ennemies : interdit d'utiliser un symbole extérieur de player cad ()\/_>D=
 
 X (ouais nan déso les ennemis ça sera des X)
 
 X  <- normal X   (very self_explanatory (can diag(maybe ?(will preshot ?))))
 
 |X| kamikaze X (pk pas) (self explanatory (Nier kamikaze flashback))
 
 A
 X sniper x  (Flees player)
 
 [X] Burly X (while shield protects (2 hits per shiled mayb), then become normal)
 
Bosses :
 
 XX
 XX   4 Xs, self-explanatory
 
  |
 -X- spiky boeh (Harrasses you (slowly tho (unless moron)))
  |
  
 O ,pour renta le pong
 
   V
 <><>  separator (moves in sin / -sin pattern)

*/


//dramatic space

/* Idees 
skills : ultra laser (single direction, non cancellable) / cross diagonal attack (petit charge up) /
*/






















