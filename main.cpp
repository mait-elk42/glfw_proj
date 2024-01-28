/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:48:20 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/28 06:48:39 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GLFW/glfw3.h>
#include <NSX/Game.hpp>
#include <dlfcn.h>

#define W_HEIGHT 500
#define W_WIDTH 500

int main() {
    int speed = 5;


    GameContext *game = new GameContext(1000, 1000, (char *)"GAME ! OSF", NULL, NULL);
    // glfwSetInputMode(game->windowptr, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    

    while (game->is_alive())
    {
        Vector2 p;

        glfwGetWindowSize(game->windowptr, &p.x, &p.y);
        game->ViewPort(0, 0, game->window_width, game->window_height);
        Vector2 v(p.x/2, p.y/2);
        game->Ortho_Projection(0, p.x, p.y, 0, -1, 1);
        game->Clear_Window();
        // v.y -= speed * (game->IsPressed('W'));
        // v.x -= speed * (game->IsPressed('A'));
        // v.y += speed * (game->IsPressed('S'));
        // v.x += speed * (game->IsPressed('D'));

        printf("x%d y%d\n", v.x, v.y);
        int x = 0;
        while(x < 100)
        {
            Vector2 pos(v.x+x, v.y);
            game->put_pixel(pos, -1);
            x++;
        }
        glfwSwapBuffers(game->windowptr);
    }
    return 0;
}
