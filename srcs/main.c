/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 10:28:19 by enennige          #+#    #+#             */
/*   Updated: 2018/05/17 16:26:57 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

//debugging function -- delete
void	print_arr(char **arr)
{
	int i;

	i = 0;
	fprintf(stderr, "\e[1;34mARRAY:\n\e[0m");
	while (arr[i] != NULL)
	{
		fprintf(stderr, "\e[1;34m|%s|\n\e[0m", arr[i]);
		i++;
	}
}


//debugging function -- delete
void	print_num_arr(int **arr, int rows, int cols)
{
	int r;
	int c;

	fprintf(stderr, "\e[1;34m NUM ARRAY:\n\e[0m");
	r = 0;
	while (r < rows)
	{
		c = 0;
		while (c < cols)
		{
			if (arr[r][c] == PLAYER_NUM)
				fprintf(stderr, "\x1B[32m%d \e[0m", arr[r][c]);
			else if (arr[r][c] == ENEMY_NUM)
				fprintf(stderr, "\x1B[31m%d \e[0m", arr[r][c]);
			else
				fprintf(stderr, "\e[1;34m %d \e[0m", arr[r][c]);
			c++;
		}
		fprintf(stderr, "\n");
		r++;
	}
}

void	print_move(int row, int col)
{
	ft_putnbr(row);
	ft_putchar(' ');
	ft_putnbr(col);
	ft_putchar('\n');
}

int main(void)
{
	t_game	game;
	t_turn	turn;
	int		can_move;

	init_game(&game);
	
	can_move = 1;
	while (can_move)
	{
		init_turn(game, &turn);
		make_maps(game, &turn);
		
		/* PRINT STATEMENTS */
		//print_arr(turn.board_map);
		//print_arr(turn.piece_map);
		//print_num_arr(turn.heatmap, game.rows, game.cols);
		place_piece(game, &turn);
		clear_turn(game, &turn);
		//fprintf(stderr, "\e[1;34mPLAYING [%d %d]\n\e[0m", turn.place_row, turn.place_col);
		if (turn.place_row != -1 && turn.place_col != -1)
		{
			print_move(turn.place_row, turn.place_col);
		}
		else
		{
			print_move(0,0);
			can_move = 0;
		}
	}
	return (0);
}
