/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:11:11 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/16 09:53:11 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_stdin(t_data *data, int ret)
{
	while (ret)
	{
		init_data(data);
		if (!data->pl_num)
			get_pl_num(data, 0, 1);
		get_board_size(data, 0, 1);
		get_board(data, 0, 1);
		get_token_size(data, 0, 1);
		get_token(data, 0, 1);
		ret = place_token(data, num_of_token_coor(data));
		if (ret)
			ft_printf("%d %d\n", data->ret[0], data->ret[1]);
		else
			ft_printf("0 0\n");
		free_data(data, 0);
	}
}

int		main(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->pl_num = 0;
	read_stdin(data, 1);
	return (0);
}
