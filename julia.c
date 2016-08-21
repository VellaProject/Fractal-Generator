/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 15:31:46 by avella            #+#    #+#             */
/*   Updated: 2016/02/21 18:21:29 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		motion_julia(int x, int y, t_struct *ms)
{
	if (ms->etat == 1)
	{
		if (x <= WIDTH && x >= 0 && y <= HEIGHT && y >= 0)
		{
			ms->j->cx = x * (ms->j->xmax - ms->j->xmin) / WIDTH + ms->j->xmin;
			ms->j->cy = y * (ms->j->ymax - ms->j->ymin) / HEIGHT + ms->j->ymin;
			expose_hoo(ms);
		}
	}
	return (0);
}

int		ft_zoom(int mouse, int x, int y, t_struct *ms)
{
	double x_zoom;
	double y_zoom;
	double i;

	if (mouse == 4)
		i = 0.8;
	else
		i = 1.2;
	x_zoom = x * (ms->j->xmax - ms->j->xmin) / WIDTH + ms->j->xmin;
	y_zoom = y * (ms->j->ymax - ms->j->ymin) / HEIGHT + ms->j->ymin;
	ms->j->xmin = (ms->j->xmin - x_zoom) * i + x_zoom;
	ms->j->xmax = (ms->j->xmax - x_zoom) * i + x_zoom;
	ms->j->ymin = (ms->j->ymin - y_zoom) * i + y_zoom;
	ms->j->ymax = (ms->j->ymax - y_zoom) * i + y_zoom;
	expose_hoo(ms);
	return (0);
}

void	julia_give(t_julia *j)
{
	j->xy = j->x1 * j->y1;
	j->x2 = j->x1 * j->x1;
	j->y2 = j->y1 * j->y1;
	j->x1 = j->x2 - j->y2 + j->cx;
	j->y1 = j->xy + j->xy + j->cy;
	j->i++;
}

void	myjulia(t_struct *ms)
{
	ms->j->x = 0;
	while (ms->j->x < ms->j->zoom_x)
	{
		ms->j->y = 0;
		while (ms->j->y < ms->j->zoom_y)
		{
			ms->j->x1 = ms->j->xmin + (ms->j->xmax - ms->j->xmin)
				* ms->j->x / ms->j->zoom_x;
			ms->j->y1 = ms->j->ymin + (ms->j->ymax - ms->j->ymin)
				* ms->j->y / ms->j->zoom_y;
			ms->j->x2 = 0;
			ms->j->y2 = 0;
			ms->j->i = 0;
			while ((ms->j->x2 + ms->j->y2 <= 4) && (ms->j->i < ms->ite))
			{
				julia_give(ms->j);
			}
			if (ok_draw2(ms->j->x, ms->j->y))
				my_pixel_put_to_image(ms->img, ms->j->x,
						ms->j->y, color_give(ms));
			ms->j->y++;
		}
		ms->j->x++;
	}
}
