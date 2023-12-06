#include "get_next_line.h"
#include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	int		fd1;
// 	int		fd2;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	fd1 = open("test1.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);



// 	line = get_next_line(fd);
// 	printf("LINE 1 FROM FD %d: %s\n", fd, line);
// 	free(line);
// 	line = get_next_line(fd1);
// 	printf("LINE 1 FROM FD %d: %s\n", fd1,  line);
// 	free(line);
// 	line = get_next_line(fd2);
// 	printf("LINE 1 FROM FD %d: %s\n", fd2,  line);
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("LINE 2 FROM FD %d: %s\n", fd, line);
// 	free(line);
// 	line = get_next_line(fd1);
// 	printf("LINE 2 FROM FD %d: %s\n", fd1,  line);
// 	free(line);
// 	line = get_next_line(fd2);
// 	printf("LINE 2 FROM FD %d: %s\n", fd2,  line);
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("LINE 3 FROM FD %d: %s\n", fd, line);
// 	free(line);
// 	line = get_next_line(fd1);
// 	printf("LINE 3 FROM FD %d: %s\n", fd1,  line);
// 	free(line);
// 	line = get_next_line(fd2);
// 	printf("LINE 3 FROM FD %d: %s\n", fd2,  line);
// 	free(line);


// 	return (0);
// }

// int	main()
// {
// 	char *line;
// 	int fd = open("big_line_no_nl", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	return 0;
// }