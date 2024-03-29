/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:29:04 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/01 23:19:12 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NSX/Game.hpp>

Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{
	
}

Vector2 Vector2::NewVectorZero()
{
	return (Vector2(0, 0));
}

int Vector2::operator==(Vector2 v2)
{
	return (this->x == v2.x && this->y == v2.y);
}

int Vector2::operator!=(Vector2 v2)
{
	return (this->x != v2.x || this->y != v2.y);
}

Vector2 Vector2::operator-=(Vector2 v2)
{
	return (Vector2(this->x-v2.x, this->y-v2.y));
}

Vector2 Vector2::operator+=(Vector2 v2)
{
	return (Vector2(this->x+v2.x, this->y+v2.y));
}