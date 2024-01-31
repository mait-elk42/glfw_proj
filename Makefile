# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 19:09:01 by mait-elk          #+#    #+#              #
#    Updated: 2024/01/31 19:11:55 by mait-elk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJ_PATH=$(CURDIR)
INC_PATH=$(PROJ_PATH)/include
FLAGS=-Werror -Wextra -Wall
HEADPATH=$(INC_PATH)NSX/Game.hpp $(INC_PATH)NSX/Vector2.hpp $(INC_PATH)NSX/GameObject.hpp $(INC_PATH)NSX/Colors.hpp $(INC_PATH)NSX/Texture.hpp $(INC_PATH)NSX/Shader.hpp
SRCS=  srcs/Vector2.cpp srcs/Game.cpp srcs/GameObject.cpp srcs/Colors.cpp srcs/Texture.cpp srcs/Shader.cpp
OBJS=$(SRCS:%.cpp=%.o)
LIBNSX=lib/libNSX.so
CC=c++
NAME=game
MAIN= image_load_example

all: $(NAME)

$(NAME): $(MAIN).o $(LIBNSX)
	$(CC) $(MAIN).o -o $(NAME) -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo -L lib -lNSX  -L lib -lGLEW -lglfw3

srcs/%.o: srcs/%.cpp
	$(CC) $(FLAGS) -c -fPIC $< -o $@ -I $(INC_PATH)

srcs/%.o: srcs/%.c
	cc $(FLAGS) -c -fPIC $< -o $@ -I $(INC_PATH)

$(MAIN).o: $(MAIN).cpp
	$(CC) -c $(MAIN).cpp -o $(MAIN).o -I $(INC_PATH)

$(LIBNSX): $(OBJS)
	c++ -shared $(OBJS) srcs/glad.o -o $(LIBNSX) -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo -L lib -lglfw3 -lGLEW
clean:
	rm -f $(OBJS) $(MAIN).o

fclean: clean
	rm -f $(NAME) $(LIBNSX)

re: fclean all

.PHONY: clean