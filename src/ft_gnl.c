/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 10:31:06 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/22 15:20:52 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static t_list	*get_file(t_list **files, const int fd)
{
	t_list	*file;

	file = *files;
	while (file != NULL)
	{
		if ((int)file->FD == fd)
			return (file);
		file = file->next;
	}
	if (!(file = ft_lstnew("\0", 1)))
		return (NULL);
	file->FD = fd;
	ft_lstadd(files, file);
	return (file);
}

static int		save_file(t_list *file, char **line)
{
	int		size;
	int		splitter;
	char	*tmp;

	size = 0;
	splitter = -1;
	while (((char *)file->content)[size] != '\0')
	{
		if (splitter == -1)
			if (((char *)file->content)[size] == SPLITTER)
				splitter = size;
		size++;
	}
	if (splitter == -1)
		splitter = size;
	if (!(*line = ft_strnew(splitter)))
		return (0);
	ft_strncpy(*line, (char *)file->content, splitter);
	if (!(tmp = ft_strnew(size - splitter)))
		return (0);
	ft_strncpy(tmp, &((char *)file->content)[splitter + 1], size - splitter);
	free(file->content);
	file->content = tmp;
	return (1);
}

int				ft_gnl(const int fd, char **line)
{
	static t_list	*files;
	t_list			*file;
	char			buff[BUFF_SIZE + 1];
	int				result;
	char			*tmp;

	if ((fd < 0 || line == NULL || read(fd, buff, 0) < 0))
		return (-1);
	if (!(file = get_file(&files, fd)))
		return (-1);
	while ((result = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[result] = '\0';
		tmp = (char *)file->content;
		if (!(file->content = ft_strjoin(tmp, buff)))
			return (-1);
		free(tmp);
		if (ft_strchr(buff, SPLITTER) != NULL)
			break ;
	}
	if (result < BUFF_SIZE && !ft_strlen((char *)file->content))
		return (0);
	if (!(save_file(file, line)))
		return (-1);
	return (1);
}
