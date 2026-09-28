/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhan <jeonhan@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 13:46:35 by jeonhan           #+#    #+#             */
/*   Updated: 2026/09/28 16:27:14 by jeonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include <hittable.h>
# include <vec3.h>

typedef struct sphere
{
	t_point3	center;
	double		radius;
}	t_sphere;

int	hit_sphere(
		t_sphere o,
		t_ray r,
		double ray_t_min_max[2],
		t_hit_record *rec);

#endif
// class sphere : public hittable {
// 	public:
// 	sphere(
		// const point3& center,
		// double radius)
		// 	: center(center), radius(std::fmax(0,radius)) {}

// 	bool hit(
		// const ray& r,
		// double ray_tmin,
		// double ray_tmax,
		// hit_record& rec) const override {
// 		vec3 oc = center - r.origin();
// 		auto a = r.direction().length_squared();
// 		auto h = dot(r.direction(), oc);
// 		auto c = oc.length_squared() - radius*radius;

// 		auto discriminant = h*h - a*c;
// 		if (discriminant < 0)
// 			return false;

// 		auto sqrtd = std::sqrt(discriminant);

// 		// Find the nearest root that lies in the acceptable range.
// 		auto root = (h - sqrtd) / a;
// 		if (root <= ray_tmin || ray_tmax <= root) {
// 			root = (h + sqrtd) / a;
// 			if (root <= ray_tmin || ray_tmax <= root)
// 				return false;
// 		}

// 		rec.t = root;
// 		rec.p = r.at(rec.t);
// 		rec.normal = (rec.p - center) / radius;

// 		return true;
// 	}

// 	private:
// 	point3 center;
// 	double radius;
// };