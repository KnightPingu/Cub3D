/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:59:43 by mprofett          #+#    #+#             */
/*   Updated: 2023/07/12 16:09:21 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	get_next_wall_distance(int direction, double *first_wall_distance) //THIS FUNCTION NEED TO BE CONNECTED WITH RAYCAST FUNCTION IN ORDER TO WORK
{
	// if (direction == FORWARD)
	// 	*first_wall_distance = vertical_ray_cast(FORWARD);
	// else if (direction == BACKWARD)
	// 	*first_wall_distance = vertical_ray_cast(BACKWARD);
	// else if (direction == LEFT)
	// 	*first_wall_distance = horizontal_ray_cast(LEFT);
	// else if (direction == RIGHT)
	// 	*first_wall_distance = horizontal_ray_cast(RIGHT);
	(void) direction;
	*first_wall_distance -= WALL_HITBOX;
}

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
		update_player_coordonates(cub->p, key);
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
			p->a *= -1;
	}
	else if (key == TURN_RIGHT)
	{
		p->a += p->rotation_speed;
		if (p->a > 2 * PI)
			p->a = p->a - (2 * PI);
	}
}

void	update_player_coordonates(t_player *p, int key)
{
	double	new_pos_dist;
	double	first_wall_distance;

	get_next_wall_distance(key, &first_wall_distance);
	p->x_off = p->x + (cos(p->a) * p->move_speed);
	p->y_off = p->y + (-1 * sin(p->a) * p->move_speed);
	new_pos_dist = sqrt(pow((p->x_off - p->x), 2) + pow((p->y_off - p->y), 2));
	if (first_wall_distance < new_pos_dist)
	{
		p->x_off = p->x + (cos(p->a) * first_wall_distance);
		p->y_off = p->y + (-1 * sin(p->a) * first_wall_distance);
	}
	p->x = p->x_off;
	p->y = p->y_off;
}
