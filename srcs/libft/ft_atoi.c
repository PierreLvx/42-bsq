/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/01 14:26:39 by fschuber          #+#    #+#             */
/*   Updated: 2014/09/18 22:00:41 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libs.h"

void	change_number(int *num, int *factor, char *ptr)
{
	if (*ptr >= 48 && *ptr <= 57)
	{
		*num += (*ptr - 48) * (*factor);
		*factor = *factor * 10;
	}
	else
	{
		*factor = 1;
		*num = 0;
	}
}

int		ft_special_atoi(char *str)
{
	int result;
	int factor;
	int length;

	factor = 1;
	result = 0;
	length = 0;
	while (*str && *str != '\n')
	{
		str++;
		length++;
	}
	str--;
	str--;
	length--;
	str--;
	length--;
	str--;
	length--;
	while (length-- > 0)
	{
		change_number(&result, &factor, str);
		str--;
	}
	return (result);
}
