/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awahib <awahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:43:08 by awahib            #+#    #+#             */
/*   Updated: 2023/12/06 09:54:22 by awahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(t_list *stash)
{
	int		i;
	t_list	*last;

	if (stash == NULL)
		return (0);
	last = ft_lstlast(stash);
	i = 0;
	while (last->content[i])
	{
		if (last->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *stash)
{
	t_list	*current;

	current = stash;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	allocate_line(char **line, t_list *stash)
{
	int	i;
	int	length;

	length = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				length++;
				break ;
			}
			i++;
			length++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char *) * (length + 1));
}

void	free_stash(t_list *stash)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp = stash;
	while (tmp)
	{
		free(tmp->content);
		tmp1 = tmp->next;
		free(tmp);
		tmp = tmp1;
	}
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
