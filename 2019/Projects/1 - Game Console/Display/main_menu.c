#include <Headers/curses.h>
#include <string.h>
#include <stdlib.h>
#include "Headers/bass.h"
#include "Headers/project_header.h"
extern struct dimension default_term_size;
WINDOW *game_menu;
HSTREAM main_background;
int show_main_menu(){
    static char mesg[4][30] = {"Arcade Game Console", "Play!", "Background Music Off", "Exit"};
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    curs_set(0);
    noecho();
    cbreak();
    clear();
    WINDOW *main_menu = newwin(2*default_term_size.y/3, 2*default_term_size.x/3, default_term_size.y/5 - 1, default_term_size.x/5-4);
    game_menu = newwin(2*default_term_size.y/3, 2*default_term_size.x/3, default_term_size.y/5 - 1, default_term_size.x/5-4);
    keypad(main_menu, TRUE);
    refresh();
    box(main_menu, 0, 0);
    wattron(main_menu, COLOR_PAIR(1));
    mvwprintw(main_menu, 0,(2*default_term_size.x/3-strlen(mesg[0]))/2,"%s",mesg[0]);
    wattroff(main_menu, COLOR_PAIR(1));
    int ch = 0, i = 0;
    for(i=1; i<4; i++) {
        if(i == 1)
            wattron(main_menu, A_STANDOUT);
        else
            wattroff(main_menu, A_STANDOUT);
        mvwprintw(main_menu, 2*(i+1), (2*default_term_size.x/3-strlen(mesg[i]))/2, "%s", mesg[i]);
    }
    wrefresh(main_menu);
    i = 1;
    if(BASS_ChannelIsActive(main_background) != BASS_ACTIVE_PLAYING && strcmp(mesg[2], "Background Music Off") == 0)
        BASS_ChannelPlay(main_background, FALSE);
    while(1) {
        ch = getch();
        mvwprintw(main_menu, 2*(i + 1), (2 * default_term_size.x / 3 - strlen(mesg[i])) / 2, "%s", mesg[i]);
        switch (ch) {
            case KEY_UP:
                i--;
                i = (i < 1) ? 3 : i;
                break;
            case KEY_DOWN:
                i++;
                i = (i > 3) ? 1 : i;
                break;
        }
        wattron(main_menu, A_STANDOUT);
        mvwprintw(main_menu, 2*(i + 1), (2 * default_term_size.x / 3 - strlen(mesg[i])) / 2, "%s", mesg[i]);
        wattroff(main_menu, A_STANDOUT);
        wrefresh(main_menu);
        if(ch == '\n' && i == 1)
            break;
        else if(ch == '\n' && i == 2){
            if(strcmp(mesg[2], "Background Music Off") == 0){
                strcpy(mesg[2], "Background Music On ");
                BASS_ChannelStop(main_background);
            } else{
                strcpy(mesg[2], "Background Music Off");
                BASS_ChannelPlay(main_background, FALSE);
            }
            wmove(main_menu, 2*(2+1), 0);
            wclrtoeol(main_menu);
            box(main_menu, 0, 0);
            wattron(main_menu, COLOR_PAIR(1));
            mvwprintw(main_menu, 0,(2 * default_term_size.x / 3 - strlen(mesg[0])) / 2,"%s",mesg[0]);
            wattroff(main_menu, COLOR_PAIR(1));
            wattron(main_menu, A_STANDOUT);
            mvwprintw(main_menu, 2*(2+1), (2 * default_term_size.x / 3 - strlen(mesg[2])) / 2, "%s", mesg[2]);
            wattroff(main_menu, A_STANDOUT);
            wrefresh(main_menu);
        }
        else if(ch == '\n' && i == 3)
            _Exit(0);
    }
    delwin(main_menu);
    return 0;
}