/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 17:14:27 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/23 17:14:54 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void ls_check_flags(t_ls *flags, char *flag_str)
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

void		ls_get_flags(t_ls *flags, int ac, char *av[])
{
	char	*str;
	char	*tmp;
	char	*tmp2;
	size_t	i;

	ft_bzero(flags, sizeof(t_ls));
	flags->not = ac == 1 ? 1 : 0; // no flags
	if (flags->not)
		return ;
	i = 1;
	while (av[i][0] == '-')
	{
		if (!(str = ft_strsub(av[i], 1, ft_strlen(av[i]))))
			ls_error();
		tmp2 = ft_strjoin(tmp, str);
		ft_strdel(&tmp);
		ft_strdel(&str);
		tmp = ft_strdup(tmp2);
		ft_strdel(&tmp2);
		i++;
	}
	ls_check_flags(flags, tmp);
	ft_strdel(&tmp);
}