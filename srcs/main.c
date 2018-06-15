/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 10:28:19 by enennige          #+#    #+#             */
/*   Updated: 2018/05/25 15:14:28 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_move(int row, int col)
{
	ft_putnbr(row);
	ft_putchar(' ');
	ft_putnbr(col);
	ft_putchar('\n');
}

void	get_map_strategy(t_game game, t_turn *turn)
{
	if (game.turns_taken < game.cols / 4)
		make_corner_heatmap(game, turn);
	if (game.turns_taken >= game.cols / 4)
		make_battle_heatmap(game, turn);
}

int		main(void)
{
	t_game	game;
	t_turn	turn;

	init_game(&game);
	while (1)
	{
		init_turn(game, &turn);
		init_heatmaps(game, &turn);
		get_map_strategy(game, &turn);
		place_piece(game, &turn);
		clear_turn(game, &turn);
		if (turn.place_row == ERROR)
		{
			print_move(0, 0);
			break ;
		}
		print_move(turn.place_row, turn.place_col);
		game.turns_taken += 1;
	}
	return (0);
}
