#include "define.h"
#include "func.h"

void f_1312_select_random_word(char answer_word[], int* max_attempt) {
    while (1) {
        printf("시도 횟수를 입력하십시오. (5~10)\n");

        if (scanf("%d", max_attempt) != 1) {
            printf("잘못된 입력입니다. 숫자를 입력하세요.\n\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF); // 입력 버퍼 비우기
            continue;
        }

        if (*max_attempt >= 5 && *max_attempt <= 10) {
            break;
        } else {
            printf("범위에 맞게 다시 입력하세요.\n\n");
        }
    }

    srand(time(NULL));
    int randomIndex = rand() % WORD_COUNT;

    for (int i = 0; i < WORD_LENGTH; i++) {
        answer_word[i] = words[randomIndex][i];
    }
    answer_word[WORD_LENGTH] = '\0';
}