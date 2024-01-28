/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:28:50 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/28 02:47:20 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2
{
private:
	
public:
	int	x;
	int	y;
			Vector2();
			Vector2(int x, int y);
			~Vector2();
	static	Vector2 NewVectorZero();
	int		operator==(Vector2 v2);
	int		operator!=(Vector2 v2);
};

#endif