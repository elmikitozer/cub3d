/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:15:05 by myevou            #+#    #+#             */
/*   Updated: 2024/09/26 14:46:23 by myevou           ###   ########.fr       */
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
	mlx_hook(cub.win, 33, 1L << 17, exit_game, &cub);
	mlx_key_hook(cub.win, key_press, &cub);
	mlx_loop_hook(cub.mlx, rc_loop, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
