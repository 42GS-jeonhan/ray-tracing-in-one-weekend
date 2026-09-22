/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhan <jeonhan@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 18:59:13 by jeonhan           #+#    #+#             */
/*   Updated: 2026/09/22 17:08:53 by jeonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>


t_color	ray_color(t_ray r) {
	t_vec3	unit_direction = r.dir;
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
	double		viewport_width = viewport_height * ((double)IMAGE_WIDTH / IMAGE_HEIGHT);
	t_point3	camera_center = vec3(0, 0, 0);

	t_vec3		viewport_u = vec3(viewport_width, 0, 0);
	t_vec3		viewport_v = vec3(0, -viewport_height, 0);

	t_point3	pixel_delta_u = vec_div(viewport_u, (double)IMAGE_WIDTH);
	t_point3	pixel_delta_v = vec_div(viewport_v, (double)IMAGE_HEIGHT);

	t_point3	viewport_upper_left = 
					vec_sub(camera_center,
						vec_sub(vec3(0, 0, focal_length),
							vec_sub(vec_div(viewport_u, 2.0), vec_div(viewport_v, 2.0))));
    t_vec3		pixel00_loc =
					vec_add(viewport_upper_left,
						vec_scale(vec_add(pixel_delta_u, pixel_delta_v) ,0.5));

	printf("P3\n%d %d\n255\n", IMAGE_WIDTH, IMAGE_HEIGHT);
	i = -1;
	while (++i < IMAGE_HEIGHT)
	{
		dprintf(2, "\rScanlines remaining: %d ", IMAGE_HEIGHT - i);
		j = -1;
		while (++j < IMAGE_WIDTH)
		{
			// pixel_color = vec3(
			// 		(double)j / (IMAGE_WIDTH - 1),
			// 		(double)i / (IMAGE_HEIGHT - 1),
			// 		0
			// 		);
			t_point3	pixel_center = vec_add(pixel00_loc,
							vec_add(
								vec_scale(pixel_delta_u, (double)j),
								vec_scale(pixel_delta_v, (double)i)));
			t_vec3		ray_dir = vec_sub(pixel_center, camera_center);
			t_ray		r = (t_ray){camera_center, ray_dir};
			pixel_color = ray_color(r);
			write_color(pixel_color);
		}
	}
	dprintf(2, "\rDone.                   \n");
	return (0);
}
