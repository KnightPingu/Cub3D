/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopeyrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:37:03 by dopeyrat          #+#    #+#             */
/*   Updated: 2023/06/07 13:37:05 by dopeyrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include "LIBFT/libft.h"
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
//V_FOV = PI / 3
# define V_FOV 1.04719755
//H_FOV = 2 * arctan(tan(V_FOV / 2) * (HORIZONTAL / VERTICAL))
# define H_FOV 1.59685138

typedef struct s_player
{
	double	x;
	double	y;
	double	a;

	double	x_off;
	double	y_off;
}				t_player;

typedef struct s_cube
{
	t_player		*p;

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

t_cube	*free_cub3d(t_cube *data);
void	free_cube_map(char **map);
int		check_args(int ac, char **argv);
t_cube	*init_data(int fd);
void	ft_exit(t_cube *data, int status);
int		is_map_id(char *str);
int		all_id_found(t_cube *data);
int		add_map_id(char *str, t_cube *data, int fd, int i);
int		re_malloc_map(char *str, t_cube *data, int fd);
void	check_map(t_cube *data);
int		is_empty_str(char *str);
int		create_trgb(int t, int r, int g, int b);

#endif