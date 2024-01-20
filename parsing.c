/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:54:03 by luhumber          #+#    #+#             */
/*   Updated: 2023/01/16 10:42:18 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_allocate_tab(t_game *game)
{
	int		fd;
	int		i;
	int		nb_line;
	char	**tab;

	fd = open(game->argv, O_RDONLY);
	if (fd == -1)
		ft_tab_free(game, -1);
	nb_line = 0;
	nb_line = ft_get_size(game, fd, nb_line);
	close(fd);
	tab = malloc(sizeof(char *) * (nb_line + 1));
	if (!tab)
		return (NULL);
	tab[nb_line] = NULL;
	fd = open(game->argv, O_RDONLY);
	i = 0;
	while (i < nb_line)
	{
		tab[i] = get_next_line(fd);
		tab[i] = ft_setup_new(tab[i]);
		i++;
	}
	close(fd);
	return (tab);
}

char	*ft_setup_new(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	line[i] = '\0';
	return (line);
}

int	ft_get_size(t_game *game, int fd, int nb_line)
{
	char	*str;

	str = get_next_line(fd);
	if (str == NULL)
		ft_tab_free(game, -1);
	while (str != NULL)
	{
		if (str == NULL)
			ft_tab_free(game, -1);
		free(str);
		str = get_next_line(fd);
		nb_line++;
	}
	return (nb_line);
}

void	ft_setup_walls(t_game *game)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	game->chest = 0;
	game->save.last.x = 0;
	game->save.last.y = 0;
	while (game->tab[i])
	{
		game->save.last.x = 0;
		k = 0;
		while (game->tab[i][k])
		{
			ft_parsing_tab(game, i, k);
			k++;
			game->save.last.x += 32;
		}
		game->save.last.y += 32;
		i++;
	}
	if (game->chest == 0 && game->tab
		[game->save.player.y / 32][(game->save.player.x / 32)] == 'E')
		ft_end_game(game);
	ft_create_character(game);
}

void	ft_parsing_tab(t_game *game, int i, int k)
{
	ft_read_img_by_pix(game, game->save.water);
	if (game->tab[i][k] == '1')
		ft_read_img_by_pix(game, game->save.wall);
	else if (game->tab[i][k] == 'C')
	{
		game->chest++;
		ft_read_img_by_pix(game, game->save.chest);
	}
	else if (game->tab[i][k] == 'E')
		ft_read_img_by_pix(game, game->save.exit);
	else if (game->tab[i][k] == 'X')
		ft_read_img_by_pix(game, game->save.open_chest);
	else if (game->tab[i][k] == 'F')
		ft_read_img_by_pix(game, game->save.ennemy);
	else if (game->tab[i][k] == 'P')
	{
		game->save.player.y = i * 32;
		game->save.player.x = k * 32;
		ft_read_player_by_pix(game, game->save.player.sprite_right);
		game->tab[i][k] = '0';
	}
}
