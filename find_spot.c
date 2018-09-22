/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_spot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:09:06 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/16 10:02:03 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		find_right_most(t_data *data, char **board, char c, int half)
{
	int		x;
	int		y;
	int		max;

	c = (half != 0) ? 'M' : c;
	max = INT_MIN;
	x = 0;
	while (x < data->x)
	{
		y = 0;
		while (y < data->y)
		{
			if (y > max && (board[x][y] == c || board[x][y] == c - 32))
			{
				max = y;
				(data->ret)[0] = x;
				(data->ret)[1] = y;
			}
			y++;
		}
		x++;
	}
	return ((max == INT_MIN) ? 0 : 1);
}

int		find_left_most(t_data *data, char **board, char c, int half)
{
	int		x;
	int		y;
	int		min;

	c = (half != 0) ? 'M' : c;
	min = INT_MAX;
	x = 0;
	while (x < data->x)
	{
		y = 0;
		while (y < data->y)
		{
			if (y < min && (board[x][y] == c || board[x][y] == c - 32))
			{
				min = y;
				(data->ret)[0] = x;
				(data->ret)[1] = y;
			}
			y++;
		}
		x++;
	}
	return ((min == INT_MAX) ? 0 : 1);
}

int		find_up_most(t_data *data, char **board, char c, int half)
{
	int		x;
	int		y;
	int		min;

	c = (half != 0) ? 'M' : c;
	min = INT_MAX;
	x = 0;
	while (x < data->x)
	{
		y = 0;
		while (y < data->y)
		{
			if (x < min && (board[x][y] == c || board[x][y] == c - 32))
			{
				min = x;
				(data->ret)[0] = x;
				(data->ret)[1] = y;
			}
			y++;
		}
		x++;
	}
	return ((min == INT_MAX) ? 0 : 1);
}

int		find_low_most(t_data *data, char **board, char c, int half)
{
	int		x;
	int		y;
	int		max;

	c = (half != 0) ? 'M' : c;
	max = INT_MIN;
	x = 0;
	while (x < data->x)
	{
		y = 0;
		while (y < data->y)
		{
			if (x > max && (board[x][y] == c || board[x][y] == c - 32))
			{
				max = x;
				(data->ret)[0] = x;
				(data->ret)[1] = y;
			}
			y++;
		}
		x++;
	}
	return ((max == INT_MIN) ? 0 : 1);
}

int		find_spot(t_data *data, char **board, int dir, int half)
{
	int		ret;
	char	c;

	if (data->x < 50)
		half = 0;
	if (half != 0)
		mask_board(data, board, 0, 0);
	c = (data->pl_num == 1) ? 'o' : 'x';
	if (dir == 0)
		ret = find_left_most(data, board, c, half);
	else if (dir == 1)
		ret = find_right_most(data, board, c, half);
	else if (dir == 2)
		ret = find_up_most(data, board, c, half);
	else
		ret = find_low_most(data, board, c, half);
	if (half != 0 && ret == 0)
		return (find_spot(data, board, dir, 0));
	return (ret);
}
