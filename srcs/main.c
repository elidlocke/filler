/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 10:28:19 by enennige          #+#    #+#             */
/*   Updated: 2018/05/15 20:57:44 by enennige         ###   ########.fr       */
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


int main(void)
{
	t_game	game;
	t_turn	turn;

	init_game(&game);
	init_turn(game, &turn);
	/* PRINT STATEMENTS */
	print_arr(turn.board_map);
	print_arr(turn.piece_map);
	fprintf(stderr, "\e[1;34mGOT PLAYER %c\n\e[0m", game.player_char);
	fprintf(stderr, "\e[1;34m STARTING AT row|%d| col|%d|\n\e[0m",
			turn.row_starti, turn.col_starti);
	
	printf("1 1\n");
	return (0);
}
