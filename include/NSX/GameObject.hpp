/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 02:17:56 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/30 00:18:41 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include <NSX/Vector2.hpp>
#include <NSX/Colors.hpp>

class GameObject
{
// private:
public:
	Vector2			position;
	Vector2			size;
	Color			color;
	GameObject();
	GameObject(Vector2 position, Vector2 size, Color color);
	~GameObject();
};

#endif