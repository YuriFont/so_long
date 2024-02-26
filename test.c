#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "./libraries/libft/get_next_line.h"

int main(void)
{
	int fd = open("./maps/mapVoid.ber", O_RDONLY);
	char *line = get_next_line(fd);
	if (!line)
		printf("Já erra\n");
	return (0);
}
