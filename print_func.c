/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:23:32 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/05 09:42:42 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_input(t_data *data)
{
	int	i;

	ft_printf("%@PLAYER NUM = %d\n", data->pl_num);
	ft_printf("%@BOARD SIZE: X = %d, Y = %d\n", data->x, data->y);
	i = 0;
	if (data->board)
		while ((data->board)[i])
			ft_printf("%@%s\n", (data->board)[i++]);
	else
		ft_printf("%@NO BOARD\n");
	ft_printf("%@TOKEN SIZE: X = %d, Y = %d\n", data->t_x, data->t_y);
	i = 0;
	if (data->token)
		while ((data->token)[i])
			ft_printf("%@%s\n", (data->token)[i++]);
	else
		ft_printf("%@NO TOKEN\n");
}

void	print_table(char **board)
{
	int	i;

	i = 0;
	while (board[i])
		ft_printf("%@%s\n", board[i++]);
}
