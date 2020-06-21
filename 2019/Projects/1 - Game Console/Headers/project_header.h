#ifndef P_O_P_MAIN_PROJECT_PROJECT_HEADER_H
#define P_O_P_MAIN_PROJECT_PROJECT_HEADER_H

#include <stdio.h>

struct rpoint{
    char symbol;
    int score;
    int num;
};

struct opponent{
    char rival;
    char dest;
};

struct put{
    char key;
    char symbol;
    int limit;
};
struct flags{
    int flagx_i,flagx_k,flagy_l,flagy_j;
};
struct dimension{
    int x;
    int y;
};
struct need{
    struct dimension ops;
    struct flags opp_s;
};
typedef struct raindbd{
    struct dimension head;
    struct raindbd *next;
}raindbd;
typedef struct db{
    raindbd *head;
    struct db *next;
}db;
struct file_name{
    char *file;
    struct file_name* next;
};

struct opp_list{
    struct need* ops;
    struct opp_list *next;
};

int load_config(char *);
int load_map(FILE *);
int load_settings(FILE *);
void random_gen(int n,char b);
void initialization();
void move_up(struct need *pos,char obj,int score[],int i);
void move_down(struct need *pos,char obj,int score[],int i);
void move_right(struct need *pos,char obj, int score[],int i);
void move_left(struct need *pos,char obj,int score[],int i);
void move_player(char c);
void print_map();
void hidecursor();
void cd(char *dir);
void run_game();
void put_dblock(struct dimension);
void delay(int number_of_seconds);
char *What_in_it(void);
int A_I(int i,int j,struct need *op);
int FindCloseFood(struct need *op);
void *move_computer(void *);
void show_start_window();
void show_pause_window();
void game_over();
db* move_db(db *);
void debug_output(int w,int b,int i , int j,char l );
void rain_db(void);
void clean_up();
void cleanup();
void att(int direction);
void *keyboard_handle(void *temp);
int show_main_menu();
void ingame_init();
void save_score(void);
void win(void);
void time_limit_reached();
int read_save(void);
#endif
