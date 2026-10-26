compiler := cc

src := src/main.c
src += src/util.c
src += src/n-balls.c

output := app.obj

flags := -Wall -Wextra -O3
flags += -I/opt/homebrew/opt/raylib/include
flags += -L/opt/homebrew/opt/raylib/lib
flags += -lraylib -framework OpenGL -framework Cocoa -framework IOKit
flags += -framework CoreVideo

build:
	$(compiler) $(src) -o $(output) $(flags)

