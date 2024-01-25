/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:21:26 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/25 22:46:00 by mait-elk         ###   ########.fr       */
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
	windowptr = glfwCreateWindow(window_height, window_width, name, monitor,  share);
    if (!windowptr)
		_nsx_exit((char *)"Cannot Create The Window", -1);
	glfwMakeContextCurrent(windowptr);
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

	// rc = gc = bc = 0;
	glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
    glPointSize(0.1f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2i(x, y);
    glEnd();
}

#endif