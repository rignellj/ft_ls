/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_current.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 15:57:45 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/05 22:23:35 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ls_files(DIR *dirp, char **files, t_ls *flags)
{
	struct dirent	*name;

	while ((name = readdir(dirp)))
	{
		if (flags->a == 1)
			files = ft_array_push(files, name->d_name);
		else
			files = *(name->d_name) != '.' ? ft_array_push(files, name->d_name)
			: files;
	}
	ft_qsort(files, 0, ft_arraylen((const char**)files) - 1,
	flags->r ? flags->fptr[1] : flags->fptr[0]);
	ft_printf("%2a\n", files);
	ft_mem_arrdel((void**)files);
}

void		ls_print_current(t_ls *flags)
{
	char	**files;
	DIR		*dirp;

	files = ft_arraynew(0);
	if ((dirp = opendir(".")) != NULL)
	{
		ls_files(dirp, files, flags);
	}
	if (closedir(dirp) == -1)
		ls_error();
}
