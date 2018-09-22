/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 10:58:25 by rsharipo          #+#    #+#             */
/*   Updated: 2018/08/31 18:49:30 by rsharipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_lstpop(t_list **lst)
{
	t_list	*tmp;
	void	*ret;

	ret = NULL;
	if (lst && *lst)
	{
		ret = (*lst)->cont;
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
		return (ret);
	}
	return (NULL);
}
