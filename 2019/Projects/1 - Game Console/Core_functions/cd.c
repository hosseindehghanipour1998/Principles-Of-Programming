#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <dirent.h>
char game_file_addr[] = "game file/";
void cd(char * direct){
    strcpy(game_file_addr, "game file/");
    strcat(game_file_addr,direct);
    chdir(game_file_addr);
    opendir(game_file_addr);
}
