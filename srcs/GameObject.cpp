/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 02:19:54 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/30 00:19:45 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NSX/GameObject.hpp>
#include <NSX/Vector2.hpp>

GameObject::GameObject()
{
	this->position = Vector2Zero;
	this->size = Vector2Zero;
}

GameObject::GameObject(Vector2 position, Vector2 size, Color color)
{
	this->size = size;
	this->position = position;
	this->color = color;
}

GameObject::~GameObject()
{
	
}