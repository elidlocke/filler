/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_turn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 20:08:03 by enennige          #+#    #+#             */
/*   Updated: 2018/05/28 11:22:44 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_map(t_game game, t_turn *turn)
{
	char	*line;
	int		i;

	while (ft_readline(0, &line) && line[0] != ' ')
		ft_strdel(&line);
	turn->board_map = (char **)malloc(sizeof(char *) * (game.rows + 1));
	if (!turn->board_map)
		return ;
	i = 0;
	while (i < game.rows)
	{
		ft_readline(0, &line);
		turn->board_map[i] =
			ft_strsub(line, ft_strchri(line, ' ') + 1, game.cols);
		ft_strdel(&line);
		i++;
	}
	turn->board_map[i] = NULL;
}

void	set_piece_dims(t_turn *turn)
{
	char	*line;
	char	**str_dims;

	ft_readline(0, &line);
	str_dims = ft_strsplit(line, ' ');
	turn->piece_rows = ft_atoi(str_dims[1]);
	turn->piece_cols = ft_atoi(str_dims[2]);
	ft_strarrdel(str_dims);
	ft_strdel(&line);
}

void	set_piece(t_turn *turn)
{
	char	*line;
	int		i;

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
	turn->board_map = NULL;
	turn->heatmap_enemy = NULL;
	turn->heatmap_self = NULL;
	turn->heatmap = NULL;
	turn->piece_rows = -1;
	turn->piece_cols = -1;
	turn->piece_map = NULL;
	turn->place_col = ERROR;
	turn->place_row = ERROR;
	set_map(game, turn);
	set_piece_dims(turn);
	set_piece(turn);
}
