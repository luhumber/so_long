/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:14:06 by luhumber          #+#    #+#             */
/*   Updated: 2023/01/16 12:20:33 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_move(t_game *game)
{
	if (game->move_left == 1)
	{
		ft_chest_left(game);
		if (ft_move_left(game) == 0)
			game->save.player.x -= 5;
	}
	else if (game->move_right == 1)
	{
		ft_chest_right(game);
		if (ft_move_right(game) == 0)
			game->save.player.x += 5;
	}
	else if (game->move_low == 1)
	{
		ft_chest_low(game);
		if (ft_move_low(game) == 0)
			game->save.player.y += 5;
	}
	else if (game->move_up == 1)
	{
		ft_chest_up(game);
		if (ft_move_up(game) == 0)
			game->save.player.y -= 5;
	}
}

int	ft_move_left(t_game *game)
{
	if (game->tab[game->save.player.y / 32]
		[(game->save.player.x - 1) / 32] != '1' && \
		game->tab[(game->save.player.y + 16) / 32]
		[(game->save.player.x - 1) / 32] != '1')
	{
		game->count++;
		ft_printf("%d\n", game->count);
		game->move_left = 0;
		return (0);
	}
	return (1);
}

int	ft_move_right(t_game *game)
{
	if (game->tab[game->save.player.y / 32]
		[(game->save.player.x + 32) / 32] != '1'
		&& game->tab[(game->save.player.y + 16) / 32]
		[(game->save.player.x + 32) / 32] != '1')
	{
		game->count++;
		ft_printf("%d\n", game->count);
		game->move_right = 0;
		return (0);
	}
	return (1);
}

int	ft_move_low(t_game *game)
{
	if (game->tab[(game->save.player.y + 32) / 32]
		[game->save.player.x / 32] != '1'
		&& game->tab[(game->save.player.y + 32) / 32]
		[game->save.player.x / 32] != '1'
		&& game->tab[(game->save.player.y + 32) / 32]
		[(game->save.player.x + 16) / 32] != '1')
	{
		game->count++;
		ft_printf("%d\n", game->count);
		game->move_low = 0;
		return (0);
	}
	return (1);
}

int	ft_move_up(t_game *game)
{
	if (game->tab[(game->save.player.y - 5) / 32]
		[game->save.player.x / 32] != '1'
		&& game->tab[(game->save.player.y - 1) / 32]
		[(game->save.player.x + 16) / 32] != '1')
	{
		game->count++;
		ft_printf("%d\n", game->count);
		game->move_up = 0;
		return (0);
	}
	return (1);
}
