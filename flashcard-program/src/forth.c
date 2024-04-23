#include <stdio.h>
#include <stdlib.h>
#include "forth.h"
#include <string.h>

struct ForthEnv {
   
};

static void push(ForthEnv* env, int value) {
    if(env -> staticPointer < STACK_SIZE) {
        env -> stack[env -> stackPointer++] = value;
    } else {
        fprintf(stderr, "Stack overflow");
    }
}

static int pop (ForthEnv* env) {
    if (env->sp > 0) {
        return env->stack[--env->sp];
    } else {
        fprintf(stderr, "Stack underflow\n");
        return 0;
    }
}


ForthEnv* forth_create_env() {
 
}

void forth_eval(ForthEnv* env, const char* code) {
    char word[MAX_WORD_LENGTH];
    while (*code != '\0') {
        if (sscanf(code, "%s", word)) {
            for (int i = 0; i < env-> dictSize; i++) {
                if(strcmp(env-> dictionary[i].name, word) ==0) {
                    env -> dictionary[i].function(env);
                    break;
                }
            }
        }
    }
}

void forth_destroy_env(ForthEnv* env) {

}
