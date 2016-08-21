/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 15:58:26 by avella            #+#    #+#             */
/*   Updated: 2016/02/21 18:21:51 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		motion_mandel(int x, int y, t_struct *ms)
{
	if (ms->etat == 1)
	{
		if (x <= WIDTH && x >= 0 && y <= HEIGHT && y >= 0)
		{
			ms->mandel->tx1 = x * (ms->mandel->xmax - ms->mandel->xmin)
				/ WIDTH + ms->mandel->xmin;
			ms->mandel->ty1 = y * (ms->mandel->ymax - ms->mandel->ymin)
				/ HEIGHT + ms->mandel->ymin;
			expose_hoo(ms);
		}
	}
	return (0);
}

int		ft_zoom_mandel(int mouse, int x, int y, t_struct *ms)
{
	double x_zoom;
	double y_zoom;
	double i;

	if (mouse == 4)
		i = 0.8;
	else
		i = 1.2;
	x_zoom = x * (ms->mandel->xmax - ms->mandel->xmin)
		/ WIDTH + ms->mandel->xmin;
	y_zoom = y * (ms->mandel->ymax - ms->mandel->ymin)
		/ HEIGHT + ms->mandel->ymin;
	ms->mandel->xmin = (ms->mandel->xmin - x_zoom) * i + x_zoom;
	ms->mandel->xmax = (ms->mandel->xmax - x_zoom) * i + x_zoom;
	ms->mandel->ymin = (ms->mandel->ymin - y_zoom) * i + y_zoom;
	ms->mandel->ymax = (ms->mandel->ymax - y_zoom) * i + y_zoom;
	expose_hoo(ms);
	return (0);
}

void	mandel_give(t_mandel *mandel)
{
	mandel->xy = mandel->x1 * mandel->y1;
	mandel->x2 = mandel->x1 * mandel->x1;
	mandel->y2 = mandel->y1 * mandel->y1;
	mandel->x1 = mandel->x2 - mandel->y2 + mandel->cx;
	mandel->y1 = mandel->xy + mandel->xy + mandel->cy;
	mandel->i++;
}

void	mandel_proced(t_struct *ms, double thex1, double they1)
{
	ms->mandel->cx = ms->mandel->xmin + (ms->mandel->xmax
			- ms->mandel->xmin) * ms->mandel->x / ms->mandel->zoom_x;
	ms->mandel->cy = ms->mandel->ymin + (ms->mandel->ymax
			- ms->mandel->ymin) * ms->mandel->y / ms->mandel->zoom_y;
	ms->mandel->x1 = thex1;
	ms->mandel->y1 = they1;
	ms->mandel->x2 = 0;
	ms->mandel->y2 = 0;
	ms->mandel->i = 0;
}

void	mymandel(t_struct *ms)
{
	double thex1;
	double they1;

	thex1 = ms->mandel->tx1;
	they1 = ms->mandel->ty1;
	ms->mandel->x = 0;
	while (ms->mandel->x < ms->mandel->zoom_x)
	{
		ms->mandel->y = 0;
		while (ms->mandel->y < ms->mandel->zoom_y)
		{
			mandel_proced(ms, thex1, they1);
			while ((ms->mandel->x2 + ms->mandel->y2 <= 4)
					&& (ms->mandel->i < ms->ite))
			{
				mandel_give(ms->mandel);
			}
			if (ok_draw2(ms->mandel->x, ms->mandel->y))
				my_pixel_put_to_image(ms->img, ms->mandel->x,
						ms->mandel->y, color_give(ms));
			ms->mandel->y++;
		}
		ms->mandel->x++;
	}
}
