#include <stdio.h>

int main()
{
    int a = 3;

    // Cast a to a char, storing it in b
    char b = (char)a;

    // To get the character '3', you need to add the ASCII offset for '0'
    char c = a + '0';

    printf("Original a (int): %d\n", a);
    printf("Casted char b (as int): %d\n", b);
    printf("Char to print '3' (as int): %d\n", c);

    // Outputting b directly often prints nothing visible (or an error box)
    printf("Casted char b (as char): %c\n", b);
    printf("Correct char c (as char): %c\n", c);

    return 0;
}