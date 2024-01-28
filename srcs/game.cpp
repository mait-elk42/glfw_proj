/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:37:34 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/28 06:47:03 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NSX/Game.hpp>

static void	_nsx_exit(char *msg, int status)
{
	printf("\nError :\n [ %s ]", msg);
	exit(status);
}

void	key_callback_def(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)mods;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

GameContext::GameContext(int window_width, int window_height, char *name, GLFWmonitor* monitor, GLFWwindow* share)
{
	if (!glfwInit())
			_nsx_exit((char *)"Cannot Init GLFW", -1);
	this->window_width = window_width;
	this->window_height = window_height;
	windowptr = glfwCreateWindow(window_height, window_width, name, monitor,  share);
    if (!windowptr)
		_nsx_exit((char *)"Cannot Create The Window", -1);
	this->monitor = monitor;
	this->share = share;
	glfwMakeContextCurrent(windowptr);
	glfwSetKeyCallback(windowptr, key_callback_def);
    glMatrixMode(GL_PROJECTION);
}

GameContext::~GameContext()
{
    glfwTerminate();
}

int	GameContext::is_alive()
{
	if (!glfwWindowShouldClose(windowptr))
	{
		glfwGetFramebufferSize(windowptr, &this->window_width, &this->window_height);
		glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
		glfwPollEvents();
		return (1);
	}
	return (0);
}

void	GameContext::put_pixel(Vector2 pos, int color)
{

	(void)color;
	glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
	glColor4f(1, 1, 1, 1);
	glVertex2i(pos.x, pos.y);
    glEnd();
}

void	GameContext::Clear_Window()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void	GameContext::ViewPort(int x, int y, int width, int height)
{
   glViewport(x, y, width, height);
}

void	GameContext::Ortho_Projection(double left, double right, double bottom, double top, double zNear, double zFar)
{
    glOrtho(left, right, bottom, top, zNear, zFar);
}

void	GameContext::put_triangle(Vector2 pos1, Vector2 pos2, Vector2 pos3, int color)
{
	(void)color;
    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glVertex2i(pos1.x, pos1.y);
    glVertex2i(pos2.x, pos2.y);
    glVertex2i(pos3.x, pos3.y);
    glEnd();
}
int	GameContext::IsPressed(int key_ascii)
{
	return (glfwGetKey(windowptr, key_ascii));
}

Vector2	GameContext::GetMousePosition()
{
	Vector2	pos;
	double 	x;
	double 	y;

	glfwGetCursorPos(this->windowptr, &x, &y);
	pos = Vector2((int)x, (int)y);
	return (pos);
}