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

bool get_key(bool key_stat) {
	if(!key_stat) {
		std::cout << "Você pega a chave. Foi mais facil do que o esperado.\n";
	} else {
		std::cout << "Você já pegou a chave, não tem nada mais aqui.\n";
	}

	return true;
}

bool inspect_door(bool has_key) {
	if(!has_key) {
		std::cout << "Você não tem a chave para abrir a porta!\n";
		return false;
	}

	std::cout << "Você abre a porta que estava trancada.\n";
	std::cout << "Você está finalmente: LIVRE!\n";
	return true;
}

int make_action(char input, bool key_stat) {
	static bool tmp_key_stat = key_stat;

	if(input == 'A') {
		inspect_door(tmp_key_stat);
		return tmp_key_stat;
	}

	if(input == 'P')
		tmp_key_stat = get_key(key_stat);

	if(input == 'O')
		look_around();

	if(input == 'M')
		show_options();
	
	if(input == 'S') {
		tmp_key_stat = true;
		return tmp_key_stat;
	}

	return 0;
}
