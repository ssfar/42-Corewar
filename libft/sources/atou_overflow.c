/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atou_overflow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssfar <samisfar.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:14:45 by ssfar             #+#    #+#             */
/*   Updated: 2020/07/23 02:12:23 by ssfar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convert a number written in ascci to the pointed unsigned int in parameters,
** without taking the sign in account.
** If the pointed value is overflowed the function return 1, else 0.
** <I> Before the number is stored, the value pointed is set to 0 but only
** if the string and pointer are not NULL.
*/

t_bool	atou_overflow(const char *str, unsigned int *result)
{
	unsigned int	prev;
	t_bool			overflow;

	overflow = false;
	if (!str || !result)
		return (overflow);
	*result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		prev = *result;
		*result = *result * 10 + (*(str++) - '0');
		if (*result < prev)
			overflow = true;
	}
	return (overflow);
}
