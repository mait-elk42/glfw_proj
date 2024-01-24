#include <GLFW/glfw3.h>
#include <iostream>

#define W_HEIGHT 500
#define W_WIDTH 500

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void winresizingCallback(GLFWwindow *window, int w, int h)
{
    int win_width, win_height;
    int win_xpos, win_ypos;
    glfwGetWindowSize(window, &win_width, &win_height);
    glfwGetWindowPos(window, &win_xpos, &win_ypos);
    if (win_width >= 1000)
        win_width = 1000;
    if (win_height >= 1000)
        win_height = 1000;
    glfwSetWindowSize(window, win_width, win_height);
    glViewport(win_width, win_height, win_width, win_height);
    glfwSetWindowPos(window, win_xpos, win_ypos);
}

void winposchangeCallback(GLFWwindow *window, int x, int y)
{
    // printf("%d , %d\n", x, y);
}

void put_pixel(int x_pos, int y_pos) {

    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
    glPointSize(0.1f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2i(x_pos, y_pos);
    glEnd();
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

int main() {
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(W_HEIGHT, W_WIDTH, "OpenGL Pixel Example", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, keyCallback);
    glfwSetFramebufferSizeCallback(window, winresizingCallback);
    glfwSetWindowPosCallback(window, winposchangeCallback);
    // glfwSetMouseButtonCallback(window, mouseCallback);

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
            int x = 0;
            while (x < 500)
                put_pixel(x++, 100);
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
