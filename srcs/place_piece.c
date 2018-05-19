/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 08:51:02 by enennige          #+#    #+#             */
/*   Updated: 2018/05/18 19:17:15 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_location_value(t_game game, t_turn *turn, int r, int c)
{
	int	location_value_sum;
	int	oflag;
	int pc;
	int pr;

	oflag = 0;
	location_value_sum = 0;
	pr = 0;
	while (pr < turn->piece_rows)
	{
		pc = 0;
		while (pc < turn->piece_cols)
		{
			if (turn->piece_map[pr][pc] == '*')
			{
				if (!(is_on_board(game, pr + r, pc + c)))
					return (-1);
				else if (turn->heatmap[pr + r][pc + c] == ENEMY_NUM)
					return (-1);
				else if (oflag && turn->heatmap[pr + r][pc + c] == PLAYER_NUM)
					return (-1);
				else if (turn->heatmap[pr + r][pc + c] == PLAYER_NUM)
					oflag = 1;
				else
					location_value_sum += turn->heatmap[pr + r][pc + c];
			}
			pc++;
		}
		pr++;
	}
	if (oflag == 0)
		return (-1);
	return (location_value_sum);
}

void	set_piece_offset(t_turn *turn)
{
	int r;
	int c;

	turn->r_offset = turn->piece_rows;
	turn->c_offset = turn->piece_cols;
	r = 0;
	while (turn->piece_map[r] != NULL)
	{
		c = 0;
		while (turn->piece_map[r][c] != '\0')
		{
			if (turn->piece_map[r][c] == '*')
			{
				if (r < turn->r_offset)
					turn->r_offset = r;
				if (c < turn->c_offset)
					turn->c_offset = c;
			}
			c++;
		}
		r++;
	}
}

void	place_piece(t_game game, t_turn *turn)
{
	int r;
	int c;
	int sum;
	int	min_sum;

	set_piece_offset(turn);
	min_sum = ERROR;
	r = turn->r_offset * -1;
	while (r < game.rows)
	{	
		c = turn->c_offset * -1;
		while (c < game.cols)
		{
			sum = get_location_value(game, turn, r, c);
			if (sum > 0 && (sum < min_sum || min_sum == ERROR))
			{
				min_sum = sum;
				turn->place_row = r;
				turn->place_col = c;
			}
			c++;
		}
		r++;
	}
}
