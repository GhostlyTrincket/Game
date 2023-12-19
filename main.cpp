#include <iostream>
#include "game.h"
#include "constructs.h"

int main() {
	intro();
	show_options();

	while(true) {
		std::cout << ">> ";
		char input = ' ';
		std::cin >> input;

		if(main_loop(input) || GameConstruct::user_exit)
			break;
	}

	return 0;
}
