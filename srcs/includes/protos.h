/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/14 03:42:50 by plavaux           #+#    #+#             */
/*   Updated: 2014/09/16 13:24:51 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOS_H
# define PROTOS_H

void	disp_stdin(void);
int		can_fit_square(int size, int x, int y, int **table);
int		*get_square(int **table);

#endif
