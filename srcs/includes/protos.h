/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavaux <plavaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/14 03:42:50 by plavaux           #+#    #+#             */
/*   Updated: 2014/09/18 22:58:27 by plavaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOS_H
# define PROTOS_H

void	disp_stdin(void);
int		can_fit_square(int size, int x, int y, int **table);
int		*get_square(int **table, int offset, int a, int size);

int		*size_arrays(char *filename, int x, int *array);
int		*get_info(char *filename);
int		**allocate_array(char*filename, int j, int k, int i);
int		**read_constraints(char *filename);

int		is_in(int **table, int x, int y);
void	print_table(int **table, int size, int *solution);

void	solve_map(char **argv, int i);

void	chk_map_chars(char buff, int *array);
void	chk_line_endings(int *array, int count, int file);
void	chk_map_min(int *array, int file);

void	ft_write_err(char *str);

#endif
