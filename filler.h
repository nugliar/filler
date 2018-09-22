/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:12:59 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/16 09:53:32 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "./libft/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_data
{
	char		**board;
	char		**token;
	int			ret[2];
	int			pl_num;
	int			x;
	int			y;
	int			t_x;
	int			t_y;
	int			hx;
	int			hy;
}				t_data;

typedef enum	e_edge
{
	LEFT = 0,
	RIGHT = 1,
	TOP = 2,
	BOTTOM = 3,
	NONE = INT_MIN,
	DOUBLE = 9999,
	MULTI = INT_MAX
}				t_edge;

void			init_data(t_data *data);
void			exit_prog(t_data *data, const char *message);
int				ft_printf(const char *format, ...);
int				place_token(t_data *data, int num);
int				num_of_token_coor(t_data *data);
void			print_table(char **board);
void			free_data(t_data *data, int i);
void			get_token_coor(t_data *data, int num, int coor[num][2]);
void			shift_coor_to_zero(int num, int coor[num][2], int n);
int				num_of_token_coor(t_data *data);
int				find_spot(t_data *data, char **board, int dir, int half);
int				choose_dir(t_data *data, char **board);
void			get_token(t_data *data, char *buf, int ret);
void			get_token_size(t_data *data, char *buf, int ret);
void			get_board(t_data *data, char *buf, int ret);
void			get_board_size(t_data *data, char *buf, int ret);
void			get_pl_num(t_data *data, char *buf, int ret);
void			mask_board(t_data *data, char **board, int x, int y);
void			mark_invalid(t_data *data, char **board, int x, int y);

#endif
