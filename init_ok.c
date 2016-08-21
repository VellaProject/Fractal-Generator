/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 15:53:01 by avella            #+#    #+#             */
/*   Updated: 2016/02/21 15:53:21 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ok_draw2(int x, int y)
{
	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
		return (1);
	return (0);
}

void	julia_init(t_struct *mystruct)
{
	mystruct->j->zoom_x = WIDTH;
	mystruct->j->zoom_y = HEIGHT;
	mystruct->j->xmin = -2;
	mystruct->j->xmax = 2;
	mystruct->j->ymin = -2;
	mystruct->j->ymax = 2;
	mystruct->j->x = 0;
	mystruct->j->y = 0;
	mystruct->j->ite = 50;
	mystruct->j->cx = -0.7;
	mystruct->j->cy = 0.2;
	myjulia(mystruct);
}

void	mandel_init(t_struct *mystruct)
{
	mystruct->mandel->x = 0;
	mystruct->mandel->y = 0;
	mystruct->mandel->zoom_x = WIDTH;
	mystruct->mandel->zoom_y = HEIGHT;
	mystruct->mandel->xmin = -2.1;
	mystruct->mandel->xmax = 0.6;
	mystruct->mandel->ymin = -1.2;
	mystruct->mandel->ymax = 1.2;
	mystruct->mandel->ite = 50;
	mystruct->mandel->x1 = 0;
	mystruct->mandel->y1 = 0;
	mystruct->mandel->tx1 = 0;
	mystruct->mandel->ty1 = 0;
	mymandel(mystruct);
}

void	burn_init(t_struct *mystruct)
{
	mystruct->burn->x = 0;
	mystruct->burn->y = 0;
	mystruct->burn->zoom_x = WIDTH;
	mystruct->burn->zoom_y = HEIGHT;
	mystruct->burn->xmin = -2.1;
	mystruct->burn->xmax = 0.6;
	mystruct->burn->ymin = -1.2;
	mystruct->burn->ymax = 1.2;
	mystruct->burn->ite = 50;
	mystruct->burn->x1 = 0;
	mystruct->burn->y1 = 0;
	mystruct->burn->tx1 = 0;
	mystruct->burn->ty1 = 0;
	myburn(mystruct);
}
