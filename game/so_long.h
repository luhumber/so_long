/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:21:18 by luhumber          #+#    #+#             */
/*   Updated: 2023/01/17 12:57:57 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <mlx.h>

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct window {
	void		*reference;
	t_vector	size;
}		t_window;

typedef struct s_program {
	void		*mlx;
	void		*img;
	t_window	window;
}		t_program;

typedef struct position {
	int	x;
	int	y;
}		t_pos;

typedef struct new_img {
	void	*img;
	char	*path;
	char	*addr;
	int		bpp;
	int		width;
	int		height;
	int		endian;
	t_pos	pos;
}		t_img;

typedef struct player {
	t_img		sprite_right;
	t_img		sprite_left;
	t_img		sprite_top;
	t_img		sprite_down;
	int			x;
	int			y;
	int			input;
}		t_player;

typedef struct sprites {
	t_img		wall;
	t_img		water;
	t_player	player;
	t_img		chest;
	t_img		ennemy;
	t_img		open_chest;
	t_img		exit;
	t_pos		last;
}		t_sprite;

typedef struct game {
	t_img		img;
	t_sprite	save;
	t_program	screen;
	int			sprite_input;
	char		**tab;
	size_t		chest;
	size_t		check_chest;
	size_t		count;
	int			nb_player;
	int			nb_ennemy;
	int			nb_exit;
	int			solution;
	char		*str;
	char		*argv;
	int			move_left;
	int			move_right;
	int			move_up;
	int			move_low;
}		t_game;

void					ft_screen_loop(t_game game);
char					**ft_allocate_tab(t_game *game);
void					ft_setup_walls(t_game *game);
void					ft_create_character(t_game *game);
int						ft_input(int keycode, void *param, t_game *game);
int						ft_reload(t_game *game);
unsigned int			ft_take_color(t_img *data, int i, int y);
void					my_mlx_pixel_put(t_img *data, int i, int y, int color);
void					ft_read_img_by_pix(t_game *game, t_img sprite);
void					ft_read_player_by_pix(t_game *game, t_img sprite);
void					ft_save_sprite(t_game *game);
t_img					ft_create_sprite(t_game game, char *path);
int						ft_tab_free(t_game *game, int error);
void					ft_end_game(t_game *game);
void					ft_parsing_tab(t_game *game, int i, int k);
int						ft_get_size(t_game *game, int fd, int nb_line);
int						ft_map_valide(t_game *game);
char					*ft_setup_new(char *line);
int						ft_full_walls(t_game *game);
int						ft_prepare_path(t_game *game);
int						ft_finding_path(t_game *game,
							char **test, int i, int k);
int						ft_parsing(t_game *game, char **test);
void					ft_free_test(char **test);
void					ft_check_char(t_game *game, char test);
int						ft_move_right(t_game *game);
int						ft_move_left(t_game *game);
int						ft_move_up(t_game *game);
int						ft_move_low(t_game *game);
void					ft_str_move(t_game *game);
void					ft_check_move(t_game *game);
void					ft_chest_left(t_game *game);
void					ft_chest_right(t_game *game);
void					ft_chest_low(t_game *game);
void					ft_chest_up(t_game *game);
int						ft_release(int keycode, t_game *game);
int						ft_first_last_walls(t_game *game);

#endif
