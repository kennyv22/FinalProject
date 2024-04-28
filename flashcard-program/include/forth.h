#ifndef FORTH_H
#define FORTH_H

#define STACK_SIZE 256
#define MAX_WORD_LENGTH 32
#define DICTIONARY_SIZE 60

typedef struct ForthEnv {
    int stack[STACK_SIZE];
    int stackPointer;
    struct ForthWord {
        char name[MAX_WORD_LENGTH];
        void (*function)(struct ForthEnv* env);
    } dictionary[DICTIONARY_SIZE];
    int dictSize;
} ForthEnv;

ForthEnv* forth_create_env();
void forth_eval(ForthEnv* env, const char* code);
void forth_destroy_env(ForthEnv* env);

#endif
