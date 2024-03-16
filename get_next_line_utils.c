/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <hsenzaki@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:16:39 by hsenzaki          #+#    #+#             */
/*   Updated: 2024/02/04 16:16:41 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

#include "leakdetect.h"
#define malloc(s) leak_detelc_malloc(s, __FILE__, __LINE__)
#define free leak_detect_free

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n != 0)
	{
		*ptr = c;
		ptr++;
		n--;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	void	*mem;

	if (size == 0 || nmemb == 0)
	{
		size = 1;
		nmemb = 1;
	}
	bytes = nmemb * size;
	if (bytes / size != nmemb)
		return (NULL);
	mem = malloc(size * nmemb);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, size * nmemb);
	return (mem);
}

int	ft_strlen(char	*s)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}



void freeList(t_node *head)
{
   t_node *tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	srclen;

	srclen = ft_strlen (src);
	if (size == 0)
	{
		return (srclen);
	}
	while (size != 1 && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (srclen);
}