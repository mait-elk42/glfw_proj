/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:48:20 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/28 19:31:00 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GLFW/glfw3.h>
#include <NSX/Game.hpp>
#include <dlfcn.h>

#define W_HEIGHT 500
#define W_WIDTH 500

int main() {
    int speed = 500;
    int gravity = 250;


    GameObject square(Vector2Zero, Vector2(10, 10));
    GameContext *game = new GameContext(500, 1000, (char *)"GAME ! OSF", NULL, NULL);
    // glfwSetInputMode(game->windowptr, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    // glfwSetInputMode(game->windowptr, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    Vector2 v(250, 250);
    

    while (game->is_alive())
    {
        game->ViewPort(0, 0, game->window_width, game->window_height);
        game->Ortho_Projection(0, game->GetWindowSize().x, game->GetWindowSize().y, 0, -1, 1);
        game->Clear_Window();

        v.y -= (speed * (game->IsPressed('W'))) * game->DeltaTime;
        v.x -= (speed * (game->IsPressed('A'))) * game->DeltaTime;
        v.y += (speed * (game->IsPressed('S'))) * game->DeltaTime;
        v.x += (speed * (game->IsPressed('D'))) * game->DeltaTime;
        if (v.y + square.size.y < 500)
            v.y += game->DeltaTime * (gravity);

        // printf("FPS(%d)\n", game->FPS);
        int y = 0;
        while (y < square.size.y)
        {
            int x = 0;
            while(x < square.size.x)
            {
                Vector2 pos(v.x+x, v.y+y);
                // printf("[x%d y%d]\n", x, y);
                // printf("%d", square.buffer[(y * square.size.y)+x]);
                game->put_pixel(pos, Color(square.buff_pixels[(y * square.size.y)+x].r,
                    square.buff_pixels[(y * square.size.y)+x].g, square.buff_pixels[(y * square.size.y)+x].b));
                x++;
            }
            // printf("\n");
            y++;
        }        
        // printf("x%d y%d\n", v.x, v.y);
        glfwSwapBuffers(game->windowptr);
    }
    return 0;
}
