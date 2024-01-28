/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 02:19:54 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/28 19:30:51 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NSX/GameObject.hpp>
#include <NSX/Vector2.hpp>

GameObject::GameObject()
{
	this->position = Vector2Zero;
	this->size = Vector2Zero;
}

GameObject::GameObject(Vector2 position, Vector2 size)
{
	int			i;

	i = size.x * size.y;
	this->size = size;
	this->position = position;
	this->buff_pixels = new Color[i];
	i = 0;
	while (i < size.x * size.y)
	{
		this->buff_pixels[i].r = 255;
		this->buff_pixels[i].g = 255;
		this->buff_pixels[i].b = 0;
		i++;
	}
		
}

GameObject::~GameObject()
{
	
}