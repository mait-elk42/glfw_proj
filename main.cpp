#include <GLFW/glfw3.h>
#include <GFX/game.hpp>
#include <iostream>

#define W_HEIGHT 500
#define W_WIDTH 500

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void    _put_square(int x, int y)
{

}

// void  mouseCallback(GLFWwindow* window, int btncode, int key_press, int action) {
//     double  posx;
//     double  posy;

//     glfwGetCursorPos(window, &posx, &posy);
//     if (key_press)
//     {
//         glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);
//         printf("%f %f\n",posx, posy);
//         put_pixel((int)posx, (int)posy);
        
//     }
// }

int maain() {
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(W_HEIGHT, W_WIDTH, "OpenGL Pixel Example", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, keyCallback);

    while (!glfwWindowShouldClose(window)) {
        int width, height;
        
        glfwGetWindowSize(window, &width, &height);
        // printf("%d %d\n",width, height);
        glViewport(width, height, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, width, 0, height, -1, 1);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // int y = 300;
        // while (y < 500)
        // {
            // int x = 0;
            // while (x < 500)
                // put_pixel(x++, 100);
        //     y++;
        // }
        // put_pixel(0, 0);
        // _put_square(10, 10);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

int main() {
    int i = 0;

    GameContext *game = new GameContext(1000, 1000, (char *)"GAME ! OSF", NULL, NULL);
    while (game->is_alive()) {
        glViewport(1000, 1000, 1000, 1000);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, 1000, 0, 1000, -1, 1);
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        printf("!! GREAT WORK %d\n", i);
        game->put_pixel(0, 0, -1);
        glfwSwapBuffers(game->windowptr);
        i++;
    }
    return 0;
}
