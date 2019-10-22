/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:02:50 by mkopiika          #+#    #+#             */
/*   Updated: 2019/10/20 15:36:52 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	sdl_initial(t_rtv *data)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		get_error(-42, FAIL_SDL);
	if (!(data->sdl.win_ptr = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, W, H, SDL_WINDOW_ALLOW_HIGHDPI)))
		get_error(-42, FAIL_SDL);
	if (!(data->sdl.srf_ptr = SDL_GetWindowSurface(data->sdl.win_ptr)))
		get_error(-42, FAIL_SDL);
}

int			main(int argc, char **argv)
{
	t_rtv	*rtv;

	if (argc != 2)
		get_error(-42, FAIL_ARGC);
	if (!(rtv = (t_rtv *)malloc(sizeof(t_rtv))))
		get_error(-42, FAIL_MALLOC);
	ft_bzero(rtv, sizeof(t_rtv));
	open_read_valid(argv, rtv);
	sdl_initial(rtv);
	calculate_tracing(rtv);
	loop_rtv(rtv);
	return (0);
}
