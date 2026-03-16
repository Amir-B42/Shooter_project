#include "allshit.h"
// #include <bits/stdc++.h>


/// Alternative plus 'trans-plateforme' que 'system("clear")'
//On dit cross-platforme btw


//ideas : Un jeu survival / fruit drop / Plateforme (jump knight) / fenêtre faux 3D en FP / Shoot the target / Tetris / Rythm game
// Priority queue : Survival, Tetris, 

/// /!\ Ne pas toucher à cette fonction, je ne la comprend pas.
// Gets a char from STDIN
// Returns immediatly, even if STDIN is empty
// in which case it returns ?
/*
int getch() 
{ 
    int ch;
    struct termios oldattr, newattr;

    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~ICANON;
    newattr.c_lflag &= ~ECHO;
    newattr.c_cc[VMIN] = 1;
    newattr.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    struct pollfd mypoll = { STDIN_FILENO, POLLIN|POLLPRI };
    
    if( poll(&mypoll, 1, acquisition_time) )
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);

    return ch; 
}
*/
// That was OPTION 1.

// OPTION 2 : 
// Source - https://stackoverflow.com/a/36431056
// Posted by Johnny Cage, modified by community. See post 'Timeline' for change history
// Retrieved 2026-02-18, License - CC BY-SA 3.0

// immediate mode getchar().
static int getch_lower_(int block)
{
    struct termios tc = {};
    int status;
    char rdbuf;
    // retrieve initial settings.
    if (tcgetattr(STDIN_FILENO, &tc) < 0)
        perror("tcgetattr()");
    // non-canonical mode; no echo.
    tc.c_lflag &= ~(ICANON | ECHO);
    tc.c_cc[VMIN] = block ? 1 : 0; // bytes until read unblocks.
    tc.c_cc[VTIME] = 0; // timeout.
    if (tcsetattr(STDIN_FILENO, TCSANOW, &tc) < 0)
        perror("tcsetattr()");
    // read char.
    if ((status = read(STDIN_FILENO, &rdbuf, 1)) < 0)
        perror("read()");
    // restore initial settings.
    tc.c_lflag |= (ICANON | ECHO);
    if (tcsetattr(STDIN_FILENO, TCSADRAIN, &tc) < 0)
        perror("tcsetattr()");
    return (status > 0) ? rdbuf : EOF;
}
/*
int getch(void)
{
    return getch_lower_(1);
}
*/
// return EOF if no input available.
int getch(void)
{
    return getch_lower_(0);
}
/// Fin /!\


///Variables globales

// Time variables
  clock_t last_refresh, now; 

/*void sleep(long t){
    clock_t z = clock();
    now = clock();
    while(now-z <= t){
        now = clock();
    }
}*/
  
//Dramatic_variables
int dramatic_number_of_times_user_fumbled = 0;
bool dramatic_user_is_a_moron = false;



/// DEBUT FONCTIONS TESTS : à remplacer par les votres.
// Prints the game board.
void print_board(int row, int col, char board[row][col]) {
  clear();fflush(stdout);
  for (int i = 0; i <row; i++) {
    for (int j = 0; j < col; j++)
      printf("%c", board[i][j]) ;
    printf("\n");
  }
  fflush(stdout);
}

// Applies Gravity to the board.
void gravity(int row, int col, char board[row][col]) {
  int pos = 4 ;
  int height = 1 ; 
  for (int i = 1; i < row; i++) {
    for (int j = pos+1; j < col; j++)
      if (board[i][j] == 'O') {
	board[i][j] = ' ' ;
	if (i > 1)
	  board[i-1][j] = 'O' ;
      }
  }
}



// Initialize the board.
void init_board_prof(int row, int col, char board[row][col]) {
  for (int j = 0; j < col; j++) {
    board[0][j] = 'M' ;
  } //Sus de le faire à l'envers mais why not
  for (int i = 1; i < row; i++) {
    for (int j = 0; j < col; j++)
      board[i][j] = ' ' ;
  }
  int pos = 4 ;
  int height = 1 ; 
  board[height+2][pos] = 'O' ;
  board[height+1][pos] = '|' ;
  board[height+1][pos+1] = '-' ;
  board[height][pos-1] = '/' ;
  board[height][pos+1] = '\\' ;
}
/// FIN FONCTION TESTS.

