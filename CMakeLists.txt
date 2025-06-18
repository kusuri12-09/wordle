cmake_minimum_required(VERSION 3.30)
project(wordle C)

set(CMAKE_C_STANDARD 11)

add_executable(wordle
        main.c
        select_random_word.c
        get_user_input.c
        check_guess.c
        print_result.c)
