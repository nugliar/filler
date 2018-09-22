/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_coor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:11:44 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/04 17:41:17 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		num_of_token_coor(t_data *data)
{
	int		x;
	int		y;
	int		count;

	count = 0;
	x = 0;
	while (x < data->t_x)
	{
		y = 0;
		while (y < data->t_y)
			if ((data->token)[x][y++] == '*')
				count++;
		x++;
	}
	return (count);
}

void	shift_coor_to_zero(int num, int coor[num][2], int n)
{
	int	min;
	int	i;

	min = INT_MAX;
	i = 0;
	while (i < num)
	{
		if (coor[i][n] < min)
			min = coor[i][n];
		i++;
	}
	i = 0;
	while (i < num)
		coor[i++][n] -= min;
	if (n == 0)
		shift_coor_to_zero(num, coor, 1);
}

void	get_token_coor(t_data *data, int num, int coor[num][2])
{
	int		x;
	int		y;

	x = 0;
	while (x < data->t_x)
	{
		y = 0;
		while (y < data->t_y)
		{
			if ((data->token)[x][y] == '*')
			{
				(*coor)[0] = x;
				(*coor)[1] = y;
				coor++;
			}
			y++;
		}
		x++;
	}
}
