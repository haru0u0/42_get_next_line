 #include "get_next_line.h"

#include "leakdetect.h"
#define malloc(s) leak_detelc_malloc(s, __FILE__, __LINE__)
#define free leak_detect_free

 int	main()
{
	int		fd;
	char	*str;
    
	leak_detect_init();
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
	leak_detect_check();
	return(0);
}