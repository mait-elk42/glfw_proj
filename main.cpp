/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:48:20 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/28 17:01:25 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GLFW/glfw3.h>
#include <NSX/Game.hpp>
#include <dlfcn.h>

#define W_HEIGHT 500
#define W_WIDTH 500

int main() {
    GameObject square(Vector2Zero, Vector2Zero);
    int speed = 500;
    int gravity = 2;


    GameContext *game = new GameContext(1000, 1000, (char *)"GAME ! OSF", NULL, NULL);
    // glfwSetInputMode(game->windowptr, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    // glfwSetInputMode(game->windowptr, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    Vector2 v(500, 500);
    

    while (game->is_alive())
    {
        game->ViewPort(0, 0, game->window_width, game->window_height);
        game->Ortho_Projection(0, game->GetWindowSize().x, game->GetWindowSize().y, 0, -1, 1);
        game->Clear_Window();

        v.y -= (speed * (game->IsPressed('W'))) * game->DeltaTime;
        v.x -= (speed * (game->IsPressed('A'))) * game->DeltaTime;
        v.y += (speed * (game->IsPressed('S'))) * game->DeltaTime;
        v.x += (speed * (game->IsPressed('D'))) * game->DeltaTime;
        // v.y += (currtime - lasttime) * (gravity);

        printf("Delta(%f)\n", game->DeltaTime);
        int y = 0;
        while (y < 100)
        {
            int x = 0;
            while(x < 100)
            {
                Vector2 pos(v.x+x, v.y+y);
                game->put_pixel(pos, -1);
                x++;
            }
            // printf("x%d y%d\n", v.x, v.y);
            y++;
        }
        glfwSwapBuffers(game->windowptr);
    }
    return 0;
}
