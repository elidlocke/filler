/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heatmaps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 17:22:04 by enennige          #+#    #+#             */
/*   Updated: 2018/05/18 19:58:37 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_heat_map_init_value(char game_char, char player_char)
{
	int num_value;

	if (game_char == '.')
		num_value = 0;
	else if (game_char == player_char ||
			ft_toupper(game_char) == player_char)
		num_value = PLAYER_NUM;
	else
		num_value = ENEMY_NUM;
	return (num_value);
}

void	init_heatmap(t_game game, t_turn *turn, char type)
{
	int r;
	int c;
	int **arr;

	if (!(arr = (int **)malloc(sizeof(int *) * (game.rows))))
		return ;
	r = 0;
	while (r < game.rows)
	{
		arr[r] = (int *)malloc(sizeof(int *) * (game.cols));
		c = 0;
		while (c < game.cols)
		{
			arr[r][c] = get_heat_map_init_value(turn->board_map[r][c],
												game.player_char);
			c++;
		}
		r++;
	}
	if (type == ENEMY)
		turn->heatmap_enemy = arr;
	else if (type == SELF)
		turn->heatmap_self = arr;
	else if (type == OPPOSITE_CORNER)
		turn->heatmap = arr;
}

void	init_heatmaps(t_game game, t_turn *turn)
{
	init_heatmap(game, turn, SELF);
	init_heatmap(game, turn, ENEMY);
	init_heatmap(game, turn, OPPOSITE_CORNER);
	print_num_arr(turn->heatmap, game.rows, game.cols);
}
