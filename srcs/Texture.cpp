/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Texture.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:35:44 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/04 00:37:10 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NSX/Game.hpp>
#include <NSX/stbi_loader_image.hpp>

Texture::Texture(const char *filename, Vector2 position, Vector2 scale)
{
	this->position = position;
	this->scale = scale;
	stbi_set_flip_vertically_on_load(true);
	this->imgptr = stbi_load(filename, &this->img_width, &this->img_height, &this->cmp, STBI_rgb_alpha);
	if (!this->imgptr)
	{
		printf("ERROR IMAGE %s", filename);
		exit(-1);
	}
	glGenTextures(1, &ID_texture);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, ID_texture);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->img_width, this->img_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->imgptr);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(this->imgptr);
}

void	Texture::Bind()
{
	glBindTexture(GL_TEXTURE_2D, this->ID_texture);
    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}