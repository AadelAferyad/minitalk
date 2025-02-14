#include "minitalk.h"
#include <stdio.h>
#include <string.h>

/*
 * 128 64 32 16 8 4 2 1
 * 0100 0001 == 65 A
 * 0000 0001
 *
 * 0000 0010
 * 0000 0100
 * 0000 1000
 * 0001 0000
 * 0010 0000
 * 0100 0001
 * */
int	main(void)
{
	char *n;

	n = "Ѳ";
	_puts(n);
	printf("\n%s len : %d", "Ѳ");
	return (0);
}
