/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SquareShape.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 02:19:54 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/28 02:48:41 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NSX/SquareShape.hpp>
#include <NSX/Vector2.hpp>

SquareShape::SquareShape()
{
	this->position = Vector2::NewVectorZero();
}

SquareShape::SquareShape(Vector2 position, Vector2 size)
{
	this->size = size;
	this->position = position;
}

SquareShape::~SquareShape()
{
	
}