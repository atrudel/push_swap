/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 18:06:03 by atrudel           #+#    #+#             */
/*   Updated: 2017/02/18 18:06:04 by atrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*to_delete;

	if (alst && *alst)
	{
		to_delete = *alst;
		*alst = to_delete->next;
		ft_lstdelone(&to_delete, del);
	}
}
