#include <stdlib.h>
#include <Headers/curses.h>
#include <unistd.h>
#include "Headers/project_header.h"
extern struct dimension default_term_size;
int main(int argc, char *argv[]) {
    int c;
    initialization();
    init_pair(3, COLOR_RED, COLOR_BLACK);
    while(1) {
        if(show_main_menu())
            break;
        if ((c = load_config(What_in_it()))) {
            clear();
            attron(COLOR_PAIR(3));
            printw("Error: corrupted game files error code: %d", c);
            printw("\nPress any key to return...");
            attroff(COLOR_PAIR(3));
            getch();
            chdir("..");
            chdir("..");
            cleanup();
            continue;
        }
        ingame_init();
        run_game();
        cleanup();
    }
    return 0;
}
