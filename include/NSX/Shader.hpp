/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:09:31 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/03 05:23:14 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_HPP
#define SHADER_HPP
class Shader{
private:
	unsigned int	COMPILER_ID;
	unsigned int	vertexShader_ID;
	unsigned int	fragmentShader_ID;
	unsigned int	VAO_ID;
	unsigned int	VBO_ID;
	unsigned int	EBO_ID;
public:
					Shader(const char *vertextSource, const char *fragmentSource);
					~Shader();
	unsigned int	GetCompilerID();
	void			bind_varr();
	int				SetUniform(const char *univarname, float value);
	void			DestroyShader();
};

#endif