/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:13:26 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/04 13:31:13 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NSX/Game.hpp>
void compileErrors(unsigned int shader, const char type)
{
	GLint hasCompiled;
	char infoLog[1024];
	if (type != 'P')
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_LINKING_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
}

GLfloat vertices[] = {
    //     COORDINATES     /        COLORS      /   TexCoord  //
    0.1f, 0.1f, 0.0f,	0.0f, 0.0f, 1.0f,	1.0f, 1.0f, // Upper right corner
    -0.1f, 0.1f, 0.0f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f, // Upper left corner
    -0.1f, -0.1f, 0.0f,	1.0f, 0.0f, 0.0f,	0.0f, 0.0f, // Lower left corner
    0.1f, -0.1f, 0.0f,	1.0f, 1.0f, 1.0f,	1.0f, 0.0f  // Lower right corner
};

GLuint indices[] = {
    0, 2, 1, // Upper triangle
    0, 3, 2  // Lower triangle
};

Shader::Shader(const char *vertextSource, const char *fragmentSource)
{
	this->vertexShader_ID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(this->vertexShader_ID, 1, &vertextSource, NULL);
	glCompileShader(this->vertexShader_ID);
	compileErrors(this->vertexShader_ID, 0);

	this->fragmentShader_ID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(this->fragmentShader_ID, 1, &fragmentSource, NULL);
	glCompileShader(this->fragmentShader_ID);
	compileErrors(this->fragmentShader_ID, 0);

	this->COMPILER_ID = glCreateProgram();
	glAttachShader(this->COMPILER_ID, this->vertexShader_ID);
	glAttachShader(this->COMPILER_ID, this->fragmentShader_ID);
	glLinkProgram(this->COMPILER_ID);
	glDeleteShader(this->vertexShader_ID);
	glDeleteShader(this->fragmentShader_ID);
	compileErrors(this->COMPILER_ID, 'P');
	glUseProgram(this->COMPILER_ID);
	
	// glGenVertexArrays(1, &this->VAO_ID);
	// glBindVertexArray(this->VAO_ID);
}

Shader::~Shader()
{
	glDeleteProgram(this->COMPILER_ID);
}

void	Shader::bind_varr()
{
	glGenVertexArrays(1, &this->VAO_ID);

	glGenBuffers(1, &VBO_ID);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(this->VAO_ID);
	glGenBuffers(1, &EBO_ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, this->VBO_ID);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(VAO_ID);
}

void	Shader::DestroyShader()
{
	glDeleteVertexArrays(1, &this->VAO_ID);
	glDeleteBuffers(1, &this->VBO_ID);
	glDeleteBuffers(1, &this->EBO_ID);
	glDeleteProgram(this->COMPILER_ID);
}

unsigned int Shader::GetCompilerID()
{
	return (this->COMPILER_ID);
}


int	Shader::SetUniformInt(const char *univarname, int value)
{
	unsigned int address = glGetUniformLocation(this->GetCompilerID(), univarname);
	if ((int)address == -1)
		return (-1);
	glUniform1i(address, value);
	return (1);
}

int	Shader::SetUniformFloat(const char *univarname, float value)
{
	unsigned int address = glGetUniformLocation(this->GetCompilerID(), univarname);
	if ((int)address == -1)
		return (-1);
	glUniform1f(address, value);
	return (1);
}
