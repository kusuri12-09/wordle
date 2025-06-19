#include "define.h"
#include "func.h"

void f_1312_select_random_word(char answer_word[], int* max_attempt) {
    while (1) {
        printf("시도 횟수를 입력하십시오. (5~10)\n");

        // 정수 입력이 아니면 오류 처리
        if (scanf("%d", max_attempt) != 1) {
            printf("잘못된 입력입니다. 숫자를 입력하세요.\n\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF); // 남은 입력 버퍼 비우기
            continue;
        }

        while (getchar() != '\n'); // 숫자 입력 후 남은 개행 제거

        // 5~10 사이면 입력 성공
        if (*max_attempt >= 5 && *max_attempt <= 10) {
            break;
        } else {
            printf("범위에 맞게 다시 입력하세요.\n\n");
        }
    }

    // 랜덤 시드 초기화
    srand(time(NULL));
    int randomIndex = rand() % WORD_COUNT; // 무작위 인덱스 선택

    // 정답 단어 복사
    for (int i = 0; i < WORD_LENGTH; i++) {
        answer_word[i] = words[randomIndex][i];
    }
    answer_word[WORD_LENGTH] = '\0'; // 문자열 종료 문자 추가
}
