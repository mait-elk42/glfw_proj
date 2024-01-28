/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 02:17:56 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/28 16:06:05 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include <NSX/Vector2.hpp>

class GameObject
{
private:
	// unsigned char	*buffer;
	Vector2			size;
	Vector2			position;
public:
	GameObject();
	GameObject(Vector2 position, Vector2 size);
	~GameObject();
};

#endif