/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:00:58 by luhumber          #+#    #+#             */
/*   Updated: 2023/01/23 10:49:43 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_valide(t_game *game)
{
	int	i;
	int	k;
	int	size;

	i = 0;
	k = 0;
	size = 0;
	while (game->tab[i][k])
		k++;
	size = k;
	game->screen.window.size.x = k * 32;
	k = 0;
	while (game->tab[i])
	{
		k = 0;
		while (game->tab[i][k])
			k++;
		if (k != size)
			ft_tab_free(game, 1);
		i++;
	}
	game->screen.window.size.y = i * 32;
	ft_full_walls(game);
	return (0);
}

int	ft_parsing(t_game *game, char **test)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	game->nb_player = 0;
	game->nb_exit = 0;
	while (test[i])
	{
		k = 0;
		while (test[i][k])
		{
			ft_check_char(game, test[i][k]);
			k++;
		}
		i++;
	}
	if (game->nb_player != 1 || game->nb_exit != 1 || game->chest < 1)
		ft_tab_free(game, 1);
	return (0);
}

int	ft_first_last_walls(t_game *game)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (game->tab[i][k])
	{
		if (game->tab[i][k] != '1')
			ft_tab_free(game, 1);
		k++;
	}
	while (game->tab[i])
		i++;
	i--;
	k = 0;
	while (game->tab[i][k])
	{
		if (game->tab[i][k] != '1')
			ft_tab_free(game, 1);
		k++;
	}
	return (0);
}

int	ft_full_walls(t_game *game)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	ft_first_last_walls(game);
	while (game->tab[i])
	{
		k = 0;
		if (game->tab[i][k] != '1')
			ft_tab_free(game, 1);
		while (game->tab[i][k])
			k++;
		if (game->tab[i][k - 1] != '1')
			ft_tab_free(game, 1);
		i++;
	}
	if (ft_prepare_path(game) != 0)
		ft_tab_free(game, 1);
	return (0);
}

int	ft_prepare_path(t_game *game)
{
	int		i;
	int		k;
	char	**test;

	i = 0;
	k = 0;
	test = ft_allocate_tab(game);
	game->chest = 0;
	ft_parsing(game, test);
	while (test[i])
	{
		k = 0;
		while (test[i][k++])
		{
			if (test[i][k] == 'P')
			{
				game->check_chest = 0;
				if (!ft_finding_path(game, test, i, k))
					ft_tab_free(game, 1);
			}
		}
		i++;
	}
	ft_free_test(test);
	return (0);
}
