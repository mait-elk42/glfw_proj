/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Texture.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:32:52 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/03 03:20:26 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_HPP
#define TEXTURE_HPP
#include <NSX/Game.hpp>

class Texture{
private:
	unsigned char 	*imgptr;
	unsigned int	ID_texture;
	int 			cmp;
	int 			img_width;
	int 			img_height;
	Vector2 		position;
	Vector2 		scale;
public:
	Texture(const char *filename, Vector2 position, Vector2 scale);
	void	Bind();
};

#endif