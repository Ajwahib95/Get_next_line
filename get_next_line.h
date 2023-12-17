/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awahib <awahib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:43:11 by awahib            #+#    #+#             */
/*   Updated: 2023/12/17 23:22:46 by awahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
void				ft_read(int fd, t_list **stash);
void				fill_stash(t_list **stash, char *buffer, int bytes_read);
void				generate_line(t_list *stash, char **line);
void				clean_stash(t_list **stash);

int					find_newline(t_list *stash);
t_list				*ft_lstlast(t_list *stash);
void				free_stash(t_list *stash);
int					ft_strlen(const char *str);
void				allocate_line(char **line, t_list *stash);

#endif