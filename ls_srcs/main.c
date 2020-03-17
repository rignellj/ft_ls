/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 17:01:46 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/17 19:16:16 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	DIR				*dirp;
	struct dirent	*name;
	struct stat		buf;

/*	if ((dirp = opendir(av[1])) == NULL)
	{
		ft_printf("Error occurred\n");
		return (1);
	}
	else
		ft_printf("Directory opened\n");

	while ((name = readdir(dirp)))
	{
		ft_printf("Name: %s\n", name->d_name);
	}
	closedir(dirp);
*/
if (!(lstat(av[1], &buf)))
		{
			ft_printf("Name: %s\n", av[1]);
		}
	return (0);
}