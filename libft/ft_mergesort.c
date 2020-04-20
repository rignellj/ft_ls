/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:10:17 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/20 12:03:17 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*merge(t_list *node, t_list *middle, int (*cmp)(void *, void *))
{
	if (!node)
		return (middle);
	if (!middle)
		return (node);
	if (cmp(node->content, middle->content) < 0)
	{
		node->next = merge(node->next, middle, cmp);
		node->next->prev = node;
		node->prev = NULL;
		return (node);
	}
	else
	{
		middle->next = merge(node, middle->next, cmp);
		middle->next->prev = middle;
		middle->prev = NULL;
		return (middle);
	}
}

static t_list	*split_list(t_list *node)
{
	t_list	*right;
	t_list	*left;
	t_list	*middle;

	right = node;
	left = node;
	while (right->next && right->next->next)
	{
		right = right->next->next;
		left = left->next;
	}
	middle = left->next;
	left->next = NULL;
	return (middle);
}

t_list			*ft_mergesort(t_list *node, int (*cmp)(void *, void *))
{
	t_list	*middle;

	if (!node || !node->next)
		return (node);
	middle = split_list(node);
	node = ft_mergesort(node, cmp);
	middle = ft_mergesort(middle, cmp);
	return (merge(node, middle, cmp));
}
