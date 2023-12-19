#include <iostream>
#include "constructs.h"

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

int get_key() {
	if(!GameConstruct::key) {
		std::cout << "Você pega a chave. Foi mais facil do que o esperado.\n";
		GameConstruct::key = true;
		return GameConstruct::key;
	}

	std::cout << "Você já pegou a chave, não tem nada mais aqui.\n";
	return 0;
}

int inspect_door(bool has_key) {
	if(!has_key) {
		std::cout << "Você não tem a chave para abrir a porta!\n";
		return 0;
	}

	std::cout << "Você abre a porta que estava trancada.\n";
	std::cout << "Você está finalmente: LIVRE!\n";
	return 1;
}

int main_loop(char input) {
	if(input == 'A') {
		inspect_door(GameConstruct::key);

		if(GameConstruct::key) {
			return 1;
		}
	}

	if(input == 'P')
		get_key();

	if(input == 'O')
		look_around();

	if(input == 'M')
		show_options();
	
	if(input == 'S') {
		GameConstruct::user_exit = true;
		return GameConstruct::user_exit;
	}

	return 0;
}
