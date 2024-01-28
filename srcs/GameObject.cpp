/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 02:19:54 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/28 16:06:13 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NSX/GameObject.hpp>
#include <NSX/Vector2.hpp>

GameObject::GameObject()
{
	this->position = Vector2::NewVectorZero();
}

GameObject::GameObject(Vector2 position, Vector2 size)
{
	this->size = size;
	this->position = position;
}

GameObject::~GameObject()
{
	
}