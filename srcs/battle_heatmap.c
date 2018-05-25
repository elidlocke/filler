/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_heatmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:25:12 by enennige          #+#    #+#             */
/*   Updated: 2018/05/24 18:33:30 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heatmap.h"

void	set_number(int **board, t_game game,
							int *coor, int fill)
{
	int r;
	int c;

	r = coor[0];
	c = coor[1];
	if (is_on_board(game, r + 1, c) && board[r + 1][c] == 0)
		board[r + 1][c] = fill;
	if (is_on_board(game, r, c + 1) && board[r][c + 1] == 0)
		board[r][c + 1] = fill;
	if (is_on_board(game, r - 1, c) && board[r - 1][c] == 0)
		board[r - 1][c] = fill;
	if (is_on_board(game, r, c - 1) && board[r][c - 1] == 0)
		board[r][c - 1] = fill;
	if (is_on_board(game, r + 1, c + 1) && board[r + 1][c + 1] == 0)
		board[r + 1][c + 1] = fill;
	if (is_on_board(game, r - 1, c - 1) && board[r - 1][c - 1] == 0)
		board[r - 1][c - 1] = fill;
	if (is_on_board(game, r + 1, c - 1) && board[r + 1][c - 1] == 0)
		board[r + 1][c - 1] = fill;
	if (is_on_board(game, r - 1, c + 1) && board[r - 1][c + 1] == 0)
		board[r - 1][c + 1] = fill;
}

int		get_fill(int direction, int rows, int cols)
{
	if (direction == -1)
		return (get_bigger_num(rows, cols) - 1);
	else
		return (1);
}

void	fill_map(t_game game, int **map, int direction, int obj_value)
{
	int coor[2];
	int	fill;
	int	filled_flag;

	filled_flag = 1;
	fill = get_fill(direction, game.rows, game.cols);
	while (fill != 0 && filled_flag == 1)
	{
		filled_flag = 0;
		coor[0] = 0;
		while (coor[0] < game.rows)
		{
			coor[1] = 0;
			while (coor[1] < game.cols)
			{
				if (map[coor[0]][coor[1]] == obj_value)
					set_number(map, game, coor, fill);
				else if (map[coor[0]][coor[1]] == fill)
				{
					set_number(map, game, coor, fill + direction);
					filled_flag = 1;
				}
				coor[1]++;
			}
			coor[0]++;
		}
		fill += direction;
	}
}

void	combine_heatmaps(t_game game, t_turn *turn)
{
	int r;
	int c;

	if (!(turn->heatmap = (int **)malloc(sizeof(int *) * game.rows)))
		return ;
	r = 0;
	while (r < game.rows)
	{
		if (!(turn->heatmap[r] = (int *)malloc(sizeof(int) * game.cols)))
			return ;
		c = 0;
		while (c < game.cols)
		{
			if (turn->heatmap_self[r][c] < 0)
				turn->heatmap[r][c] = turn->heatmap_self[r][c];
			else
			{
				turn->heatmap[r][c] = turn->heatmap_self[r][c]
									+ turn->heatmap_enemy[r][c];
			}
			c++;
		}
		r++;
	}
}

void	make_battle_heatmap(t_game game, t_turn *turn)
{
	fill_map(game, turn->heatmap_self, -1, PLAYER_NUM);
	fill_map(game, turn->heatmap_enemy, 1, ENEMY_NUM);
	combine_heatmaps(game, turn);
}
