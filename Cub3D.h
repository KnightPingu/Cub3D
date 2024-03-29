/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:37:03 by dopeyrat          #+#    #+#             */
/*   Updated: 2023/07/17 10:52:37 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include "LIBFT/libft.h"
# include <math.h>
# include <mlx.h>

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define EXIT_MALLOC 2
# define EXIT_OPEN 3
# define EXIT_READ 4
# define EXIT_EXTENSION 5
# define EXIT_MAP_ERROR 6
# define EXIT_MISS_ID 7
# define EXIT_DUP_ID 8
# define EXIT_COR_ID 9
# define EXIT_WALL_ERROR 10
# define EXIT_MISS_PLAYER 11
# define EXIT_DUP_PLAYER 12

# define PI 3.14159265
# define HORIZONTAL 1920
# define VERTICAL 1080
# define MINIMAP_CENTER_X 1795
# define MINIMAP_CENTER_Y 125
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
//V_FOV = PI / 3
# define V_FOV 1.04719755
//H_FOV = 2 * arctan(tan(V_FOV / 2) * (HORIZONTAL / VERTICAL))
# define H_FOV 1.59685138

/*GAME SETUP*/

# define WALK_SPEED 0.2
# define RUN_SPEED 0.6
# define ROTATION_SPEED 0.1
# define WALL_HITBOX 0.1
# define SPRITE_SPEED 20

/*KEYCODES*/

# define FORWARD 13
# define BACKWARD 1
# define LEFT 0
# define RIGHT 2
# define TURN_LEFT 123
# define TURN_RIGHT 124
# define ESCAPE 53
# define RUN 257

/*HOOKS MACROS*/

#define KEYPRESS 2
#define KEYRELEASE 3
#define DESTROYNOTIFY 17

typedef struct s_player
{
	double	x;
	double	y;
	double	a;
	double	x_off;
	double	y_off;
	double	rotation_speed;
	double	move_speed;
}				t_player;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img;


typedef struct s_map_textures
{
	t_img	*no;
	t_img	*so;
	t_img	*we;
	t_img	*ea;
}	t_map_datas;

typedef struct s_minimap
{
	unsigned int border;
	unsigned int floor;
	unsigned int walls;
	unsigned int fov;
	unsigned int empty;
}	t_minimap;


typedef struct s_display_datas
{
	void			*mlx;
	void			*win;
	t_img			*old_img;
	t_img			*new_img;
	int				frame;
	int				sprite_c;
}	t_display;

typedef struct s_ray
{
	double	distance;
	char	wall_face;
	double	wall_h;
}				t_ray;

typedef struct s_cube
{
	t_player		*p;
	t_minimap		*minimap;
	t_display		*display;
	t_map_datas		*map_img;
	char			**map;
	int				m_y;
	int				m_x;
	char			*n_t;
	char			*s_t;
	char			*w_t;
	char			*e_t;
	unsigned int	f;
	unsigned int	c;
	int				f_f;
	int				c_f;
}				t_cube;

/*DISPLAY*/

t_display	*init_display(char *map_name);
t_img		*init_fullscreen_image(void *mlx_ptdr);
t_minimap	*init_minimap(void);
t_map_datas	*init_map_textures(t_cube *datas);

/*IMAGE*/

void		put_pixel_on_img(t_img *image, int x, int y, int color);

/*KEYBOARD HOOKS*/

int			ft_key_press_hook(int key, t_cube *cub);
int			ft_key_release_hook(int key, t_cube *cub);
int			ft_red_cross_hook(void);
// void		update_player_coordonates(t_player *p, int key);
void		update_player_radiant(t_player *p, int key);

/*LOOP*/

int			ft_loop_hook(t_cube *data);

/*MINIMAP*/

void		render_minimap(t_img *image, t_cube *data);

t_cube		*free_cub3d(t_cube *data);
void		free_cube_map(char **map);
int			check_args(int ac, char **argv);
t_cube		*init_data(int fd);
void		ft_exit(t_cube *data, int status);
int			is_map_id(char *str);
int			all_id_found(t_cube *data);
int			add_map_id(char *str, t_cube *data, int fd, int i);
int			re_malloc_map(char *str, t_cube *data, int fd);
void		check_map(t_cube *data);
int			is_empty_str(char *str);
int			create_trgb(int t, int r, int g, int b);

#endif
