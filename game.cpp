#include <iostream>

void intro() {
	std::cout << "Você acorda em um local desconhecido, em sua frente há uma chave.\n";
	std::cout << "A sua direita, há uma porta.\n";
	std::cout << "O que você quer fazer?\n";
}

void show_options() {
	std::cout << "OPÇÕES:\n";
	std::cout << "\t*[A]brir a porta.\n";
	std::cout << "\t*[P]egar a chave.\n";
	std::cout << "\t*[O]lhar em volta.\n";
	std::cout << "\t+[M]ostrar opções.\n";
	std::cout << "\t+[S]air do jogo.\n";
}

void look_around() {
	std::cout << "Não há muito a se falar, tirando o fato de que:\n";
	std::cout << "Você está preso em um lugar escuro, há uma chave no chão, ";
	std::cout << "e uma porta que pode te libertar a sua direita.\n";
}

bool get_key() {
	std::cout << "Você pega a chave. Foi mais facil do que o esperado.\n";
	return true;
}

bool inspect_door(bool key_stat) {
	if(!key_stat) {
		std::cout << "Você não tem a chave para abrir a porta!\n";
		return false;
	}

	std::cout << "Você abre a porta que estava trancada.\n";
	std::cout << "Você está finalmente: LIVRE!\n";
	exit(0); // best that i could think
}

void make_action(char input) {
	static bool got_key = false;

	switch(input) {
		case 'A':
			inspect_door(got_key);
		break;
		case 'P':
			got_key = get_key();
		break;
		case 'O':
			look_around();
		break;
		case 'M':
			show_options();
		break;
		case 'S':
		break;
		default:
			std::cout << "Comando não identificado!\n";
		break;
	}
}

void run_game() {
	const bool game_loop = true;

	while(game_loop) {
		std::cout << ">> ";
		char input = ' ';
		std::cin >> input;

		make_action(input);
	}
}
