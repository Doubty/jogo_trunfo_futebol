#include <iostream> // incluído para usar funções de entrada e saída.
#include <fstream>  // incluído para trabalhar com a leitura de arquivos (somente!)
#include <random>  // incluído para gerar os números pseudoaleatórios
using namespace std; // usado para abreviar o cin e cout

struct baralho
{
	char nome[30];     // nome do jogador
	int idade;          // idade do jogador
	int gols;         // gols do jogador
	int titulos;      // titulos do jogador
	double salario;   // salario do jogador

};

// Função para calcular a pontuação das rodadas de acordo com o atributo selecionado.
void rodadas(int atributo, char jogador1[30], char jogador2[30], baralho * baralhoJogador1[], baralho * baralhoJogador2[], int tam, int carta,
	int * ptJogador1, int * ptJogador2, int prioridade, int rodadaFinal);

int main() {

	fstream fin; // Criação do objeto para leitura do arquivo binário

	// Variáveis para os nomes dos jogadores
	char jogador1[30]; 
	char jogador2[30];

	baralho * baralhoJogador1[4];  // Baralho do jogador 1
	baralho * baralhoJogador2[4];  // Baralho do jogador 2

	char escolha; // Variável de teste de partida, se quer jogar ou não.
	int atributo; // variável para seleção de atributos
	int ptJogador1=0, ptJogador2=0; // Variáveis para pontuação dos jogadores

	// Variáveis usadas como molde para ler do arquivo binário o cabeçaho e quantidade de cartas registradas.
	char cabecalho[] = "AAAAAAA";
	unsigned short qtdCartas = 0;

	// abrindo arquivo binário no modo de leitura
	fin.open("../baralho.data", ios_base::in | ios_base::binary);

	// lendo cabeçalho e quantidade de cartas registradas no arquivo.
	fin.read((char *)&cabecalho, sizeof(char) * 7);
	fin.read((char *)&qtdCartas, sizeof(unsigned short));

	// criando vetor dinâmico de cartas
	baralho * Baralho = new baralho[qtdCartas];


	if (fin.is_open())     // verificando se o arquivo foi aberto corretamente e é um arquivo de baralho de cartas
	{

		if (strcmp(cabecalho, "BARALHO") == 0) {

			for (int i = 0; i < qtdCartas; i++) {
				fin.read((char *)&Baralho[i], sizeof(baralho));
			}
			
			
		}
		else {
			cout << "O arquivo não é um baralho de cartas!" << endl;
			system("pause");
			return EXIT_FAILURE;

		}
	}else {

		cout << "O arquivo nao pode ser lido ou não existe!" << endl;
		system("pause");
		return EXIT_FAILURE;

	}

	// fechando arquivo 
	fin.close();
	
	// menu do jogo
	cout << "Super Trunfo Futebol" << endl;
	cout << "--------------------"<< endl;
	cout << "Iniciar nova partida? [S/N] ";
	cin >> escolha;

	if (escolha == 's' || escolha == 'S') {
		cout << "Jogador 1: ";
		cin >> jogador1;
		cout << "Jogador 2: ";
		cin >> jogador2;
		cout << "----------" << endl;
	}



	// Gerador de números pseudoaleatórios
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0,qtdCartas-1);
		
   // fim do gerador de números pesudoaleatórios
	
	
	// Loop para manter o fluxo das partidas
	while (escolha != 'n' && escolha !='N') {

		// preenchendo os baralhos dos jogadores com as cartas aleatórias
		for (int i = 0; i < 4; i++) {
			baralhoJogador1[i] = &(Baralho[dist(mt)]);
			baralhoJogador2[i] = &(Baralho[dist(mt)]);
		}

		// começo da primeira rodada
		cout << endl;
		cout << "[" << jogador1 << "]" << endl;
		cout << "Carta: " << (baralhoJogador1[0])->nome << endl;
		cout << "1. Idade" << endl;
		cout << "2. Gols" << endl;
		cout << "3. Titulos" << endl;
		cout << "4. Salario" << endl;

		cout << "Escolha o atributo: " << " [ ] \b\b\b";
		cin >> atributo;
		cout << endl;

		rodadas(atributo, jogador1, jogador2, baralhoJogador1, baralhoJogador2, 4, 0, &ptJogador1, &ptJogador2, 1,0);
		// fim da primeira rodada

		// começo da segunda rodada
		cout << endl;
		cout << "[" << jogador2 << "]" << endl;
		cout << "Carta: " << (baralhoJogador2[1])->nome << endl;
		cout << "1. Idade" << endl;
		cout << "2. Gols" << endl;
		cout << "3. Titulos" << endl;
		cout << "4. Salario" << endl;

		cout << "Escolha o atributo: " << " [ ] \b\b\b";
		cin >> atributo;
		cout << endl;

		rodadas(atributo, jogador1, jogador2, baralhoJogador1, baralhoJogador2, 4, 1, &ptJogador1, &ptJogador2, 2,0);
		// fim da segunda rodada

		// começo da terceira rodada
		cout << endl;
		cout << "[" << jogador1 << "]" << endl;
		cout << "Carta: " << (baralhoJogador1[2])->nome << endl;
		cout << "1. Idade" << endl;
		cout << "2. Gols" << endl;
		cout << "3. Titulos" << endl;
		cout << "4. Salario" << endl;

		cout << "Escolha o atributo: " << " [ ] \b\b\b";
		cin >> atributo;
		cout << endl;

		rodadas(atributo, jogador1, jogador2, baralhoJogador1, baralhoJogador2, 4, 2, &ptJogador1, &ptJogador2, 1,0);
		// fim da terceira rodada

		// começo da quarta rodada
		cout << endl;
		cout << "[" << jogador2 << "]" << endl;
		cout << "Carta: " << (baralhoJogador2[3])->nome << endl;
		cout << "1. Idade" << endl;
		cout << "2. Gols" << endl;
		cout << "3. Titulos" << endl;
		cout << "4. Salario" << endl;

		cout << "Escolha o atributo: " << " [ ] \b\b\b";
		cin >> atributo;
		cout << endl;

		rodadas(atributo, jogador1, jogador2, baralhoJogador1, baralhoJogador2, 4, 3, &ptJogador1, &ptJogador2, 2,1);
		// fim da quarta rodada


	
		// começo de nova partida
		// resetando pontuação para a próxima partida para não começar com a pontuacao anterior
		ptJogador1 = 0; 
		ptJogador2 = 0; 
		cout << endl;
		cout << "Super Trunfo Futebol" << endl;
		cout << "--------------------" << endl;
		cout << "Iniciar nova partida? [S/N] ";
		cin >> escolha;
		system("cls");
		cout << "Super Trunfo Futebol" << endl;
		cout << "--------------------" << endl;
	}

	delete[] Baralho; // Delete no vetor dinâmico de baralho para liberar a memória alocada após fim do programa

	system("pause");

	return 0;
}


