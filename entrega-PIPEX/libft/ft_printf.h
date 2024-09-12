/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:22:21 by eriviere          #+#    #+#             */
/*   Updated: 2024/07/18 13:06:04 by eriviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
//Libreries
# include <unistd.h>
# include <stdarg.h>
//Functions
void	print_char(char c, int *counter);
void	print_string(char *str, int *counter);
void	print_di(int nb, int *counter);
void	print_unsigned(unsigned int nb, int *counter);
void	print_hexa(unsigned int nb, char type, int *counter);
void	print_pointer(unsigned long ptr, int *counter);
int		ft_printf(const char *str, ...);
#endif
