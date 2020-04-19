/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 17:37:13 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/17 16:02:28 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strfee(char const *s1, char const *s2, char const *s3)
{
	if (s1 != NULL)
		ft_memdel((void**)&s1);
	if (s2 != NULL)
		ft_memdel((void**)&s2);
	if (s3 != NULL)
		ft_memdel((void**)&s3);
}
