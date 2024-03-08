/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <hsenzaki@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:15:56 by hsenzaki          #+#    #+#             */
/*   Updated: 2024/03/08 00:12:33 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

typedef struct node {
	int	data;
	struct	node *next;
} node_t;

void	create_newnode(node_t	*head, int	buff)
{
	node_t	*newnode;
	node_t	*findlast;

	findlast = head;
	newnode = malloc(sizeof(node_t));
	newnode->data = buff;
	newnode->next = NULL;
	while (findlast->next != NULL)
		findlast = findlast->next;
	findlast->next = newnode;
}

char	*get_next_line(int fd)
{
	char	*buff;
	node_t	*head;
	node_t	*ptr;

	head = malloc(sizeof(node_t));
	head->data = NULL;
	head->next = NULL;
	create_newnode(head, 1);
	create_newnode(head, 2);
	create_newnode(head, 3);

	ptr = head;
	while (ptr->next != NULL)
	{
		if (ptr->data != NULL)
			printf("%d\n",ptr->data);
		ptr = ptr->next;
	}
	// read(fd, buff, BUFFER_SIZE);
	return("teststring");
}

void	main()
{
	int		fd;
	char	*str;
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);

	printf("return value:%s",str);
	close(fd);
}
