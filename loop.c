/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:23:53 by mprofett          #+#    #+#             */
/*   Updated: 2023/07/17 10:54:32 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	ft_loop_hook(t_cube *data)
{
	if (data->display->sprite_c + SPRITE_SPEED <= data->display->frame)
	{
		data->display->sprite_c = data->display->frame;
		//change_texture_image_pointer;
	}
	data->display->new_img = init_fullscreen_image(data->display);
	render_minimap(data->display->new_img, data);
	mlx_clear_window(data->display->mlx, data->display->win);
	if (data->display->old_img)
	{
		mlx_destroy_image(data->display->mlx, data->display->old_img->mlx_img);
		data->display->old_img = data->display->new_img;
	}
	else
		data->display->old_img = data->display->new_img;
	mlx_put_image_to_window(data->display->mlx, data->display->win,
		data->display->old_img->mlx_img, 0, 0);
	if (++data->display->frame == 2000000000)
	{
		data->display->frame = 0;
		data->display->sprite_c = 0;
	}
	return (0);
}
