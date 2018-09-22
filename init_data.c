/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 18:59:24 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/01 11:30:26 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_data(t_data *data)
{
	data->board = NULL;
	data->token = NULL;
	data->x = 0;
	data->y = 0;
	data->t_x = 0;
	data->t_y = 0;
	(data->ret)[0] = -1;
	(data->ret)[1] = -1;
}
