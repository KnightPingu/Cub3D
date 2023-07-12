/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:17:14 by mprofett          #+#    #+#             */
/*   Updated: 2023/07/12 15:45:53 by mprofett         ###   ########.fr       */
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
	return (display);
}

t_img	*init_image(t_display *display)
{
	t_img	*image;

	image = malloc(sizeof(t_img));
	if (!image)
		exit (EXIT_MALLOC);
	image->mlx_img = mlx_new_image(display->mlx, HORIZONTAL, VERTICAL);
	if (!image->mlx_img)
		exit (EXIT_MALLOC);
	image->addr = mlx_get_data_addr(image->mlx_img, &image->bpp,
			&image->line_len, &image->endian);
	if (!image->addr)
		exit (EXIT_MALLOC);
	return (image);
}
