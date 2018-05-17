/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_turn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 20:08:03 by enennige          #+#    #+#             */
/*   Updated: 2018/05/17 09:56:14 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    set_map(t_game game, t_turn *turn)
{
    char    *line;
    int     i;

    while (ft_readline(0, &line) && line[0] != ' ')
        ft_strdel(&line);
    turn->board_map = (char **)malloc(sizeof(char *) * (game.rows + 1));
    if (!turn->board_map)
        return ;
    i = 0;
    while (i < game.rows)
    {
        ft_readline(0, &line);
		// TODO: THIS IS A BUG, as line can start with OoXx or . v
        turn->board_map[i] = ft_strsub(line, ft_strchri(line, '.'), game.cols);
        ft_strdel(&line);
        i++;
    }
    turn->board_map[i] = NULL;
}

void    set_piece_dims(t_turn *turn)
{
    char    *line;
    char    **str_dims;

    ft_readline(0, &line);
    str_dims = ft_strsplit(line, ' ');
    turn->piece_rows = ft_atoi(str_dims[1]);
    turn->piece_cols = ft_atoi(str_dims[2]);
    //fprintf(stderr, "\e[1;34mPIECE ROWS: |%d| & PIECE COLS: |%d|\n\e[0m",
    //        turn->piece_rows, turn->piece_cols);
    ft_strarrdel(str_dims);
    ft_strdel(&line);
}

void    set_piece(t_turn *turn)
{
    char    *line;
    int     i;

    turn->piece_map = (char **)malloc(sizeof(char *) * (turn->piece_rows + 1));
    if (!turn->piece_map)
        return ;
    i = 0;
    while (i < turn->piece_rows)
    {
        ft_readline(0, &line);
        turn->piece_map[i] = ft_strdup(line);
        ft_strdel(&line);
        i++;
    }
    turn->piece_map[i] = NULL;
}

void	init_turn(t_game game, t_turn *turn)
{
    set_map(game, turn);
    set_piece_dims(turn);
    set_piece(turn);
}
