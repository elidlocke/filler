/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 12:05:37 by enennige          #+#    #+#             */
/*   Updated: 2018/05/15 15:45:27 by enennige         ###   ########.fr       */
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
	int				piece_rows;
	int				piece_cols;
	char			**piece_map;
}					t_turn;

