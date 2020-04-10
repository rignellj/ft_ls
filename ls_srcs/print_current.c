/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_current.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 12:39:30 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/10 13:36:06 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_current(t_list **node)
{
	t_list	*current;

	current = *node;
	ft_putchar('\n');
	while (current)
	{
		if (current->content)
		{
			ft_printf("Previous %p\n", current->prev);
			ft_printf("Name of current %s, current address %p\n",
			((t_file*)current->content)->name, current);
			ft_printf("Next %p\n", current->next);
			ft_printf("-----------------\n");
		}
		current = current->next;
	}
	ft_putchar('\n');
}