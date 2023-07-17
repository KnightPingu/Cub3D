/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:17:14 by mprofett          #+#    #+#             */
/*   Updated: 2023/07/17 10:52:48 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

t_display	*init_display(char *map_name)
{
	t_display	*display;

	display = malloc(sizeof(t_display));
	if (!display)
		exit (EXIT_MALLOC);
	display->mlx = mlx_init();
	if (!display->mlx)
		exit (EXIT_MALLOC);
	display->win
		= mlx_new_window(display->mlx, HORIZONTAL, VERTICAL, map_name);
	if (!display->win)
		exit (EXIT_MALLOC);
	display->old_img = NULL;
	display->new_img = NULL;
	display->frame = 0;
	display->sprite_c = 0;
	return (display);
}

t_img	*init_fullscreen_image(void *mlx_ptr)
{
	t_img	*image;

	image = malloc(sizeof(t_img));
	if (!image)
		exit (EXIT_MALLOC);
	image->mlx_img = mlx_new_image(mlx_ptr, HORIZONTAL, VERTICAL);
	if (!image->mlx_img)
		exit (EXIT_MALLOC);
	image->addr = mlx_get_data_addr(image->mlx_img, &image->bpp,
			&image->line_len, &image->endian);
	if (!image->addr)
		exit (EXIT_MALLOC);
	return (image);
}

t_img	*init_xpm_image(void *mlx_ptr, char *text)
{
	t_img	*image;
	int		width;
	int		height;

	width = TEXTURE_WIDTH;
	height = TEXTURE_HEIGHT;
	image = malloc(sizeof(t_img));
	if (!image)
		exit (EXIT_MALLOC);
	image->mlx_img = mlx_xpm_file_to_image(mlx_ptr, text, &width, &height);
	if (!image->mlx_img)
		exit (EXIT_MALLOC);
	image->addr = mlx_get_data_addr(image->mlx_img, &image->bpp,
			&image->line_len, &image->endian);
	if (!image->addr)
		exit (EXIT_MALLOC);
	return (image);
}

t_minimap	*init_minimap(void)
{
	t_minimap	*minimap;

	minimap = malloc(sizeof(t_minimap));
	if (!minimap)
		exit (EXIT_MALLOC);
	minimap->border = create_trgb(0, 100, 100, 100);
	minimap->floor = create_trgb(0, 50, 50, 50);
	minimap->fov = create_trgb(0, 150, 150, 150);
	minimap->walls = create_trgb(0, 200, 200, 200);
	minimap->empty = create_trgb(255, 0, 0, 0);
	return (minimap);
}

t_map_datas	*init_map_textures(t_cube *datas)
{
	t_map_datas	*map_img;
	map_img = malloc(sizeof(t_map_datas));
	if (!map_img)
		exit (EXIT_MALLOC);
	map_img->no = init_xpm_image(datas->display->mlx, datas->n_t);
	map_img->so = init_xpm_image(datas->display->mlx, datas->s_t);
	map_img->we = init_xpm_image(datas->display->mlx, datas->w_t);
	map_img->ea = init_xpm_image(datas->display->mlx, datas->e_t);
	return (map_img);
}
