/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 07:08:39 by hsenzaki          #+#    #+#             */
/*   Updated: 2024/03/09 07:08:42 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "leakdetect.h"
#define malloc(s) leak_detelc_malloc(s, __FILE__, __LINE__)
#define free leak_detect_free

char	*create_line(t_node	*head)
{
	t_node	*node_ptr;
	char	*str_ptr;
	int		char_count;
	char	*all;
	char	*all_cpy;
	bool	islast;

	islast = 0;
	char_count = 0;
	node_ptr = head -> next;
	while (islast != 1)
	{
		char_count = char_count + ft_strlen(node_ptr->data);
		if (node_ptr->next == NULL)
			islast = 1;
		else
			node_ptr = node_ptr->next;
	}

	//all = ft_calloc(char_count + 1, sizeof(char));
	all = malloc((char_count + 1) * sizeof(char));
	ft_memset(all, 0, (char_count + 1) * sizeof(char));
	all_cpy = all; 
	node_ptr = head->next;
	islast = 0;
	while (islast != 1)
	{
		str_ptr = node_ptr->data;
		while (*str_ptr != '\0')
		{
			*all = *str_ptr;
			str_ptr++;
			all++;
		}
		if (node_ptr->next == NULL)
			islast = 1;
		else
			node_ptr = node_ptr->next;
	}
	return(all_cpy);
}

void	insert_by(t_node	*head, char	*buff)
{
    t_node		*node;
	t_node		*findlast;
	char	*buff_cpy;

	buff_cpy = buff;
	findlast = head;
	//node = ft_calloc(1, sizeof(t_node));
	node = malloc(sizeof(t_node));
	ft_memset(node, 0, sizeof(t_node));

	while(*buff != '\n' && *buff != '\0')
		buff++;
	*buff = '\0';  //たぶん必要
	node->data = buff_cpy;
	node->next = NULL;
	while (findlast->next != NULL)
		findlast = findlast->next;
	findlast->next = node;
}

char	*insert_by_withres(t_node	*head, char	*buff)
{
    t_node		*node;
	t_node		*findlast;
	char	*res;
	char  *res_cpy;
	char	*buff_cpy;
	char	*nl;

	buff_cpy = buff;
	findlast = head;
	//node = ft_calloc(1, sizeof(t_node));
	node = malloc(sizeof(t_node));
	ft_memset(node, 0, sizeof(t_node));

	while(*buff != '\n')
		buff++;

	nl = buff;
	buff++;
	//res = ft_calloc(BUFFER_SIZE, sizeof(char));
	res = malloc(BUFFER_SIZE * sizeof(char));
	ft_memset(res, 0, BUFFER_SIZE * sizeof(char));
	res_cpy = res;
	while(*buff != '\0')
	{
		*res = *buff;
		res++;
		buff++;
	}
	*(nl + 1) = '\0';
	node->data = buff_cpy;
	node->next = NULL;
	while (findlast->next != NULL)
		findlast = findlast->next;
	findlast->next = node;
	return(res_cpy);
}



void	insert_full(t_node	*head, char	*buff)
{
	t_node	*node;
	t_node	*findlast;

	findlast = head;
	//node = ft_calloc (1, sizeof(t_node));
	node = malloc(sizeof(t_node));
	ft_memset(node, 0, sizeof(t_node));
	node->data = buff;
	node->next = NULL;
	while (findlast->next != NULL)
		findlast = findlast->next;
	findlast->next = node;
}



int     checkstatus(char    *buff)
{
    int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		//printf("buff[i]: %c\n", buff[i]);
		if(buff[i] == '\n' && i < BUFFER_SIZE - 1 && buff[i + 1] != '\0')
			return(1);
        else if(buff[i] == '\n')
            return(2);
        else if(buff[i]== '\0')
            return(3);
		i++;
	}
	return(0);
}

char	*get_next_line(int fd)
{
    t_node	*head;
	char	*buff;
    static int     status = 0;
    int		byte_read;
    bool    done;
	char *rtn;
	static char	*res;

	if (BUFFER_SIZE < 1 || status == 3 || fd < 0 )
		return (NULL);
	byte_read = 1;
	done = 0;
	//head = ft_calloc(1, sizeof(t_node));
	head = malloc(sizeof(t_node));
	ft_memset(head, 0, sizeof(t_node));
	head->data = NULL;
	head->next = NULL;

    if(status == 1)
        insert_full(head, res);
    while (done != 1)
    {
		//buff = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
		ft_memset(buff, 0, (BUFFER_SIZE + 1) * sizeof(char));
        byte_read = read(fd, buff, BUFFER_SIZE);
		//printf("byte_read: %d\n", byte_read);
        if (byte_read < 0 || (BUFFER_SIZE != 0 && *buff == '\0'))
		{
			free(buff);
			free(head);
			return (NULL);
		}
        buff[BUFFER_SIZE] = '\0';
		if (byte_read != 0)
			status = checkstatus (buff);
		else if(byte_read == 0)
			status = 2;
		//printf("status: %d\n", status);
        if (status == 0)
		{
            insert_full(head, buff);
		}
		else if (status == 1)
		{
            res = insert_by_withres(head, buff);
            done = 1;
        }
		else if (status == 2 || status == 3)
		{
			insert_by(head, buff);
			done = 1;
		}
		
    }

	rtn = create_line(head);
	freeList(head);
    return(rtn);
}