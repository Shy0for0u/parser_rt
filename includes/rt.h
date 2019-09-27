//
// Created by Dremora lord Gorold goodbrother on 26/09/2019.
//

#ifndef PARSER_RT_H
#define PARSER_RT_H

#include "../libft/includes/libft.h"
#include "../libgm/include/libgm.h"

#include <stdio.h>

typedef struct		s_sphere
{
	t_int4			data;
	t_float4		data_1;
	t_float4		center;
}					t_sphere;

typedef struct		s_cone
{
	int 			id;
	int 			color;
	t_float4		center;
	float 			base_radius;
}					t_cone;

typedef struct		s_obj
{
	t_sphere		spheres[4];
}					t_obj;

typedef struct		s_mem
{
	char			*type_obj;
	int 			id;
	float 			center[4];
	float 			radius;
	int 			color[4];
	int 			specular;
	float 			reflection;
}					t_mem;

typedef struct		s_rt
{
	t_mem			memory[100];
	t_cone			cone;
	t_mat4			t;
	t_float4		o;
	t_obj			obj;
}					t_rt;
#endif //PARSER_RT_H
