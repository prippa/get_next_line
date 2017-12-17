
#include "get_next_line.h"
# include <stdio.h>

int	main(int argc, char **argv)
{
	argc = 0;
	char *str;
	int fd1 = open(argv[1], O_RDONLY);
	while (get_next_line(fd1, &str) == 1)
	{
		printf("%s\n", str);
		free(str);
	}
	
	// int fd2 = open(argv[2], O_RDONLY);
	// int fd3 = open(argv[3], O_RDONLY);
	// int fd4 = open(argv[4], O_RDONLY);
	// printf("%d\n", get_next_line(fd1, &str));
	// printf("%s\n", str);
	// printf("%d\n", get_next_line(fd1, &str));
	// printf("%s\n", str);
	// printf("%d\n", get_next_line(fd1, &str));
	// printf("%s\n", str);
	// printf("%d\n", get_next_line(fd2, &str));
	// printf("%s\n", str);
	// printf("%d\n", get_next_line(fd4, &str));
	// printf("%s\n", str);
	// printf("%d\n", get_next_line(fd2, &str));
	// printf("%s\n", str);
	// printf("%d\n", get_next_line(fd4, &str));
	// printf("%s\n", str);
	// printf("%d\n", get_next_line(fd4, &str));
	// printf("%s\n", str);
	// printf("%d\n", get_next_line(fd1, &str));
	// printf("%s\n", str);

	// printf("%d\n", get_next_line(fd1, &str));
	// printf("%s\n", str);
	// printf("%d\n", get_next_line(fd2, &str));
	// printf("%s\n", str);
	// printf("%d\n", get_next_line(fd3, &str));
	// printf("%s\n", str);
	// printf("%d\n", get_next_line(fd4, &str));
	// printf("%s\n", str);

	// system("leaks get_next_line");

	// printf("%d\n", printf("%d\n", get_next_line(fd1, &str)));
	// printf("%s\n", str);
	// str = NULL;
	// printf("%d\n", printf("%d\n", get_next_line(fd2, &str)));
	// printf("%s\n", str);
	// str = NULL;
	// printf("%d\n", printf("%d\n", get_next_line(fd1, &str)));
	// printf("%s\n", str);
	// str = NULL;
	// printf("%d\n", printf("%d\n", get_next_line(fd2, &str)));
	// printf("%s\n", str);


	// int i = 1;
	// while ((printf("%d\n", get_next_line(fd1, &str))) == 1)
	// {
	// 	printf("%d\n", i);
	// 	free(str);
	// 	i++;
	// }
	return (0);
}