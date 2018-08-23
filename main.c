
#include "get_next_line.h"
#include <stdio.h>

int	main2(int argc, char **argv)
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

int main(int argc, char **argv)
{
	main2(argc, argv);
	system("leaks -q get_next_line");
	return (0);
}
