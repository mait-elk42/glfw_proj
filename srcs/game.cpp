/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:37:34 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/28 18:52:37 by mait-elk         ###   ########.fr       */
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
	this->FPS = 0;
	this->DeltaTime = 0;
	this->time.curr_time = glfwGetTime();
	this->time.last_time = glfwGetTime();
}

GameContext::~GameContext()
{
    glfwTerminate();
}

int	GameContext::is_alive()
{
	static int tfps = 0;
	static float second = 0;
	if (!glfwWindowShouldClose(windowptr))
	{
		this->time.curr_time = glfwGetTime();
		this->DeltaTime = this->time.curr_time - this->time.last_time;
		this->time.last_time = this->time.curr_time;
		glfwGetFramebufferSize(windowptr, &this->window_width, &this->window_height);
		glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
		glfwPollEvents();
		if (second < 1)
		{
			second += this->DeltaTime;
			tfps++;
		}
		else{
			this->FPS = tfps;
			second = 0;
			tfps = 0;
		}
		return (1);
	}
	return (0);
}

// void	GameContext::put_pixel(Vector2 pos, int color)
// {
// 	(void)color;
// 	glEnable(GL_POINT_SMOOTH);
// 	glEnable(GL_BLEND);
//     glBegin(GL_POINTS);
// 	glColor4i(255, 255, 255, 255);
// 	glVertex2i(pos.x, pos.y);
//     glEnd();
// }

void GameContext::put_pixel(Vector2 pos, Color c)
{
    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
    glColor3f((float)c.r /255.0f, (float)c.g /255.0f, (float)c.b /255.0f);
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

Vector2	GameContext::GetWindowPosition()
{
	Vector2 wpos;

	glfwGetWindowPos(windowptr, &wpos.x, &wpos.y);
	return (wpos);
}

Vector2	GameContext::GetWindowSize()
{
	Vector2 wsize;

	glfwGetWindowSize(windowptr, &wsize.x, &wsize.y);
	return (wsize);
}

Vector2	GameContext::GetFramebufferSize()
{
	Vector2 fbuffsize;

	glfwGetFramebufferSize(windowptr, &fbuffsize.x, &fbuffsize.y);
	return (fbuffsize);
}