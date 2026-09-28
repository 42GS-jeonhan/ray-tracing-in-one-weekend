/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhan <jeonhan@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:07:46 by jeonhan           #+#    #+#             */
/*   Updated: 2026/09/28 17:46:35 by jeonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <hittable.h>

void	set_face_normal(t_hit_record *hr, t_ray r, t_vec3 outward_normal)
{
	hr->is_front_face = vec_dot(r.dir, outward_normal) < 0;
	if (hr->is_front_face == 0)
		hr->normal = vec_scale(outward_normal, -1);
	else
		hr->normal = outward_normal;
}
