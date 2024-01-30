/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Texture.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:35:44 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/30 22:45:11 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NSX/Texture.hpp>
# ifndef STB_IMAGE_IMPLEMENTATION
#  define STB_IMAGE_IMPLEMENTATION
#  include <NSX/stb_image.h>
#endif
Texture::Texture(const char *filename, Vector2 position, Vector2 scale)
{
	(void)scale;
	(void)position;
	this->imgptr = stbi_load(filename, &this->xy.x, &this->xy.y, &this->cmp, 0);
	if (!this->imgptr)
		{
			printf("ERROR IMAGE %s", filename);
			exit(-1);
		}
}