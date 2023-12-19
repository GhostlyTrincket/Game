OUT_BIN=game.out
CPP_FILES=main.cpp game.cpp constructs.cpp
CPP_FLAGS=-Wall -Wextra -Weffc++ -Werror -o $(OUT_BIN)

game: main.cpp
	g++ $(CPP_FLAGS) $(CPP_FILES)
