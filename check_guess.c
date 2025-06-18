#include "define.h"
#include "func.h"

void f_1305_check_guess(const char* answer, const char* input, char* result) {
    int answer_count[26] = {0};
    int used_count[26] = {0};

    for (int i = 0; i < WORD_LENGTH; i++) {
        answer_count[answer[i] - 'A']++;
    }

    for (int i = 0; i < WORD_LENGTH; i++) {
        if (input[i] == answer[i]) {
            result[i] = 'o';
            used_count[input[i] - 'A']++;
        } else {
            result[i] = '?';
        }
    }

    for (int i = 0; i < WORD_LENGTH; i++) {
        if (result[i] == '?') {
            char current_char = input[i];
            int char_index = current_char - 'A';

            if (answer_count[char_index] > used_count[char_index]) {
                result[i] = '~';
                used_count[char_index]++;
            } else {
                result[i] = 'x';
            }
        }
    }

    result[WORD_LENGTH] = '\0';
}
