
#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (-1);
	char *str = NULL;
	int fd1 = open(argv[1], O_RDONLY);
	while (get_next_line(fd1, &str) == 1)
	{
		printf("%s\n", str);
		free(str);
	}
	return (0);
}