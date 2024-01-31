/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Texture.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:35:44 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/31 17:51:18 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NSX/Texture.hpp>
# ifndef STB_IMAGE_IMPLEMENTATION
#  define STB_IMAGE_IMPLEMENTATION
#  include <NSX/stb_image.h>
#endif
# include <glad/glad.h>
# include <GLFW/glfw3.h>
# include <iostream>
# include <fstream>
# include <sstream>
# include <iostream>

static std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

Texture::Texture(const char *filename, Vector2 position, Vector2 scale)
{
	std::string v = get_file_contents("default.vert");
	std::string f = get_file_contents("default.frag");
	const char* vertexSource = v.c_str();
	const char* fragmentSource = f.c_str();
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	this->SHADER_PROG_ID = glCreateProgram();
	glAttachShader(this->SHADER_PROG_ID, vertexShader);
	glAttachShader(this->SHADER_PROG_ID, fragmentShader);
	glLinkProgram(this->SHADER_PROG_ID);
	// compileErrors(ID, "PROGRAM");

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

    // GLuint uniID = glGetUniformLocation(this->SHADER_PROG_ID, "scale");
	this->position = position;
	this->scale = scale;
	stbi_set_flip_vertically_on_load(true);
	this->imgptr = stbi_load(filename, &this->xy.x, &this->xy.y, &this->cmp, 0);
	if (!this->imgptr)
	{
		printf("ERROR IMAGE %s", filename);
		exit(-1);
	}
	glGenTextures(1, &ID_texture);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, ID_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, xy.x, xy.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->imgptr);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(this->imgptr);
	glBindTexture(GL_TEXTURE_2D, 1);
	// GLuint texUni = glGetUniformLocation(this->SHADER_PROG_ID, "tex0");
	// printf("%d\n", ID_texture);
}