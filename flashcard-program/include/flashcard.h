#ifndef FLASHCARD_H
#define FLASHCARD_H
#include "forth.h"

typedef struct Flashcard Flashcard;

Flashcard* flashcard_new(const char* question, const char* answer);
void flashcard_delete(Flashcard* flashcard);
void flashcard_display(const Flashcard* flashcard, ForthEnv* env);

#endif
