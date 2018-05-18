/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_turn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 13:20:35 by enennige          #+#    #+#             */
/*   Updated: 2018/05/17 14:33:43 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_chararr(char **arr)
{
	int i;

	i = 0;
	if (arr)
	{
		while (arr[i] != NULL)
		{
			ft_strdel(&arr[i]);
			i++;	
		}
	}
}

void	free_intarr(int **arr, int rows)
{
	int r;
	
	r = 0;
	if (arr)
	{
		while (r < rows)
		{
			if (arr[r])
				free(arr[r]);
			r++;
		}
	}
}

void	clear_turn(t_game game, t_turn *turn)
{
	//free_chararr(turn->board_map);
	//turn->board_map = NULL;
	free_intarr(turn->heatmap_enemy, game.rows);
	turn->heatmap_enemy = NULL;
	free_intarr(turn->heatmap_self, game.rows);
	turn->heatmap_self = NULL;
	free_intarr(turn->heatmap, game.rows);
	turn->heatmap = NULL;
	//free_chararr(turn->piece_map);
	//turn->piece_map = NULL;
}
