/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_type_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 13:41:23 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/22 19:57:21 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	sticky_bits(t_file *f, char permission)
{
	if (permission == '0')
		return ;
	if (permission == '1' || permission == '3' || permission == '5' ||
		permission == '7')
		f->mode[8] = f->mode[8] == '-' ? 'T' : 't';
	if (permission == '2' || permission == '3' || permission == '6' ||
		permission == '7')
		f->mode[5] = f->mode[5] == '-' ? 'S' : 's';
	if (permission == '4' || permission == '5' || permission == '6' ||
		permission == '7')
		f->mode[2] = f->mode[2] == '-' ? 'S' : 's';
}

static void	permissions(t_file *f, char *t_m)
{
	int		current;

	current = ft_strlen(t_m) - 3;
	f->mode = ft_strnew(9);
	while (t_m[current])
	{
		if (t_m[current] == '7')
			ft_strncat(f->mode, "rwx", 3);
		else if (t_m[current] == '6')
			ft_strncat(f->mode, "rw-", 3);
		else if (t_m[current] == '5')
			ft_strncat(f->mode, "r-x", 3);
		else if (t_m[current] == '4')
			ft_strncat(f->mode, "r--", 3);
		else if (t_m[current] == '3')
			ft_strncat(f->mode, "-wx", 3);
		else if (t_m[current] == '2')
			ft_strncat(f->mode, "-w-", 3);
		else if (t_m[current] == '1')
			ft_strncat(f->mode, "--x", 3);
		else if (t_m[current] == '0')
			ft_strncat(f->mode, "---", 3);
		current++;
	}
	sticky_bits(f, t_m[ft_strlen(t_m) - 4]);
}

static void	char_dir_block(t_file *f, char *t_m)
{
	if (t_m[0] == '1')
		f->type = 'p';
	else if (t_m[0] == '2')
		f->type = 'c';
	else if (t_m[0] == '4')
		f->type = 'd';
	else
		f->type = 'b';
}

static void	regular_symbolic_socket(t_file *f, char *t_m)
{
	if (t_m[1] == '0')
		f->type = '-';
	else if (t_m[1] == '2')
		f->type = 'l';
	else if (t_m[1] == '4')
		f->type = 's';
	else
		f->type = 'W';
}

void		ls_type_mode(struct stat *buf, t_file *f)
{
	char	*type_mode;
	
	type_mode = ft_itoa_base(buf->st_mode, 8, 0);
	if (ft_strlen(type_mode) == 6)
		regular_symbolic_socket(f, type_mode);
	else
		char_dir_block(f, type_mode);
	permissions(f, type_mode);
	ft_strdel(&type_mode);
}
