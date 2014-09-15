/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 15:34:24 by plavaux           #+#    #+#             */
/*   Updated: 2014/09/15 23:03:39 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

void	ft_putchar(char str);
void	ft_putnbr(int s);
void	ft_putstr(char *str);
int		ft_strlen(char *str);

int		ft_close(int fd);
int		ft_open(char *file);
int		ft_read(int fd);

#endif
