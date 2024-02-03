/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:48:20 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/03 05:27:26 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NSX/Game.hpp>

#define W_HEIGHT 500
#define W_WIDTH 500

int	main2() {
    int	speed = 400;
    int gravity = 400;
	int in_floor = 0;
	int jumping = 0;


	GameObject square(Vector2(100, 100), Vector2(50, 50), Color(200, 200, 100));
	GameObject enemy(Vector2(500, 100), Vector2(50, 50), Color(255, 0, 0));
	GameContext *game = new GameContext(500, 1000, (char *)"GAME ! OSF", NULL, NULL);
	// glfwSetInputMode(game->windowptr, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	while (game->is_alive())
	{
		game->ViewPort(0, 0, game->window_width, game->window_height);
		game->Ortho_Projection(0, game->GetWindowSize().x, game->GetWindowSize().y, 0, -10, 10);
		game->Clear_Window();

		if (game->IsPressed('W'))
				square.position.y -= speed * game->DeltaTime;
		if (game->IsPressed('A'))
				square.position.x -= speed * game->DeltaTime;
		if (game->IsPressed('S'))
				square.position.y += speed * game->DeltaTime;
		if (game->IsPressed('D'))
				square.position.x += speed * game->DeltaTime;
		
		if (square.position.y + square.size.y < game->GetWindowSize().y)
			square.position.y += game->DeltaTime * (gravity);
		else
			in_floor = 1;
		if (enemy.position.y + enemy.size.y < game->GetWindowSize().y)
			enemy.position.y += game->DeltaTime * (gravity);
		if ((game->IsPressed(' ') && in_floor) || jumping)
		{
			if (jumping++ < 10)
				square.position.y-= game->DeltaTime * (900);
			else
				in_floor = jumping = 0;
		}

		game->put_square(square);
		game->put_square(enemy);
		glfwSwapBuffers(game->windowptr);
	}
	return 0;
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

int main()
{
	GameContext context(1000, 1000, "GAME", NULL, NULL);
	std::string v = get_file_contents("default.vert");
	std::string f = get_file_contents("default.frag");
	const char* vertexSource = v.c_str();
	const char* fragmentSource = f.c_str();

	Texture texture("textures/image.png", Vector2One, Vector2One);
	Shader shader(vertexSource, fragmentSource);
	shader.SetUniform("tex0", 1);
    while (context.is_alive())
    {
		context.Ortho_Projection(0, context.GetWindowSize().x, context.GetWindowSize().y, 0, -10, 10);
		context.ViewPort(0, 0, context.window_width, context.window_height);
        context.Clear_Window();
		texture.Bind();
		shader.bind_varr();
		context.DrawBuffer();
	}

	shader.DestroyShader();

    glfwDestroyWindow(context.windowptr);
    glfwTerminate();

    return 0;
}