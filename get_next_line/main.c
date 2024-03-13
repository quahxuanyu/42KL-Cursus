#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	char *file = "hello";
	int fd = open(file, O_RDWR);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));
}