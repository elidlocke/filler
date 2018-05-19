/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_num_heatmaps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 11:39:37 by enennige          #+#    #+#             */
/*   Updated: 2018/05/18 17:00:07 by enennige         ###   ########.fr       */
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

	if (!(turn->heatmap= (int **)malloc(sizeof(int *) * game.rows)))
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
			{
				turn->heatmap[r][c] = turn->heatmap_self[r][c];
			}
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

void	make_maps(t_game game, t_turn *turn)
{
	init_heat_map(game, turn, 's');
	fill_map(game, turn->heatmap_self, -1, PLAYER_NUM);
	init_heat_map(game, turn, 'e');
	fill_map(game, turn->heatmap_enemy, 1, ENEMY_NUM);
	combine_heatmaps(game, turn);
}

