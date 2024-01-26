/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:21:26 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/26 12:51:57 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP
#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>

static void	_nsx_exit(char *msg, int status)
{
	printf("\nError :\n [ %s ]", msg);
	exit(status);
}

static void	key_callback_def(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)mods;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

class GameContext
{
private:
	GLFWmonitor*	monitor;
	GLFWwindow*		share;
	void (*err_catch)(const char *);
	int				window_width;
	int				window_height;
public:
	GLFWwindow		*windowptr;
	GameContext(int window_width, int window_height, char *name, GLFWmonitor* monitor, GLFWwindow* share);
	~GameContext();
	int		is_alive();
	void	put_pixel(int x, int y, int color);
};

GameContext::GameContext(int window_width, int window_height, char *name, GLFWmonitor* monitor, GLFWwindow* share)
{
	err_catch = NULL;
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
}

GameContext::~GameContext()
{
    glfwTerminate();
}

int	GameContext::is_alive()
{
	if (!glfwWindowShouldClose(windowptr))
	{
		glfwPollEvents();
		return (1);
	}
	return (0);
}

void	GameContext::put_pixel(int x, int y, int color)
{
	// float rc, gc, bc;

	(void)color;
	// rc = gc = bc = 0;
	glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
    glPointSize(0.1f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2i(x, y);
    glEnd();
}

class Vector2 {
private:
	int	x;
	int	y;

public:
	Vector2(int x, int y);
	~Vector2();
	void ReInitialize(int x, int y);
};

#endif