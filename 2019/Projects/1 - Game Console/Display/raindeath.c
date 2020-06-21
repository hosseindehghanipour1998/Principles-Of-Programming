#include "Headers/project_header.h"
#include <stdlib.h>
extern char deathblock,**game_map;
extern char object;
extern int raindb;
int rain_x,rain_y;
extern int lose_flag;
extern char character;
extern struct opponent opp;
extern struct dimension map_size;
raindbd* del_di(raindbd * head,int x, int y){
    if(head == NULL)
        return head;
    if (head->head.y == y || head->head.x== x){
        raindbd* temp = head->next;
        free(head);
        return temp;
    }else{
        head->next = del_di(head->next,x,y);
        return head;
    }
}
db * del(db * head){
    if (head == NULL)
        return head;
    if(head->head == NULL){
        db* temp = head;
        if(head->next!= NULL)
            head = head->next;
        else
            head = NULL;
        free(temp);
        return head;
    }else{
        head->next = del(head->next);
        return head;
    }
}
raindbd *move_rain(raindbd * head){
    if (head == NULL)
        return head;
    else{
        int x = head->head.x;
        int y = head->head.y;
        if (game_map[y + 1][x] == ' ' && game_map[y][x] == deathblock) {
            game_map[y + 1][x] = game_map[y][x];
            game_map[y][x] = ' ';
            head->head.y++;
            head->head.x = x;
        }else {
            if(game_map[y+1][x] == character && game_map[y][x] == deathblock) {
                lose_flag =1;
            }
            else if(game_map[y+1][x] == opp.rival && game_map[y][x] == deathblock){
                game_map[y+1][x] = ' ';
            }
            game_map[y][x] = ' ';
            head = del_di(head, x, y);
        }
        if(head != NULL)
            head->next = move_rain(head->next);
        return head;
    }
}
db* move_db(db * head){
    if(head == NULL){
        return head;
    }else{
        raindbd*temp = move_rain(head->head);
        head->head = temp;
        head->next = move_db(head->next);
        head = del(head);
        return head;
    }
}
db * add_db(db * head,raindbd * head2){
    if(head == NULL){
        db *temp = (db*)malloc(sizeof(db));
        temp->next = NULL;
        temp->head = head2;
        return temp;
    }else{
        head->next = add_db(head->next,head2);
        return head;
    }
}
raindbd *add_rain (raindbd* head,int x, int y){
    if (head == NULL){
        raindbd* temp = (raindbd *)malloc(sizeof(raindbd));
        temp->head.x = x;
        temp->head.y = y;
        temp->next = NULL;
        return temp;
    }else {
        head ->next = add_rain(head->next,x,y);
        return head;
    }
}
void rain_db(void){
    static db* head = NULL;
    if (raindb == 0){
        return;
    }
    raindbd* temp1;
    temp1 =NULL;
    int counter = 0;
    while (counter != raindb) {
        counter++;
        random_gen(1, deathblock);
        temp1 = add_rain(temp1, rain_x, rain_y);
    }
    head = add_db(head, temp1);
    head = move_db(head);
}