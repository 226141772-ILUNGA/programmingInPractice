#include <stdio.h>
#include "utilities.h"

static void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int readInt(const char *prompt)
{
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) {
        clearInputBuffer();
        printf("Invalid input. %s", prompt);
    }
    return value;
}

float readFloat(const char *prompt)
{
    float value;
    printf("%s", prompt);
    while (scanf("%f", &value) != 1) {
        clearInputBuffer();
        printf("Invalid input. %s", prompt);
    }
    return value;
}