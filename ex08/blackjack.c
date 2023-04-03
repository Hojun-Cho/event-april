#include <stdio.h>
#include <ctype.h>

int	ft_math(char *str, int *ace)
{
	int	sum;

	sum = 0;
	while (*str)
	{
		if (isdigit(*str) && *str != '1')
			sum += *str - '0';
		else if (*str == 'A')
		{
			sum += 11;
			*ace = *ace + 1;
		}
		else if (*str == 'T' || *str == 'J' || *str == 'D' || *str == 'K')
			sum += 10;
		str++;
	}
	return (sum);
}

int	main(int argc, char *argv[])
{
	int		sum;
	int		ace;

	if (argc == 2)
	{
		ace = 0;
		sum = ft_math(argv[1], &ace);
		while (sum > 22 && ace--)
			sum -= 10;
		if (sum == 21)
			printf("Blackjack!\n");
		else
			printf("%d\n", sum);
	}
	return (0);
}
