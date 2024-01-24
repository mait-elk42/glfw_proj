LIBGFX=lib/libgfx.a
NAME=game

all: $(NAME)

$(NAME): $(LIBGFX)
	g++ main.cpp -o game $(LIBGFX) -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo -I include -D GL_SILENCE_DEPRECATION

$(LIBGFX):
	ar -crs $(LIBGFX) ./lib/objs/*
c:
	rm game
