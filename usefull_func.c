/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 15:47:51 by avella            #+#    #+#             */
/*   Updated: 2016/02/21 18:50:40 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		error_arg(void)
{
	ft_putstr("Choix de Fractale : /fractol\n");
	ft_putstr("                             Julia\n");
	ft_putstr("                             Mandel\n");
	ft_putstr("                             Burning\n");
	exit(1);
}

void		my_pixel_put_to_image(t_img *myimg, int x, int y, int color)
{
	myimg->data = mlx_get_data_addr(myimg->img_ptr,
			&myimg->bpp, &myimg->sizeline, &myimg->endian);
	myimg->data[y * myimg->sizeline + x * myimg->bpp / 8] = color % 256;
	color /= 256;
	myimg->data[y * myimg->sizeline + x * myimg->bpp / 8 + 1] = color % 256;
	color /= 256;
	myimg->data[y * myimg->sizeline + x * myimg->bpp / 8 + 2] = color % 256;
}

int			color_give(t_struct *ms)
{
	if (ms->fracnum == 1)
		return (RGB(127.5 * cos(ms->ite), 127.5
					* sin(210 * ms->j->i / ms->ite)
					, 127.5 * cos(210 * ms->j->i / ms->ite)));
	else if (ms->fracnum == 2)
		return (RGB(127.5 * cos(ms->ite), 127.5
					* sin(210 * ms->mandel->i / ms->ite)
					, 127.5 * cos(210 * ms->mandel->i / ms->ite)));
	else if (ms->fracnum == 3)
		return (RGB(127.5 * cos(ms->ite), 127.5
					* sin(210 * ms->burn->i / ms->ite)
					, 127.5 * cos(210 * ms->burn->i / ms->ite)));
	else
		return (0x00FFFF);
}
