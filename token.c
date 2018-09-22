/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 09:33:39 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/16 10:01:09 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		spot_valid(t_data *data, int i, int num, int coor[num][2])
{
	int		j;
	int		x;
	int		y;
	char	c;

	j = 0;
	while (j < num)
	{
		x = data->ret[0] + coor[j][0] - coor[i][0];
		y = data->ret[1] + coor[j][1] - coor[i][1];
		if (x >= data->x || x < 0)
			return (0);
		if (y >= data->y || y < 0)
			return (0);
		c = data->board[x][y];
		if (!(c == '.' || c == '#'))
			return (0);
		j++;
	}
	return (1);
}

void	convert_coor(t_data *data, char **token, int pos)
{
	int		x;
	int		y;
	int		count;

	x = 0;
	count = -1;
	while (x < data->t_x)
	{
		y = 0;
		while (y < data->t_y)
		{
			if (token[x][y] == '*')
				count++;
			if (count == pos)
			{
				(data->ret)[0] = (data->ret)[0] - x;
				(data->ret)[1] = (data->ret)[1] - y;
				return ;
			}
			y++;
		}
		x++;
	}
}

int		try_spot(t_data *data, char **board, int num, int coor[num][2])
{
	int		i;

	i = 0;
	board[data->ret[0]][data->ret[1]] = '#';
	while (i < num)
	{
		if (spot_valid(data, i, num, coor))
		{
			convert_coor(data, data->token, i);
			return (1);
		}
		i++;
	}
	board[data->ret[0]][data->ret[1]] = 'N';
	return (0);
}

int		place_token(t_data *data, int num)
{
	int			coor[num][2];
	int			placed;
	int			val;
	static int	dir;

	val = choose_dir(data, data->board);
	if (val == DOUBLE || val == MULTI)
		dir = dir % 4;
	else
		dir = val;
	get_token_coor(data, num, coor);
	shift_coor_to_zero(num, coor, 0);
	placed = 0;
	while (!placed && find_spot(data, data->board, dir, (val == MULTI)))
	{
		placed = try_spot(data, data->board, num, coor);
		if (!placed)
			data->board[data->ret[0]][data->ret[1]] = 'N';
	}
	dir++;
	return (placed);
}
