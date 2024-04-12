#ifndef FORTH_H
#define FORTH_H

typedef struct ForthEnv ForthEnv;

ForthEnv* forth_create_env();
void forth_eval(ForthEnv* env, const char* code);
void forth_destroy_env(ForthEnv* env);

#endif
