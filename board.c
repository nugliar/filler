/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:21:20 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/04 17:21:54 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	clean_board(char **board)
{
	int		i;
	int		j;

	i = 0;
	while (board[i])
	{
		j = 0;
		while (board[i][j])
		{
			if (board[i][j] == 'o')
				board[i][j] = 'O';
			j++;
		}
		i++;
	}
}

void	put_on_board(t_data *data, int i, int num, int coor[num][2])
{
	int		j;
	int		x;
	int		y;

	j = 0;
	clean_board(data->board);
	while (j < num)
	{
		x = data->ret[0] + coor[j][0] - coor[i][0];
		y = data->ret[1] + coor[j][1] - coor[i][1];
		data->board[x][y] = 'o';
		j++;
	}
}
