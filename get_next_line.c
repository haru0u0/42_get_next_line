/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <hsenzaki@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:15:56 by hsenzaki          #+#    #+#             */
/*   Updated: 2024/03/08 18:35:13 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

typedef struct node {
	char	*data;
	struct	node *next;
} node_t;

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s != 0)
	{
		i++;
		s++;
	}
	return (i);
}

void	insert_newnode(node_t	*head, char	*buff)
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

char	*create_line(node_t	*head)
{
	node_t	*node_ptr;
	char	*str_ptr;
	int		char_count;
	char	*all;
	char	*all_cpy;

	char_count = 0;
	node_ptr = head -> next;
	while (node_ptr->next != NULL)
	{
		str_ptr = node_ptr->data;
		char_count = char_count + ft_strlen(str_ptr);
		node_ptr = node_ptr->next;
	}
	str_ptr = node_ptr->data;
	char_count = char_count + ft_strlen(str_ptr);
	printf("char_count: %d\n", char_count);

	all = malloc(char_count * sizeof(char));
	all_cpy = all; 
	node_ptr = head->next;
	while (node_ptr->next != NULL)
	{
		str_ptr = node_ptr->data;
		while (*str_ptr != '\0')
		{
			*all = *str_ptr;
			str_ptr++;
			all++;
		}
		node_ptr = node_ptr->next;
	}
	str_ptr = node_ptr->data;
	while (*str_ptr != '\0')
	{
		*all = *str_ptr;
		str_ptr++;
		all++;
	}
	return(all_cpy);
}

node_t	*initialize_node(node_t *head)
{
	head = malloc(sizeof(node_t));
	head->data = NULL;
	head->next = NULL;
	return(head);
}

char	*get_next_line(int fd)
{
	node_t	*head;
	node_t	*ptr;
	char	*all;
	char	*buff;

	head = initialize_node(head);

	buff = malloc (BUFFER_SIZE + sizeof(char));
	read(fd, buff, BUFFER_SIZE);
	buff[BUFFER_SIZE] = '\0';
	printf("buff: %s", buff);
	insert_newnode(head, buff);

	//buff = malloc (BUFFER_SIZE + sizeof(char));
	//buff[BUFFER_SIZE] = '\0';
	//insert_newnode(head, buff);

	//all ="hello";
	all = create_line(head);
	return(all);
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
