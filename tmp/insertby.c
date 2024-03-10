char	*insert_by(t_node	*head, char	*buff, int status)
{
    t_node		*node;
	t_node		*findlast;
	char		*bynlnt;
	char		*bynlnt_cpy;
	static char	*res;

	if (buff == NULL)
	{
		insert_full(head, res);
		bynlnt_cpy = NULL;
	}
	else
	{
		findlast = head;
		node = ft_calloc(1, sizeof(t_node));
		bynlnt = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		bynlnt_cpy = bynlnt;

		while(*buff != '\n' && *buff != '\0')
		{
			*bynlnt = *buff;
			bynlnt++;
			buff++;
		}
		if (status == 1)
        {
			*bynlnt = '\n';
			buff++;
			res = buff;
		}else if (status == 2)
            *bynlnt = '\n';
        else if(status == 3)
			*bynlnt = '\0';

		node->data = bynlnt_cpy;
		node->next = NULL;
		while (findlast->next != NULL)
			findlast = findlast->next;
		findlast->next = node;
	}
	return(bynlnt_cpy);
}