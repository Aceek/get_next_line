/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:56:12 by ilinhard          #+#    #+#             */
/*   Updated: 2022/05/10 18:58:14 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_add_buff(int fd, char *save);
char	*ft_get_line(char *str);
char	*ft_clear(char *str);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		ft_strchr(char *str, char to_find);
char	*ft_strjoin(char *s1, char *s2);

#endif