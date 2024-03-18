#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	char *file = "hello";
	int fd = open(file, O_RDWR);
	int	i;

	i = 0;
	while (++i <= 5)
		printf("RETURN RESULTS %i: %s\n", i, get_next_line(fd));
}