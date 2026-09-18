/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhan <jeonhan@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 15:45:21 by jeonhan           #+#    #+#             */
/*   Updated: 2026/09/18 16:00:52 by jeonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <vec3.h>

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		dir;
}	t_ray;

t_point3	ray_at(t_ray r, double t);

#endif
