/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 12:05:37 by enennige          #+#    #+#             */
/*   Updated: 2018/05/14 20:44:20 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*FOR DEGUBBING ONLY */
#include <stdio.h>
/* END DEBUGGING */

#include <unistd.h>
#include "libft.h"

typedef struct				s_game
{
	int				rows;
	int				columns;
	unsigned char	**str_map;
	unsigned char	player_char;
}					t_game;

typedef struct		s_piece
{
	int				rows;
	int				columns;
	unsigned char	**str_map;
}					t_piece;

