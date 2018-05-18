/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 12:05:37 by enennige          #+#    #+#             */
/*   Updated: 2018/05/17 14:34:38 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

/*FOR DEGUBBING ONLY */
# include <stdio.h>
/* END DEBUGGING */

# include <unistd.h>
# include "libft.h"

# define PLAYER_NUM -1
# define ENEMY_NUM -2
# define ERROR -1

typedef struct		s_game
{
	int				rows;
	int				cols;
	unsigned char	player_char;
}					t_game;

typedef struct		s_turn
{
	char			**board_map;
	int				**heatmap_enemy;
	int				**heatmap_self;
	int				**heatmap;
	int				piece_rows;
	int				piece_cols;
	char			**piece_map;
	int				place_row;
	int				place_col;
}					t_turn;

int					get_bigger_num(int a, int b);
int					is_on_board(t_game game, int row, int col);

void				init_game(t_game *game);
void				init_turn(t_game game, t_turn *turn);
void				make_maps(t_game game, t_turn *turn);
void				place_piece(t_game game, t_turn *turn);
void				clear_turn(t_game game, t_turn *turn);

#endif
