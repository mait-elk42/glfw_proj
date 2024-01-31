/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Texture.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:32:52 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/31 16:54:31 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_HPP
#define TEXTURE_HPP
#include <NSX/Vector2.hpp>
class Texture{
public:
	unsigned int	SHADER_PROG_ID;
	unsigned char 	*imgptr;
	unsigned int	ID_texture;
	int 			cmp;
	int 			img_width;
	int 			imt_height;
	Vector2 		position;
	Vector2 		xy;
	Vector2 		scale;
	Texture(const char *filename, Vector2 position, Vector2 scale);
};

#endif