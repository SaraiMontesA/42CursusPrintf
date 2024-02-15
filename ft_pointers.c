/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:35:09 by sarmonte          #+#    #+#             */
/*   Updated: 2024/02/15 16:25:54 by sarmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length_pointer(unsigned long long ptr);

static void	ft_search_pointer(unsigned long long ptr);

// Function for print a pointer
int	ft_print_pointer(unsigned long long ptr)
{
	int	size;

	size = 0;
	size += ft_print_string("0x");
	if (ptr == 0)
		size += ft_print_character('0');
	else
	{
		ft_search_pointer(ptr);
		size += ft_length_pointer(ptr);
	}
	return (size);
}

// Function for length of the pointer
static int	ft_length_pointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

// Function for search the pointer
static void	ft_search_pointer(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_search_pointer(ptr / 16);
		ft_search_pointer(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_print_character(ptr + '0');
		else
			ft_print_character(ptr - 10 + 'a');
	}
}
