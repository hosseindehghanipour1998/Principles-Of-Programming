#include <Headers/curses.h>
#include "Headers/bass.h"
#include "Headers/project_header.h"
extern int c;
extern char Exit;
extern struct dimension map_size;
extern WINDOW *game_window;
void show_pause_window(){
    struct dimension win_size;
    static float volume;
    static char mesg[4][10] = {"Paused", "Resume", "Mute", "Quit"};
    win_size.x = 2*map_size.x/3;
    win_size.y = map_size.y/3+1;
    WINDOW *pause_win = newwin(win_size.y, win_size.x ,map_size.y/3, map_size.x/5 - 1);
    box(pause_win, 0, 0);
    wattron(pause_win, COLOR_PAIR(1));
    mvwprintw(pause_win, 0,(win_size.x-strlen(mesg[0]))/2,"%s",mesg[0]);
    wattroff(pause_win, COLOR_PAIR(1));
    int ch = 0, i = 0;
    for(i=1; i<4; i++ ) {
        if(i == 1)
            wattron(pause_win, A_STANDOUT);
        else
            wattroff(pause_win, A_STANDOUT);
        mvwprintw(pause_win, i+1, (win_size.x-strlen(mesg[i]))/2, "%s", mesg[i]);
    }
    wrefresh( pause_win );
    i = 1;
    keypad( pause_win, TRUE );
    while(1) {
        ch = getch();
        mvwprintw(pause_win, i + 1, (win_size.x - strlen(mesg[i])) / 2, "%s", mesg[i]);
        switch (ch) {
            case KEY_UP:
                i--;
                i = (i < 1) ? 2 : i;
                break;
            case KEY_DOWN:
                i++;
                i = (i > 3) ? 1 : i;
                break;
        }
        wattron(pause_win, A_STANDOUT);
        mvwprintw(pause_win, i + 1, (win_size.x - strlen(mesg[i])) / 2, "%s", mesg[i]);
        wattroff(pause_win, A_STANDOUT);
        wrefresh(pause_win);
        if (ch == '\n') {
            if (i == 2) {
                if (strcmp(mesg[2], "Mute") == 0) {
                    strcpy(mesg[2], "Unmute");
                    volume = BASS_GetVolume();
                    BASS_SetVolume(0);
                } else {
                    strcpy(mesg[2], "Mute");
                    BASS_SetVolume(volume);
                }
                wmove(pause_win, 3, 0);
                wclrtoeol(pause_win);
                box(pause_win, 0, 0);
                wattron(pause_win, COLOR_PAIR(1));
                mvwprintw(pause_win, 0,(win_size.x-strlen(mesg[0]))/2,"%s",mesg[0]);
                wattroff(pause_win, COLOR_PAIR(1));
                wattron(pause_win, A_STANDOUT);
                mvwprintw(pause_win, 3, (win_size.x - strlen(mesg[2])) / 2, "%s", mesg[2]);
                wattroff(pause_win, A_STANDOUT);
                wrefresh(pause_win);
            } else if (i == 3) {
                c = Exit;
                return;
            }
            else if(i == 1) {
                c = 0;
                break;
            }
        }
    }
    wrefresh(pause_win);
    delwin(pause_win);
    werase(game_window);
}