void print_bigger(char c){
    switch(c){
        case 'A' :
            break;
    }
}

void print_smaller(char c){
    
}

void mot_anime(char* s){
    printf("%s",s);
}

void sleep_float(double seconds) {
    struct timespec ts;
    ts.tv_sec = (time_t)seconds;                          // Partie entière
    ts.tv_nsec = (long)((seconds - ts.tv_sec) * 1e9);     // Partie décimale en nanosecondes

    nanosleep(&ts, NULL);
}

void print_flush(char* s, long duration){
    int i = 0;
    clock_t t = clock();
    clock_t last = clock();
    while (s[i] != '\0'){
        last = clock();
        if(last-t > duration){
            t = last;
            printf("%c",s[i]);fflush(stdout);
            //sleep_float(duration);
            i++;
        }
    }
    printf("\n");
}

void clear_buffer(){
    int c = getchar();
    while (c != '\n' && c != EOF) c = getchar() ; // On "mange" tout jusqu'au \n
}

void dramatic_error_because_dumbass_user_a_appuyersurentreesansrienecrire(){
    long dramatic_time = 100000;
    int dramatic_n = 3;
    last_refresh = clock();
    switch(dramatic_number_of_times_user_fumbled){
        case 0:
        while(dramatic_n != 0){
            now = clock();
            if(last_refresh - now > dramatic_time){
                printf(".");
                fflush(stdout);
                last_refresh = now;
                dramatic_n--;
            }
            print_flush("Eh bien...\n",100000);
            sleep(1);
            printf("On dirait que... \n",1000);
            sleep(1);
            printf("Tu as comme qui dirais...\n",900);
            sleep(1);
            printf("Appuyé(e)(s) sur entrée mais sans rien écrire...?\n",900);
            sleep(2);
            printf("C'est une erreur, n'est-ce pas ? J'ose espérer que c'est une erreur, car sinon...\n",900);
            sleep(1);
            printf("Pour cette fois on va dire que c'était juste une maladresse, donc ça va.\n",1000);
            sleep(1);
            printf("Mais j'espère que tu feras plus attention à l'avenir.\n",1000);
            sleep(2);
            //dramatic_user_is_a_moron = true;
            dramatic_number_of_times_user_fumbled++;
            break;
        }
        case 1:
            printf("Encore ?");
            sleep(5);
            printf("Vois tu, je commence à douter du caractère accidentel de tes actions... ");
            sleep(2);
            printf("Mais on va dire que tout le monde fait des erreurs");
            sleep(1);
            printf("Une Dernière erreur...");
            sleep(3);
            dramatic_number_of_times_user_fumbled++;
            break;
        case 2:
            print_flush("Hahahahahahaha...",100000);
            sleep(1);
            printf("C'est bon, j'en ai assez \n");
            sleep(1);
            printf("Tu seras punis pour tes actions");
            dramatic_user_is_a_moron = true;
            dramatic_number_of_times_user_fumbled++;
            break;
    }
}

