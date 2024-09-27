/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:15:05 by myevou            #+#    #+#             */
/*   Updated: 2024/09/27 11:54:48 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	print_map(t_cub *cub)
// {
// 	int i, j;
// 	for (i = 0; i < cub->map.height; i++)
// 	{
// 		for (j = 0; j < cub->map.width; j++)
// 		{
// 			printf("%d ", cub->map.grid[i][j]);
// 		}
// 		printf("\n");
// 	}
// }

int	main(int ac, char **av)
{
	t_cub	cub;

	(void)ac;
	(void)av;
	// parsing(&cub, ac, av);
	// init_map(&cub);
	init(&cub);
	// print_map(&cub);
	// printf("Player Position: (%f, %f)\n", cub.player.x, cub.player.y);
	// print_map(&cub);
	// mlx_hook(cub.win, 2, 1L << 0, key_press, &cub);
	mlx_hook(cub.win, 33, 1L << 17, exit_cub, &cub);
	mlx_hook(cub.win, 2, 1L << 0, key_press, &cub);   // 2 pour KeyPress
	mlx_hook(cub.win, 3, 1L << 1, key_release, &cub); // 3 pour KeyRelease
	mlx_hook(cub.win, 6, 1L<<6, mouse_move, &cub); // 6 pour MotionNotify
	// mlx_key_hook(cub.win, key_press, &cub);
	mlx_loop_hook(cub.mlx, rc_loop, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
