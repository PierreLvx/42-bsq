/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 15:34:24 by plavaux           #+#    #+#             */
/*   Updated: 2014/09/18 05:00:00 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

void	ft_putchar(char str);
void	ft_putnbr(int s);
void	ft_putstr(char *str);
int		ft_strlen(char *str);

void	change_number(int *num, int *factor, char *ptr);
int		ft_atoi(char *str);
int		ft_special_atoi(char *str);

int		**read_stdin(void);

#endif
