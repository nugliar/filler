/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:56:33 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/01 11:29:55 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_data(t_data *data, int i)
{
	if (data->board)
	{
		while (data->board[i])
			free(data->board[i++]);
		free(data->board);
		data->board = NULL;
	}
	i = 0;
	if (data->token)
	{
		while (data->token[i])
			free(data->token[i++]);
		free(data->token);
		data->token = NULL;
	}
}
