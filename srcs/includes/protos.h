/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/14 03:42:50 by plavaux           #+#    #+#             */
/*   Updated: 2014/09/16 19:26:27 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOS_H
# define PROTOS_H

void	disp_stdin(void);
int		can_fit_square(int size, int x, int y, int **table);
int		*get_square(int **table, int offset, int a);

int	size_arrays(char *filename, int x, int n);
int	*get_info(char *filename);
int	**allocate_array(char*filename, int j, int k);
int	**read_constraints(char *filename);

#endif
