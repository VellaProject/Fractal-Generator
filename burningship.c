/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 16:08:00 by avella            #+#    #+#             */
/*   Updated: 2016/02/21 18:22:10 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			motion_burning(int x, int y, t_struct *ms)
{
	if (ms->etat == 1)
	{
		if (x <= WIDTH && x >= 0 && y <= HEIGHT && y >= 0)
		{
			ms->burn->tx1 = x * (ms->burn->xmax
					- ms->burn->xmin) / WIDTH + ms->burn->xmin;
			ms->burn->ty1 = y * (ms->burn->ymax
					- ms->burn->ymin) / HEIGHT + ms->burn->ymin;
			expose_hoo(ms);
		}
	}
	return (0);
}

int			ft_zoom_burning(int mouse, int x, int y, t_struct *ms)
{
	double x_zoom;
	double y_zoom;
	double i;

	if (mouse == 4)
		i = 0.8;
	else
		i = 1.2;
	x_zoom = x * (ms->burn->xmax - ms->burn->xmin)
		/ WIDTH + ms->burn->xmin;
	y_zoom = y * (ms->burn->ymax - ms->burn->ymin)
		/ HEIGHT + ms->burn->ymin;
	ms->burn->xmin = (ms->burn->xmin - x_zoom) * i + x_zoom;
	ms->burn->xmax = (ms->burn->xmax - x_zoom) * i + x_zoom;
	ms->burn->ymin = (ms->burn->ymin - y_zoom) * i + y_zoom;
	ms->burn->ymax = (ms->burn->ymax - y_zoom) * i + y_zoom;
	expose_hoo(ms);
	return (0);
}

void		burn_give(t_burn *burn)
{
	burn->xy = fabs(burn->x1 * burn->y1);
	burn->x2 = burn->x1 * burn->x1;
	burn->y2 = burn->y1 * burn->y1;
	burn->x1 = burn->x2 - burn->y2 + burn->cx;
	burn->y1 = burn->xy + burn->xy + burn->cy;
	burn->i++;
}

void		burn_proced(t_struct *ms, double thex1, double they1)
{
	ms->burn->cx = ms->burn->xmin + (ms->burn->xmax
			- ms->burn->xmin) * ms->burn->x / ms->burn->zoom_x;
	ms->burn->cy = ms->burn->ymin + (ms->burn->ymax
			- ms->burn->ymin) * ms->burn->y / ms->burn->zoom_y;
	ms->burn->x1 = thex1;
	ms->burn->y1 = they1;
	ms->burn->x2 = 0;
	ms->burn->y2 = 0;
	ms->burn->i = 0;
}

void		myburn(t_struct *ms)
{
	double thex1;
	double they1;

	thex1 = ms->burn->tx1;
	they1 = ms->burn->ty1;
	ms->burn->x = 0;
	while (ms->burn->x < ms->burn->zoom_x)
	{
		ms->burn->y = 0;
		while (ms->burn->y < ms->burn->zoom_y)
		{
			burn_proced(ms, thex1, they1);
			while ((ms->burn->x2 + ms->burn->y2 <= 4)
					&& (ms->burn->i < ms->ite))
			{
				burn_give(ms->burn);
			}
			if (ok_draw2(ms->burn->x, ms->burn->y))
				my_pixel_put_to_image(ms->img, ms->burn->x,
						ms->burn->y, color_give(ms));
			ms->burn->y++;
		}
		ms->burn->x++;
	}
}
