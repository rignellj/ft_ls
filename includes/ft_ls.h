/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:38:31 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/14 12:59:23 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include "../libft/printf_srcs/includes/ft_printf.h"

/*
********************************************************************************
**                                                                            **
**                         DEV                                                **
**                                                                            **
********************************************************************************
*/

void			print_current(t_list **node);

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
	long		epoc;
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
	int			ac;
	int			links_len;
	int			owner_len;
	int			group_len;
	int			size_len;
	t_list		*first;
	int			(*fptr[2])(void*, void*);
}				t_ls;

/*
********************************************************************************
**                                                                            **
**                         MOST IMPORTANT FUNCTIONS                           **
**                                                                            **
********************************************************************************
*/

void			ls_open_directories(t_ls *flags, t_list **node, char *dir);
void			ls_read_directories(t_list **node, t_ls *flags, DIR *dirp,
				char *path);
void			ls_lstadd_linkedlist(t_list **node, t_ls *f, char *s, int i);
void			ls_lstadd(t_list **node, char *av);
void			ls_file_add(t_list **node, char *file_name, struct stat *buf, char *path);
void			ls_del_current(t_list **node, t_list *current, t_ls *flags);
void			ls_lstdel(t_list **node, t_ls *flags);
void			ls_error(void);

/*
********************************************************************************
**                                                                            **
**                         LS DATA FUNCTIONS                                  **
**                                                                            **
********************************************************************************
*/

void			ls_type_mode(struct stat *buf, t_file *f);
void			ls_group_owner(struct stat *buf, t_file *f);
void			ls_last_modified(struct stat *buf, t_file *f);
void			ls_get_flags(t_ls *flags, char *av[], size_t *i, int ac);

/*
********************************************************************************
**                                                                            **
**                         SORT/CMP FUNCTIONS                                 **
**                                                                            **
********************************************************************************
*/

int				compare_high_low(void *s1, void *s2);
int				compare_low_high(void *s1, void *s2);
t_list			*ls_find_first(t_list *current);

/*
********************************************************************************
**                                                                            **
**                         PRINT FUNCTIONS                                    **
**                                                                            **
********************************************************************************
*/

void			ls_print_current(t_ls *flags, t_list **node);
void			ls_print_files_del(t_list **node, t_ls *flags, int i);
void			ls_print_content(t_list *current, t_ls *flags);
t_list			**ls_print_not_existing_f(char *av[], size_t *i, t_ls *flags, t_list **node);

#endif
