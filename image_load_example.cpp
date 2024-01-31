#include <NSX/Texture.hpp>
#include <NSX/Shader.hpp>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include <NSX/stb_image.h>

#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

void compileErrors(unsigned int shader, const char* type)
{
	GLint hasCompiled;
	char infoLog[1024];
	if (type[0] != 'P')
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

std::string get_file_contents(const char* filename)
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
// TEMP CLASSES
// class Shader
// {
// public:
// 	// Reference ID of the Shader Program
// 	GLuint ID;
// 	// Constructor that build the Shader Program from 2 different shaders
// 	Shader(const char* vertexFile, const char* fragmentFile)
// 	{
// 		// Convert the shader source strings into character arrays
// 		const char* vertexSource = get_file_contents(vertexFile).c_str();
// 		const char* fragmentSource = get_file_contents(fragmentFile).c_str();
// 		// Create Vertex Shader Object and get its reference
// 		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
// 		// Attach Vertex Shader source to the Vertex Shader Object
// 		glShaderSource(vertexShader, 1, &vertexSource, NULL);
// 		// Compile the Vertex Shader into machine code
// 		glCompileShader(vertexShader);
// 		// Checks if Shader compiled succesfully
// 		compileErrors(vertexShader, "VERTEX");
// 		// Create Fragment Shader Object and get its reference
// 		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
// 		// Attach Fragment Shader source to the Fragment Shader Object
// 		glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
// 		// Compile the Vertex Shader into machine code
// 		glCompileShader(fragmentShader);
// 		// Checks if Shader compiled succesfully
// 		compileErrors(fragmentShader, "FRAGMENT");
// 		// Create Shader Program Object and get its reference
// 		ID = glCreateProgram();
// 		// Attach the Vertex and Fragment Shaders to the Shader Program
// 		glAttachShader(ID, vertexShader);
// 		glAttachShader(ID, fragmentShader);
// 		// Wrap-up/Link all the shaders together into the Shader Program
// 		glLinkProgram(ID);
// 		// Checks if Shaders linked succesfully
// 		compileErrors(ID, "PROGRAM");
// 		// Delete the now useless Vertex and Fragment Shader objects
// 		glDeleteShader(vertexShader);
// 		glDeleteShader(fragmentShader);
// 	}
// 	// Activates the Shader Program
// 	void Activate()
// 	{
// 		glUseProgram(ID);
// 	}
// 	// Deletes the Shader Program
// 	void Delete()
// 	{
// 		glDeleteProgram(ID);
// 	}
// private:
// 	// Checks if the different Shaders have compiled properly
// 	void compileErrors(unsigned int shader, const char* type)
// 	{
// 		GLint hasCompiled;
// 		char infoLog[1024];
// 		if (type[0] != 'P')
// 		{
// 			glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
// 			if (hasCompiled == GL_FALSE)
// 			{
// 				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
// 				std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n" << infoLog << std::endl;
// 			}
// 		}
// 		else
// 		{
// 			glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
// 			if (hasCompiled == GL_FALSE)
// 			{
// 				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
// 				std::cout << "SHADER_LINKING_ERROR for:" << type << "\n" << infoLog << std::endl;
// 			}
// 		}
// 	}
// };
// class Texture
// {
// public:
// 	GLuint ID;
// 	GLenum type;
// 	Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType)
// 	{
// 		// Assigns the type of the texture ot the texture object
// 		type = texType;
// 		// Stores the width, height, and the number of color channels of the image
// 		int widthImg, heightImg, numColCh;
// 		// Flips the image so it appears right side up
// 		stbi_set_flip_vertically_on_load(true);
// 		// Reads the image from a file and stores it in bytes
// 		unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);
// 		// Generates an OpenGL texture object
// 		glGenTextures(1, &ID);
// 		// Assigns the texture to a Texture Unit
// 		glActiveTexture(slot);
// 		glBindTexture(texType, ID);
// 		// Configures the type of algorithm that is used to make the image smaller or bigger
// 		glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
// 		glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
// 		// Configures the way the texture repeats (if it does at all)
// 		glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
// 		glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);
// 		// Extra lines in case you choose to use GL_CLAMP_TO_BORDER
// 		// float flatColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
// 		// glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatColor);
// 		// Assigns the image to the OpenGL Texture object
// 		glTexImage2D(texType, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, bytes);
// 		// Generates MipMaps
// 		glGenerateMipmap(texType);
// 		// Deletes the image data as it is already in the OpenGL Texture object
// 		stbi_image_free(bytes);
// 		// Unbinds the OpenGL Texture object so that it can't accidentally be modified
// 		glBindTexture(texType, 0);
// 	}
// 	// Assigns a texture unit to a texture
// 	void texUnit(Shader& shader, const char* uniform, GLuint unit)
// 	{
// 		// Gets the location of the uniform
// 		GLuint texUni = glGetUniformLocation(shader.ID, uniform);
// 		// Shader needs to be activated before changing the value of a uniform
// 		shader.Activate();
// 		// Sets the value of the uniform
// 		glUniform1i(texUni, unit);
// 	}
// 	// Binds a texture
// 	void Bind()
// 	{
// 		glBindTexture(type, ID);
// 	}
// 	// Unbinds a texture
// 	void Unbind()
// 	{
// 		glBindTexture(type, 0);
// 	}
// 	// Deletes a texture
// 	void Delete()
// 	{
// 		glDeleteTextures(1, &ID);
// 	}
// };

class VBO
{
public:
	// Reference ID of the Vertex Buffer Object
	GLuint ID;
	// Constructor that generates a Vertex Buffer Object and links it to vertices
	VBO(GLfloat* vertices, GLsizeiptr size){
		glGenBuffers(1, &ID);
		glBindBuffer(GL_ARRAY_BUFFER, ID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	// Binds the VBO
	void Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, ID);
	}
	// Unbinds the VBO
	void Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	// Deletes the VBO
	void Delete()
	{
		glDeleteBuffers(1, &ID);
	}
};
class VAO
{
public:
	// ID reference for the Vertex Array Object
	GLuint ID;
	// Constructor that generates a VAO ID
	VAO()
	{
		glGenVertexArrays(1, &ID);
	}

	// Links a VBO Attribute such as a position or color to the VAO
	void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
	{
		VBO.Bind();
		glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
		glEnableVertexAttribArray(layout);
		VBO.Unbind();
	}
	// Binds the VAO
	void Bind()
	{
		glBindVertexArray(ID);
	}
	// Unbinds the VAO
	void Unbind()
	{
		glBindVertexArray(0);
	}
	// Deletes the VAO
	void Delete()
	{
		glDeleteVertexArrays(1, &ID);
	}
};
// class EBO
// {
// public:
// 	// ID reference of Elements Buffer Object
// 	GLuint ID;
// 	// Constructor that generates a Elements Buffer Object and links it to indices
// 	EBO(GLuint* indices, GLsizeiptr size)
// 	{
// 		glGenBuffers(1, &ID);
// 		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
// 		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
// 	}
// 	// Binds the EBO
// 	void Bind()
// 	{
// 		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
// 	}
// 	// Unbinds the EBO
// 	void Unbind()
// 	{
// 		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
// 	}
// 	// Deletes the EBO
// 	void Delete()
// 	{
// 		glDeleteBuffers(1, &ID);
// 	}
// };

// Vertices coordinates
GLfloat vertices[] = {
    //     COORDINATES     /        COLORS      /   TexCoord  //
    0.1f, 0.1f, 0.0f,	0.0f, 0.0f, 1.0f,	1.0f, 1.0f, // Upper right corner
    -0.1f, 0.1f, 0.0f,	0.0f, 1.0f, 0.0f,	0.0f, 1.0f, // Upper left corner
    -0.1f, -0.1f, 0.0f,	1.0f, 0.0f, 0.0f,	0.0f, 0.0f, // Lower left corner
    0.1f, -0.1f, 0.0f,	1.0f, 1.0f, 1.0f,	1.0f, 0.0f  // Lower right corner
};

// Indices for vertices order
GLuint indices[] = {
    0, 2, 1, // Upper triangle
    0, 3, 2  // Lower triangle
};

int main()
{
	// GLuint ID;
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Set GLFW to use OpenGL 3.3 Core Profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(1000, 1000, "OPENGL IMAGE TEST", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGL();

    // Generates Shader object using shaders default.vert and default.frag
    // Shader shaderProgram("default.vert", "default.frag");
	std::string v = get_file_contents("default.vert");
	std::string f = get_file_contents("default.frag");
	const char* vertexSource = v.c_str();
	const char* fragmentSource = f.c_str();

	Shader shader(vertexSource, fragmentSource);

	/**
	 * VERTEX SHADER CREATED .. *^ 
	*/
	// Create Vertex Shader Object and get its reference
	// GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// // Attach Vertex Shader source to the Vertex Shader Object
	// glShaderSource(vertexShader, 1, &vertexSource, NULL);
	// // Compile the Vertex Shader into machine code
	// glCompileShader(vertexShader);
	// // Checks if Shader compiled succesfully
	// // compileErrors(vertexShader, "VERTEX");
	/**
	 * VERTEX FRAGMENT CREATED .. *^ 
	*/
	// // Create Fragment Shader Object and get its reference
	// GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	// // Attach Fragment Shader source to the Fragment Shader Object
	// glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	// // Compile the Vertex Shader into machine code
	// glCompileShader(fragmentShader);
	// // Checks if Shader compiled succesfully
	// // compileErrors(fragmentShader, "FRAGMENT");
	/*
	* CREATING A COMPILER TO COMPILE THE SHADERS
	*/
	// Create Shader Program Object and get its reference
	// ID = glCreateProgram();
	// // Attach the Vertex and Fragment Shaders to the Shader Program
	// glAttachShader(ID, vertexShader);
	// glAttachShader(ID, fragmentShader);
	// // Wrap-up/Link all the shaders together into the Shader Program
	// glLinkProgram(ID);
	// Checks if Shaders linked succesfully
	// compileErrors(ID, "PROGRAM");

	/*
	* DELETING THE SHADERS AFTER REGISTER
	*/
	// Delete the now useless Vertex and Fragment Shader objects
	// glDeleteShader(vertexShader);
	// glDeleteShader(fragmentShader);

    // Generates Vertex Array Object and binds it
	GLuint VAO1_ID;
    // VAO VAO1;
	glGenVertexArrays(1, &VAO1_ID);
    // VAO1.Bind();
	glBindVertexArray(VAO1_ID);

    // Generates Vertex Buffer Object and links it to vertices
    // VBO VBO1(vertices, sizeof(vertices));
	GLuint VBO1_ID;
	glGenBuffers(1, &VBO1_ID);
	glBindBuffer(GL_ARRAY_BUFFER, VBO1_ID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // Generates Element Buffer Object and links it to indices
    // EBO EBO1(indices, sizeof(indices));
	GLuint EBO_ID;
	glGenBuffers(1, &EBO_ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Links VBO attributes such as coordinates and colors to VAO
    // VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	// VBO1.Bind();
	glBindBuffer(GL_ARRAY_BUFFER, VBO1_ID);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// VBO1.Unbind();
    // VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	// VBO1.Bind();
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// VBO1.Unbind();
    // VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	// VBO1.Bind();
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	// VBO1.Unbind();
    // Unbind all to prevent accidentally modifying them
    // VAO1.Unbind();
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
    // VBO1.Unbind();
    // EBO1.Unbind();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // Gets ID of uniform called "scale"
    // GLuint uniID = glGetUniformLocation(ID, "scale");
	GLuint ID_texture;
    // Texture popCat("textures/marimonda.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	// Assigns the type of the texture ot the texture object

		// Stores the width, height, and the number of color channels of the image
		int widthImg, heightImg, numColCh;
		// Flips the image so it appears right side up
		// Reads the image from a file and stores it in bytes
		stbi_set_flip_vertically_on_load(true);
		unsigned char* bytes = stbi_load("textures/player.png", &widthImg, &heightImg, &numColCh, 0);
		// Texture img("textures/marimonda.png", Vector2(100, 100), Vector2One);
		// Generates an OpenGL texture object
		glGenTextures(1, &ID_texture);
		// Assigns the texture to a Texture Unit
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, ID_texture);

		// Configures the type of algorithm that is used to make the image smaller or bigger
		// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		// Configures the way the texture repeats (if it does at all)
		// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// Extra lines in case you choose to use GL_CLAMP_TO_BORDER
		// float flatColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
		// glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatColor);

		// Assigns the image to the OpenGL Texture object
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
		// Generates MipMaps
		glGenerateMipmap(GL_TEXTURE_2D);

		// Deletes the image data as it is already in the OpenGL Texture object
		stbi_image_free(bytes);

		// Unbinds the OpenGL Texture object so that it can't accidentally be modified
//		 glBindTexture(GL_TEXTURE_2D, 0);
    // popCat.texUnit(shaderProgram, "tex0", 0);
		// glUseProgram(shader.GetCompilerID());
		GLuint texUni = glGetUniformLocation(shader.GetCompilerID(), "tex0");
		// Shader needs to be activated before changing the value of a uniform
		// Sets the value of the uniform
		glUniform1i(texUni, 1);
    // Main while loop
    while (!glfwWindowShouldClose(window))
    {
		// glOrtho(0, 1000, 1000, 0, -10, 10);
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // shaderProgram.Activate();
		// glUseProgram(ID);
        // glUniform1f(uniID, 3);
        // popCat.Bind();
		glBindTexture(GL_TEXTURE_2D, ID_texture);

        // VAO1.Bind();
		glBindVertexArray(VAO1_ID);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // VAO1.Delete();
	glDeleteVertexArrays(1, &VAO1_ID);
    // VBO1.Delete();
	glDeleteBuffers(1, &VBO1_ID);
    // EBO1.Delete();
	glDeleteBuffers(1, &EBO_ID);
    // popCat.Delete();
	glDeleteTextures(1, &ID_texture);
    // shaderProgram.Delete();
	/**
	 * ITS WILL DELETE WHEN DESTROY THE SHADER CLASS *&^ OR YOU CAN DESTROY IT MANUALLY
	*/
	shader.DestroyCompiler();
	

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
