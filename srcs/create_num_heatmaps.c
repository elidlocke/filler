/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_num_heatmaps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 11:39:37 by enennige          #+#    #+#             */
/*   Updated: 2018/05/16 13:32:47 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

//create a board of the size that can hold integers
void	init_heat_map(t_game game, t_turn *turn)
{
	int r;
	int c;

	if (!(turn->heatmap_init = (int **)malloc(sizeof(int *) * (game.rows))))
		return ;
	r = 0;
	while (r < game.rows)
	{
		turn->heatmap_init[r] = (int *)malloc(sizeof(int *) * (game.cols));
		c = 0;
		while (c < game.cols)
		{
			if (turn->board_map[r][c] == '.')
				turn->heatmap_init[r][c] = 0;
			else if (turn->board_map[r][c] == game.player_char ||
					ft_toupper(turn->board_map[r][c]) == game.player_char)
				turn->heatmap_init[r][c] = -1;
			else
				turn->heatmap_init[r][c] = -2;
			c++;
		}
		r++;
	}
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
	fprintf(stderr, "\e[1;34mrow: %d col: %d\e[0m", start_row, start_col);
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

void	get_enemy_map(t_game game, t_turn *turn)
{
	//dup the init'd map instead of modifying it!!
	turn->heatmap_enemy = turn->heatmap_init;
	while (i < game.rows)
	{
		set_number(turn->heatmap_enemy, game, turn->start_row + 1, turn->start_col, 1);
	}
}

// repeat flood fill, with opposite count for myself

