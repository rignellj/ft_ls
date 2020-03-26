/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:38:31 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/26 20:17:03 by jrignell         ###   ########.fr       */
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
	int			logical_len;
	int			element_size;
	int			links;
	int			size;
	int			exist;
	char		type;
	char		*name;
	char		*mode;
	char		*owner;
	char		*path;
	char		*group;
	char		*last_mod;
	t_list		*head;
	t_list		*tail;
}				t_file;

typedef struct	s_ls
{
	int			a;
	int			l;
	int			not;
	int			r;
	int			rec;
	int			t;
	t_list		*first;
}				t_ls;

/*
********************************************************************************
**                                                                            **
**                         FUNCTIONS                                          **
**                                                                            **
********************************************************************************
*/

void			ls_print_content(t_list *node, t_ls *flags);
void			ls_type_mode(struct stat *buf, t_file *f);
void			ls_group_owner(struct stat *buf, t_file *f);
void			ls_last_modified(struct stat *buf, t_file *f);
void			ls_get_flags(t_ls *flags, int ac, char *av[], size_t *i);
void			ls_error(void);

/*
********************************************************************************
**                                                                            **
**                         LIST FUNCTIONS                                     **
**                                                                            **
********************************************************************************
*/

void			ls_lstadd(t_list **node, char *av);
t_list			*ft_mergesort(t_list *node);

#endif
