#ifndef WORDLE_HEADER_H
#define WORDLE_HEADER_H

// C 내장 라이브러리 정의
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 상수 정의
#define WORD_LENGTH 5
#define WORD_COUNT 100

// 단어 목록 정의
extern const char words[WORD_COUNT][WORD_LENGTH + 1];

#endif //WORDLE_HEADER_H
