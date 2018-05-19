/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 09:53:12 by enennige          #+#    #+#             */
/*   Updated: 2018/05/18 12:17:26 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_offset(t_turn *turn)
{
	int pr;
	int pc;

	pr = 0;
	turn->piece_row_offset = turn->piece_rows;
	turn->piece_col_offset  = turn->piece_cols;
	while (pr < turn->piece_rows)
	{
		pc = 0;
		while (pc < turn->piece_cols)
		{
			if (turn->piece_map[pr][pc] == '*')
			{
				if (pr < turn->piece_row_offset)
					turn->piece_row_offset = pr;
				if (pc < turn->piece_col_offset)
					turn->piece_col_offset = pc;
			}
			pc++;
		}
		pr++;
	}
}

void	set_trimmed_piece(t_turn *turn)
{
	int r;

	turn->piece_trimmed_map = (char **)malloc(sizeof(char *) *
			(turn->piece_rows - turn->piece_row_offset + 1));
	if (!(turn->piece_trimmed_map))
		return ;
	r = 0;
	while (r < turn->piece_rows - turn->piece_row_offset)
	{
		turn->piece_trimmed_map[r] = ft_strsub(turn->piece_map[r + turn->piece_row_offset], turn->piece_col_offset, turn->piece_cols - turn->piece_col_offset);
		r++;
	}
	turn->piece_trimmed_map[r] = NULL;
}

void	trim_piece(t_turn *turn)
{
	set_offset(turn);
	set_trimmed_piece(turn);
}
