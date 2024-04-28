#ifndef FLASHCARD_H
#define FLASHCARD_H

#include "forth.h"

typedef struct Flashcard {
    char* question;
    char* answer;
} Flashcard;

// Function declarations...
Flashcard* flashcard_new(const char* question, const char* answer);
void flashcard_delete(Flashcard* flashcard);
void flashcard_display(const Flashcard* flashcard, ForthEnv* env);

#endif
