/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhan <jeonhan@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 18:59:13 by jeonhan           #+#    #+#             */
/*   Updated: 2026/09/26 14:09:09 by jeonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double	hit_sphere(t_point3 center, double radius, t_ray r) {
	t_vec3	oc = vec_sub(center, r.origin);
	double	a = vec_dot(r.dir, r.dir);
	double	b = (-2.0) * vec_dot(r.dir, oc);
	double	c = vec_dot(oc, oc) - (radius * radius);
	double	discriminant = (b * b) - (4.0 * a * c);
	
	if (discriminant < 0)
		return -1.0;
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a));
}

t_color	ray_color(t_ray r) {
	double	t;

	t = hit_sphere(vec3(0,0,-1), 0.5, r);
	if (t > 0.0)
	{
		t_vec3 n = vec_unit(vec_sub(ray_at(r, t), vec3(0, 0, -1)));
		return (vec_scale(vec3(n.e[0]+1, n.e[1]+1, n.e[2]+1), 0.5));
	}
	t_vec3	unit_direction = vec_unit(r.dir);
    double	a = 0.5 * (unit_direction.e[1] + 1.0);
    return vec_add(
		vec_scale(vec3(1.0, 1.0, 1.0), (1.0 - a)), vec_scale(vec3(0.5, 0.7, 1.0) ,a)
	);
}

int	main(void)
{
	int		i;
	int		j;
	t_color	pixel_color;

	// double		ratio = (double)IMAGE_WIDTH / IMAGE_HEIGHT;
	double		focal_length = 1.0;
	double		viewport_height = 2.0;
	double		viewport_width = viewport_height * ((double)IMAGE_WIDTH / (double)IMAGE_HEIGHT);
	t_point3	camera_center = vec3(0, 0, 0);

	t_vec3		viewport_u = vec3(viewport_width, 0, 0);
	t_vec3		viewport_v = vec3(0, -viewport_height, 0);

	t_point3	pixel_delta_u = vec_div(viewport_u, (double)IMAGE_WIDTH);
	t_point3	pixel_delta_v = vec_div(viewport_v, (double)IMAGE_HEIGHT);

	t_point3 viewport_upper_left = 
				vec_sub(camera_center,
					vec_add(vec3(0, 0, focal_length),
						vec_add(vec_div(viewport_u, 2.0), vec_div(viewport_v, 2.0))));
    t_vec3		pixel00_loc =
					vec_add(viewport_upper_left,
						vec_scale(vec_add(pixel_delta_u, pixel_delta_v) ,0.5));

	printf("P3\n%d %d\n255\n", IMAGE_WIDTH, IMAGE_HEIGHT);
	j = -1;
	while (++j < IMAGE_HEIGHT)
	{
		dprintf(2, "\rScanlines remaining: %d ", IMAGE_HEIGHT - j);
		i = -1;
		while (++i < IMAGE_WIDTH)
		{
			// pixel_color = vec3(
			// 		(double)j / (IMAGE_WIDTH - 1),
			// 		(double)i / (IMAGE_HEIGHT - 1),
			// 		0
			// 		);
			t_point3	pixel_center = vec_add(pixel00_loc,
							vec_add(
								vec_scale(pixel_delta_u, (double)i),
								vec_scale(pixel_delta_v, (double)j)));
			t_vec3		ray_dir = vec_sub(pixel_center, camera_center);
			t_ray		r = (t_ray){camera_center, ray_dir};
			pixel_color = ray_color(r);
			write_color(pixel_color);
		}
	}
	dprintf(2, "\rDone.                   \n");
	return (0);
}
