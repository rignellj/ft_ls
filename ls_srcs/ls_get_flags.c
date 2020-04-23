/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 17:14:27 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/23 17:27:51 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdlib.h>

static void	ls_check_illegal(char *str)
{
	char	*flags;
	int		i;

	i = 0;
	flags = "Ralrt";
	while (str[i])
	{
		if (ft_strchr(flags, str[i]) == NULL)
		{
			ft_printf("ft_ls: illegal option -- %c\n", str[i]);
			ft_printf("usage: ft_ls [-Ralrt] [file ...]\n");
			ft_strdel(&str);
			exit(1);
		}
		i++;
	}
}

static void	put_functions_to_array(t_ls *flags)
{
	if (flags->t)
		flags->fptr[0] = &compare_low_high_int;
	else
		flags->fptr[0] = &compare_low_high;
}

static void	ls_check_flags(t_ls *flags, char *flag_str)
{
	ls_check_illegal(flag_str);
	if (ft_strchr(flag_str, 'a'))
		flags->a = 1;
	if (ft_strchr(flag_str, 'l'))
		flags->l = 1;
	if (ft_strchr(flag_str, 'r'))
		flags->r = 1;
	if (ft_strchr(flag_str, 'R'))
		flags->rec = 1;
	if (ft_strchr(flag_str, 't'))
		flags->t = 1;
}

void		ls_get_flags(t_ls *flags, char *av[], size_t *i, int ac)
{
	char	*str;
	char	*tmp;
	int		flag;

	ft_bzero(flags, sizeof(t_ls));
	if (!(tmp = ft_strnew(0)))
		exit(1);
	flag = 0;
	while (av[*i] && av[*i][0] == '-')
	{
		if (!(str = ft_strsub(av[*i], 1, ft_strlen(av[*i]))))
			exit(1);
		str = ft_joindel(tmp, str);
		if (!(tmp = ft_strdup(str)))
			exit(1);
		ft_strdel(&str);
		(*i)++;
		flag = 1;
	}
	flags->ac = ac - *i;
	if (flag)
		ls_check_flags(flags, tmp);
	put_functions_to_array(flags);
	ft_strdel(&tmp);
}
