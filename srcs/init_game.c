/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 20:06:55 by enennige          #+#    #+#             */
/*   Updated: 2018/05/18 19:20:20 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    set_player(t_game *game)
{
    char *line;
    unsigned char player;

    ft_readline(0, &line);
    player = (unsigned char)line[10];
    if (player == '1')
    {
        game->player_char = 'O';
    }
    else if (player == '2')
    {
        game->player_char = 'X';
    }
    ft_strdel(&line);
}

void    set_board_dims(t_game *game)
{
    char    *line;
    char    **str_dims;

    ft_readline(0, &line);
    str_dims = ft_strsplit(line, ' ');
    game->rows = ft_atoi(str_dims[1]);
    game->cols = ft_atoi(str_dims[2]);
    //fprintf(stderr, "\e[1;34mROWS: |%d| & COLS: |%d|\n\e[0m",
	//		game->rows, game->cols);
    ft_strarrdel(str_dims);
    ft_strdel(&line);
}

void    init_game(t_game *game)
{
	game->turns_taken = 0;
	game->start_row = ERROR;
    game->start_col = ERROR;
	game->furthest_corner_row = ERROR;
    game->furthest_corner_col = ERROR;
	set_player(game);
    set_board_dims(game);
}
