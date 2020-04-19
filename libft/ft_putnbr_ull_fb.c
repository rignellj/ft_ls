/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ull_fb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:33:20 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/15 18:50:18 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_ull_fd(unsigned long long int n, int fd)
{
	if (n >= 10)
		ft_putnbr_ull_fd(n / 10, fd);
	ft_putchar_fd((char)(n % 10 + '0'), fd);
}
