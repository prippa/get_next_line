
#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (-1);
	char *str = NULL;
	int fd1 = open(argv[1], O_RDONLY);
	// fd1 = 0;
	while (get_next_line(fd1, &str) == 1)
	{
		printf("%s\n", str);
		free(str);
	}
	return (0);
}

// static int gnl_sub_line(char **str, char **line, size_t *i)
// {
// 	unsigned int start;

// 	start = (unsigned int)*i;
// 	if (!(*str)[*i])
// 	{
// 		ft_strdel(&(*str));
// 		return (0);
// 	}
// 	while ((*str)[*i] && (*str)[*i] != '\n')
// 		*i += 1;
// 	*line = ft_strsub(*str, start,  *i - start);
// 	if ((*str)[*i])
// 		*i += 1;
// 	return (1);
// }

// int	main2(void)
// {
// 	char *str = ft_strdup("1\n2\n3\n4");
// 	char *line = NULL;
// 	size_t i = 0;

// 	while (1)
// 	{
// 		if (!gnl_sub_line(&str, &line, &i))
// 			break ;
// 		ft_printf("line - [%s]\n", line);
// 		ft_strdel(&line);
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	main2();
// 	system("leaks -q a.out");
// 	return (0);
// }
