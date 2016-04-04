#include <stdio.h>

int main()
{
    char letter;

    printf("The alphabet:\n");
    for (letter = 'a'; letter <= 'z'; letter++) {
        printf("%c", letter);
    }
    printf("\n");
}
