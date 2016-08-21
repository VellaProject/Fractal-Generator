/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 16:18:39 by avella            #+#    #+#             */
/*   Updated: 2016/02/21 18:17:02 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define WIDTH 800
# define HEIGHT 600
# include "libft.h"

typedef struct									s_img
{
	void				*mlx;
	void				*win;
	unsigned long		img_color;
	char				*data;
	void				*img_ptr;
	int					sizeline;
	int					bpp;
	int					x;
	int					y;
	int					endian;
	void				*mlx_ptr;
}												t_img;

typedef struct									s_julia
{
	int		x;
	int		y;
	int		i;
	double	zoom_x;
	double	zoom_y;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	cx;
	double	cy;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	xy;
	double	ite;
}												t_julia;

typedef struct									s_mandel
{
	int		x;
	int		y;
	int		i;
	double	zoom_x;
	double	zoom_y;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	cx;
	double	cy;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	xy;
	double	tx1;
	double	ty1;
	double	ite;
}												t_mandel;

typedef struct									s_burn
{
	int		x;
	int		y;
	int		i;
	double	zoom_x;
	double	zoom_y;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	cx;
	double	cy;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	xy;
	double	ite;
	double	tx1;
	double	ty1;
}												t_burn;

typedef struct									s_struct
{
	int					fracnum;
	void				*mlx;
	void				*win;
	char				***coord;
	int					i;
	int					maxline;
	double				zoom;
	t_img				*img;
	int					ite;
	float				xv;
	float				yv;
	int					other;
	int					etat;
	double				jv1;
	double				jv2;
	double				zo;
	double				mx;
	double				my;
	float				offx;
	float				offy;
	float				mxite;
	float				vale;
	float				ratio;
	t_julia				*j;
	t_mandel			*mandel;
	t_burn				*burn;
}												t_struct;

void											error_arg(void);
int												expose_hoo(t_struct *mystruct);
void											myburn(t_struct *mystruct);
void											burn_init(t_struct *mystruct);
int												ft_zoom_burning(int mouse
		, int x, int y,
		t_struct *mystruct);
int												motion_burning(int x, int y,
		t_struct *mystruct);
int												motion_mandel(int x, int y,
		t_struct *mystruct);
void											mymandel(t_struct *mystruct);
void											myjulia(t_struct *mystruct);
void											draw_julia(t_img *myimg);
void											my_pixel_put_to_image(t_img
		*myimg,
		int x, int y, int color);
int												ft_zoom(int mouse,
		int x, int y, t_struct *mystruct);
void											julia_init(t_struct *mystruct);
int												ft_zoom_mandel(int mouse,
		int x, int y, t_struct *mystruct);
void											mandel_init(t_struct *mystruct);
int												motion_julia(int x,
		int y, t_struct *mystruct);
int												ok_draw2(int x, int y);
int												color_give(t_struct *ms);
#endif
