.DEFAULT_GOAL := run

CC = clang++
CFLAGS = -Wall -Wextra -std=c++20

scathach:
	$(CC) $(CFLAGS) src/Main.cpp src/Graphics.cpp src/Game.cpp src/Input.cpp src/Sprite.cpp src/AnimatedSprites.cpp $$(pkg-config --cflags --libs sdl2 SDL2_image) -o build/scathach

path: scathach
	ln -sfn ../content build/content

run: path
	./build/scathach

clean:
	rm ./build/* *.o
