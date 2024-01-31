/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:13:26 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/31 22:28:39 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GLFW/glfw3.h>
#include <NSX/Shader.hpp>
// #include <glad/glad.h>

Shader::Shader(const char *vertextSource, const char *fragmentSource)
{
	this->COMPILER_ID = glCreateProgram();
	this->vertexShader_ID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(this->vertexShader_ID, 1, &vertextSource, NULL);
	glCompileShader(this->vertexShader_ID);
	this->fragmentShader_ID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(this->fragmentShader_ID, 1, &fragmentSource, NULL);
	glCompileShader(this->fragmentShader_ID);
	glAttachShader(this->COMPILER_ID, this->vertexShader_ID);
	glAttachShader(this->COMPILER_ID, this->fragmentShader_ID);
	glLinkProgram(this->COMPILER_ID);
	glDeleteShader(this->vertexShader_ID);
	glDeleteShader(this->fragmentShader_ID);
	glUseProgram(this->COMPILER_ID);

	// glGenVertexArrays(1, &this->VAO_ID);
	// glBindVertexArray(this->VAO_ID);
}

Shader::~Shader()
{
	glDeleteProgram(this->COMPILER_ID);
}

void	Shader::DestroyCompiler()
{
	glDeleteProgram(this->COMPILER_ID);
}

unsigned int Shader::GetCompilerID()
{
	return (this->COMPILER_ID);
}