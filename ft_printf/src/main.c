#include "ft_printf.h"
#include <stdio.h>

int main ()
{
    char                c;
    char                *s;
    int                 d;
    int                 i;
    unsigned int        u;
    unsigned int        x;

    c = 'A';
    s = "Test";
    d = 10;
    i = 10;
    u = -50;
    x = 69;
    /* No format */
    printf("\033[1;37m");
    printf("No format\n");
    printf("\033[0;37m");
    printf("Test\n");
    ft_printf("Test\n");
    printf("\n");
    /* Character */
    printf("\033[1;37m");
    printf("Character\n");
    printf("\033[0;37m");
    printf("%c\n", c);
    ft_printf("%c\n", c);
    printf("\n");
    /* String */
    printf("\033[1;37m");
    printf("String\n");
    printf("\033[0;37m");
    printf("%s\n", s);
    ft_printf("%s\n", s);
    printf("\n");
    /* Decimal */
    printf("\033[1;37m");
    printf("Decimal\n");
    printf("\033[0;37m");
    printf("%d\n", d);
    ft_printf("%d\n", d);
    printf("\n");
    /* Integer */
    printf("\033[1;37m");
    printf("Integer\n");
    printf("\033[0;37m");
    printf("%i\n", i);
    ft_printf("%i\n", i);
    printf("\n");
    /* Unsigned Decimal */
    printf("\033[1;37m");
    printf("Unsigned Decimal\n");
    printf("\033[0;37m");
    printf("%u\n", u);
    ft_printf("%u\n", u);
    printf("\n");
    /* Hexadecimal lowecase */
    printf("\033[1;37m");
    printf("Hexadecimal lowercase\n");
    printf("\033[0;37m");
    printf("%x\n", x);
    ft_printf("%x\n", x);
    printf("\n");
    /* Hexadeciaml uppercase */
    printf("\033[1;37m");
    printf("Hexadecimal uppercase\n");
    printf("\033[0;37m");
    printf("%X\n", x);
    ft_printf("%X\n", x);
    printf("\n");
    /* Mixed using integer as an example*/
    printf("\033[1;37m");
    printf("Mixed using integer as an example\n");
    printf("\033[0;37m");
    printf("Test, %i, test\n", i);
    ft_printf("Test, %i, test\n", i);
}