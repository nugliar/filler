/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:11:12 by rsharipo          #+#    #+#             */
/*   Updated: 2018/09/03 10:31:38 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *src, int size)
{
	char	*new;

	new = NULL;
	new = (char *)malloc(ft_strlen(src) + size + 1);
	if (!new)
		return (NULL);
	if (src)
	{
		ft_strcpy(new, src);
		free(src);
	}
	else
		*new = 0;
	return (new);
}
