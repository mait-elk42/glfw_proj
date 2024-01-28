# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 19:09:01 by mait-elk          #+#    #+#              #
#    Updated: 2024/01/28 16:03:23 by mait-elk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJ_PATH=$(CURDIR)
INC_PATH=$(PROJ_PATH)/include
FLAGS=-Werror -Wextra -Wall
HEADPATH=$(INC_PATH)NSX/Game.hpp $(INC_PATH)NSX/Vector2.hpp $(INC_PATH)NSX/GameObject.hpp
SRCS=  srcs/Vector2.cpp srcs/Game.cpp srcs/GameObject.cpp 
OBJS=$(SRCS:%.cpp=%.o)
LIBNSX=lib/libNSX.so
CC=c++
NAME=game

all: $(NAME)

$(NAME): main.o $(LIBNSX)
	$(CC) main.o -o $(NAME) -L lib -lNSX

srcs/%.o: srcs/%.cpp
	$(CC) $(FLAGS) -c -fPIC $< -o $@ -I $(INC_PATH)

main.o: main.cpp
	$(CC) -c main.cpp -o main.o -I $(INC_PATH)

$(LIBNSX): $(OBJS)
	c++ -shared $(OBJS) -o $(LIBNSX) -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo -L lib -lglfw3

clean:
	rm -f $(OBJS) main.o

fclean: clean
	rm -f $(NAME) $(LIBNSX)

re: fclean all

.PHONY: clean