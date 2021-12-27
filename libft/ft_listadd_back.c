/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 00:24:03 by ccoto             #+#    #+#             */
/*   Updated: 2020/11/26 02:24:05 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_listadd_back(t_list **alst, t_list *new)
{
	t_list	*lst_element;

	if (!new || !alst)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		lst_element = ft_listlast(*alst);
		lst_element->next = new;
	}
}
