#include "./src/ft_printf.h"
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
	d = 69;
	i = 69;
	u = -50;
	x = 420;
	len1 = 0;
	len2 = 0;
	/* Text Only */
	printf("\033[1;37m");
	printf("Text Only\n");
	printf("\033[0;37m");
	len1 = printf("Test string\n");
	len2 = ft_printf("Test string\n");
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
	/* Character */
	printf("\033[1;37m");
	printf("Character\n");
	printf("\033[0;37m");
	len1 = printf("%c\n", c);
	len2 = ft_printf("%c\n", c);
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
	/* String */
	printf("\033[1;37m");
	printf("String\n");
	printf("\033[0;37m");
	len1 = printf("%s\n", s);
	len2 = ft_printf("%s\n", s);
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
	/* Pointer */
	printf("\033[1;37m");
	printf("Pointer\n");
	printf("\033[0;37m");
	len1 = printf("%p\n", p);
	len2 = ft_printf("%p\n", p);
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
	/* Decimal */
	printf("\033[1;37m");
	printf("Decimal\n");
	printf("\033[0;37m");
	len1 = printf("%d\n", d);
	len2 = ft_printf("%d\n", d);
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
	/* Integer */
	printf("\033[1;37m");
	printf("Integer\n");
	printf("\033[0;37m");
	len1 = printf("%i\n", i);
	len2 = ft_printf("%i\n", i);
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
	/* Unsigned Decimal */
	printf("\033[1;37m");
	printf("Unsigned Decimal\n");
	printf("\033[0;37m");
	len1 = printf("%u\n", u);
	len2 = ft_printf("%u\n", u);
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
	/* Hexadecimal lowecase */
	printf("\033[1;37m");
	printf("Hexadecimal lowercase\n");
	printf("\033[0;37m");
	len1 = printf("%x\n", x);
	len2 = ft_printf("%x\n", x);
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
	/* Hexadecimal uppercase */
	printf("\033[1;37m");
	printf("Hexadecimal uppercase\n");
	printf("\033[0;37m");
	len1 = printf("%X\n", x);
	len2 = ft_printf("%X\n", x);
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
	/* Percent sign */
	printf("\033[1;37m");
	printf("Percent sign\n");
	printf("\033[0;37m");
	len1 = printf("%%\n");
	len2 = ft_printf("%%\n");
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
	/* Text and format (Char) */
	printf("\033[1;37m");
	printf("Text and format (Char)\n");
	printf("\033[0;37m");
	len1 = printf("Test, %c\n", c);
	len2 = ft_printf("Test, %c\n", c);
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
	/* Text and format (String) */
	printf("\033[1;37m");
	printf("Text and format (String)\n");
	printf("\033[0;37m");
	len1 = printf("Test, %s\n", s);
	len2 = ft_printf("Test, %s\n", s);
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
	/* Text and format (Pointer) */
	printf("\033[1;37m");
	printf("Text and format (Pointer)\n");
	printf("\033[0;37m");
	len1 = printf("Test, %p\n", p);
	len2 = ft_printf("Test, %p\n", p);
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
	/* Text and format (Decimal) */
	printf("\033[1;37m");
	printf("Text and format (Decimal)\n");
	printf("\033[0;37m");
	len1 = printf("Test, %d\n", d);
	len2 = ft_printf("Test, %d\n", d);
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
	/* Text and format (Integer) */
	printf("\033[1;37m");
	printf("Text and format (Integer)\n");
	printf("\033[0;37m");
	len1 = printf("Test, %i\n", i);
	len2 = ft_printf("Test, %i\n", i);
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
	/* Text and format (Unsigned Decimal) */
	printf("\033[1;37m");
	printf("Text and format (Unsigned Decimal)\n");
	printf("\033[0;37m");
	len1 = printf("Test, %u\n", u);
	len2 = ft_printf("Test, %u\n", u);
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
	/* Text and format (Hexadecimal lowercase) */
	printf("\033[1;37m");
	printf("Text and format (Hexadecimal lowercase)\n");
	printf("\033[0;37m");
	len1 = printf("Test, %x\n", x);
	len2 = ft_printf("Test, %x\n", x);
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
	/* Text and format (Hexadecimal uppercase) */
	printf("\033[1;37m");
	printf("Text and format (Hexadecimal uppercase)\n");
	printf("\033[0;37m");
	len1 = printf("Test, %X\n", x);
	len2 = ft_printf("Test, %X\n", x);
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
	/* Text and format (Percent sign) */
	printf("\033[1;37m");
	printf("Text and format (Percent sign)\n");
	printf("\033[0;37m");
	len1 = printf("Test, %%\n");
	len2 = ft_printf("Test, %%\n");
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
	/* Multiple formats */
	printf("\033[1;37m");
	printf("Multiple formats\n");
	printf("\033[0;37m");
	len1 = printf("%i, %c and %s\n", i, c, s);
	len2 = ft_printf("%i, %c and %s\n", i, c, s);
	printf("Printed Characters with printf: %i\n", len1);
	if (len1 != len2)
		printf("\033[0;31m");
	printf("Printed Characters with ft_printf: %i\n", len2);
	if (len1 != len2)
		printf("\033[0;37m");
	printf("\n");
}
