/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_turn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 20:08:03 by enennige          #+#    #+#             */
/*   Updated: 2018/05/15 20:57:48 by enennige         ###   ########.fr       */
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
    fprintf(stderr, "\e[1;34mPIECE ROWS: |%d| & PIECE COLS: |%d|\n\e[0m",
            turn->piece_rows, turn->piece_cols);
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

void	set_startpoint(t_game game, t_turn *turn)
{
	char	**str_arr;
	int		c;
	int		r;

	str_arr = turn->board_map;	
	r = 0;
	fprintf(stderr, "\e[1;34m%c\e[0m", game.player_char);
	while (str_arr[r] != NULL)
	{
		c = 0;
		while (str_arr[r][c] != '\0')
		{
			fprintf(stderr, "\e[1;34m%c\e[0m", str_arr[r][c]);
			if (str_arr[r][c] == game.player_char ||
				ft_toupper(str_arr[r][c]) == game.player_char)
			{
				turn->row_starti = r;
				turn->col_starti = c;
				return;
			}
			c++;
		}
		r++;
	}
}

void	init_turn(t_game game, t_turn *turn)
{
    set_map(game, turn);
    set_piece_dims(turn);
    set_piece(turn);
	set_startpoint(game, turn);
}
