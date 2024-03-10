/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <hsenzaki@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:17:23 by hsenzaki          #+#    #+#             */
/*   Updated: 2024/03/09 02:09:25 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct node
{
	char		*data;
	struct node	*next;
}	t_node;

int     checkstatus(char    *buff);
void	insert_full(t_node	*head, char	*buff);
char	*create_line(t_node	*head);
int	ft_strlen(char	*s);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	*get_next_line(int fd);
void freeList(t_node *head);
void	insert_by(t_node	*head, char	*buff, int status);
char	*insert_by_withres(t_node	*head, char	*buff);
#endif
