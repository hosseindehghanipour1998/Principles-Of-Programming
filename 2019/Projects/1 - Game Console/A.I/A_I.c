#include "Headers/project_header.h"
struct dimension pos;
extern char **game_map;
extern char solidblock, deathblock, moveblock, wall, object;
extern char up, down, left, right, character, Exit;
extern struct opponent opp;
int A_I(int i,int j, struct need * opps){
    int mx, my,c2;
    int x_p_y = opps->ops.y;
    int  x_p_x = opps->ops.x;
    if (((mx = i - x_p_y) < 0)&&(opps->opp_s.flagx_k ==0) && (game_map[x_p_y-1][x_p_x] == ' ' || game_map[x_p_y-1][x_p_x] == opp.dest)) {
        c2 = up;
        opps->opp_s.flagx_k = 1;
        opps->opp_s.flagy_j =0;
        opps->opp_s.flagy_l =0;
    } else if (((my = j - x_p_x) > 0&& opps->opp_s.flagy_l ==0) && (game_map[x_p_y][x_p_x+1] == ' ' || game_map[x_p_y][x_p_x+1] == opp.dest)) {
        c2 = right;
        opps->opp_s.flagx_k= 0;
        opps->opp_s.flagx_i =0;
        opps->opp_s.flagy_j = 1;
    } else if ((((mx = i - x_p_y) > 0)&& (opps->opp_s.flagx_k == 0)) && (game_map[x_p_y+1][x_p_x] == ' ' || game_map[x_p_y+1][x_p_x] == opp.dest)) {
        c2 = down;
        opps->opp_s.flagy_l = 0;
        opps->opp_s.flagx_i =1;
        opps->opp_s.flagy_j = 0;
    } else if (((my = j - x_p_x) < 0&& opps->opp_s.flagy_j == 0) && (game_map[x_p_y][x_p_x-1] == ' ' || game_map[x_p_y][x_p_x-1] == opp.dest)){
        c2 =left;
        opps->opp_s.flagx_k= 0;
        opps->opp_s.flagx_i =0;
        opps->opp_s.flagy_l = 1;
    } else if((mx == 0&& opps->opp_s.flagx_k ==0 )&& (game_map[x_p_y-1][x_p_x] == ' ' || game_map[x_p_y-1][x_p_x] == opp.dest)){
        opps->opp_s.flagy_l = 0;
        opps->opp_s.flagx_i =1;
        opps->opp_s.flagy_j = 0;
        c2 =down;
    } else if((my == 0&& opps->opp_s.flagy_j ==0) && (game_map[x_p_y][x_p_x-1] == ' ' || game_map[x_p_y][x_p_x-1] == opp.dest)){
        opps->opp_s.flagx_k= 0;
        opps->opp_s.flagx_i =0;
        opps->opp_s.flagy_l = 1;
        c2 =left;
    } else if((mx == 0&& opps->opp_s.flagx_k ==0) && (game_map[x_p_y+1][x_p_x] == ' ' || game_map[x_p_y+1][x_p_x] == opp.dest)){
        opps->opp_s.flagy_l = 0;
        opps->opp_s.flagx_i = 1;
        opps->opp_s.flagy_j = 0;
        c2 =down;
    } else if((my == 0&& opps->opp_s.flagy_l ==0) && (game_map[x_p_y][x_p_x+1] == ' ' || game_map[x_p_y][x_p_x+1] == opp.dest)){
        opps->opp_s.flagx_k= 0;
        opps->opp_s.flagx_i =0;
        opps->opp_s.flagy_j = 1;
        c2 =right;
    }else if(opps->opp_s.flagy_j==0 &&(game_map[x_p_y][x_p_x-1] == ' ' || game_map[x_p_y][x_p_x-1] == opp.dest)){
        c2 = left;
        opps->opp_s.flagx_k= 0;
        opps->opp_s.flagx_i =0;
        opps->opp_s.flagy_l = 1;
    }else if(opps->opp_s.flagx_k == 0 &&(game_map[x_p_y+1][x_p_x] == ' ' || game_map[x_p_y+1][x_p_x] == opp.dest)){
        opps->opp_s.flagy_l = 0;
        opps->opp_s.flagx_i =1;
        opps->opp_s.flagy_j = 0;
        c2 = down;
    }else if(opps->opp_s.flagy_l== 0 &&(game_map[x_p_y][x_p_x+1] == ' ' || game_map[x_p_y][x_p_x+1] == opp.dest)){
        c2 = right;
        opps->opp_s.flagx_k= 0;
        opps->opp_s.flagx_i =0;
        opps->opp_s.flagy_j = 1;
    }else if(opps->opp_s.flagx_i == 0 &&(game_map[x_p_y-1][x_p_x] == ' ' || game_map[x_p_y-1][x_p_x] == opp.dest)){
        opps->opp_s.flagx_k= 1;
        opps->opp_s.flagy_l = 0;
        opps->opp_s.flagy_j = 0;
        c2 = up;
    }else if(game_map[x_p_y][x_p_x-1] == ' ' || game_map[x_p_y][x_p_x-1] == opp.dest){
        c2 = left;
        opps->opp_s.flagx_k= 0;
        opps->opp_s.flagx_i =0;
        opps->opp_s.flagy_j = 0;
        opps->opp_s.flagy_l = 1;
    }else if(game_map[x_p_y+1][x_p_x] == ' ' || game_map[x_p_y+1][x_p_x] == opp.dest){
        opps->opp_s.flagx_k= 0;
        opps->opp_s.flagx_i =1;
        opps->opp_s.flagy_j = 0;
        opps->opp_s.flagy_l = 0;
        c2 = down;
    }else if(game_map[x_p_y][x_p_x+1] == ' ' || game_map[x_p_y][x_p_x+1] == opp.dest){
        c2 = right;
        opps->opp_s.flagx_k= 0;
        opps->opp_s.flagx_i =0;
        opps->opp_s.flagy_j = 1;
        opps->opp_s.flagy_l = 0;
    }else if(game_map[x_p_y-1][x_p_x] == ' ' || game_map[x_p_y-1][x_p_x] == opp.dest){
        opps->opp_s.flagx_k= 1;
        opps->opp_s.flagx_i =0;
        opps->opp_s.flagy_j = 0;
        opps->opp_s.flagy_l = 0;
        c2 = up;
    }
    return c2;
}
