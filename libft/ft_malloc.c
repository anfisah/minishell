#include "libft.h"

t_list	**init_list(void)
{
	static t_list	*free_list;

	return (&free_list);
}

void	*ft_malloc(unsigned long size)
{
	char	*buffer;
	t_list	*new_elem;

	buffer = malloc(size);
	if (!buffer)
	{
		free_list();
		printf("ERROR Malloc\n");
		exit (1);
	}
	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
	{
		free(buffer);
		free_list();
		printf("ERROR Malloc\n");
		exit (1);
	}
	new_elem->content = buffer;
	new_elem->next = 0;
	ft_listadd_back(init_list(), new_elem);
	return (buffer);
}

int	ft_free(void *ptr)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;
	t_list	**start;

	prev = 0;
	start = init_list();
	current = *start;
	while (current)
	{
		next = current->next;
		if (current->content == ptr)
		{
			free(ptr);
			free(current);
			if (prev)
				prev->next = next;
			else
				*start = next;
			return (1);
		}
		prev = current;
		current = current->next;
	}
	return (0);
}

void	free_list(void)
{
	t_list	*current;
	t_list	*next;
	t_list	**start;

	start = init_list();
	current = *start;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*start = 0;
}
