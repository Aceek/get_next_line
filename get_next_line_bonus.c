/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:53:46 by ilinhard          #+#    #+#             */
/*   Updated: 2022/05/11 01:41:01 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_add_buff(int fd, char *save)
{
	char	*buff;
	int		read_len;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	read_len = 1;
	while (!ft_strchr(save, '\n') && read_len != 0)
	{
		read_len = read(fd, buff, BUFFER_SIZE);
		if (read_len < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[read_len] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*ft_get_line(char *str)
{
	char	*new;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new = malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_clear(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new)
		return (free(str), NULL);
	i++;
	j = 0;
	while (str[i + j])
	{
		new[j] = str[i + j];
		j++;
	}
	new[j] = '\0';
	free(str);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (NULL);
	save[fd] = ft_add_buff(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = ft_get_line(save[fd]);
	save[fd] = ft_clear(save[fd]);
	return (line);
}
