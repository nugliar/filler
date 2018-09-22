/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:25:34 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/04 17:28:37 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_token(t_data *data, char *buf, int ret)
{
	int		i;

	data->token = (char **)malloc(sizeof(char *) * (data->t_x + 1));
	if (!(data->token))
		exit_prog(data, "Memalloc failure\n");
	i = 0;
	while (i < data->t_x && (ret = get_next_line(0, &buf)))
	{
		if (ret < 0)
			exit_prog(data, "Token read failure\n");
		if (i < data->t_x)
			(data->token)[i++] = ft_strdup(buf);
		if (buf)
			free(buf);
		buf = NULL;
	}
	data->token[i] = NULL;
}

void	get_token_size(t_data *data, char *buf, int ret)
{
	int		i;

	ret = get_next_line(0, &buf);
	if (ret <= 0)
		exit_prog(data, "Token size read failure\n");
	i = 0;
	while (buf[i] && !ft_isdigit(buf[i]))
		i++;
	data->t_x = (int)ft_atoi(buf + i);
	while (buf[i] && !(buf[i] == ' ' || buf[i] == '\t'))
		i++;
	data->t_y = (int)ft_atoi(buf + (++i));
	if (buf)
		free(buf);
}

void	get_board(t_data *data, char *buf, int ret)
{
	int		i;

	data->board = (char **)malloc(sizeof(char *) * (data->x + 1));
	if (!(data->board))
		exit_prog(data, "Memalloc failure\n");
	i = 0;
	if ((get_next_line(0, &buf)) > 0)
		free(buf);
	buf = NULL;
	while (i < data->x)
	{
		ret = get_next_line(0, &buf);
		if (ret <= 0 || !ft_isdigit(*buf))
			exit_prog(data, "Board read failure\n");
		(data->board)[i++] = ft_strdup(buf + 4);
		if (buf)
			free(buf);
		buf = NULL;
	}
	(data->board)[i] = NULL;
}

void	get_board_size(t_data *data, char *buf, int ret)
{
	int		i;

	while (!ft_strstr(buf, "Plateau"))
	{
		if (buf)
			free(buf);
		buf = NULL;
		ret = get_next_line(0, &buf);
		if (ret <= 0)
			exit_prog(data, "Board size read failure\n");
	}
	i = 0;
	while (buf[i] && !ft_isdigit(buf[i]))
		i++;
	data->x = (int)ft_atoi(buf + i);
	while (buf[i] && !(buf[i] == ' ' || buf[i] == '\t'))
		i++;
	data->y = (int)ft_atoi(buf + (++i));
	if (buf)
		free(buf);
}

void	get_pl_num(t_data *data, char *buf, int ret)
{
	while (!ft_strstr(buf, "[./rsharipo.filler]"))
	{
		if (buf)
			free(buf);
		buf = NULL;
		ret = get_next_line(0, &buf);
		if (ret <= 0)
			exit_prog(data, "Player number read failure\n");
	}
	if (ft_strstr(buf, "$$$ exec p1"))
		data->pl_num = 1;
	else if (ft_strstr(buf, "$$$ exec p2"))
		data->pl_num = 2;
	if (buf)
		free(buf);
}
