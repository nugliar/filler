/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:10:48 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/05 10:20:33 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	mask_board(t_data *data, char **board, int x, int y)
{
	char	c;

	c = (data->pl_num == 1) ? 'O' : 'X';
	while (x < data->x)
	{
		y = 0;
		while (y < data->y)
		{
			if (board[x][y] == c || board[x][y] == c + 32)
			{
				if (x % 20 == 0)
					board[x][y] = 'M';
				else if (y % 20 == 0)
					board[x][y] = 'M';
			}
			y++;
		}
		x++;
	}
}
