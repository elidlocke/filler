/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 08:51:02 by enennige          #+#    #+#             */
/*   Updated: 2018/05/17 18:02:48 by enennige         ###   ########.fr       */
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
				{
					//fprintf(stderr, "\e[1;34m[%d %d]: NOT ON BOARD\n\e[0m", r, c);
					return (-1);
				}
				else if (turn->heatmap[pr + r][pc + c] == ENEMY_NUM)
				{
					//fprintf(stderr, "\e[1;34m[%d %d]: ON ENEMY\n\e[0m", r, c);
					return (-1);
				}
				else if (oflag && turn->heatmap[pr + r][pc + c] == PLAYER_NUM)
				{
					//fprintf(stderr, "\e[1;34m[%d %d]: ON SELF TWICE\n\e[0m", r, c);
					return (-1);
				}
				else if (turn->heatmap[pr + r][pc + c] == PLAYER_NUM)
				{
					oflag = 1;
				}
				else
					location_value_sum += turn->heatmap[pr + r][pc + c];
			}
			pc++;
		}
		pr++;
	}
	if (oflag == 0)
	{
		//fprintf(stderr, "\e[1;34m[%d %d]: NOT TOUCHING SELF\n\e[0m", r, c);
		return (-1);
	}
	return (location_value_sum);
}

void	place_piece(t_game game, t_turn *turn)
{
	int r;
	int c;
	int sum;
	int	min_sum;

	min_sum = -1;
	r = 0;
	while (r < game.rows)
	{	
		c = 0;
		while (c < game.cols)
		{
			sum = get_location_value(game, turn, r, c);
			if (sum > 0 && (sum < min_sum || min_sum == -1))
			{
				min_sum = sum;
				turn->place_row = r;
				turn->place_col = c;
			}
			c++;
		}
		r++;
	}
	//fprintf(stderr, "\e[1;34m chose row:%d col:%d\n\e[0m", turn->place_row, turn->place_col);
}
