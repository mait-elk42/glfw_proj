/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:09:31 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/31 19:18:20 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_HPP
#define SHADER_HPP
class Shader{
private:
	unsigned int	COMPILER_ID;
	unsigned int	vertexShader_ID;
	unsigned int	fragmentShader_ID;
public:
	Shader();
};

#endif