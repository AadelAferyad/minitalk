#include <stdio.h>

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
	int	n;
	n = 0;
	
	n = n << 1;
	n = n | 1;

	n = n << 1;
	n = n << 1;
	n = n << 1;
	n = n << 1;
	n = n << 1;

	n = n << 1;
	n = n | 1;
	printf("%d %c\n", n, n);
	return (0);
}
