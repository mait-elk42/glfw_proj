/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:48:20 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/30 00:29:19 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GLFW/glfw3.h>
#include <NSX/Game.hpp>
#include <dlfcn.h>

#define W_HEIGHT 500
#define W_WIDTH 500

int	main() {
    int	speed = 500;
    int gravity = 250;


	GameObject square(Vector2(500, 100), Vector2(500, 500), Color(200, 200, 100));
	GameContext *game = new GameContext(500, 1000, (char *)"GAME ! OSF", NULL, NULL);
	// glfwSetInputMode(game->windowptr, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	while (game->is_alive())
	{
		game->ViewPort(0, 0, game->window_width, game->window_height);
		game->Ortho_Projection(0, game->GetWindowSize().x, game->GetWindowSize().y, 0, -10, 10);
		game->Clear_Window();

		square.position.y -= (speed * (game->IsPressed('W'))) * game->DeltaTime;
		square.position.x -= (speed * (game->IsPressed('A'))) * game->DeltaTime;
		square.position.y += (speed * (game->IsPressed('S'))) * game->DeltaTime;
		square.position.x += (speed * (game->IsPressed('D'))) * game->DeltaTime;
		// if (v.y + square.size.y < 500)
		// 	v.y += game->DeltaTime * (gravity);

		// printf("FPS(%d)\n", game->FPS);
		// printf("x%d y%d\n", v.x, v.y);
		game->put_square(square);
		glfwSwapBuffers(game->windowptr);
	}
	return 0;
}
