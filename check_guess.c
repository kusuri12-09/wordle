#include "define.h"
#include "func.h"

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