void menu(){
    clear();
    bool is_here = true;
    mot_anime("\tMENU PRINCIPAL \n");
    printf("Yo, très cher player. Tu entres ici dans mon antre (rip les non français). M'enfin bref, sans plus de blabla, choisi ton jeu ! (et par pitié, je t'en SUPPLIE, commence pas à écrire des choses bizarres sur le terminal car on se connait, je n'ai absolument pas traité ces cas)\nNB : Quand on demande un input, on attends toujours un char, donc dans le cas où plus d'un caractère est entré, seul le premier compte, de plus si vous appuyez sur entrée sans input, il va considérer que vous avez écrit entrée, donc faut reappuyer sur entrée (Mais personne appuyerait juste sur entré sans input n'est-ce-pas ?).\n C'est valable pour chaque input demandé  \n");
    printf("\n 1- Yellow Buster (stupid name ik) \n 2- Tetris \n 3- Jumping knight \n 4- Pjsk \n 5- Pong (ouah le vieeeeuuux) \n n- Nous quitter :( \n Input (char only) :");fflush(stdout);
    while(is_here){
        int n = getchar() - 48;
        //getchar();
        clear_buffer(); //Le bazooka pour tuer la mouche (mais sait-on jamais, les users sont bizarres (bazooka qui n'aura finalement mm pas marché(nvm il marche)));
        switch(n){
            case -38 : dramatic_error_because_dumbass_user_a_appuyersurentreesansrienecrire(); menu();break;
            case 1 : menu_yellowbuster(); break;
            case 2 : menu_tetris(); break;
            case 3 : jumpingknight(); break;
            case 4 : menu_pjsk(); break;
            case 5 : menu_pong(); break;
            case 6 :
                printf("You sure you wanna quit ? Y/N : ");fflush(stdout);
                char c = getchar();
                if (c == 'y' || c == 'Y'){
                    printf("Aight, it was nice knowing you... See ya someday ig ! (ig stands for incredible gamer btw <3)");fflush(stdout);break;
                    is_here = false;
                    break;
                }
                else{
                    if(c == 'N' || c == 'n'){ printf("Uh, Ok, that was awkward... anyway");fflush(stdout);sleep(2); menu();break;}
                }
            case 62 : printf("BAHAHAHHAHAHAHAHAHAHA, il a vraiment écrit n *Rolling on the floor mocking you*. Mais plus sérieusement, use your noggin'"); fflush(stdout);sleep(2); menu(); break;
            default : printf("Brother you had a single thing to do, I promise clicking a valid input isn't that hard bro, try again (but don't do something stupid, or I might become Bellagoune)");fflush(stdout);sleep(2);menu(); break;
        }
    }
    //assert(42==1);
}

int main_du_prof () {
    
    
  /// Variable For Timers
  long gravity_time = 50000 ; //Intervalle entre les refreshs


    /// A adapter.
  // Init Board
  char board[15][100] ;
  int row = 15 ;
  int col = 100 ;
  int pos = 6 ;
  int height = 1 ; 
  init_board_prof(row, col, board);


  /// A comprendre pour adapter.
  // Game Loop
  print_board(row, col, board) ;
  int n = 0 ;
  last_refresh = clock() ;
  
  while (n != -1) {
    int n  = getch () - 48;
    if (0 <= n && n < col) {
      board[row-1][n+pos] = 'O' ;
      print_board(row, col, board) ;
    }
    now = clock() ;
    if (now - last_refresh > gravity_time) {
        last_refresh = now ;
      gravity(row, col, board) ;
      print_board(row, col, board) ;
    }

  }    
}



/// DRAFT : des design d'obstacles.
/*
 O      X
 |-     X
/ \     X



 O
 OO
 OOO

    /\
   /  \
  /    \
 /      \


 ||---------||
 
 
 ________________><___
 
 
 ---------------------
 
 §--------
 
 
 
 

 */
 

void main(){
    srand((unsigned)time(NULL));
    int v = rand()%10 +1;
    int a = rand()%10 +1;
    int e = rand()%10 +1;
    int b = rand()%10 +1;
    printf("%d %d %d %d",v,a,e,b);
    printf ("\033[31;01m_____  \033[00m\033[32;01m_____\033[00m\033[31;01m_____  \033[00m\033[34;01m____\033[00m \n");
    printf ("\033[31;01m_____  \033[00m\033[32;01m_____  \033[00m\033[33;01m_____  \033[00m\033[34;01m____   \033[00m\033[35;01m |   \033[00m\033[36;01m  __\033 \n");
    printf ("\033[31;01m  |    \033[00m\033[32;01m|____  \033[00m\033[33;01m  |    \033[00m\033[34;01m|___|  \033[00m\033[35;01m |   \033[00m\033[36;01m /__\033 \n");
    printf ("\033[31;01m  |    \033[00m\033[32;01m|____  \033[00m\033[33;01m  |    \033[00m\033[34;01m|  \\   \033[00m\033[35;01m |   \033[00m\033[36;01m  __/\033\n");
    printf ("\033[31;01mBonjour rouge\033[00m\n");
    printf ("\033[32;01mBonjour vert\033[00m\n");
    printf ("\033[33;01mBonjour JAUNE\033[00m\n");
    printf ("\033[34;01mBonjour bleu\033[00m\n");
    printf ("\033[35;01mBonjour violet\033[00m\n");
    printf ("\033[36;01mBonjour bleu ciel\033[00m\n");
    printf ("\033[37;01mBonjour blanc\033[00m\n");
    menu();
    int n = getchar()-97;
    printf("%c",n);
    //main_du_prof();
}
 
 
 
 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
