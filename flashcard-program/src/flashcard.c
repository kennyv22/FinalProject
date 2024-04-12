#include <stdio.h>
#include <stdlib.h>
#include "flashcard.h"

struct Flashcard {
    char* question;
    char* answer;
};

Flashcard* flashcard_new(const char* question, const char* answer) {
    Flashcard* card = (Flashcard*)malloc(sizeof(Flashcard));
    if (card == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for flashcard\n");
        exit(EXIT_FAILURE);
    }
    card->question = strdup(question);
    card->answer = strdup(answer);
    return card;
}

void flashcard_delete(Flashcard* flashcard) {
    if (flashcard != NULL) {
        free(flashcard->question);
        free(flashcard->answer);
        free(flashcard);
    }
}

void flashcard_display(const Flashcard* flashcard) {
    printf("Question: %s\n", flashcard->question);
}
