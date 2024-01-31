/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:28:50 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/31 16:41:17 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#define Vector2Zero  Vector2::NewVectorZero()
#define Vector2One  Vector2(1, 1)

class Vector2
{
private:
	
public:
	int	x;
	int	y;
				Vector2();
				Vector2(int x, int y);
				~Vector2();
	static		Vector2 NewVectorZero();
	int			operator==(Vector2 v2);
	int			operator!=(Vector2 v2);
	Vector2		operator-=(Vector2 v2);
	Vector2		operator+=(Vector2 v2);
};


#endif