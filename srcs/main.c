/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 10:28:19 by enennige          #+#    #+#             */
/*   Updated: 2018/05/14 20:45:35 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int ft_readline(const int fd, char **line)
{
	int		ret;
	int		i;
	char	buffer_char;
	char	*buffer_line;

	buffer_line = (char *)malloc(sizeof(1));
	buffer_line[0] = '\0';
	
	if (read(fd, &buffer_char, 0) < 0 || fd < 0 || line == NULL)
		return (-1);
	i = 0;
	while ((ret = read(fd, &buffer_char, 1)))
	{
		i += 1;
		if (buffer_char == '\n')
		{
			*line = buffer_line;
			return (1);
		}
		//TODO: replace with better / faster / cleaner
		//function to append char to end of string
		ft_addnfix(&buffer_line, buffer_char, 1, 2);
	}
	return (0);
}

int	set_player(t_game *game)
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
	return (1);
}

unsigned char	set_board_width(char *line)
{
	unsigned char ;
}

int main(void)
{
	char		*line;
	static int	game_started;
	t_game		game;
	//t_piece		piece;
	
	if (!game_started)
	{
		set_player(&game);
		game_started = 1;
	}
	
	ft_readline(0, &line);
	fprintf(stderr, "\e[1;34m%s\n\e[0m", line);
	ft_strdel(&line);
	
	printf("1 1\n");
	return (0);
}

