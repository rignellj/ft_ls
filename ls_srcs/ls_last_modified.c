/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_last_modified.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 19:26:57 by jrignell          #+#    #+#             */
/*   Updated: 2020/03/24 19:20:31 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char		*ls_join_and_delete(char *s1, char *s2)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (new);
}

static char		*date_without_seconds(char *hh_tt_ss)
{
	char	**tab_hours_minutes_seconds;
	char	*hours;
	char	*minutes;
	char	*ret;

	tab_hours_minutes_seconds = ft_strsplit(hh_tt_ss, ':');
	hours = ft_strdup(tab_hours_minutes_seconds[0]);
	minutes = ft_add_char(tab_hours_minutes_seconds[1], ':');
	ret = ls_join_and_delete(hours, minutes);
	ft_mem_arrdel((void**)tab_hours_minutes_seconds);
	return (ret);
}

static char		*modify_date(char *date, int year_or_hh_mm)
{
	char	**tab_date;
	char	*join;
	char	*ret;
	char	*tmp;
	char	*tmp2;
	
	tab_date = ft_strsplit(date, ' ');
	tmp = ft_add_char(tab_date[1], ' ');
	join = ls_join_and_delete(ft_strdup(tab_date[2]), tmp);
	if (year_or_hh_mm)
	{
		tmp = ft_add_char(tab_date[4], ' ');
		ret = ls_join_and_delete(join, tmp);
	}
	else
	{
		tmp = date_without_seconds(tab_date[3]);
		tmp2 = ft_add_char(tmp, ' ');
		ret = ls_join_and_delete(join, tmp2);
		ft_strdel(&tmp);
	}
	ft_mem_arrdel((void**)tab_date);
	return (ret);
}

void			ls_last_modified(struct stat *buf, t_file *f)
{
	long			epoc_time;
	char			*date;
	long			now;
	int				year_or_hh_mm;
	int				half_year_in_seconds;

	now = time(NULL);
	half_year_in_seconds = 15778476;
	epoc_time = buf->st_mtime;
	year_or_hh_mm = FT_ABS((now - epoc_time)) > half_year_in_seconds ? 1 : 0;
	date = ft_strdup(ctime(&epoc_time));
	f->last_mod = modify_date(date, year_or_hh_mm);
	ft_strdel(&date);
}
