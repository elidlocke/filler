/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 08:51:02 by enennige          #+#    #+#             */
/*   Updated: 2018/05/19 16:48:56 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		validate_location(t_game game, t_turn *turn, int *coor, int *oflag)
{
	if (!(is_on_board(game, coor[0], coor[1])))
		return (-1);
	else if (turn->heatmap[coor[0]][coor[1]] == ENEMY_NUM)
		return (-1);
	else if (*oflag && turn->heatmap[coor[0]][coor[1]] == PLAYER_NUM)
		return (-1);
	else if (turn->heatmap[coor[0]][coor[1]] == PLAYER_NUM)
		*oflag = 1;
	return (0);
}

int		get_location_value(t_game game, t_turn *turn, int *coor, int oflag)
{
	int sum_coor[2];
	int pcoor[2];

	turn->place_value = 0;
	pcoor[0] = 0;
	while (pcoor[0] < turn->piece_rows)
	{
		pcoor[1] = 0;
		while (pcoor[1] < turn->piece_cols)
		{
			if (turn->piece_map[pcoor[0]][pcoor[1]] == '*')
			{
				sum_coor[0] = pcoor[0] + coor[0];
				sum_coor[1] = pcoor[1] + coor[1];
				if (validate_location(game, turn, sum_coor, &oflag) == -1)
					return (-1);
				turn->place_value += turn->heatmap[sum_coor[0]][sum_coor[1]];
			}
			pcoor[1]++;
		}
		pcoor[0]++;
	}
	if (oflag == 0)
		return (-1);
	return (turn->place_value);
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
	int coor[2];
	int sum;
	int	min_sum;
	int	oflag;

	set_piece_offset(turn);
	min_sum = ERROR;
	coor[0] = turn->r_offset * -1;
	while (coor[0] < game.rows)
	{
		coor[1] = turn->c_offset * -1;
		while (coor[1] < game.cols)
		{
			oflag = 0;
			sum = get_location_value(game, turn, coor, oflag);
			if (sum > 0 && (sum < min_sum || min_sum == ERROR))
			{
				min_sum = sum;
				turn->place_row = coor[0];
				turn->place_col = coor[1];
			}
			coor[1]++;
		}
		coor[0]++;
	}
}
