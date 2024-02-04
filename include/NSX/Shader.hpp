/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:09:31 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/04 13:30:44 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_HPP
#define SHADER_HPP
class Shader{
private:
	unsigned int	vertexShader_ID;
	unsigned int	fragmentShader_ID;
	unsigned int	VAO_ID;
	unsigned int	VBO_ID;
	unsigned int	EBO_ID;
public:
	unsigned int	COMPILER_ID;
					Shader(const char *vertextSource, const char *fragmentSource);
					~Shader();
	unsigned int	GetCompilerID();
	void			bind_varr();
	int				SetUniformInt(const char *univarname, int value);
	int				SetUniformFloat(const char *univarname, float value);
	void			DestroyShader();
};

#endif