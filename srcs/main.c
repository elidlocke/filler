/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 10:28:19 by enennige          #+#    #+#             */
/*   Updated: 2018/05/17 12:07:55 by enennige         ###   ########.fr       */
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
			fprintf(stderr, "\e[1;34m%d \e[0m", arr[r][c]);
			c++;
		}
		fprintf(stderr, "\n");
		r++;
	}
}

int main(void)
{
	t_game	game;
	t_turn	turn;

	init_game(&game);

	init_turn(game, &turn);
	make_maps(game, &turn);
	
	/* PRINT STATEMENTS */
	//print_arr(turn.board_map);
	//print_arr(turn.piece_map);
	fprintf(stderr, "\e[1;34mGOT PLAYER %c\n\e[0m", game.player_char);
	//print_num_arr(turn.heatmap_self, game.rows, game.cols);
	//print_num_arr(turn.heatmap_enemy, game.rows, game.cols);
	print_num_arr(turn.heatmap, game.rows, game.cols);
	
	place_piece(game, &turn);
	// TAKE TURN
	//printf("%d %d\n", 1, 1);
	printf("%d %d\n", turn.place_row, turn.place_col);
	return (0);
}
