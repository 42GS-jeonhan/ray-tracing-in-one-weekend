/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonhan <jeonhan@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 17:42:37 by jeonhan           #+#    #+#             */
/*   Updated: 2026/09/17 21:03:37 by jeonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <math.h>

typedef struct s_vec3
{
	double	e[3];
}	t_vec3;
typedef t_vec3	t_point3;

t_vec3	vec3(double x, double y, double z); //벡터 생성
t_vec3	vec_add(t_vec3 a, t_vec3 b); //벡터 더하기
t_vec3	vec_sub(t_vec3 a, t_vec3 b); //벡터 빼기
t_vec3	vec_scale(t_vec3 v, double n); //스칼라 곱하기
t_vec3	vec_div(t_vec3 v, double n); //스칼라 나누기

t_vec3	vec_mul(t_vec3 a, t_vec3 b); //벡터 성분곱
double	vec_dot(t_vec3 a, t_vec3 b); //벡터 내적
t_vec3	vec_cross(t_vec3 a, t_vec3 b); //벡터 외적
double	vec_length(t_vec3 v); //벡터 크기
t_vec3	vec_unit(t_vec3 v); //단위벡터 만들기(정규화)

#endif
