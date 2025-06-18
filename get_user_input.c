#include "define.h"
#include "func.h"

int f_1306_get_user_input(char input[]) {
    char buffer[100];  // 넉넉하게 선언

    while (1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF); // 입력 버퍼 비우기

        printf("단어를 입력하세요 (5글자): ");

        // 입력 오류 발생 시
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("입력 오류 발생. 다시 시도하세요.\n");
            continue;
        }

        // 개행 문자 제거
        buffer[strcspn(buffer, "\n")] = '\0';

        // 입력이 5글자가 아닐 시
        if (strlen(buffer) != WORD_LENGTH) {
            printf("입력 오류: 정확히 5글자 단어를 입력해주세요.\n");
            continue;
        }

        // 모두 대문자로 변환
        for (int i = 0; i < WORD_LENGTH; i++) {
            input[i] = toupper(buffer[i]);
        }
        input[WORD_LENGTH] = '\0';

        break;
    }

    return 0;
}
