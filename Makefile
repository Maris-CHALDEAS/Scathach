.DEFAULT_GOAL := run

CC = clang++
CFLAGS = -Wall -Wextra -std=c++20

scathach:
	$(CC) $(CFLAGS) src/Main.cpp src/Graphics.cpp $$(pkg-config --cflags --libs sdl2) -o build/scathach

run: scathach
	./build/scathach

clean:
	rm ./build/* *.o
