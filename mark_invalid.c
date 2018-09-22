/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_invalid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:22:17 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/05 10:55:02 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_invalid(t_data *data, char **board, int x, int y)
{
	int	count;
	int	lx;
	int	ly;

	lx = data->x;
	ly = data->y;
	count = 0;
	(x - 1 < 0) ? count += 3 : 0;
	(x + 1 >= lx) ? count += 3 : 0;
	(y - 1 < 0) ? count += 3 : 0;
	(y + 1 >= ly) ? count += 3 : 0;
	(x - 1 >= 0 && board[x - 1][y] != '.') ? count++ : 0;
	(x + 1 < lx && board[x + 1][y] != '.') ? count++ : 0;
	(y - 1 >= 0 && board[x][y - 1] != '.') ? count++ : 0;
	(y + 1 < ly && board[x][y + 1] != '.') ? count++ : 0;
	(x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] != '.') ? count++ : 0;
	(x - 1 >= 0 && y + 1 < ly && board[x - 1][y + 1] != '.') ? count++ : 0;
	(x + 1 < lx && y - 1 >= 0 && board[x + 1][y - 1] != '.') ? count++ : 0;
	(x + 1 < lx && y + 1 < ly && board[x + 1][y + 1] != '.') ? count++ : 0;
	return ((count >= 9) ? 1 : 0);
}

void	mark_invalid(t_data *data, char **board, int x, int y)
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
				if (is_invalid(data, data->board, x, y))
					board[x][y] = 'S';
			}
			y++;
		}
		x++;
	}
}
