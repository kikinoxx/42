/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:19:00 by kmorin            #+#    #+#             */
/*   Updated: 2023/03/20 15:19:27 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_mouse(int mousecode, t_f *p)
{
	if (mousecode == 4 || mousecode == 5)
	{
		if (mousecode == 4)
			p->zoom *= 0.8;
		else
			p->zoom /= 0.8;
	}
	if (!ft_strncmp(p->name, "Mandelbrot", 11))
		ft_mandelbrot_start(p);
	if (!ft_strncmp(p->name, "Julia", 5))
		ft_julia_start(p);
	return (0);
}
