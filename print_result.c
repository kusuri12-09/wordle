#include "define.h"
#include "func.h"

int f_1302_print_result(char user_guess[], char result[]) {
    printf("추측: ");
    for (int i = 0; i < WORD_LENGTH; i++) {
        printf("%c ", user_guess[i]);
    }

    printf("\n결과: ");
    for (int i = 0; i < WORD_LENGTH; i++) {
        printf("%c ", result[i]);
    }
    printf("\n\n");

    for (int i = 0; i < WORD_LENGTH; i++) {
        if (result[i] != 'o') {
            return 0;
        }
    }

    return 1;
}