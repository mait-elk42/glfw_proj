/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SquareShape.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 02:17:56 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/28 02:42:29 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARESHAPE_HPP
#define SQUARESHAPE_HPP
#include <NSX/Vector2.hpp>

class SquareShape
{
private:
	Vector2	size;
	Vector2	position;
public:
	SquareShape();
	SquareShape(Vector2 position, Vector2 size);
	~SquareShape();
};

#endif