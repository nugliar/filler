/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 10:30:29 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/03 10:56:47 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	exit_prog(t_data *data, const char *message)
{
	free_data(data, 0);
	write(2, "ERROR: ", 7);
	write(2, message, ft_strlen(message));
	exit(0);
}
