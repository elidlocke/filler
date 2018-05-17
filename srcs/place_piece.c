/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 08:51:02 by enennige          #+#    #+#             */
/*   Updated: 2018/05/17 11:59:04 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_location_value(t_game game, t_turn *turn, int r, int c)
{
	int	location_value_sum;
	int	oflag;
	int pc;
	int pr;

	(void)game;
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
					//fprintf(stderr, "\e[1;34m NOT ON BOARD\n\e[0m");
					return (-1);
				}
				else if (turn->heatmap[pr + r][pc + c] == ENEMY_NUM)
				{
					//fprintf(stderr, "\e[1;34m ON ENEMY\n\e[0m");
					return (-1);
				}
				else if (turn->heatmap[pr + r][pc + c] == PLAYER_NUM)
				{
					//fprintf(stderr, "\e[1;34m ON PLAYER\n\e[0m");
					oflag = 1;
				}
				else if (oflag && turn->heatmap[pr + r][pc + c] == PLAYER_NUM)
				{
					//fprintf(stderr, "\e[1;34m ON PLAYER TWICE\n\e[0m");
					return (-1);
				}
				else
				{
					location_value_sum += turn->heatmap[pr + r][pc + c];
				}
			}
			pc++;
		}
		pr++;
	}
	if (oflag == 0)
	{
		//fprintf(stderr, "\e[1;34m NOT ON SELF\n\e[0m");
		return (-1);
	}
	return (location_value_sum);
}


//get lowest position for piece

void	place_piece(t_game game, t_turn *turn)
{
	int r;
	int c;
	int sum;
	int	min_sum;

	min_sum = -1;
	//fprintf(stderr, "\e[1;34mVALUES:\n\e[0m");
	r = 0;
	while (r < game.rows)
	{	
		c = 0;
		while (c < game.cols)
		{
			//fprintf(stderr, "\e[1;34m row:%d col:%d", r, c);
			sum = get_location_value(game, turn, r, c);
			//fprintf(stderr, "\e[1;34m \n%d\n\e[0m", sum);
			if (sum > 0 && (sum < min_sum || min_sum == -1))
			{
				min_sum = sum;
				turn->place_row = r;
				turn->place_col = c;
			}
			c++;
		}
		//fprintf(stderr, "\e[1;34m\n\e[0m");
		r++;
	}
	fprintf(stderr, "\e[1;34m chose row:%d col:%d\n\e[0m", turn->place_row, turn->place_col);
}
