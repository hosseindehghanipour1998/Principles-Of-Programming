cmake_minimum_required(VERSION 3.13)
project(P_O_P_Main_Project C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-pthread -O3")
include_directories(.)

add_executable(P_O_P_Main_Project
        Config_loader/load_configs.c
        Config_loader/load_map.c
        Config_loader/load_settings.c
        Core_functions/cd.c
        Core_functions/delay.c
        Movement/move_player.c
        Movement/player_movement.c
        Headers/project_header.h
        Core_functions/initialization.c
        main.c
        Display/print_map.c
        Movement/put_dblock.c
        Core_functions/random_gen.c
        run_game.c
        "Display/game_selection_menu.c" Movement/move_comp.c
        A.I/FindCloseFood.c Display/end_of_game.c A.I/A_I.c Display/start_window.c Display/pause_window.c
        Display/raindeath.c
        Core_functions/cleanup.c Movement/attack.c Movement/keyboard_handle.c Display/main_menu.c Core_functions/save_score.c "Core_functions/read_score.c")

target_link_libraries(P_O_P_Main_Project ${CMAKE_SOURCE_DIR}/Libraries/pdcurses.a)
target_link_libraries(P_O_P_Main_Project ${CMAKE_SOURCE_DIR}/Libraries/bass.lib)