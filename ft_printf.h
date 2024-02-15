/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:33:32 by sarmonte          #+#    #+#             */
/*   Updated: 2024/02/15 16:26:14 by sarmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* #########################################
// #    INCLUDES OF EXTERNAL LIBRARIES     #
// #######################################*/

// It is used to handle variable number of function arguments.
# include <stdarg.h>
# include <unistd.h>

/* #########################################	
// #    LIST OF FUNCTIONS                  #
// #######################################*/

int	ft_print_character(int character);
int	ft_printf(const char *str, ...);
int	ft_print_string(char *str);
int	ft_print_number(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hexadecimal(unsigned int num, const char word);
int	ft_print_pointer(unsigned long long ptr);

#endif