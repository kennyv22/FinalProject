#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flashcard.h"
#include "forth.h"

#define NUM_FLASHCARDS 10  // Define the number of flashcards

// Function prototype
void initialize_flashcards(Flashcard* preset_flashcards[]);

int main() {
    // Initialize FORTH environment
    ForthEnv* env = forth_create_env();

    // Define the preset flashcards array
    Flashcard* preset_flashcards[NUM_FLASHCARDS];

    // Initialize preset flashcards
    initialize_flashcards(preset_flashcards);

    // Example usage
    char term[100];

    // Select a random flashcard
    int index = rand() % NUM_FLASHCARDS;
    Flashcard* card = preset_flashcards[index];

    // Display the definition using FORTH
    flashcard_display(card, env);

    // Prompt the user for the term
    printf("Please enter the term corresponding to the definition: ");
    fgets(term, sizeof(term), stdin);
    term[strcspn(term, "\n")] = '\0'; // Remove trailing newline character

    // Check if the input matches the correct term
    if (strcmp(term, card->question) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct term is: %s\n", card->question);
    }

    // Destroy FORTH environment
    forth_destroy_env(env);

    // Destroy preset flashcards
    for (int i = 0; i < NUM_FLASHCARDS; i++) {
        flashcard_delete(preset_flashcards[i]);
    }

    return 0;
}

// Function to initialize preset flashcards
void initialize_flashcards(Flashcard* preset_flashcards[]) {
    // Initialize flashcards here
    preset_flashcards[0] = flashcard_new("Question 1", "Answer 1");
    preset_flashcards[1] = flashcard_new("Question 2", "Answer 2");
    // Add more flashcards as needed
}
