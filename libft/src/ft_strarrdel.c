/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:47:03 by enennige          #+#    #+#             */
/*   Updated: 2018/05/15 14:57:50 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Free an array of strings
*/
void    ft_strarrdel(char **str_arr)
{
    int i;

    i = 0;
    while (str_arr[i] != NULL)
    {
        ft_strdel(&(str_arr[i]));
        i++;
    }
    free(str_arr);
}
