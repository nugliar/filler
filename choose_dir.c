/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:18:12 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/04 17:20:18 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_edges(t_data *data, char **board, int *edge)
{
	int		i;
	char	c;

	c = (data->pl_num == 1) ? 'O' : 'X';
	i = -1;
	while (!edge[LEFT] && board[++i])
		if (board[i][0] == c || board[i][0] == c + 32)
			edge[LEFT] = 1;
	i = -1;
	while (!edge[RIGHT] && board[++i])
		if (board[i][data->y - 1] == c || board[i][data->y - 1] == c + 32)
			edge[RIGHT] = 1;
	i = -1;
	while (!edge[TOP] && board[0][++i])
		if (board[0][i] == c || board[0][i] == c + 32)
			edge[TOP] = 1;
	i = -1;
	while (!edge[BOTTOM] && board[data->x - 1][++i])
		if (board[data->x - 1][i] == c || board[data->x - 1][i] == c + 32)
			edge[BOTTOM] = 1;
}

int		edge_is(int *edge)
{
	int		i;
	int		count;
	int		ret;

	i = 0;
	count = 0;
	while (i < 4)
		if (edge[i++])
			count++;
	if (count == 2)
		return (DOUBLE);
	else if (count > 2)
		return (MULTI);
	if (count == 0)
		return (NONE);
	ret = (edge[LEFT]) ? LEFT : 0;
	ret = (edge[RIGHT]) ? RIGHT : 0;
	ret = (edge[TOP]) ? TOP : 0;
	ret = (edge[BOTTOM]) ? BOTTOM : 0;
	return (ret);
}

int		edge_nearby(t_data *data, char **board)
{
	char	c;
	int		x;
	int		y;

	c = (data->pl_num == 1) ? 'O' : 'X';
	x = 0;
	while (x < data->x)
	{
		y = 0;
		while (y < data->y)
		{
			if (board[x][y] == c || board[x][y] == c + 32)
			{
				if (x > (data->x) / 2)
					return (LEFT);
				else
					return (RIGHT);
			}
			y++;
		}
		x++;
	}
	return (LEFT);
}

int		choose_dir(t_data *data, char **board)
{
	static int	edge[4];
	int			dir;
	int			num_edges;

	check_edges(data, board, edge);
	num_edges = edge_is(edge);
	if (num_edges != DOUBLE && num_edges != MULTI)
	{
		if (edge_is(edge) == NONE)
			return (edge_nearby(data, board));
		edge[LEFT] ? dir = RIGHT : 0;
		edge[RIGHT] ? dir = LEFT : 0;
		edge[TOP] ? dir = BOTTOM : 0;
		edge[BOTTOM] ? dir = TOP : 0;
	}
	else
		dir = num_edges;
	return (dir);
}
