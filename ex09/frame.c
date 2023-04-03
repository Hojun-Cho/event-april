#include <stdio.h>
#include	<string.h>
#include <stdlib.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

size_t	ft_skip_until_not_c(const char **str, const char *c)
{
	const char	*_str;

	_str = *str;
	while (**str && strchr(c, **str) == NULL)
		*str += 1;
	return (*str - _str);
}

size_t	ft_skip_until_c(const char **str, const char *c)
{		
	const char	*_str;

	_str = *str;
	while (**str && strchr(c, **str))
		*str += 1;
	return (*str - _str);
}
static size_t	count_word(const char *str, char *c)
{
	size_t	cnt;

	cnt = 0;
	ft_skip_until_c(&str, c);
	while (*str)
	{
		ft_skip_until_not_c(&str, c);
		ft_skip_until_c(&str, c);
		cnt++;
	}
	return (cnt);
}

static char	**write_words(char **dst, const char *src, char *c)
{
	size_t	i;
	size_t	j;

	i = 0;
	ft_skip_until_c(&src, c);
	while (*src)
	{
		j = ft_skip_until_not_c(&src, c);
		dst[i] = strndup(src - j, j);
		if (dst[i++] == NULL)
		{	
			while (i--)
				free(dst[i]);
			return (NULL);
		}
		ft_skip_until_c(&src, c);
	}
	return (dst);
}

char	**ft_split(const char *s, char c)
{
	char	arr[2];
	size_t	size;
	char	**res;

	arr[0] = c;
	arr[1] = 0;
	size = count_word(s, arr);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (res)
	{
		res[size] = NULL;
		if (write_words(res, s, arr))
			return (res);
		free(res);
	}
	return (NULL);
}

void	print_t_b(int len)
{
	for(int i = 0; i< len +4;i++)
		printf("*");
	printf("\n");
}

char	**print(char **wrds, int len)
{
	if (*wrds== NULL)
		return NULL;
	printf("* ");
	int x= printf("%s", *wrds);
	for(int i = 0; i< len-x;i++)
		printf(" ");
	printf(" *\n");
	return print(++wrds, len);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	char **res = ft_split(argv[1], ' ');
	int max_len = 0;
	for (int i = 0; res[i];i++)
		max_len = MAX(max_len, strlen(res[i]));
	print_t_b(max_len);
	print(res, max_len);
	print_t_b(max_len);	
}
