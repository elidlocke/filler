/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:12:40 by enennige          #+#    #+#             */
/*   Updated: 2018/05/15 15:20:36 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strchri() function locates the first occurrence of c (converted to a
** char) in the string pointed to by s and returns it's index
*/

#include "libft.h"

int		ft_strchri(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (0);
}
