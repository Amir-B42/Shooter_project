#include "allshit.h"


int rowp = 16; //9
int colp = 50; //30

//int x_pos = 15;
//int y_pos = 5;
int p1_pos = 4;//l
int p2_pos = 4;//r
int p3_pos = 25;//u
int p4_pos = 25;//d

char table[16][50]; //[9][30]

void init_table(int row, int col,int max_ball,int* posx,int* posy){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(j==0||i==0||j==col-1||i==row-1) table[i][j] = '#';
            else table[i][j] = ' ';
        }
    }
    table[p1_pos][1] = '|';
    table[p2_pos][col-2] = '|';
    table[1][p3_pos] = '_';
    table[row-2][p4_pos] = '_';
    for(int i=0;i<max_ball;i++){
        table[posy[i]][posx[i]] = 'O';
    }
}

void move_an_o(int* dirx, int* diry, int* y_pos, int* x_pos, int i, bool* l, bool* r, bool* u, bool* d){
    if(diry[i]==1){ //up
        //if(table[ypos[i] -1][xpos[i]] == '_' ) *u = false;
        if(table[y_pos[i] -1][x_pos[i]] == '|'){ if(y_pos[i] == 1) *l = false; else *r = false; }
        if(table[y_pos[i] -1][x_pos[i]] == '_') *u = false;
                            if(y_pos[i] -1 == 0){
                                table[y_pos[i]][x_pos[i]] = ' ';
                                diry[i] = 2;
                                y_pos[i]++;
                                table[y_pos[i]][x_pos[i]] = 'O';
                            }
                            else{table[y_pos[i]][x_pos[i]] = ' ';
                            y_pos[i]--;
                            table[y_pos[i]][x_pos[i]] = 'O';}
            }
            else{
                        //if(table[ypos[i] +1][xpos[i]] == '_') *u = false;
                        if(table[y_pos[i] +1][x_pos[i]] == '|'){ if(x_pos[i] == colp-2) *r = false; else *l = false; }
                        if(table[y_pos[i] +1][x_pos[i]] == '_') *d = false;
                            if(y_pos[i] +1 == rowp-1){
                                diry[i] = 1;
                                table[y_pos[i]][x_pos[i]] = ' ';
                                y_pos[i]--;
                                table[y_pos[i]][x_pos[i]] = 'O';
                            }
                            else{table[y_pos[i]][x_pos[i]] = ' ';
                            y_pos[i]++;
                            table[y_pos[i]][x_pos[i]] = 'O';}
            }
            if(dirx[i] ==1){
                    if(table[y_pos[i]][x_pos[i] +1] == '_'){ if (y_pos[i] == 1) *u = false; else *d = false;}
                    if(table[y_pos[i]][x_pos[i] +1] == '|') *r = false;
                    if(x_pos[i] +1 == colp-1){ // || table[y_pos][x_pos+1] == '|'){
                        dirx[i] = 2;
                        table[y_pos[i]][x_pos[i]] = ' ';
                        x_pos[i]--;
                        table[y_pos[i]][x_pos[i]] = 'O';
                    }
                    else{ table[y_pos[i]][x_pos[i]] = ' ';
                    x_pos[i]++;
                    table[y_pos[i]][x_pos[i]] = 'O';}
                    
            }
            
            else{
                if(table[y_pos[i]][x_pos[i] -1] == '_'){ if (y_pos[i] == 1) *u = false; else *d = false;}
                if(table[y_pos[i]][x_pos[i] -1] == '|') *l = false;
                if(x_pos[i] -1 == 0){ // || table[y_pos][x_pos-1] == '|'){
                        dirx[i] = 1;
                        table[y_pos[i]][x_pos[i]] = ' ';
                        x_pos[i]++;
                        table[y_pos[i]][x_pos[i]] = 'O';
                    }
                    else{table[y_pos[i]][x_pos[i]] = ' ';
                    x_pos[i]--;
                    table[y_pos[i]][x_pos[i]] = 'O';}
            }
}

