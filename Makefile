comp := cc
src := src/main.c src/util.c src/n-balls.c
output := game.o

flags := -I/opt/homebrew/opt/raylib/include -L/opt/homebrew/opt/raylib/lib
flags += -lraylib -framework OpenGL -framework Cocoa -framework IOKit
flags += -framework CoreVideo

build:
	$(comp) $(src) -o $(output) $(flags)

