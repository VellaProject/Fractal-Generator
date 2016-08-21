/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 15:41:27 by avella            #+#    #+#             */
/*   Updated: 2016/02/21 15:50:22 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			event_mlx(int keycode, t_struct *mystruct)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 42)
	{
		if (mystruct->etat == 1)
		{
			mystruct->etat = 0;
		}
		else
			mystruct->etat = 1;
	}
	if (keycode == 69)
	{
		mystruct->ite += 40;
	}
	if (keycode == 78)
	{
		mystruct->ite -= 40;
	}
	expose_hoo(mystruct);
	return (0);
}

t_struct	*give_struct(void)
{
	t_struct	*mystruct;
	t_img		*myimg;
	t_julia		*jul;
	t_mandel	*m;
	t_burn		*b;

	b = (t_burn *)malloc(sizeof(t_burn) * 1);
	m = (t_mandel *)malloc(sizeof(t_mandel) * 1);
	jul = (t_julia *)malloc(sizeof(t_julia) * 1);
	myimg = (t_img *)malloc(sizeof(t_img) * 1);
	mystruct = (t_struct *)malloc(sizeof(t_struct) * 1);
	mystruct->mlx = mlx_init();
	mystruct->win = mlx_new_window(mystruct->mlx, WIDTH, HEIGHT, "FRACTOL");
	myimg->img_ptr = mlx_new_image(mystruct->mlx, WIDTH, HEIGHT);
	mystruct->j = jul;
	mystruct->mandel = m;
	mystruct->burn = b;
	mystruct->img = myimg;
	mystruct->etat = 0;
	mystruct->ite = 50;
	return (mystruct);
}

int			expose_hoo(t_struct *mystruct)
{
	mlx_destroy_image(mystruct->mlx, mystruct->img->img_ptr);
	mystruct->img->img_ptr = mlx_new_image(mystruct->mlx, WIDTH, HEIGHT);
	if (mystruct->fracnum == 1)
		myjulia(mystruct);
	else if (mystruct->fracnum == 2)
		mymandel(mystruct);
	else if (mystruct->fracnum == 3)
		myburn(mystruct);
	mlx_put_image_to_window(mystruct->mlx,
			mystruct->win, mystruct->img->img_ptr, 0, 0);
	return (0);
}

void		fractal_choice(char **argv, t_struct *mystruct)
{
	if (ft_strequ(argv[1], "Julia") == 1)
	{
		mystruct->fracnum = 1;
		julia_init(mystruct);
		mlx_mouse_hook(mystruct->win, ft_zoom, mystruct);
		mlx_hook(mystruct->win, 6, (1L << 6), motion_julia, mystruct);
	}
	else if (ft_strequ(argv[1], "Mandel") == 1)
	{
		mystruct->fracnum = 2;
		mandel_init(mystruct);
		mlx_mouse_hook(mystruct->win, ft_zoom_mandel, mystruct);
		mlx_hook(mystruct->win, 6, (1L << 6), motion_mandel, mystruct);
	}
	else if (ft_strequ(argv[1], "Burning") == 1)
	{
		mystruct->fracnum = 3;
		burn_init(mystruct);
		mlx_mouse_hook(mystruct->win, ft_zoom_burning, mystruct);
		mlx_hook(mystruct->win, 6, (1L << 6), motion_burning, mystruct);
	}
	else
		error_arg();
}

int			main(int argc, char **argv)
{
	t_struct *mystruct;

	if (argc != 2)
	{
		error_arg();
		return (0);
	}
	mystruct = give_struct();
	fractal_choice(argv, mystruct);
	mlx_put_image_to_window(mystruct->mlx,
			mystruct->win, mystruct->img->img_ptr, 0, 0);
	mlx_expose_hook(mystruct->win, expose_hoo, mystruct);
	mlx_key_hook(mystruct->win, event_mlx, mystruct);
	mlx_loop(mystruct->mlx);
	return (0);
}
