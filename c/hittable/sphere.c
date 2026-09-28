/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhan <jeonhan@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 15:30:45 by jeonhan           #+#    #+#             */
/*   Updated: 2026/09/28 17:45:40 by jeonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sphere.h>

int	hit_sphere(t_sphere o, t_ray r, double ray_t_min_max[2], t_hit_record *rec)
{
	t_vec3	oc;
	double	a;
	double	h;
	double	disc;
	double	root;

	oc = vec_sub(o.center, r.origin);
	a = vec_dot(r.dir, r.dir);
	h = vec_dot(r.dir, oc);
	disc = h * h - a * (vec_dot(oc, oc) - (o.radius * o.radius));
	if (disc < 0)
		return (0);
	disc = sqrt(disc);
	root = (h - disc) / a;
	if (root <= ray_t_min_max[0] || ray_t_min_max[1] <= root)
	{
		root = (h + disc) / a;
		if (root <= ray_t_min_max[0] || ray_t_min_max[1] <= root)
			return (0);
	}
	rec->t = root;
	rec->p = ray_at(r, rec->t);
	set_face_normal(&rec, r, vec_div(vec_sub(rec->p, o.center), o.radius));
	return (1);
}
