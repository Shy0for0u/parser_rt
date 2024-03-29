/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gm_mat_create_from_vec.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:12:10 by ahorker           #+#    #+#             */
/*   Updated: 2019/05/02 21:12:10 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libgm.h"

t_mat4	gm_mat_create(t_float4 v_1, t_float4 v_2, t_float4 v_3, t_float4 v_4)
{
	t_mat4	t;

	t.v[0] = v_1;
	t.v[1] = v_2;
	t.v[2] = v_3;
	t.v[3] = v_4;
	return (t);
}
