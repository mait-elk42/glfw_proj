/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:21:26 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/28 04:14:54 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP
#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <NSX/Vector2.hpp>
#include <NSX/SquareShape.hpp>

class GameContext
{
private:
	GLFWmonitor*	monitor;
	GLFWwindow*		share;
	int				window_width;
	int				window_height;
public:
	GLFWwindow		*windowptr;
			GameContext(int window_width, int window_height, char *name, GLFWmonitor* monitor, GLFWwindow* share);
			~GameContext();
	Vector2	GetMousePosition();
	int		is_alive();
	void	put_pixel(Vector2 pos, int color);
	void	put_triangle(Vector2 pos1, Vector2 pos2, Vector2 pos3, int color);
	void	Clear_Window();
	void	ViewPort(int x, int y, int width, int height);
	int		IsPressed(int key_ascii);
	void	Ortho_Projection(double left, double right, double bottom, double top, double zNear, double zFar);
};

#endif