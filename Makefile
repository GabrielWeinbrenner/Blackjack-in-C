game:
	g++ src/*.cpp -o play -std=c++11 -Wall -g -I include -L lib -l SDL2-2.0.0 -l SDL2_image -l SDl2_ttf -lm
