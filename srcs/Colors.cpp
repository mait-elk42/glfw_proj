/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:36:11 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/28 19:23:55 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NSX/Colors.hpp>

Color::Color()
{
	
}

Color::Color(unsigned char r, unsigned char g, unsigned char b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

Color::~Color()
{
	
}

// int	Color::To_Integer()
// {
// 	int	rgb;

// 	rgb = 0;
// 	rgb = (rgb += this->r) << 16;
// 	rgb = (rgb += this->g) << 8;
// 	rgb = (rgb += this->b);
// 	return (rgb);
// }

// int	RGBTo_Integer(unsigned char r, unsigned char g, unsigned char b)
// {
// 	int	rgb;

// 	rgb = 0;
// 	rgb = (rgb += r) << 16;
// 	rgb = (rgb += g) << 8;
// 	rgb = (rgb += b);
// 	return (rgb);
// }
