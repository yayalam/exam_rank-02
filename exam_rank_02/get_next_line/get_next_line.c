/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylambark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:28:31 by ylambark          #+#    #+#             */
/*   Updated: 2022/02/25 14:58:35 by ylambark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *get_next_line(int fd)
{
	char	*str;
	char	s;
	int		i;
	int		j;

	i = 1;
	j = 0;
	str = NULL;
	s = '\0';
	if (BUFFER_SIZE < 0 && fd == -1)
		return (0);
	str = (char *)malloc(9999);
	if (!str)
		return(0);
	while (s != '\n' && i != 0)
	{
		i = read(fd, &s, 1);
		if (i == -1)
		{
			free(str);
			return (0);
		}
		if (i != 0)
			str[j++] = s;
		str[j] = '\0';
	}
	if (!*str || !str)
	{
		free(str);
		return (0);
	}
	return (str);
}
int main()
{
     int fd;
     fd = open("tst.txt",O_RDONLY);
	 char *t;
     int i=0;
     t = get_next_line(fd);
     while (t != NULL)
	 {
         printf("%s",t);
         t = get_next_line(fd);
         i++;
     }
     close(fd);
}