///Fonction maîtresse
void pong(int max_ball){
    long refresh_time = 100000;
    int chance = rand()%100 +1;
    clock_t start_time = clock();
    bool l = true;
    bool r = true;
    bool u = true;
    bool d = true;
    int* dirx = malloc(sizeof(int)*max_ball); //1 = ->, 2 = <-
    int* diry = malloc(sizeof(int)*max_ball);// 1 = up, 2 = down
    int* posx = malloc(sizeof(int)*max_ball);
    int* posy = malloc(sizeof(int)*max_ball);
    for(int i = 0;i<max_ball;i++){
        dirx[i] = rand()%2 +1;
        diry[i] = rand()%2 +1;
        posy[i] = rand()%(rowp-4) +2;
        posx[i] = rand()%(colp-4) +2;
    }
    init_table(rowp,colp,max_ball,posx,posy);
    last_refresh = clock();
    bool game_is_on = true;
    while(l||r||u||d){
        now = clock();
         int p1 = getch(); //e for up, d for down
        //int p2 = getch(); //o pour en o, l pour Le bas // Scram that, faut mettre 2 char en mm temps pr ça
        if(p1 == 'e' && p1_pos != 1 && l) {table[p1_pos][1] = ' ', table[p1_pos-1][1] = '|'; p1_pos--;}
        if(p1 == 'd' && p1_pos != rowp-2 && l) {table[p1_pos][1] = ' ', table[p1_pos+1][1] = '|'; p1_pos++;}
        if(p1 == 'o' && p2_pos != 1 && r) {table[p2_pos][colp-2] = ' ', table[p2_pos-1][colp-2] = '|'; p2_pos--;}
        if(p1 == 'l' && p2_pos != rowp-2 && r) {table[p2_pos][colp-2] = ' ', table[p2_pos+1][colp-2] = '|'; p2_pos++;}
        if(p1 == 't' && p3_pos != 1 && u) {table[1][p3_pos] = ' ', table[1][p3_pos-1] = '_'; p3_pos--;}
        if(p1 == 'y' && p3_pos != colp-2 && u) {table[1][p3_pos] = ' ', table[1][p3_pos+1] = '_'; p3_pos++;}
        if(p1 == 'v' && p4_pos != 1 && d) {table[rowp-2][p4_pos] = ' ', table[rowp-2][p4_pos-1] = '_'; p4_pos--;}
        if(p1 == 'b' && p4_pos != colp-2 && d) {table[rowp-2][p4_pos] = ' ', table[rowp-2][p4_pos+1] = '_'; p4_pos++;}
        //printf("%d  %d \n",now,last_refresh);fflush(stdout);
        if(now - last_refresh > refresh_time){
            last_refresh = now;
            clear();fflush(stdout);
            print_board(rowp,colp,table); printf("\n Commandes :\n   Lefty : e = up, d = down \n   Righty : o = up, l = down  \n   Uppy : t = left, y = right  \n   Floor : v = left, b = right \n"); 
            
            if(l) {printf("-Lefty is alive  ");fflush(stdout);} else {printf("-Lefty is ded  ");fflush(stdout);}
            if(r) {printf("-Righty is alive \n");fflush(stdout);} else {printf("-Righty ded\n");fflush(stdout);}
            if(u) printf("-Uppy lives  "); else printf("-Uppy ded  ");
            if(d) printf("-Floor is alive\n"); else printf("-Floor is dead\n");
            fflush(stdout);
            for(int i=0;i<max_ball;i++){
                move_an_o(dirx,diry,posy,posx,i,&l,&r,&u,&d);   
            }
        }
        fflush(stdout);
    }
    int duration = (last_refresh - start_time)/1000000 ;
    printf("Welp, bien joué ! (enfin je crois, j'ai pas encore compté la durée)\n %d secondes survécues ! (je crois)",duration); fflush(stdout);
}

void menu_pong(){
    clear();
    printf("Yo, welcome to REVISITED PONG (ouais ça a changé entre temps à cause d'un ptit bug (que j'ai fix), ducoup bug became feature)\n 1- Jouer \n 2- How to play \n 3- Quitter \n Input : "); fflush(stdout);
    int n = getchar() -48;
    clear_buffer();
    switch(n){
        case 1:     
            printf("Select how many balls you want babe girl (/o/) : "); fflush(stdout);
            int balls = getchar() -48; clear_buffer();
            pong(balls); break;
        case 2:
            printf("big flm, DM moi si tu comprends vrm rien, que je puisse me moquer de vous de façon appropriée \n Entrer quelque chose pour revenir au menu "); fflush(stdout); 
            int f = getchar();
            clear_buffer();
            menu_pong();break;
        case 3: printf("Buh-bye loser");fflush(stdout);sleep(1); menu(); break;
        default : printf("Pitié, y'a que 3 chiffres, recommence");fflush(stdout);sleep(1); menu_pong(); break; 
    }
}







/*TODO : 
-Rajouter des ifs pour pas que des fois ça supprime une plaque (enft suffit juste d'échanger l'ordre des déplacements)
-Dormir
-Un peu d'eau aussi c'est important
-Game stop when hit wall (very often)

-Scrap the thing prior
-It's reverse pong, the ball destroys les bouncers
-May explode if moron
*/

/*Ce que j'ai appris de tt ça :
On break pas un if
*/


































