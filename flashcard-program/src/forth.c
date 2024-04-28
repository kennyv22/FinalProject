#include <stdio.h>
#include <stdlib.h>
#include "forth.h"
#include <string.h>

static void push(ForthEnv* env, int value) {
    if(env->stackPointer < STACK_SIZE) {
        env->stack[env->stackPointer++] = value;
    } else {
        fprintf(stderr, "Stack overflow\n");
    }
}

static int pop (ForthEnv* env) {
    if (env->stackPointer > 0) {
        return env->stack[--env->stackPointer];
    } else {
        fprintf(stderr, "Stack underflow\n");
        return 0;
    }
}

ForthEnv* forth_create_env() {
    printf("Creating Forth environment...\n");
    ForthEnv* env = (ForthEnv*)malloc(sizeof(ForthEnv));
    if (env == NULL) {
        fprintf(stderr, "Failed to allocate memory for Forth environment\n");
        exit(EXIT_FAILURE);
    }
    printf("Memory allocated for Forth environment\n");

    // Initialize stack pointer
    env->stackPointer = 0;
    // Initialize dictionary size
    env->dictSize = 0;

    printf("Forth environment created successfully\n");

    printf("Stack size: %d\n", STACK_SIZE);
    printf("Dictionary size: %d\n", DICTIONARY_SIZE);
    printf("Stack pointer: %d\n", env->stackPointer);
    printf("Dictionary size: %d\n", env->dictSize);

    return env;
}

void forth_eval(ForthEnv* env, const char* code) {
    char word[MAX_WORD_LENGTH];
    while (*code != '\0') {
        if (sscanf(code, "%s", word)) {
            for (int i = 0; i < env->dictSize; i++) {
                if (strcmp(env->dictionary[i].name, word) == 0) {
                    env->dictionary[i].function(env);
                    break;
                }
            }
        }
    }
}

void forth_destroy_env(ForthEnv* env) {
    free(env);
}
