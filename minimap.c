/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:53:58 by mprofett          #+#    #+#             */
/*   Updated: 2023/07/14 15:37:00 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	pixel_is_in_minimap(double x, double y)
{
	double	dist;
	double	radius;

	radius = 125;
	dist = sqrtf(pow(x - MINIMAP_CENTER_X, 2) + pow(y - 125, 2)) - radius;
	if (dist <= -3.00000000)
		return (0);
	return (1);
}

int	pixel_is_in_minimap_border(double x, double y)
{
	double	dist;
	double	radius;

	radius = 125;
	dist = sqrtf(pow(x - MINIMAP_CENTER_X, 2) + pow(y - 125, 2)) - radius;
	if (dist <= 0.00000000 && !(dist <= -3.00000000))
		return (0);
	return (1);
}

void	put_pixel_on_minimap(t_img *image, t_cube *data, int *x, int *y)
{
	double	x_map;
	double	y_map;
	int		x_index;
	int		y_index;

	x_map = MINIMAP_CENTER_X - *x;
	y_map = MINIMAP_CENTER_Y - *y;
	x_index = data->p->x - (x_map / 10);
	y_index = data->p->y - (y_map / 10);
	if (x_index < 0 || x_index > data->m_x - 1 || y_index > data->m_y - 1
		|| y_index < 0)
		put_pixel_on_img(image, *x, *y, data->minimap->empty);
	else if (x_map <= 1 && x_map >= -1 && y_map <= 1 && y_map >= -1)
		put_pixel_on_img(image, *x, *y, data->minimap->fov);
	else if (data->map[y_index][x_index] == '0')
		put_pixel_on_img(image, *x, *y, data->minimap->floor);
	else if (data->map[y_index][x_index] == '1')
		put_pixel_on_img(image, *x, *y, data->minimap->walls);
}

void	render_minimap(t_img *image, t_cube *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < VERTICAL)
	{
		x = -1;
		while (++x < HORIZONTAL)
		{
			if (y < VERTICAL / 2)
			{
				if (pixel_is_in_minimap_border(x, y) == 0)
					put_pixel_on_img(image, x, y, data->minimap->border);
				else if (pixel_is_in_minimap(x, y) == 0)
					put_pixel_on_minimap(image, data, &x, &y);
			}
			else
				put_pixel_on_img(image, x, y, data->minimap->empty);
		}
	}
}
