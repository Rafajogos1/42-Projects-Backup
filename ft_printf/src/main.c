#include "ft_printf.h"
#include <stdio.h>

int	main ()
{
	char				c;
	char				*s;
	int					*p;
	int					d;
	int					i;
	unsigned int		u;
	unsigned int		x;
	int					len1;
	int					len2;

	c = 'A';
	s = "Test";
	p = &i;
	d = 10;
	i = 10;
	u = -50;
	x = 69;
	/* No format */
	printf("\033[1;37m");
	printf("No format\n");
	printf("\033[0;37m");
	len1 = printf("Test\n");
	len2 = ft_printf("Test\n");
	printf("Printed Characters with printf: %i\n", len1);
	printf("Printed Characters with ft_printf: %i\n", len2);
	printf("\n");
	/* Character */
	printf("\033[1;37m");
	printf("Character\n");
	printf("\033[0;37m");
	len1 = printf("%c\n", c);
	len2 = ft_printf("%c\n", c);
	printf("Printed Characters with printf: %i\n", len1);
	printf("Printed Characters with ft_printf: %i\n", len2);
	printf("\n");
	/* String */
	printf("\033[1;37m");
	printf("String\n");
	printf("\033[0;37m");
	len1 = printf("%s\n", s);
	len2 = ft_printf("%s\n", s);
	printf("Printed Characters with printf: %i\n", len1);
	printf("Printed Characters with ft_printf: %i\n", len2);
	printf("\n");
	/* Pointer */
	printf("\033[1;37m");
	printf("Pointer\n");
	printf("\033[0;37m");
	len1 = printf("%p\n", p);
	len2 = ft_printf("%p\n", p);
	printf("Printed Characters with printf: %i\n", len1);
	printf("Printed Characters with ft_printf: %i\n", len2);
	printf("\n");
	/* Decimal */
	printf("\033[1;37m");
	printf("Decimal\n");
	printf("\033[0;37m");
	len1 = printf("%d\n", d);
	len2 = ft_printf("%d\n", d);
	printf("Printed Characters with printf: %i\n", len1);
	printf("Printed Characters with ft_printf: %i\n", len2);
	printf("\n");
	/* Integer */
	printf("\033[1;37m");
	printf("Integer\n");
	printf("\033[0;37m");
	len1 = printf("%i\n", i);
	len2 = ft_printf("%i\n", i);
	printf("Printed Characters with printf: %i\n", len1);
	printf("Printed Characters with ft_printf: %i\n", len2);
	printf("\n");
	/* Unsigned Decimal */
	printf("\033[1;37m");
	printf("Unsigned Decimal\n");
	printf("\033[0;37m");
	len1 = printf("%u\n", u);
	len2 = ft_printf("%u\n", u);
	printf("Printed Characters with printf: %i\n", len1);
	printf("Printed Characters with ft_printf: %i\n", len2);
	printf("\n");
	/* Hexadecimal lowecase */
	printf("\033[1;37m");
	printf("Hexadecimal lowercase\n");
	printf("\033[0;37m");
	len1 = printf("%x\n", x);
	len2 = ft_printf("%x\n", x);
	printf("Printed Characters with printf: %i\n", len1);
	printf("Printed Characters with ft_printf: %i\n", len2);
	printf("\n");
	/* Hexadeciaml uppercase */
	printf("\033[1;37m");
	printf("Hexadecimal uppercase\n");
	printf("\033[0;37m");
	len1 = printf("%X\n", x);
	len2 = ft_printf("%X\n", x);
	printf("Printed Characters with printf: %i\n", len1);
	printf("Printed Characters with ft_printf: %i\n", len2);
	printf("\n");
	/* Mixed using integer as an example*/
	printf("\033[1;37m");
	printf("Mixed using integer as an example\n");
	printf("\033[0;37m");
	len1 = printf("Test, %i, test\n", i);
	len2 = ft_printf("Test, %i, test\n", i);
	printf("Printed Characters with printf: %i\n", len1);
	printf("Printed Characters with ft_printf: %i\n", len2);
	printf("\n");
	/* Multiple formats */
	printf("\033[1;37m");
	printf("Multiple formats\n");
	printf("\033[0;37m");
	len1 = printf("%i and %c\n", i, c);
	len2 = ft_printf("%i and %c\n", i, c);
	printf("Printed Characters with printf: %i\n", len1);
	printf("Printed Characters with ft_printf: %i\n", len2);
	printf("\n");
}
