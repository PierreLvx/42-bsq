/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/15 15:34:24 by plavaux           #+#    #+#             */
/*   Updated: 2014/09/18 22:10:01 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

void	ft_putchar(char str);
int		ft_strlen(char *str);

void	change_number(int *num, int *factor, char *ptr);
int		ft_special_atoi(char *str);

int		**get_stdin(void);

#endif
