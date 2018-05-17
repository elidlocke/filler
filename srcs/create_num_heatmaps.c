/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_num_heatmaps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 11:39:37 by enennige          #+#    #+#             */
/*   Updated: 2018/05/16 20:24:41 by enennige         ###   ########.fr       */
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
		num_value = -1;
	else
		num_value = -2;
	return (num_value);
}

void	init_heat_map(t_game game, t_turn *turn, char type)
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
	if (type == 'e')
		turn->heatmap_enemy = arr;
	else
		turn->heatmap_self = arr;
}

int		is_on_board(t_game game, int start_row, int start_col)
{
	if ((start_row >= 0 && start_row < game.rows) &&
		(start_col >= 0 && start_col < game.cols))
		return (1);
	return (0);
}

//fill it with starting values for myself and for enemy
void	set_number(int **board, t_game game,
							int start_row, int start_col, int fill_num)
{
	if (is_on_board(game, start_row + 1, start_col) && board[start_row + 1][start_col] == 0)
		board[start_row + 1][start_col] = fill_num;
	if (is_on_board(game, start_row, start_col + 1) && board[start_row][start_col + 1] == 0)
		board[start_row][start_col + 1]  = fill_num;
	if (is_on_board(game, start_row - 1, start_col) && board[start_row - 1][start_col] == 0)
		board[start_row - 1][start_col] = fill_num;
	if (is_on_board(game, start_row, start_col - 1) && board[start_row][start_col - 1] == 0)
		board[start_row][start_col - 1] = fill_num;
	if (is_on_board(game, start_row + 1, start_col + 1) && board[start_row + 1][start_col + 1] == 0)
		board[start_row + 1][start_col + 1] = fill_num;
	if (is_on_board(game, start_row - 1, start_col - 1) && board[start_row - 1][start_col - 1] == 0)
		board[start_row - 1][start_col - 1] = fill_num;
	if (is_on_board(game, start_row + 1, start_col - 1) && board[start_row + 1][start_col - 1] == 0)
		board[start_row + 1][start_col - 1] = fill_num;
	if (is_on_board(game, start_row - 1, start_col + 1) && board[start_row - 1][start_col + 1] == 0)
		board[start_row - 1][start_col + 1] = fill_num;
}

/* Could refactor to get the max number from any x point to the edge */
int		get_bigger_num(int a, int b)
{
	if (a >= b)
		return a;
	return b;
}

void	fill_map(t_game game, int **map, int direction, int obj_value)
{
	int r;
	int c;
	int	fill_num;
	int max_num;

	max_num = get_bigger_num(game.rows, game.cols) + 1;
	if (direction == -1)
		fill_num = max_num - 1;
	else
		fill_num = 1;
	while (fill_num != 0 && fill_num != max_num)
	{
		r = 0;
		while (r < game.rows)
		{
			c = 0;
			while (c < game.cols)
			{
				if (map[r][c] == obj_value)
					set_number(map, game, r, c, fill_num);
				else if (map[r][c] == fill_num)
					set_number(map, game, r, c, fill_num + direction);
				c++;
			}
			r++;
		}
		fill_num += direction;
	}
}

void	combine_heatmaps(t_game game, t_turn *turn)
{
	int r;
	int c;

	if (!(turn->heatmap_ultimate = (int **)malloc(sizeof(int *) * game.rows)))
		return ;
	r = 0;
	while (r < game.rows)
	{
		if (!(turn->heatmap_ultimate[r] = (int *)malloc(sizeof(int) * game.cols)))
			return ;
		c = 0;
		while (c < game.cols)
		{
			if (turn->heatmap_self[r][c] < 0)
			{
				turn->heatmap_ultimate[r][c] = turn->heatmap_self[r][c];
			}
			else
			{
				turn->heatmap_ultimate[r][c] = turn->heatmap_self[r][c]
												+ turn->heatmap_enemy[r][c];
			}
			c++;
		}
		r++;
	}
}

void	make_maps(t_game game, t_turn *turn)
{
	fill_map(game, turn->heatmap_self, -1, -1);
	fill_map(game, turn->heatmap_enemy, 1, -2);
	combine_heatmaps(game, turn);
}

// repeat flood fill, with opposite count for myself

