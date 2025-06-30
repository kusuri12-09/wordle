#include <stdio.h>      // 표준 입출력 함수 (printf, scanf 등)
#include <time.h>       // 시간 관련 함수 (srand, time 등)
#include <stdlib.h>     // 난수 함수 (rand, srand 등)
#include <string.h>     // 문자열 처리 함수 (strlen, strcpy 등)
#include <ctype.h>      // 문자 검사 및 변환 함수 (isalpha, toupper 등)

// 매크로 정의
#define WORD_LENGTH 5   // 게임에서 사용할 단어의 길이 (5글자)
#define WORD_COUNT 100  // 단어 목록 개수

// 게임에서 사용할 정답 후보 단어 배열 (5글자 영단어 100개)
const char words[WORD_COUNT][WORD_LENGTH + 1] = {
        // 음식 관련 + 일반 단어 혼합
        "APPLE", "BACON", "BAGEL", "BEANS", "BERRY", "BREAD", "BROTH", "CANDY", "CHILI", "CHIPS",
        "CLOVE", "COCOA", "CREAM", "CRISP", "DONUT", "FLOUR", "FRIES", "FRUIT", "GRAPE", "GRAVY",
        "HONEY", "JELLY", "JERKY", "JUICE", "LEMON", "MANGO", "MEATS", "MELON", "OLIVE", "ONION",
        "PASTA", "PEACH", "PECAN", "PIZZA", "SALAD", "SALSA", "SAUCE", "STEAK", "SUGAR", "SUSHI",
        "SYRUP", "TACOS", "TOAST", "WATER", "WHEAT", "LIVER", "CIDER", "WINES", "CAKES", "TARTS",
        "ADULT", "BASIS", "CHAIR", "DREAM", "ERROR", "FAITH", "GLASS", "HORSE", "INDEX", "JOINT",
        "KNIFE", "LABEL", "METER", "NIGHT", "ORDER", "PARTY", "QUEEN", "RIGHT", "SENSE", "TABLE",
        "UNION", "VALUE", "BATCH", "YOUTH", "ZONEA", "ALARM", "BRAIN", "CLOUD", "DEATH", "EARTH",
        "FIELD", "GRADE", "HOTEL", "ISSUE", "JUDGE", "KINGS", "LAYER", "MUSIC", "NOISE", "PLATE",
        "PLACE", "QUAKE", "RIVER", "STAFF", "TRUST", "SHEEP", "VOICE", "TRUCK", "YACHT", "ZEBRA"
};

// 함수 선언
void f_1312_select_random_word(char answer_word[], int* max_attempt);  // 무작위 정답 단어 선택 + 시도 횟수 입력
int f_1306_get_user_input(char input[]);                               // 사용자 입력 받기
void f_1305_check_guess(const char* answer, const char* input, char* result);  // 정답과 입력 비교하여 결과 생성
int f_1302_print_result(char user_guess[], char result[]);             // 결과 출력 + 정답 여부 반환

// 메인 함수: 게임 전체 흐름 제어
int main(void) {
    char answer_word[WORD_LENGTH + 1];      // 정답 단어
    int max_attempt;                        // 최대 기회(입력으로 결정)
    char user_input[WORD_LENGTH + 1];       // 유저 답안
    char result[WORD_LENGTH + 1];           // 결과 저장 배열 (O, ~, X만 저장)

    f_1312_select_random_word(answer_word, &max_attempt);  // 정답 단어 선정 및 최대 기회 입력

    printf("GAME START.\n\n");

    for (int attempt = 1; attempt <= max_attempt; attempt++) {
        printf("시도 %d/%d\n", attempt, max_attempt);
        f_1306_get_user_input(user_input);
        f_1305_check_guess(answer_word, user_input, result);

        if (f_1302_print_result(user_input, result)) {
            printf("CLEAR %d/%d\n", attempt, max_attempt);
            printf("정답: %s\n", answer_word);
            break;
        } // 정답 출력 안되고 비정상적으로 종료되는 오류 있음
    }

    if (WORD_COUNT == user_input) {
        printf("게임 실패! 정답은 %s였습니다.\n", answer_word);
    }
    printf("아무 키나 누르면 종료됩니다...");
    getchar();
    return 0;

}

// 정답 단어 무작위 선택 + 시도 횟수 입력 받는 함수
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

// 사용자로부터 단어 입력받고 검증하는 함수
int f_1306_get_user_input(char input[]) {
    char buffer[100];  // 입력 버퍼

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

// 정답과 입력을 비교하여 결과 생성
void f_1305_check_guess(const char* answer, const char* input, char* result) {
    int answer_count[26] = {0}; // 정답 단어의 알파벳 빈도
    int used_count[26] = {0};   // 판정에 사용된 알파벳 수

    // 정답 단어의 알파벳 빈도 계산
    for (int i = 0; i < WORD_LENGTH; i++) {
        answer_count[answer[i] - 'A']++;
    }

    // 1차 판정: 위치와 글자가 모두 일치하는 경우
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (input[i] == answer[i]) {
            result[i] = 'o'; // 정확히 맞음
            used_count[input[i] - 'A']++;
        } else {
            result[i] = '?'; // 나중에 처리
        }
    }

    // 2차 판정: 글자는 존재하지만 위치가 다른 경우
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (result[i] == '?') {
            char current_char = input[i];
            int char_index = current_char - 'A';

            // 아직 더 남아있으면 '~', 없으면 'x'
            if (answer_count[char_index] > used_count[char_index]) {
                result[i] = '~'; // 글자는 있음, 위치 다름
                used_count[char_index]++;
            } else {
                result[i] = 'x'; // 글자 자체가 없음
            }
        }
    }

    result[WORD_LENGTH] = '\0'; // 문자열 종료
}

// 사용자 입력과 판정 결과 출력, 정답 여부 반환
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