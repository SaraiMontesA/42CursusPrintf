/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:34:13 by sarmonte          #+#    #+#             */
/*   Updated: 2024/02/15 01:35:06 by sarmonte         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_printf.h"

static int	ft_select_format(va_list argument, const char word);

// Function for print one character
int	ft_print_character(int character)
{
	write(1, &character, 1);
	return (1);
}
// Function for select flag
int	ft_print_flag(const char flag)
{
	int size;

	size = 0;
	if (flag == '-')
		return (ft_print_character('-'));	// Alinea a la izquierda el valor dentro del campo especificado.
	else if (flag == 0)
		return (ft_print_character(0));		// Rellena con ceros a la izquierda hasta alcanzar la anchura del campo.
	else if (flag == '.')
		return (ft_print_character('.'));	// Es complicado, consultarlo
	else if (flag == '#')
		return (ft_print_character('#'));	// Usa "forma alternativa" para ciertos tipos de formato. Por ejemplo, para %x o %X, añade un 0x o 0X al principio del número.
	else if (flag == ' ')
		return (ft_print_character(' '));	// Inserta un espacio antes del número si no se muestra el signo.
	else if (flag == '+')
		size += (ft_print_character('+'));	// Obliga a printf a mostrar siempre el signo de un número. 
	else
		write(1, &flag, 1);
	return (size);
}

// Function principal for print the string
int	ft_printf(const char *str, ...)
{
	int		i;
	int		size;
	va_list	argument;

	i = 0;
	size = 0;
	va_start(argument, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_select_format(argument, str[i + 1]);
			i++;
		}
		else
		{
			size += ft_print_character(str[i]);
		}
		i++;
	}
	va_end(argument);
	return (size);
}

// Function for select the format of arguments after '%'
static int	ft_select_format(va_list argument, const char word)
{
	int	size;

	size = 0;
	if (word == '-' || word == '0' || word == '.' || word == '#' || word == ' ' || word == '+')
		size += ft_print_flag(word);
	else if (word == 'c')
		size += ft_print_character(va_arg(argument, int));
	else if (word == 's')
		size += ft_print_string(va_arg(argument, char *));
	else if (word == 'p')
		size += ft_print_pointer(va_arg(argument, unsigned long long));
	else if (word == 'd' || word == 'i')
		size += ft_print_number(va_arg(argument, int));
	else if (word == 'u')
		size += ft_print_unsigned(va_arg(argument, unsigned int));
	else if (word == 'x' || word == 'X')
		size += ft_print_hexadecimal(va_arg(argument, unsigned int), word);
	else
		size += ft_print_character(word);
	return (size);
}

