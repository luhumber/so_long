/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:53:04 by luhumber          #+#    #+#             */
/*   Updated: 2023/01/16 11:37:09 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_input(int keycode, void *param, t_game *game)
{
	game = (t_game *)param;
	if (keycode == 53)
		ft_tab_free(game, 0);
	else if (keycode == 2)
		game->move_right = 1;
	else if (keycode == 0)
		game->move_left = 1;
	else if (keycode == 13)
		game->move_up = 1;
	else if (keycode == 1)
		game->move_low = 1;
	else
		return (0);
	game->save.player.input = keycode;
	ft_check_move(game);
	return (0);
}

void	ft_create_character(t_game *game)
{
	if (game->save.player.input == 0)
		ft_read_player_by_pix(game, game->save.player.sprite_left);
	else if (game->save.player.input == 2)
		ft_read_player_by_pix(game, game->save.player.sprite_right);
	else if (game->save.player.input == 1)
		ft_read_player_by_pix(game, game->save.player.sprite_down);
	else if (game->save.player.input == 13)
		ft_read_player_by_pix(game, game->save.player.sprite_top);
}

void	ft_read_player_by_pix(t_game *game, t_img sprite)
{
	unsigned int	color;
	int				i;
	int				y;

	i = 0;
	while (i < 32)
	{
		y = 0;
		while (y < 32)
		{
			color = ft_take_color(&sprite, i, y);
			if (color != 0xFF000000)
				my_mlx_pixel_put(&game->img, game->save.player.x + i,
					game->save.player.y + y, color);
			y++;
		}
		i++;
	}
}

void	ft_check_char(t_game *game, char test)
{
	if (test == 'C')
		game->chest++;
	else if (test == 'P')
		game->nb_player++;
	else if (test == 'E')
		game->nb_exit++;
	else if (test == 'F')
		game->nb_ennemy++;
	else if (test != '0' && test != '1')
		ft_tab_free(game, 1);
}
