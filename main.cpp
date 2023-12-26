#include <iostream>
#include "game.h"

int main() {
	intro();
	show_options();

	const bool game_loop = true;
	bool player_key = false;
	bool ending_unlocked = false;

	while(game_loop) {
		std::cout << ">> ";
		char input = ' ';
		std::cin >> input;

		ending_unlocked = make_action(input, player_key);

		if(ending_unlocked)
			break;
	}

	return 0;
}
