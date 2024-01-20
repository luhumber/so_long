/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:16:12 by lucas             #+#    #+#             */
/*   Updated: 2023/01/17 10:43:41 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_chest_left(t_game *game)
{
	if (game->tab[(game->save.player.y + 16) / 32]
		[(game->save.player.x - 1) / 32] == 'C')
			game->tab[(game->save.player.y + 16) / 32]
		[(game->save.player.x - 1) / 32] = 'X';
	else if (game->tab[(game->save.player.y + 16) / 32]
		[(game->save.player.x - 1) / 32] == 'F')
		ft_tab_free(game, 2);
}

void	ft_chest_right(t_game *game)
{
	if (game->tab[(game->save.player.y + 15) / 32]
		[(game->save.player.x + 25) / 32] == 'C')
			game->tab[(game->save.player.y + 15) / 32]
		[(game->save.player.x + 25) / 32] = 'X';
	else if (game->tab[(game->save.player.y + 15) / 32]
		[(game->save.player.x + 25) / 32] == 'F')
		ft_tab_free(game, 2);
}

void	ft_chest_low(t_game *game)
{
	if (game->tab[(game->save.player.y + 32) / 32]
		[(game->save.player.x + 16) / 32] == 'C')
				game->tab[(game->save.player.y + 32) / 32]
		[(game->save.player.x + 16) / 32] = 'X';
	else if (game->tab[(game->save.player.y + 32) / 32]
		[(game->save.player.x + 16) / 32] == 'F')
		ft_tab_free(game, 2);
}

void	ft_chest_up(t_game *game)
{
	if (game->tab[(game->save.player.y - 1) / 32]
		[(game->save.player.x + 16) / 32] == 'C')
			game->tab[(game->save.player.y - 1) / 32]
		[(game->save.player.x + 16) / 32] = 'X';
	else if (game->tab[(game->save.player.y - 1) / 32]
		[(game->save.player.x + 16) / 32] == 'F')
		ft_tab_free(game, 2);
}
