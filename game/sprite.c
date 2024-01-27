/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:29:49 by luhumber          #+#    #+#             */
/*   Updated: 2023/01/12 20:16:38 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_save_sprite(t_game *game)
{
	game->save.water = ft_create_sprite(*game, "img/sea.xpm");
	game->save.wall = ft_create_sprite(*game, "img/rock.xpm");
	game->save.chest = ft_create_sprite(*game, "img/chest.xpm");
	game->save.open_chest = ft_create_sprite(*game, "img/open-chest.xpm");
	game->save.ennemy = ft_create_sprite(*game, "img/ennemy.xpm");
	game->save.exit = ft_create_sprite(*game, "img/boat.xpm");
	game->save.player.sprite_right
		= ft_create_sprite(*game, "img/boat_right.xpm");
	game->save.player.sprite_left
		= ft_create_sprite(*game, "img/boat_left.xpm");
	game->save.player.sprite_top
		= ft_create_sprite(*game, "img/boat_top.xpm");
	game->save.player.sprite_down
		= ft_create_sprite(*game, "img/boat_down.xpm");
}

t_img	ft_create_sprite(t_game game, char *path)
{
	int		width;
	int		height;
	t_img	sprite;

	sprite.img = mlx_xpm_file_to_image(game.screen.mlx, path, &width, &height);
	sprite.addr = mlx_get_data_addr(sprite.img, &sprite.bpp, &sprite.width,
			&sprite.endian);
	return (sprite);
}

void	ft_read_img_by_pix(t_game *game, t_img sprite)
{
	unsigned int	color;
	int				i;
	int				y;

	i = 0;
	(void)sprite;
	while (i < 32)
	{
		y = 0;
		while (y < 32)
		{
			color = ft_take_color(&sprite, i, y);
			if (color != 0xFF000000)
				my_mlx_pixel_put(&game->img, game->save.last.x + i,
					game->save.last.y + y, color);
			y++;
		}
		i++;
	}
}

unsigned int	ft_take_color(t_img *data, int i, int y)
{
	char	*dst;

	dst = data->addr + (y * data->width + i
			* (data->bpp / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_img *data, int i, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->width + i
			* (data->bpp / 8));
	*(unsigned int *)dst = color;
}
