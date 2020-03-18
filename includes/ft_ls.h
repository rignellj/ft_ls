/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:38:31 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/18 19:43:23 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include "../printf_srcs/includes/ft_printf.h"

/*
********************************************************************************
**                                                                            **
**                         DEV                                                **
**                                                                            **
********************************************************************************
*/

# include <stdio.h>

/*
********************************************************************************
**                                                                            **
**                         STRUCTS                                            **
**                                                                            **
********************************************************************************
*/

typedef struct	s_f
{
	char		*name;
	char		type;
	char		*mode;
	char		*owner;
	char		*group;
	char		*last_mod;
	int			links;
	int			size;
	struct s_f	*next;
	struct s_f	*prev;
}				t_f;

typedef struct	s_ls
{
	
}				t_ls;

/*
********************************************************************************
**                                                                            **
**                         FUNCTIONS                                          **
**                                                                            **
********************************************************************************
*/

void			ls_form_data(struct stat *buf, char **av);
void			ls_type_mode(struct stat *buf, t_f *f);
void			ls_group_owner(struct stat *buf, t_f *f);
void			ls_last_modified(struct stat *buf, t_f *f);

#endif
