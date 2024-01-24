all:
	g++ main.cpp -o game -L. -lglfw3 -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo -I include -D GL_SILENCE_DEPRECATION