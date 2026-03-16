#ifndef ALLSHIT_H
#define ALLSHIT_H
#define clear() printf("\033[H\033[J"); fflush(stdout);
//#define clear() system("clear")
#include <unistd.h>
#include <poll.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <assert.h>


//global shit
void print_board(int row,int col, char board[row][col]);
int getch();
void menu();
void clear_buffer();
void sleep_float(double seconds);
// Time variables
extern clock_t last_refresh, now; 
//dramatic variables
extern int dramatic_number_of_times_user_fumbled;
extern bool dramatic_user_is_a_moron;

//1
void menu_tetris();

//2
void menu_yellowbuster();

//3
void jumpingknight();

//4
void menu_pjsk();

//5
void menu_pong();

#endif
