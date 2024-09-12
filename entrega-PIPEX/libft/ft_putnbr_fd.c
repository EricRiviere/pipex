/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:20:57 by eriviere          #+#    #+#             */
/*   Updated: 2024/06/25 10:33:29 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putbase_fd(int nbr, const char *base, int fd)
{
	int		base_len;
	long	nb;
	char	c;

	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		write (fd, "-", 1);
		nb = -((long)nbr);
	}
	else
		nb = (long)nbr;
	if (nb > (base_len - 1))
		ft_putbase_fd(nb / base_len, base, fd);
	c = base[nb % base_len];
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char const	*base;

	base = "0123456789";
	ft_putbase_fd(n, base, fd);
}
