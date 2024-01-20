/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:34:45 by luhumber          #+#    #+#             */
/*   Updated: 2023/01/23 10:49:47 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_screen_loop(t_game game)
{
	game.screen.mlx = mlx_init();
	game.screen.window.reference = mlx_new_window(game.screen.mlx,
			game.screen.window.size.x, game.screen.window.size.y, "so_long");
	game.img.img = mlx_new_image(game.screen.mlx,
			game.screen.window.size.x, game.screen.window.size.y);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bpp,
			&game.img.width, &game.img.endian);
	ft_save_sprite(&game);
	ft_setup_walls(&game);
	ft_str_move(&game);
	mlx_put_image_to_window(game.screen.mlx,
		game.screen.window.reference, game.img.img,
		0, 0);
	mlx_hook(game.screen.window.reference, 2, 0, ft_input, &game);
	mlx_hook(game.screen.window.reference, 3, 0, ft_release, &game);
	mlx_hook(game.screen.window.reference, 17, 0, ft_tab_free, &game);
	mlx_loop_hook(game.screen.mlx, ft_reload, &game);
	mlx_loop(game.screen.mlx);
}

void	ft_str_move(t_game *game)
{
	char	*str;

	str = ft_itoa(game->count);
	game->str = ft_strjoin("mouvement ", str);
	mlx_string_put(game->screen.mlx, game->screen.window.reference,
		10, 25, 0x00FF0000, game->str);
	free(str);
	free(game->str);
}

int	ft_reload(t_game *game)
{
	ft_check_move(game);
	mlx_clear_window(game->screen.mlx, game->screen.window.reference);
	ft_setup_walls(game);
	ft_create_character(game);
	mlx_put_image_to_window(game->screen.mlx,
		game->screen.window.reference, game->img.img, 0, 0);
	ft_str_move(game);
	return (0);
}

int	ft_finding_path(t_game *game, char **test, int i, int k)
{
	int	found;

	if (game->chest + 1 == game->check_chest)
		return (1);
	if (test[i][k] == 'C' || test[i][k] == 'E')
		game->check_chest += 1;
	if (test[i][k] == '1' || test[i][k] == 'A' || test[i][k] == 'F')
		return (0);
	test[i][k] = 'A';
	found = ft_finding_path(game, test, i, k + 1);
	found = ft_finding_path(game, test, i + 1, k);
	found = ft_finding_path(game, test, i, k - 1);
	found = ft_finding_path(game, test, i - 1, k);
	return (found);
}
