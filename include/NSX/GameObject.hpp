/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 02:17:56 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/28 19:23:17 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include <NSX/Vector2.hpp>
#include <NSX/Colors.hpp>

class GameObject
{
private:
	Vector2			position;
public:
	Vector2			size;
	Color			*buff_pixels;
	GameObject();
	GameObject(Vector2 position, Vector2 size);
	~GameObject();
};

#endif