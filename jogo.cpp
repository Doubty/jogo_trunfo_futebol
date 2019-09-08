#include <iostream> // inclu�do para usar fun��es de entrada e sa�da.
#include <fstream>  // inclu�do para trabalhar com a leitura de arquivos (somente!)
#include <random>  // inclu�do para gerar os n�meros pseudoaleat�rios
using namespace std; // usado para abreviar o cin e cout

struct baralho
{
	char nome[30];     // nome do jogador
	int idade;          // idade do jogador
	int gols;         // gols do jogador
	int titulos;      // titulos do jogador
	double salario;   // salario do jogador

};

// Fun��o para calcular a pontua��o das rodadas de acordo com o atributo selecionado.
void rodadas(int atributo, char jogador1[30], char jogador2[30], baralho * baralhoJogador1[], baralho * baralhoJogador2[], int tam, int carta,
	int * ptJogador1, int * ptJogador2, int prioridade, int rodadaFinal);

int main() {

	fstream fin; // Cria��o do objeto para leitura do arquivo bin�rio

	// Vari�veis para os nomes dos jogadores
	char jogador1[30]; 
	char jogador2[30];

	baralho * baralhoJogador1[4];  // Baralho do jogador 1
	baralho * baralhoJogador2[4];  // Baralho do jogador 2

	char escolha; // Vari�vel de teste de partida, se quer jogar ou n�o.
	int atributo; // vari�vel para sele��o de atributos
	int ptJogador1=0, ptJogador2=0; // Vari�veis para pontua��o dos jogadores

	// Vari�veis usadas como molde para ler do arquivo bin�rio o cabe�aho e quantidade de cartas registradas.
	char cabecalho[] = "AAAAAAA";
	unsigned short qtdCartas = 0;

	// abrindo arquivo bin�rio no modo de leitura
	fin.open("../baralho.data", ios_base::in | ios_base::binary);

	// lendo cabe�alho e quantidade de cartas registradas no arquivo.
	fin.read((char *)&cabecalho, sizeof(char) * 7);
	fin.read((char *)&qtdCartas, sizeof(unsigned short));

	// criando vetor din�mico de cartas
	baralho * Baralho = new baralho[qtdCartas];


	if (fin.is_open())     // verificando se o arquivo foi aberto corretamente e � um arquivo de baralho de cartas
	{

		if (strcmp(cabecalho, "BARALHO") == 0) {

			for (int i = 0; i < qtdCartas; i++) {
				fin.read((char *)&Baralho[i], sizeof(baralho));
			}
			
			
		}
		else {
			cout << "O arquivo n�o � um baralho de cartas!" << endl;
			system("pause");
			return EXIT_FAILURE;

		}
	}else {

		cout << "O arquivo nao pode ser lido ou n�o existe!" << endl;
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



	// Gerador de n�meros pseudoaleat�rios
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0,qtdCartas-1);
		
   // fim do gerador de n�meros pesudoaleat�rios
	
	
	// Loop para manter o fluxo das partidas
	while (escolha != 'n' && escolha !='N') {

		// preenchendo os baralhos dos jogadores com as cartas aleat�rias
		for (int i = 0; i < 4; i++) {
			baralhoJogador1[i] = &(Baralho[dist(mt)]);
			baralhoJogador2[i] = &(Baralho[dist(mt)]);
		}

		// come�o da primeira rodada
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

		// come�o da segunda rodada
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

		// come�o da terceira rodada
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

		// come�o da quarta rodada
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


	
		// come�o de nova partida
		// resetando pontua��o para a pr�xima partida para n�o come�ar com a pontuacao anterior
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

	delete[] Baralho; // Delete no vetor din�mico de baralho para liberar a mem�ria alocada ap�s fim do programa

	system("pause");

	return 0;
}


// funcao para calcular os pontos das rodadas de acordo com o atributo selecionado, bem como, mostrar os dados de acordo com a vez do jogador.
void rodadas(int atributo, char jogador1[30], char jogador2[30], baralho * baralhoJogador1[], baralho * baralhoJogador2[], int tam, int carta, 
	int * ptJogador1, int * ptJogador2, int prioridade, int rodadaFinal) {

	switch (atributo) {

	case 1:

		// ir� mostrar a carta e atributo da mesma de acordo com a vez ou prioridade do jogador na rodada atual.
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
	
		// gerador da pontua��o de acordo com o atributo e compara��o entre os atributos das cartas dos jogadores. 
		// Vai verificar qual carta ganha a rodade e incrementar a pontua��o do jogador
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
		// em caso de derrota, a pontua��o n�o � incrementada.


		// estrutura pra selecionar quem vai ser mostrado primeiro de acordo com a prioridade da vez do jogador. 
		// Tamb�m ir� verificar o fim da partida e mostrar a mensagem de fim de partida com a pontua��o final.
		if (prioridade==1) {
			// ir� aparecer o primeiro jogador, porque est� na vez dele.
			if (rodadaFinal==0) {
				// n�o ir� aparece final, porque a partida ainda n�o est� terminada.
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
			// O inverso da primeira condi��o, no caso, ir� aparecer o segundo jogador como primeiro.
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
