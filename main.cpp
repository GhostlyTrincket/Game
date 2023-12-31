#include <iostream>
#include "game.h"

int main() {
	intro();
	show_options();

	const bool game_loop = true;

	while(game_loop) {
		std::cout << ">> ";
		char input = ' ';
		std::cin >> input;

		make_action(input);
	}

	return 0;
}
