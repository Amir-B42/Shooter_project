#include "allshit.h"

typedef struct block {bool* cases; int rotate_point;} block; //le rotate_point étant le numéro de la case [1,9]

char tboard[32][12];
int trow = 32;
int tcol = 12;

bool* available_blocks[10];

void tetris_board(int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i==row-1) tboard[i][j] = '_';
            if(j==0||j==col-1) tboard[i][j] = '|';
            else tboard[i][j] = ' ';
        }
    }
}

void rotate(){
    
}

///Fonction maîtresse
void tetris(){
    bool lose = false;
    while(!false){
        
        print_board(trow,tcol,tboard);
    }
}

void menu_tetris(){
    clear();
    fflush(stdout);
    printf ("\033[31;01m_____  \033[00m\033[32;01m_____  \033[00m\033[33;01m_____  \033[00m\033[34;01m____   \033[00m\033[35;01m |   \033[00m\033[36;01m  __\033 \n");
    printf ("\033[31;01m  |    \033[00m\033[32;01m|____  \033[00m\033[33;01m  |    \033[00m\033[34;01m|___|  \033[00m\033[35;01m |   \033[00m\033[36;01m /__\033 \n");  
    printf ("\033[31;01m  |    \033[00m\033[32;01m|____  \033[00m\033[33;01m  |    \033[00m\033[34;01m|  \\   \033[00m\033[35;01m |   \033[00m\033[36;01m  __/\033 \033[37;01m \033[00 \n");     
    printf("m(Pretty cool, huh ? Anyway) \n\n You may now choose, dear player : \n 1- Jouer \n 2- Retour au menu principal \n Input : ");
    fflush(stdout);
    int n = getchar() -48;
    switch(n){
        case 1: tetris(); break;
        case 2: printf("Buh-bye loser");fflush(stdout); break;
    }
}



























