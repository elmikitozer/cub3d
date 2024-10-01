/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:15:05 by myevou            #+#    #+#             */
/*   Updated: 2024/10/01 17:35:02 by myevou           ###   ########.fr       */
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

void	print_map_grid(t_map *cub)
{
	int	i;
	int	j;

	i = 0;
	// printf("Map int:\n");
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
			printf("%d ", cub->grid[i][j++]);
		printf("\n");
		i++;
	}
}

int	main(int ac, char **av)
{
	t_cub	cub;

	// parsing(&cub, ac, av);
	// init_map(&cub);
	// init_cub(&cub);
	// init_player_keys(&cub);
	// init_cub(&cub);
	// init_player_keys(&cub);
	// init_map(&cub);
	if (parsing(&cub, ac, av))
		exit(1);
	// parsing(&cub, ac, av);
	cub.map.grid = cub.map.map_int;
	// printf("\n");
	// print_map_grid(&cub.map);
	init(&cub);
	// printf("Player Position: (%f, %f)\n", cub.player.x, cub.player.y);
	// print_map_grid(&cub.map);
	// printf("cub.map.grid[12][3] = %d\n", cub.map.grid[12][3]);
	// printf("Player Position: (%f, %f)\n", cub.player.x, cub.player.y);
	// print_map_int(&cub);
	// print_map(&cub);
	// print_map(&cub);
	// mlx_hook(cub.win, 2, 1L << 0, key_press, &cub);
	// print_map_grid(&cub.map);
	mlx_hook(cub.win, 33, 1L << 17, exit_cub, &cub);
	mlx_hook(cub.win, 2, 1L << 0, key_press, &cub);   // 2 pour KeyPress
	mlx_hook(cub.win, 3, 1L << 1, key_release, &cub); // 3 pour KeyRelease
	mlx_hook(cub.win, 6, 1L << 6, mouse_move, &cub);  // 6 pour MotionNotify
	// mlx_key_hook(cub.win, key_press, &cub);
	// print_map_grid(&cub.map);
	mlx_loop_hook(cub.mlx, rc_loop, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
