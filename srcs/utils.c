/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 09:06:18 by enennige          #+#    #+#             */
/*   Updated: 2018/05/17 10:15:32 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int     get_bigger_num(int a, int b)
{
    if (a >= b)
        return a;
    return b;
}

int     is_on_board(t_game game, int row, int col)
{
    if ((row >= 0 && row < game.rows) &&
        (col >= 0 && col < game.cols))
        return (1);
    return (0);
}
