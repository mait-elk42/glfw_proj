/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:33:39 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/28 19:23:43 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
#define COLORS_HPP

class Color{
public:
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
		Color();
		Color(unsigned char r, unsigned char g, unsigned char b);
		~Color();
	// int	To_Integer();
	// static int	RGBTo_Integer(unsigned char r, unsigned char g, unsigned char b);
};

#endif