// funcao para calcular os pontos das rodadas de acordo com o atributo selecionado, bem como, mostrar os dados de acordo com a vez do jogador.
void rodadas(int atributo, char jogador1[30], char jogador2[30], baralho * baralhoJogador1[], baralho * baralhoJogador2[], int tam, int carta, 
	int * ptJogador1, int * ptJogador2, int prioridade, int rodadaFinal) {

	switch (atributo) {

	case 1:

		// irá mostrar a carta e atributo da mesma de acordo com a vez ou prioridade do jogador na rodada atual.
		if (prioridade==1) {
			cout << "[" << jogador1 << "] " << (baralhoJogador1[carta])->nome << " | " << (baralhoJogador1[carta])->idade << endl;
			cout << "[" << jogador2 << "] " << (baralhoJogador2[carta])->nome << " | " << (baralhoJogador2[carta])->idade << endl;
			cout << endl;
		}
		else {
			cout << "[" << jogador2 << "] " << (baralhoJogador2[carta])->nome << " | " << (baralhoJogador2[carta])->idade << endl;
			cout << "[" << jogador1 << "] " << (baralhoJogador1[carta])->nome << " | " << (baralhoJogador1[carta])->idade << endl;
			cout << endl;
		}
	
		// gerador da pontuação de acordo com o atributo e comparação entre os atributos das cartas dos jogadores. 
		// Vai verificar qual carta ganha a rodade e incrementar a pontuação do jogador
		if (baralhoJogador1[carta]->idade == baralhoJogador2[carta]->idade) {
		// caso de empate
			*ptJogador1 += 1;
			*ptJogador2 += 1;
		}
		else if (baralhoJogador1[carta]->idade > baralhoJogador2[carta]->idade) {
			// caso onde o primeiro jogador ganha
			*ptJogador1 += 2;
		}
		else {
			// caso onde o segundo jogador ganha
			*ptJogador2 += 2;
		}
		// em caso de derrota, a pontuação não é incrementada.


		// estrutura pra selecionar quem vai ser mostrado primeiro de acordo com a prioridade da vez do jogador. 
		// Também irá verificar o fim da partida e mostrar a mensagem de fim de partida com a pontuação final.
		if (prioridade==1) {
			// irá aparecer o primeiro jogador, porque está na vez dele.
			if (rodadaFinal==0) {
				// não irá aparece final, porque a partida ainda não está terminada.
				cout << "Placar: " << jogador1 << " " << *ptJogador1 << " x " << *ptJogador2 << " " << jogador2 << endl;
				cout << endl;
				cout << "-----------------------------" << endl;
			}
			else {
				cout << "Final: " << jogador1 << " " << *ptJogador1 << " x " << *ptJogador2 << " " << jogador2 << endl;
				cout << endl;
				cout << "-----------------------------" << endl;
			}
		
		}
		else {
			// O inverso da primeira condição, no caso, irá aparecer o segundo jogador como primeiro.
			if (rodadaFinal==0) {
				cout << "Placar: " << jogador2 << " " << *ptJogador2 << " x " << *ptJogador1 << " " << jogador1 << endl;
				cout << endl;
				cout << "-----------------------------" << endl;
			}
			else {
				cout << "Final: " << jogador2 << " " << *ptJogador2 << " x " << *ptJogador1 << " " << jogador1 << endl;
				cout << endl;
				cout << "-----------------------------" << endl;
			}
		
		}

		break;

	case 2:

		if (prioridade == 1) {
			cout << "[" << jogador1 << "] " << (baralhoJogador1[carta])->nome << " | " << (baralhoJogador1[carta])->gols << endl;
			cout << "[" << jogador2 << "] " << (baralhoJogador2[carta])->nome << " | " << (baralhoJogador2[carta])->gols << endl;
			cout << endl;
		}
		else {
			cout << "[" << jogador2 << "] " << (baralhoJogador2[carta])->nome << " | " << (baralhoJogador2[carta])->gols << endl;
			cout << "[" << jogador1 << "] " << (baralhoJogador1[carta])->nome << " | " << (baralhoJogador1[carta])->gols << endl;
			cout << endl;
		}


		if (baralhoJogador1[carta]->gols == baralhoJogador2[carta]->gols) {

			*ptJogador1 += 1;
			*ptJogador2 += 1;
		}
		else if (baralhoJogador1[carta]->gols > baralhoJogador2[carta]->gols) {
			*ptJogador1 += 2;
		}
		else {
			*ptJogador2 += 2;
		}

		if (prioridade == 1) {
			if (rodadaFinal == 0) {
				cout << "Placar: " << jogador1 << " " << *ptJogador1 << " x " << *ptJogador2 << " " << jogador2 << endl;
				cout << endl;
				cout << "-----------------------------" << endl;
			}
			else {
				cout << "Final: " << jogador1 << " " << *ptJogador1 << " x " << *ptJogador2 << " " << jogador2 << endl;
				cout << endl;
				cout << "-----------------------------" << endl;
			}

		}
		else {
			if (rodadaFinal == 0) {
				cout << "Placar: " << jogador2 << " " << *ptJogador2 << " x " << *ptJogador1 << " " << jogador1 << endl;
				cout << endl;
				cout << "-----------------------------" << endl;
			}
			else {
				cout << "Final: " << jogador2 << " " << *ptJogador2 << " x " << *ptJogador1 << " " << jogador1 << endl;
				cout << endl;
				cout << "-----------------------------" << endl;
			}

		}

		break;

	case 3:

		if (prioridade == 1) {
			cout << "[" << jogador1 << "] " << (baralhoJogador1[carta])->nome << " | " << (baralhoJogador1[carta])->titulos << endl;
			cout << "[" << jogador2 << "] " << (baralhoJogador2[carta])->nome << " | " << (baralhoJogador2[carta])->titulos << endl;
			cout << endl;
		}
		else {
			cout << "[" << jogador2 << "] " << (baralhoJogador2[carta])->nome << " | " << (baralhoJogador2[carta])->titulos << endl;
			cout << "[" << jogador1 << "] " << (baralhoJogador1[carta])->nome << " | " << (baralhoJogador1[carta])->titulos << endl;
			cout << endl;
		}


		if (baralhoJogador1[carta]->titulos == baralhoJogador2[carta]->titulos) {

			*ptJogador1 += 1;
			*ptJogador2 += 1;
		}
		else if (baralhoJogador1[carta]->titulos  > baralhoJogador2[carta]->titulos) {
			*ptJogador1 += 2;
		}
		else {
			*ptJogador2 += 2;
		}

		if (prioridade == 1) {
			if (rodadaFinal == 0) {
				cout << "Placar: " << jogador1 << " " << *ptJogador1 << " x " << *ptJogador2 << " " << jogador2 << endl;
				cout << endl;
				cout << "-----------------------------" << endl;
			}
			else {
				cout << "Final: " << jogador1 << " " << *ptJogador1 << " x " << *ptJogador2 << " " << jogador2 << endl;
				cout << endl;
				cout << "-----------------------------" << endl;
			}

		}
		else {
			if (rodadaFinal == 0) {
				cout << "Placar: " << jogador2 << " " << *ptJogador2 << " x " << *ptJogador1 << " " << jogador1 << endl;
				cout << endl;
				cout << "-----------------------------" << endl;
			}
			else {
				cout << "Final: " << jogador2 << " " << *ptJogador2 << " x " << *ptJogador1 << " " << jogador1 << endl;
				cout << endl;
				cout << "-----------------------------" << endl;
			}

		}

		break;

	case 4:

		if (prioridade == 1) {
			cout << "[" << jogador1 << "] " << (baralhoJogador1[carta])->nome << " | " << (baralhoJogador1[carta])->salario << endl;
			cout << "[" << jogador2 << "] " << (baralhoJogador2[carta])->nome << " | " << (baralhoJogador2[carta])->salario << endl;
			cout << endl;
		}
		else {
			cout << "[" << jogador2 << "] " << (baralhoJogador2[carta])->nome << " | " << (baralhoJogador2[carta])->salario << endl;
			cout << "[" << jogador1 << "] " << (baralhoJogador1[carta])->nome << " | " << (baralhoJogador1[carta])->salario << endl;
			cout << endl;
		}

		
		if (baralhoJogador1[carta]->salario == baralhoJogador2[carta]->salario) {

			*ptJogador1 += 1;
			*ptJogador2 += 1;
		}
		else if (baralhoJogador1[carta]->salario  > baralhoJogador2[carta]->salario) {
			*ptJogador1 += 2;
		}
		else {
			*ptJogador2 += 2;
		}

		
		if (prioridade == 1) {
			
			if (rodadaFinal == 0) {
				
				cout << "Placar: " << jogador1 << " " << *ptJogador1 << " x " << *ptJogador2 << " " << jogador2 << endl;
				cout << endl;
				cout << "-----------------------------" << endl;
			}
			else {
				cout << "Final: " << jogador1 << " " << *ptJogador1 << " x " << *ptJogador2 << " " << jogador2 << endl;
				cout << endl;
				cout << "-----------------------------" << endl;
			}

		}
		else {
			
			if (rodadaFinal == 0) {
				cout << "Placar: " << jogador2 << " " << *ptJogador2 << " x " << *ptJogador1 << " " << jogador1 << endl;
				cout << endl;
				cout << "-----------------------------" << endl;
			}
			else {
				cout << "Final: " << jogador2 << " " << *ptJogador2 << " x " << *ptJogador1 << " " << jogador1 << endl;
				cout << endl;
				cout << "-----------------------------" << endl;
			}

		}

		break;

	default:
		cout << "Opcao invalida!!!" << endl;

	}
}
