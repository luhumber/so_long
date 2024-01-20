/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:13:15 by luhumber          #+#    #+#             */
/*   Updated: 2023/01/16 11:58:52 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{	
	t_game		game;

	if (argc != 2)
		ft_tab_free(&game, -1);
	game.count = 0;
	game.argv = argv[1];
	if (!ft_strnstr(game.argv, ".ber", ft_strlen(game.argv)))
		ft_tab_free(&game, -1);
	game.tab = ft_allocate_tab(&game);
	ft_map_valide(&game);
	ft_screen_loop(game);
	ft_tab_free(&game, 0);
}

void	ft_free_test(char **test)
{
	int	i;

	i = 0;
	while (test[i])
		free(test[i++]);
	free(test);
}

int	ft_tab_free(t_game *game, int error)
{
	int	i;

	i = 0;
	if (error == -1)
	{
		ft_printf("Error\nInvalid map");
		exit(1);
	}
	if (error == 2)
		ft_printf("Dommage tu as coulé...\n");
	if (game->tab)
	{
		while (game->tab[i])
			free(game->tab[i++]);
		free(game->tab);
	}
	if (error == 1)
	{
		ft_printf("Error\nInvalid map");
		exit(1);
	}
	exit(0);
}

void	ft_end_game(t_game *game)
{
	ft_printf("Bravo ! Tu as gagné en %d mouvements\n", game->count);
	ft_tab_free(game, 0);
}

int	ft_release(int keycode, t_game *game)
{
	(void)keycode;
	game->move_right = 0;
	game->move_left = 0;
	game->move_up = 0;
	game->move_low = 0;
	return (0);
}
