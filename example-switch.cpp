/// switch READLINE 0
/// {READLINE} uselibrary readline

#include <cstdio>
#ifdef USE_READLINE
#include <readline/readline.h>
#endif

int main()
{
#ifdef USE_READLINE
    char *input = readline("What's your name? "); 
    printf("Hi there, %s!\n", input);
#else
    printf("Hi John Doe!\n");
#endif
}
