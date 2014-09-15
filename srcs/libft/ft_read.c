/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 22:59:51 by plavaux           #+#    #+#             */
/*   Updated: 2014/09/15 23:07:15 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libs.h"

int	ft_read(int fd)
{
	int		ret;
	char	buff[BUFFER_SIZE + 1];

	while ((ret = read(fd, buff, BUFFER_SIZE)))
	{
		buff[ret] = '\0';
		ft_putstr(buff);
	}
	return (fd);
}
