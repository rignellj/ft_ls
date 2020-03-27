/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_not_existing_f.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 14:30:49 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/27 21:02:26 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		**ls_bubblesort(char **array)
{
	int		flag;
	int		i;

	// array = ft_strsplit(str, ' ');
	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (array[i] && array[i + 1])
		{
			if (ft_strcmp(array[i], array[i + 1]) > 0)
			{
				ft_swap((void**)&array[i], (void**)&array[i + 1]);
				flag = 1;
			}
			i++;
		}
	}
	return (array);
}

static void	ls_print_not_e(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		ft_printf("ft_ls: %s: No such file or directory\n", array[i]);
		i++;
	}
	ft_mem_arrdel((void**)array);
}

static int	ls_lstat(char *av)
{
	struct stat	buf;

	if (lstat(av, &buf) == 0)
		return (1);
	else
		return (0);
}

char		*ls_print_not_existing_f(char *av[], size_t *i)
{
	size_t	j;
	// char	*str;
	char	*exist;
	char	**not_exist;
	
	// ft_printf("Here\n");
	not_exist = ft_arraynew(0);
	// str = ft_strnew(0);
	exist = ft_strnew(0);
	
	j = *i;
	while (av[j])
	{
		if (!ls_lstat(av[j]))// str = ft_joindel(str, ft_add_char(av[j], ' '));
			not_exist = ft_array_push((const char**)not_exist, av[j]);
		else
			exist = ft_joindel(exist, ft_add_char(av[j], ' '));
		j++;
	}
	ls_bubblesort(not_exist);
	ls_print_not_e(not_exist);
	// ft_mem_arrdel((void**)not_exist);
	// ft_strdel(&str);
	return (exist);
}
