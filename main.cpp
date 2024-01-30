/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:48:20 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/30 15:47:24 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <NSX/Game.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include "include/NSX/stb_image.h"

#define W_HEIGHT 500
#define W_WIDTH 500

int	main2() {
    int	speed = 400;
    int gravity = 400;
	int in_floor = 0;
	int jumping = 0;


	GameObject square(Vector2(100, 100), Vector2(50, 50), Color(200, 200, 100));
	GameObject enemy(Vector2(500, 100), Vector2(50, 50), Color(255, 0, 0));
	GameContext *game = new GameContext(500, 1000, (char *)"GAME ! OSF", NULL, NULL);
	// glfwSetInputMode(game->windowptr, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	while (game->is_alive())
	{
		game->ViewPort(0, 0, game->window_width, game->window_height);
		game->Ortho_Projection(0, game->GetWindowSize().x, game->GetWindowSize().y, 0, -10, 10);
		game->Clear_Window();

		if (game->IsPressed('W'))
				square.position.y -= speed * game->DeltaTime;
		if (game->IsPressed('A'))
				square.position.x -= speed * game->DeltaTime;
		if (game->IsPressed('S'))
				square.position.y += speed * game->DeltaTime;
		if (game->IsPressed('D'))
				square.position.x += speed * game->DeltaTime;
		
		if (square.position.y + square.size.y < game->GetWindowSize().y)
			square.position.y += game->DeltaTime * (gravity);
		else
			in_floor = 1;
		if (enemy.position.y + enemy.size.y < game->GetWindowSize().y)
			enemy.position.y += game->DeltaTime * (gravity);
		if ((game->IsPressed(' ') && in_floor) || jumping)
		{
			if (jumping++ < 10)
				square.position.y-= game->DeltaTime * (900);
			else
				in_floor = jumping = 0;
		}

		game->put_square(square);
		game->put_square(enemy);
		glfwSwapBuffers(game->windowptr);
	}
	return 0;
}


int	main() {
	GameContext *game = new GameContext(500, 1000, (char *)"GAME ! OSF", NULL, NULL);
	while (game->is_alive())
	{
		game->ViewPort(0, 0, game->window_width, game->window_height);
		game->Ortho_Projection(0, game->GetWindowSize().x, game->GetWindowSize().y, 0, -10, 10);
		game->Clear_Window();
		
		glfwSwapBuffers(game->windowptr);
	}
	return 0;
}
