/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <hsenzaki@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:15:56 by hsenzaki          #+#    #+#             */
/*   Updated: 2024/03/09 04:30:07 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
// #define BUFFER_SIZE 5

int	ft_strlen(char	*s)
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

void	insert_newnode(t_node	*head, char	*buff)
{
	t_node	*newnode;
	t_node	*findlast;

	findlast = head;
	newnode = ft_calloc (1, sizeof(t_node));
	newnode->data = buff;
	newnode->next = NULL;
	while (findlast->next != NULL)
		findlast = findlast->next;
	findlast->next = newnode;
}

void	insert_newnode_eol(t_node	*head, char	*buff)
{
	t_node		*newnode;
	t_node		*findlast;
	char		*bynewline;
	char		*bynewline_cpy;
	static char	*rest;
	static int	isrest = 0;

	if (buff == NULL)
	{
		if(isrest == 1)
		{
			insert_newnode(head, rest);
		}
	}
	else
	{
		findlast = head;
		newnode = ft_calloc(1, sizeof(t_node));
		bynewline = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		bynewline_cpy = bynewline;

		while(*buff != '\n' || *buff != '\0')
		{
			*bynewline = *buff;
			bynewline++;
			buff++;
		}
		if (*buff == '\n')
		{
			*bynewline = '\n';
			buff++;
			rest = buff;
			isrest = 1;
		}else if(*buff == '\0')
		{
			*bynewline = '\0';
		}

		newnode->data = bynewline_cpy;
		newnode->next = NULL;
		while (findlast->next != NULL)
			findlast = findlast->next;
		findlast->next = newnode;
	}
}

char	*create_line(t_node	*head)
{
	t_node	*node_ptr;
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

	all = ft_calloc(char_count + 1, sizeof(char));
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

bool	is_eol(char	*str)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if(str[i] == '\n' || str[i]== '\0')
			return(1);
		i++;
	}
	return(0);
}

char	*get_next_line(int fd)
{
	t_node	*head;
	char	*buff;
	bool	done;
	int		byte_read;
	char	*all;

	if (BUFFER_SIZE < 1)
		return (NULL);
	done = 0;
	byte_read = 1;
	head = ft_calloc(1, sizeof(t_node));
	head->data = NULL;
	head->next = NULL;

	insert_newnode_eol(head, NULL);

	while (done == 0)
	{
		buff = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buff);
			return (NULL);
		}
		else
			buff[BUFFER_SIZE] = '\0';
		if (is_eol(buff) == 0)
			insert_newnode(head, buff);
		else
		{
			insert_newnode_eol(head, buff);
			done = 1;
		}
	}
	all = create_line(head);
	free(head);
	return(all);
}


int	main()
{
	int		fd;
	char	*str;
	
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