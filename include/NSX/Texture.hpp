/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Texture.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:32:52 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/30 22:40:09 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_HPP
#define TEXTURE_HPP
#include <NSX/Vector2.hpp>
class Texture{
public:
	void *imgptr;
	Vector2 position;
	Vector2 xy;
	int cmp;
	Vector2 scale;
	Texture(const char *filename, Vector2 position, Vector2 scale);
};

#endif