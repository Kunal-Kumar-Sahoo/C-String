#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int n = 100;
    char *str = malloc(sizeof(char) * n);
    if (str == NULL)
    {
        return -1;
    }

    int length = 0;
    printf("Enter a string: ");
    char ch;
    while ((ch = getchar()) != '\n')
    {
        if (length > (3*n/4))
        {
            n *= 2;
            str = realloc(str, sizeof(char) * n);
            if (str == NULL)
            {
                return -1;
            }
        }
        str[length] = ch;
        length++;
    }
    *(str + length) = '\0';
    
    str = realloc(str, (length +1) * sizeof(char));
    if (str == NULL)
    {
        return -1;
    }
    printf("Text: %s\n", str);

    free(str);
    return 0;
}
