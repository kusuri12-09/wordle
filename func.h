#ifndef WORDLE_FUNC_H
#define WORDLE_FUNC_H

// 함수 정의 헤더파일
void f_1312_select_random_word(char answer_word[], int* max_attempt);
int f_1306_get_user_input(char input[]);
void f_1305_check_guess(const char* answer, const char* input, char* result);
int f_1302_print_result(char user_guess[], char result[]);

#endif //WORDLE_FUNC_H