/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awahib <awahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:43:06 by awahib            #+#    #+#             */
/*   Updated: 2023/12/19 22:10:29 by awahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*stash[1024];
	char			*line;
	int				check_error;

	check_error = ft_read(fd, stash);
	if (stash[fd] == NULL || check_error == -1)
	{
		free_stash(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	generate_line(stash[fd], &line);
	clean_stash(&stash[fd]);
	if (line[0] == '\0')
	{
		free_stash(stash[fd]);
		stash[fd] = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

int	ft_read(int fd, t_list **stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(sizeof(char) * (size_t)(BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (0);
	while (!find_newline(stash[fd]))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read == -1)
		{
			free_stash(stash[fd]);
			stash[fd] = NULL;
			free(buffer);
			return (-1);
		}
		buffer[bytes_read] = '\0';
		fill_stash(stash, buffer, bytes_read, fd);
	}
	free(buffer);
	return (0);
}

void	fill_stash(t_list **stash, char *buffer, int bytes_read, int fd)
{
	int		i;
	t_list	*last_node;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (bytes_read + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buffer[i] && i < bytes_read)
	{
		new_node->content[i] = buffer[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (stash[fd] == NULL)
	{
		stash[fd] = new_node;
		return ;
	}
	last_node = ft_lstlast(stash[fd]);
	last_node->next = new_node;
}

void	generate_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	allocate_line(line, stash);
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	clean_stash(t_list **stash)
{
	int		i;
	int		j;
	t_list	*last_node;
	t_list	*clean_node;

	clean_node = malloc(sizeof(t_list));
	if (stash == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last_node = ft_lstlast(*stash);
	i = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	if (last_node->content && last_node->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * ((ft_strlen(last_node->content)
					- i) + 1));
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last_node->content[i])
		clean_node->content[j++] = last_node->content[i++];
	clean_node->content[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}
