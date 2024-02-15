/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:36:22 by sarmonte          #+#    #+#             */
/*   Updated: 2024/02/15 16:26:03 by sarmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function for print a string
int	ft_print_string(char *str)
{
	int	size;

	size = 0;
	if (str == 0)
		return (ft_print_string("(null)"));
	while (str[size])
		size += ft_print_character(str[size]);
	return (size);
}

// Function for print a number
int	ft_print_number(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += ft_print_character('0');
	if (n == -2147483648)
	{
		size += ft_print_string("-2147483648");
		return (size);
	}
	if (n < 0)
	{
		size += ft_print_character('-');
		n = -n;
	}
	if (n > 0)
		size += ft_print_unsigned((unsigned int)n);
	return (size);
}

// Function for print an unsigned number
int	ft_print_unsigned(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += ft_print_character('0');
	else
	{
		if (n / 10 != 0)
			ft_print_unsigned(n / 10);
		ft_print_character((n % 10) + '0');
		while (n > 0)
		{
			n /= 10;
			size++;
		}
	}
	return (size);
}
