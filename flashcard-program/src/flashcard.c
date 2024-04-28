#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flashcard.h"

// Function to create a new flashcard
Flashcard* flashcard_new(const char* question, const char* answer) {
    // Allocate memory for the new flashcard
    Flashcard* new_flashcard = (Flashcard*)malloc(sizeof(Flashcard));
    if (new_flashcard == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for flashcard\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for question and answer strings
    new_flashcard->question = strdup(question);
    new_flashcard->answer = strdup(answer);

    return new_flashcard;
}

// Function to delete a flashcard
void flashcard_delete(Flashcard* flashcard) {
    if (flashcard != NULL) {
        // Free memory allocated for question and answer strings
        free(flashcard->question);
        free(flashcard->answer);
        // Free memory allocated for the flashcard structure
        free(flashcard);
    }
}

// Function to display a flashcard
void flashcard_display(const Flashcard* flashcard, ForthEnv* env) {
    // Display the question and answer of the flashcard
    printf("Question: %s\n", flashcard->question);
    printf("Answer: %s\n", flashcard->answer);
}
