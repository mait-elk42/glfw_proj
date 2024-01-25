/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:21:26 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/25 20:05:32 by mait-elk         ###   ########.fr       */
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
	GLFWwindow		*windowptr;
	GLFWmonitor*	monitor;
	GLFWwindow*		share;
	void (*err_catch)(const char *);
	int				window_width;
	int				window_height;
public:
	GameContext(int window_width, int window_height, char *name, GLFWmonitor* monitor, GLFWwindow* share);
	~GameContext();
	void	error_catch(void (*f)(const char *));
	int		is_alive();
};

GameContext::GameContext(int window_width, int window_height, char *name, GLFWmonitor* monitor, GLFWwindow* share)
{
	if (!glfwInit())
	{
		if (err_catch)
			err_catch((char *)"Cannot Init GLFW");
		else
			_nsx_exit((char *)"Cannot Init GLFW", -1);
	}
	windowptr = glfwCreateWindow(window_height, window_width, name, monitor,  share);
    if (!windowptr)
	{
		if (err_catch)
			err_catch((char *)"Cannot Create The Window");
		else
			_nsx_exit((char *)"Cannot Create The Window", -1);
	}
	glfwMakeContextCurrent(windowptr);
}

GameContext::~GameContext()
{
    glfwTerminate();
}

void	GameContext::error_catch(void (*f)(const char *))
{
	err_catch = f;
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

#endif