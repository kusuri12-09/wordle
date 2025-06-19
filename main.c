#include "define.h"
#include "func.h"

int main(void) {
    char answer_word[WORD_LENGTH + 1];      // 정답 단어
    int max_attempt;                        // 최대 기회(입력으로 결정)
    char user_input[WORD_LENGTH + 1];       // 유저 답안
    char result[WORD_LENGTH + 1];           // 결과 저장 배열 (O, ~, X만 저장)

    f_1312_select_random_word(answer_word, &max_attempt);  // 정답 단어 선정 및 최대 기회 입력

    printf("%s\n", answer_word);

    printf("GAME START.\n\n");

    for (int attempt = 1; attempt <= max_attempt; attempt++) {
        printf("시도 %d/%d\n", attempt, max_attempt);
        f_1306_get_user_input(user_input);
        f_1305_check_guess(answer_word, user_input, result);

        if (f_1302_print_result(user_input, result)) {
            printf("CLEAR %d/%d\n", attempt, max_attempt);
            printf("정답: %s\n", answer_word);
            return 0;
        } // 정답 출력 안되고 비정상적으로 종료되는 오류 있음
    }

    printf("게임 실패! 정답은 %s였습니다.\n", answer_word);
    return 0;
}

// 단어 목록 정의
const char words[WORD_COUNT][WORD_LENGTH + 1] = {
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