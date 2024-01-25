# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 19:09:01 by mait-elk          #+#    #+#              #
#    Updated: 2024/01/25 22:14:30 by mait-elk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Werror -Wextra -Wall 
HEADPATH= include/GFX/test.hpp include/GFX/game.hpp 
SRCS= main.c srcs/test.c 
OBJS= main.o $(SRCS:.c=.o) 
LIBGFX= lib/libgfx.a 
CC= c++
NAME= game 

all: $(NAME)

$(NAME): main.o $(LIBGFX) 
	$(CC) main.o -o $(NAME) $(LIBGFX) -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo -L lib -lglfw3

main.o: main.cpp
	$(CC) -c main.cpp -o main.o -I include

$(LIBGFX): $(OBJS)
	ar -crs $(LIBGFX) $(OBJS)

%.o: %.c $(HEADPATH)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean