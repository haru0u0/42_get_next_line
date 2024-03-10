 #include "get_next_line.h"
 int	main()
{
	int		fd;
	char	*str;
    
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("\n\n<< return value1:%s >>\n",str);

	str = get_next_line(fd);
	printf("\n\n<< return value2:%s >>\n",str);

	str = get_next_line(fd);
	printf("\n\n<< return value2:%s >>\n",str);

	str = get_next_line(fd);
	printf("\n\n<< return value1:%s >>\n",str);

	str = get_next_line(fd);
	printf("\n\n<< return value1:%s >>\n",str);

	str = get_next_line(fd);
	printf("\n\n<< return value1:%s >>\n",str);

	str = get_next_line(fd);
	printf("\n\n<< return value1:%s >>\n",str);

	str = get_next_line(fd);
	printf("\n\n<< return value1:%s >>\n",str);

	str = get_next_line(fd);
	printf("\n\n<< return value1:%s >>\n",str);

	close(fd);
}