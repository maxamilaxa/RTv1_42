/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 20:02:10 by mkopiika          #+#    #+#             */
/*   Updated: 2019/10/20 15:25:03 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		game_over(t_window *sdl)
{
	if (sdl->srf_ptr)
		SDL_FreeSurface(sdl->srf_ptr);
	if (sdl->win_ptr)
		SDL_DestroyWindow(sdl->win_ptr);
	SDL_Quit();
}

void			loop_rtv(t_rtv *rtv)
{
	SDL_Event	event;
	int			key_code;
	int			prog_loop;

	prog_loop = 42;
	while (prog_loop == 42)
	{
		while (SDL_PollEvent(&event))
		{
			key_code = event.key.keysym.sym;
			if ((event.type == SDL_KEYDOWN && key_code == SDLK_ESCAPE)
				|| (event.type == SDL_QUIT))
				prog_loop = 0;
		}
	}
	game_over(&rtv->sdl);
}
