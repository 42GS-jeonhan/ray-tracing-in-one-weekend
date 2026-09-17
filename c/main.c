/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhan <jeonhan@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 18:59:13 by jeonhan           #+#    #+#             */
/*   Updated: 2026/09/17 17:28:10 by jeonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	main(void)
{
	int	i;
	int	j;

	printf("P3\n%d %d\n255\n", IMAGE_WIDTH, IMAGE_HEIGHT);
	i = -1;
	while (++i < IMAGE_HEIGHT)
	{
		dprintf(2, "\rScanlines remaining: %d ", IMAGE_HEIGHT - i);
		j = -1;
		while (++j < IMAGE_WIDTH)
		{
			printf("%d %d %d\n",
				(int)((double)j / (IMAGE_WIDTH - 1) * 255.999), //r
				(int)((double)i / (IMAGE_HEIGHT - 1) * 255.999), //g
				0 //b
				);
			usleep(10);
		}
	}
	dprintf(2, "\rDone.                   \n");
	return (0);
}
