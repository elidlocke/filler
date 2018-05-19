/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corner_heatmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:25:30 by enennige          #+#    #+#             */
/*   Updated: 2018/05/19 12:45:58 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heatmap.h"

void	set_startpoint(t_game *game, t_turn *turn)
{
	int r;
	int c;

	if (game->start_row != ERROR && game->start_col != ERROR)
		return ;
	r = 0;
	while (r < game->rows)
	{
		c = 0;
		while (c < game->cols)
		{
			if (turn->board_map[r][c] == game->player_char)
			{
				game->start_row = r;
				game->start_col = c;
			}
			c++;
		}
		r++;
	}
}

void	set_corner(t_game *game)
{
	if (game->furthest_corner_row != ERROR &&
			game->furthest_corner_col != ERROR)
		return ;
	game->furthest_corner_row = 0;
	game->furthest_corner_col = 0;
	if ((game->rows - 1 - game->start_row) > game->start_row)
		game->furthest_corner_row = game->rows - 1;
	if ((game->cols - 1 - game->start_col) > game->start_col)
		game->furthest_corner_col = game->cols - 1;
}

void	fill_empty_map_chars(t_game game, t_turn *turn)
{
	int r;
	int c;
	int fill_big;

	fill_big = game.rows * game.cols;
	r = 0;
	while (r < game.rows)
	{
		c = 0;
		while (c < game.cols)
		{
			if (turn->heatmap[r][c] == 0)
			{
				turn->heatmap[r][c] = fill_big;
			}
			c++;
		}
		r++;
	}
}

void	make_corner_heatmap(t_game game, t_turn *turn)
{
	set_startpoint(&game, turn);
	set_corner(&game);
	turn->heatmap[game.furthest_corner_row][game.furthest_corner_col] =
		CORNER_NUM;
	fill_map(game, turn->heatmap, 1, CORNER_NUM);
	fill_empty_map_chars(game, turn);
}
