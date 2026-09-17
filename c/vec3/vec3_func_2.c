/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_func_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhan <jeonhan@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 18:03:46 by jeonhan           #+#    #+#             */
/*   Updated: 2026/09/17 21:25:25 by jeonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec_mul(t_vec3 a, t_vec3 b)
{
	return (vec3((a.e[0] * b.e[0]), (a.e[1] * b.e[1]), (a.e[2] * b.e[2])));
}

double	vec_dot(t_vec3 a, t_vec3 b)
{
	return ((a.e[0] * b.e[0]) + (a.e[1] * b.e[1]) + (a.e[2] * b.e[2]));
}

t_vec3	vec_cross(t_vec3 a, t_vec3 b)
{
	return (
		vec3(
			(a.e[1] * b.e[2]) - (a.e[2] * b.e[1]),
			(a.e[2] * b.e[0]) - (a.e[0] * b.e[2]),
			(a.e[0] * b.e[1]) - (a.e[1] * b.e[0])
		)
	);
}

double	vec_length(t_vec3 v)
{
	return (sqrt(vec_dot(v, v)));
}

t_vec3	vec_unit(t_vec3 v)
{
	return (vec_div(v, vec_length(v)));
}
