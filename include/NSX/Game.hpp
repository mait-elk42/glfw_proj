/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:21:26 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/03 03:49:33 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <NSX/Vector2.hpp>
#include <NSX/Shader.hpp>
#include <NSX/GameObject.hpp>
#include <NSX/Texture.hpp>
#include <NSX/Colors.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>


typedef struct __Time{
	float	curr_time;
	float	last_time;
} Time;

class GameContext
{
private:
	GLFWmonitor*	monitor;
	GLFWwindow*		share;
	Time			time;
public:
	float			DeltaTime;
	int				FPS;
	int				window_width;
	int				window_height;
	GLFWwindow		*windowptr;
			GameContext(int window_width, int window_height, char *name, GLFWmonitor* monitor, GLFWwindow* share);
			~GameContext();
	Vector2	GetMousePosition();
	Vector2	GetWindowPosition();
	Vector2	GetWindowSize();
	Vector2	GetFramebufferSize();
	int		is_alive();
	void	put_pixel(Vector2 pos, Color c);
	void	put_triangle(Vector2 pos1, Vector2 pos2, Vector2 pos3, int color);
	void	put_square(GameObject object);
	void	Clear_Window();
	void	ViewPort(int x, int y, int width, int height);
	int		IsPressed(int key_ascii);
	void	Ortho_Projection(double left, double right, double bottom, double top, double zNear, double zFar);
	void	DrawBuffer();
};

#endif