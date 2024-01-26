# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 19:09:01 by mait-elk          #+#    #+#              #
#    Updated: 2024/01/26 12:49:39 by mait-elk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJ_PATH= $(CURDIR)/
INC_PATH= $(PROJ_PATH)/include
FLAGS= -Werror -Wextra -Wall 
HEADPATH= include/GFX/game.hpp 
SRCS= main.cpp srcs/game.cpp
OBJS= main.o $(SRCS:.cpp=.o) 
LIBGFX= lib/libgfx.a 
CC= c++
NAME= game 

all: $(NAME)

$(NAME): main.o $(LIBGFX)
	$(CC) main.o -o $(NAME) $(LIBGFX) -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo -L lib -lglfw3

main.o: main.cpp
	$(CC) -c main.cpp -o main.o -I $(INC_PATH)

$(LIBGFX): $(OBJS)
	ar -crs $(LIBGFX) $(OBJS)

srcs/%.o: srcs/%.cpp $(HEADPATH)
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC_PATH)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean