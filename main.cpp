/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:48:20 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/28 04:36:06 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GLFW/glfw3.h>
#include <NSX/Game.hpp>
#include <dlfcn.h>

#define W_HEIGHT 500
#define W_WIDTH 500

int main() {
    int speed = 5;

    Vector2 v(500, 500);

    GameContext *game = new GameContext(1000, 1000, (char *)"GAME ! OSF", NULL, NULL);
    game->ViewPort(0, 0, 2000, 2000);
    while (game->is_alive())
    {
        game->Clear_Window();
        game->Ortho_Projection(0, 1000, 0, 1000, -1, 1);
        v.y += speed * (game->IsPressed('W'));
        v.x -= speed * (game->IsPressed('A'));
        v.y -= speed * (game->IsPressed('S'));
        v.x += speed * (game->IsPressed('D'));
        // v.x *= !(v.x > 1000);
        // v.y *= !(v.y > 1000);
        // if (v.x < 0)
        //     v.x = 1000;
        // if (v.y < 0)
        //     v.y = 1000;
        Vector2 mousepos;
    
        mousepos = game->GetMousePosition();
        printf("x%d y%d (MOUSE x%d y%d)\n", v.x, v.y, mousepos.x, mousepos.y);
        game->put_pixel(v, -1);
        glfwSwapBuffers(game->windowptr);
    }
    return 0;
}
