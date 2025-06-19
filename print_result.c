#include "define.h"
#include "func.h"

int f_1302_print_result(char user_guess[], char result[]) {
    int is_correct = 1;

    // 사용자가 추측한 입력 값 출력
    printf("추측: ");
    for (int i = 0; i < WORD_LENGTH; i++) {
        printf("%c ", user_guess[i]);
    }

    // 판정 결과 출력(O, ~, X)
    printf("\n결과: ");
    for (int i = 0; i < WORD_LENGTH; i++) {
        printf("%c ", result[i]);
    }
    printf("\n\n");

    // 모든 문자가 정답('O')인지 확인하여 정답 여부 반환
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (result[i] != 'o') {
            is_correct = 0;
            return is_correct; // 아직 틀린 글자 있음
        }
    }

    return is_correct; // 모든 글자 정답
}