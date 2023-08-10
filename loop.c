/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:23:53 by mprofett          #+#    #+#             */
/*   Updated: 2023/08/10 15:44:01 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	ft_loop_hook(t_cube *data)
{
	static int hook = 0;

	if (data->display->sprite_c + SPRITE_SPEED <= data->display->frame)
	{
		data->display->sprite_c = data->display->frame;
		//change_texture_image_pointer;
	}
	if (hook == 0)
	{
		//raycast
		render_minimap(data->display->new_img, data);
		mlx_put_image_to_window(data->display->mlx, data->display->win,
		data->display->new_img->mlx_img, 0, 0);
		++hook;
	}
	else
	{
		//raycast
		render_minimap(data->display->old_img, data);
		mlx_put_image_to_window(data->display->mlx, data->display->win,
		data->display->old_img->mlx_img, 0, 0);
		--hook;
	}
	if (++data->display->frame == 2000000000)
	{
		data->display->frame = 0;
		data->display->sprite_c = 0;
	}
	return (0);
}
