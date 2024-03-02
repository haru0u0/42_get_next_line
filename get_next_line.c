/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <hsenzaki@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:15:56 by hsenzaki          #+#    #+#             */
/*   Updated: 2024/03/02 10:52:14 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void	*loop()
{

}

char	*get_next_line(int fd)
{
	char	buff[100];
	int	i;
	int	rtn;
	char	*line;
	i = 0;
	line = malloc(100);

	if(line < 0)
	{
		return("error");
	}

	rtn = read(fd, buff, 6);
	printf("return of read: %d\n", rtn);
	while(i < 10 && buff[i]!='\n')
	{
		line[i] = buff[i];
		i++;
	}


	while(i < 10 && buff[i]!='\n')
	{
		line[i] = buff[i];
		i++;
	}

	return(line);
}

void	main()
{
	int		fd;
	char	*str;
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);

	printf("\nreturn value:%s",str);
	close(fd);
}
