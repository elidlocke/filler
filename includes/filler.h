/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 12:05:37 by enennige          #+#    #+#             */
/*   Updated: 2018/05/16 20:19:21 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*FOR DEGUBBING ONLY */
#include <stdio.h>
/* END DEBUGGING */

#include <unistd.h>
#include "libft.h"

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
	int				**heatmap_ultimate;
	int				piece_rows;
	int				piece_cols;
	char			**piece_map;
}					t_turn;

void				init_game(t_game *game);
void				init_turn(t_game game, t_turn *turn);

/* MAYBE CLEAN UP */
void				print_num_arr(int **arr, int rows, int cols);
void				init_heat_map(t_game game, t_turn *turn, char type);
void				make_maps(t_game game, t_turn *turn);
