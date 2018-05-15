/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 10:28:19 by enennige          #+#    #+#             */
/*   Updated: 2018/05/15 15:50:48 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_player(t_game *game)
{
	char *line;
	unsigned char player;
	
	ft_readline(0, &line);
	player = (unsigned char)line[10];	
	if (player == '1')
	{
		game->player_char = 'o';
	}
	else if (player == '2')
	{
		game->player_char = 'x';
	}
	ft_strdel(&line);
	fprintf(stderr, "\e[1;34mGOT PLAYER %c\n\e[0m", game->player_char);
}

void	set_board_dims(t_game *game)
{
	char	*line;
	char	**str_dims;
	
	ft_readline(0, &line);
	str_dims = ft_strsplit(line, ' ');
	game->rows = ft_atoi(str_dims[1]);
	game->cols = ft_atoi(str_dims[2]);
	fprintf(stderr, "\e[1;34mROWS: |%d| & COLS: |%d|\n\e[0m", game->rows, game->cols);
	ft_strarrdel(str_dims);
	ft_strdel(&line);
}

void	set_piece_dims(t_turn *turn)
{
	char	*line;
	char	**str_dims;
	
	ft_readline(0, &line);
	str_dims = ft_strsplit(line, ' ');
	turn->piece_rows = ft_atoi(str_dims[1]);
	turn->piece_cols = ft_atoi(str_dims[2]);
	fprintf(stderr, "\e[1;34mPIECE ROWS: |%d| & PIECE COLS: |%d|\n\e[0m",
			turn->piece_rows, turn->piece_cols);
	ft_strarrdel(str_dims);
	ft_strdel(&line);
}

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

void	set_map(t_game *game, t_turn *turn)
{
	char    *line;
	int		i;

	while (ft_readline(0, &line) && line[0] != ' ')
		ft_strdel(&line);
	turn->board_map = (char **)malloc(sizeof(char *) * (game->rows + 1));
	if (!turn->board_map)
		return ;
	i = 0;
	while (i < game->rows)
	{
		ft_readline(0, &line);
		turn->board_map[i] = ft_strsub(line, ft_strchri(line, '.'), game->cols);
		ft_strdel(&line);
		i++;
	}
	turn->board_map[i] = NULL;
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

int main(void)
{
	t_game	game;
	t_turn	turn;
	
	set_player(&game);
	set_board_dims(&game);
	
	set_map(&game, &turn);
	print_arr(turn.board_map);
	set_piece_dims(&turn);
	set_piece(&turn);
	print_arr(turn.piece_map);
	printf("1 1\n");
	return (0);
}
