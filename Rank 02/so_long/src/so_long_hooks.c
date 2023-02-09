/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:04:07 by rafael            #+#    #+#             */
/*   Updated: 2023/02/09 22:15:53 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	void	*g;

	g = game;
	if (keycode == 65307)
		mlx_destroy_window(game->game, game->win);
	ft_printf("%i\n", keycode);
	return (0);
}
