CXX = g++
CXXFLAGS = -std=c++14 -Wall -g
SDL_CFLAGS := $(shell pkg-config --cflags sdl2 SDL2_image SDL2_mixer SDL2_ttf)
SDL_LDFLAGS := $(shell pkg-config --libs sdl2 SDL2_image SDL2_mixer SDL2_ttf)

SRC = $(shell find . -type f -name '*.cpp' \
    ! -path './addons/lua-5.4.8/*' \
    ! -path './addons/gzip/*' \
    ! -path './addons/zlib-1.3.1/*' \
    ! -path './addons/beep/*')
	
OBJ = $(SRC:.cpp=.o)

TARGET = dg2d

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(SDL_LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SDL_CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
