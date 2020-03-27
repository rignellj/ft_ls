/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 17:14:27 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/27 14:22:29 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ls_check_flags(t_ls *flags, char *flag_str)
{
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

void		ls_get_flags(t_ls *flags, int ac, char *av[], size_t *i)
{
	char	*str;
	char	*tmp;

	ft_bzero(flags, sizeof(t_ls));
	tmp = ft_strnew(0);
	while (av[*i] && av[*i][0] == '-')
	{
		if (!(str = ft_strsub(av[*i], 1, ft_strlen(av[*i]))))
			ls_error();
		str = ft_joindel(tmp, str);
		tmp = ft_strdup(str);
		ft_strdel(&str);
		(*i)++;
	}
	if ((flags->not = ac == 1 ? 1 : 0))
		ls_check_flags(flags, tmp);
	ft_strdel(&tmp);
}
