/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:46:32 by enennige          #+#    #+#             */
/*   Updated: 2018/05/14 19:56:19 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_board	init_game(t_board *game)
{
	game->rows = 0;
	game->columns = 0;
	game->player_char = 'e';
}

t_board init_piece(t_piece *piece)
{
	piece->rows = 0;
	piece->columns = 0;
}
