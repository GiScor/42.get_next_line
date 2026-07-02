#include <stdio.h>
#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <curses.h>
int	main()
{
	char ch;
	char *str;
	int fd = open("./test.txt", O_RDONLY);

	/*printf("\t[Press ENTER to print next line]");*/
	/*scanf("%c",&ch);*/
	/*str = get_next_line(fd);*/
	/*while (ch && str)*/
	/*{*/
		/*if (str)*/
		/*{*/
			/*printf("%s", str);*/
			/*printf("\t[Press ENTER to print next line]");*/
			/*scanf("%c",&ch);*/
			/*str = get_next_line(fd);*/
		/*}*/
	/*}*/
	str = get_next_line(fd);
	int	i = 1;
	while (str)
	{
		printf(" [%0d]%s", i++, str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
}
