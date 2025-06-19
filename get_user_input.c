#include "define.h"
#include "func.h"

// 사용자로부터 단어 입력받고 검증하는 함수
int f_1306_get_user_input(char input[]) {
    char buffer[100];  // 입력 버퍼

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF); // 입력 버퍼 비우기

    while (1) {
        printf("단어를 입력하세요 (5글자): ");

        // 문자열 입력 (엔터 포함해서 읽음)
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("입력 오류 발생. 다시 시도하세요.\n");
            continue;
        }

        // 개행 문자 제거
        buffer[strcspn(buffer, "\n")] = '\0';

        // 정확히 5글자인지 확인
        if (strlen(buffer) != WORD_LENGTH) {
            printf("입력 오류: 정확히 5글자 단어를 입력해주세요.\n");
            continue;
        }

        // 입력이 모두 알파벳인지 확인
        int all_alpha = 1;
        for (int i = 0; i < WORD_LENGTH; i++) {
            if (!isalpha(buffer[i])) {
                all_alpha = 0;
                break;
            }
        }
        if (!all_alpha) {
            printf("입력 오류: 알파벳만 입력해주세요.\n");
            continue;
        }

        // 입력을 대문자로 변환하여 저장
        for (int i = 0; i < WORD_LENGTH; i++) {
            input[i] = toupper(buffer[i]);
        }
        input[WORD_LENGTH] = '\0'; // 문자열 종료

        break; // 유효한 입력이면 루프 종료
    }

    return 0;
}