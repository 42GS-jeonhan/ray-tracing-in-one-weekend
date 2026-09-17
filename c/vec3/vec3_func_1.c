/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_func_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhan <jeonhan@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 18:03:46 by jeonhan           #+#    #+#             */
/*   Updated: 2026/09/17 21:09:31 by jeonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3(double x, double y, double z)
{
	return ((t_vec3){{x, y, z}});
}

t_vec3	vec_add(t_vec3 a, t_vec3 b)
{
	return (vec3(a.e[0] + b.e[0], a.e[1] + b.e[1], a.e[2] + b.e[2]));
}

t_vec3	vec_sub(t_vec3 a, t_vec3 b)
{
	return (vec3(a.e[0] - b.e[0], a.e[1] - b.e[1], a.e[2] - b.e[2]));
}

t_vec3	vec_scale(t_vec3 v, double n)
{
	return (vec3(v.e[0] * n, v.e[1] * n, v.e[2] * n));
}

t_vec3	vec_div(t_vec3 v, double n)
{
	return (vec_scale(v, 1.0 / n));
}
