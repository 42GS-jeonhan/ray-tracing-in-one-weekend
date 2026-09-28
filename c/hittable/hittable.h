/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhan <jeonhan@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 21:27:24 by jeonhan           #+#    #+#             */
/*   Updated: 2026/09/28 17:46:28 by jeonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H

# include <ray/ray.h>

typedef struct s_hit_record {
	t_point3	p;
	t_vec3		normal;
	double		t;
	int			is_front_face;
}	t_hit_record;

void	set_face_normal(t_hit_record *hr, t_ray r, t_vec3 outward_normal);

// void set_face_normal(const ray& r, const vec3& outward_normal)
// {
// 	front_face = dot(r.direction(), outward_normal) < 0;
// 	normal = front_face ? outward_normal : -outward_normal;
// }

#endif
// class hittable {
// 	virtual ~hittable() = default;
// 	virtual bool hit(
// const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
// };
// bool hit_object(
	// const t_object *obj,
	// const t_ray *r,
	// double t_min,
	// double t_max,
	// t_hit_record *rec);

// bool hit_object(
	// const t_object *obj,
	// const t_ray *r,
	// double t_min,
	// double t_max,
	// t_hit_record *rec)
// {
//     if (obj->type == OBJ_SPHERE)
//         return (hit_sphere(&obj->as.sphere, r, t_min, t_max, rec));
//     if (obj->type == OBJ_PLANE)
//         return (hit_plane(&obj->as.plane, r, t_min, t_max, rec));
//     if (obj->type == OBJ_CYLINDER)
//         return (hit_cylinder(&obj->as.cylinder, r, t_min, t_max, rec));
//     return (false);
// }