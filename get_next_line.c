/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <hsenzaki@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:15:56 by hsenzaki          #+#    #+#             */
/*   Updated: 2024/02/06 22:24:51 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char	buff[100];
	int	i;
	i = 0;

	read(fd, buff, 100);
	while(i < 100)
	{
		printf("%c", buff[i]);
		i++;
	}
}

void	main()
{
	int		fd;
	char	*str;
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);

	printf("%s",str);
	close(fd);
}
