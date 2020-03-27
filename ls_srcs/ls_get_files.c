/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 17:16:56 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/27 21:04:34 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
/*
static char	**ls_only_files(char *str)
{
	char	**array;
	char	*files;
	char	*dirs;
	int		i;

	i = 0;
	array = ft_strsplit(str, ' ');
	while (array[i])
	{
		
	}
}
*/
void		ls_get_files(t_ls *flags, char *files_dir)
{
	char	**array;
	int		i;

	i = 0;
	flags->a = flags->a;
//	ls_only_files(files_dir);
	ft_printf("\%s\n", files_dir);
	array = ft_strsplit(files_dir, ' ');
	// array = ls_bubblesort(files_dir);
	while (array[i + 1])
		ft_printf("%s ", array[i++]);
//	ft_printf("%s", array[i]);
	ft_mem_arrdel((void**)array);
	ft_strdel(&files_dir);
}
