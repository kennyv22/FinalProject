#include <stdio.h>
#include <stdlib.h>
#include "flashcard.h"
#include "forth.h"

void prompt_for_term(const Flashcard* flashcard, ForthEnv* env) {
    flashcard_display(flashcard);
  
    printf("Please enter the term corresponding to the definition: ");
  
    char term[100]; // Adjust the size according to your needs
    fgets(term, sizeof(term), stdin);
 
    if (strcmp(term, flashcard->question) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct term is: %s\n", flashcard->question);
    }
}

int main() {
    ForthEnv* env = forth_create_env();
    
    Flashcard* card = flashcard_new("Apple", "A fruit");
    prompt_for_term(card, env);
    flashcard_delete(card);
    
    forth_destroy_env(env);
    
    return 0;
}
