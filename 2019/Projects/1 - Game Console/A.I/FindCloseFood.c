#include <math.h>
#include <Headers/curses.h>
#include "Headers/project_header.h"
extern struct opponent opp;
extern char **game_map;
extern struct dimension map_size;
int FindCloseFood(struct need *op) {
    register int i, j;
    op->ops.y;
    int best_cdotx = -1, best_cdoty = -1, best_dist = 100000;
    int new_dist;
    for (i = 0; i < map_size.y; i++) {
        for (j = 0; j < map_size.x; j++) {
            if (game_map[i][j] == opp.dest) {
                new_dist = pow((i - op->ops.y), 2) + pow((j - op->ops.x), 2);
                if (new_dist < best_dist) {
                    best_dist = new_dist;
                    best_cdotx = i;
                    best_cdoty = j;
                }
            }
        }
    }
    return A_I(best_cdotx, best_cdoty,op);
}
