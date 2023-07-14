/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:59:43 by mprofett          #+#    #+#             */
/*   Updated: 2023/07/14 10:53:37 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

/*void	first_wall_distance(int direction, double *first_wall_distance) //THIS FUNCTION NEED TO BE CONNECTED WITH RAYCAST FUNCTION IN ORDER TO WORK
{
	if (p->y_off > 0)
		vertical_ray(data, (double)(3 / 2) * PI, vertical);
	else
		vertical_ray(data, (double)PI / 2, vertical);
	if (p->x_off > 0)
		horizontal_ray(data, 0, horizontal);
	else
		horizontal_ray(data, PI, horizontal);
}*/

int	ft_red_cross_hook(void)
{
	exit (EXIT_SUCCESS);
	return (0);
}

int	ft_key_release_hook(int key, t_cube *cub)
{
	if (key == RUN)
		cub->p->move_speed = WALK_SPEED;
	return (0);
}

int	ft_key_press_hook(int key, t_cube *cub)
{
	if (key == FORWARD || key== BACKWARD || key == LEFT || key == RIGHT)
		// update_player_coordonates(cub->p, key);
		;
	else if (key == TURN_LEFT || key == TURN_RIGHT)
		update_player_radiant(cub->p, key);
	else if (key == RUN)
		cub->p->move_speed = RUN_SPEED;
	else if (key == ESCAPE)
		exit(EXIT_SUCCESS);;
	return (0);
}

void	update_player_radiant(t_player *p, int key)
{
	if (key == TURN_LEFT)
	{
		p->a -= p->rotation_speed;
		if (p->a < 0)
			p->a += 2 * PI;
	}
	else if (key == TURN_RIGHT)
	{
		p->a += p->rotation_speed;
		if (p->a > 2 * PI)
			p->a = p->a - (2 * PI);
	}
}

// void	update_player_coordonates(t_cube *data, t_player *p, int key)
// {
// 	t_ray	vertical;
// 	t_ray	horizontal;

// 	p->x_off = p->x + (cos(p->a) * p->move_speed);
// 	p->y_off = p->y + (-1 * sin(p->a) * p->move_speed);
// 	first_wall_distance(&vertical, &horizontal, p, data);
// 	if (ft_abs_d(p->y_off) > ft_abs_d(vertical.distance) && p->y_off < 0)
// 		p->y_off = vertical.distance + WALL_HITBOX;
// 	else if (ft_abs_d(p->y_off) > ft_abs_d(vertical.distance))
// 		p->y_off = vertical.distance - WALL_HITBOX;
// 	if (ft_abs_d(p->x_off) > ft_abs_d(horizontal.distance) && p->x_off < 0)
// 		p->x_off = horizontal.distance + WALL_HITBOX;
// 	else if (ft_abs_d(p->x_off) > ft_abs_d(horizontal.distance))
// 		p->x_off = horizontal.distance - WALL_HITBOX;
// 	p->x = p->x_off;
// 	p->y = p->y_off;
// }
