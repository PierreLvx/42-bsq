/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 15:32:03 by plavaux           #+#    #+#             */
/*   Updated: 2014/09/15 15:32:16 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int s)
{
	if (s < 0)
		ft_putchar(s + '0');
	if (s >= 10)
	{
		ft_putnbr(s / 10);
		ft_putnbr(s % 10);
	}
	else
		ft_putchar(s + '0');
}
