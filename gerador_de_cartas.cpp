
#define _CRT_SECURE_NO_WARNINGS // Define usado para usar funções da cstring
#include <iostream> // Incluido para usar funções de entrada e saída de dados
#include <fstream> // Incluido para leitura e escrita de arquivos de texto e binário
#include<cstring> // incluido para usar funções de manipulação de strings
using namespace std; // Incluido para abreviacao de caminho

struct baralho
{
	char nome[30];     // nome do jogador
	int idade;          // idade do jogador
	int gols;         // gols do jogador
	int titulos;      // titulos do jogador
	double salario;   // salario do jogador
	
};



int main() {

	baralho Baralho[32]; // Vetor de Baralho que contém todas as cartas

	ifstream fin;     // cria objeto para leitura de arquivo
	ofstream fout;   // cria objeto para escrita de arquivo


	// Variáveis para registrar e ler o cabeçaho e quantidade de cartas. (molde)
	char cabecalho[] = "BARALHO";
	unsigned short qtdCartas = 0;
	int numQtd = 0; // variável para auxilar na contagem de quantidade de elementos do arquivo de texto
	
	fin.open("../baralho.data", ios_base::in | ios_base::binary | ios_base::_Nocreate);
	fin.read((char *)&cabecalho, sizeof(char) * 7);
	fin.read((char *)&qtdCartas, sizeof(unsigned short));

	if (fin.is_open() )     // se o arquivo foi aberto sem erros e o cabecalho está de acordo
	{
	  
		if (strcmp(cabecalho, "BARALHO") == 0) {

		for (int i = 0; i < qtdCartas;i++) {
			fin.read((char *)&Baralho[i], sizeof(baralho) );
	}
		fin.close();
		}
		else {
			cout << "O arquivo não é um baralho de cartas!" << endl;
			system("pause");
			return EXIT_FAILURE;
		}
	}
	else {

		cout << "O arquivo nao existe. Sera criado um!" << endl;	

	}


	// Menu de opções para as tarefas do gerador
		char escolha; // Variável para escolha
		

		do{

			cout << "Gerador de Cartas" << endl;
			cout << "-----------------" << endl;
			cout << "(C)adastrar" << endl;
			cout << "(I)mportar" << endl;
			cout << "(A)lterar" << endl;
			cout << "(E)xcluir" << endl;
			cout << "(L)istar" << endl;
			cout << "(S)air" << endl;
			cout << endl;
			cout << "Escolha uma opcao [ ] \b\b\b";
			cin >> escolha;
			system("cls");

			// Escolha da opção acima
			// Não criei funções porque não achei necessário, pois irei usar apenas uma vez e achei a organização no switch bem intuitiva.
			switch (escolha) {

			case 'c':
			case 'C':
				cout << "Cadastrar carta" << endl;
				cout << "---------------" << endl;
				cout << "Nome    :";
				cin >> Baralho[qtdCartas].nome;
				cout << "Idade   :";
				cin >> Baralho[qtdCartas].idade;
				cout << "Gols    :";
				cin >> Baralho[qtdCartas].gols;
				cout << "Titulos :";
				cin >> Baralho[qtdCartas].titulos;
				cout << "Salario :";
				cin >> Baralho[qtdCartas].salario;
				cout << endl;
				qtdCartas++;

				break;

			case 'i':
			case 'I':
				
				cout << "Importar carta" << endl;
				cout << "---------------" << endl;
				cout << "Arquivo: ";
				
				// Variável para receber o nome do arquivo
				char nomeArq[30];
			
				cin >> nomeArq;

				cout << endl;
				cout << "Importando: " << endl;
		
				// Abrindo arquivo de texto pertecente ao projeto gerador de cartas!
				fin.open(nomeArq);
				// atribuindo ao vetor Baralho as cartas inseridas
				for (int i = qtdCartas; fin.good() &&!fin.eof(); i++) {
					fin >> Baralho[i].nome;
					fin >> Baralho[i].idade;
					fin >> Baralho[i].gols;
					fin >> Baralho[i].titulos;
					fin >> Baralho[i].salario;
					numQtd++;
				}

				fin.close();
				// fecha o arquivo 

				// exibindo as cartas que estão sendo inseridas no baralho
				for (int i = qtdCartas; i < (qtdCartas+numQtd); i++) {
					cout << Baralho[i].nome << " " << Baralho[i].idade << " " << Baralho[i].gols
						<< " " << Baralho[i].titulos << " " << Baralho[i].salario << endl;
				}

				qtdCartas = qtdCartas + numQtd;
				cout << endl;
				

				break;

			case 'a':
			case 'A':

				cout << "Atualizar carta" << endl;
				cout << "---------------" << endl;
				// Primeiro mostra as cartas do baralho atual
				for (int i = 0; i < qtdCartas; i++) {

					cout << (i + 1) << ")" << " " << Baralho[i].nome << endl;
				}
				cout << endl;
				cout << "Digite o numero da carta: [ ] \b\b\b";
				// de acordo com o número da carta será excluido
				// o vetor vai de 0  até < quantidade de cartas, assim, a posição vai ser de (NumAlt-1)
				// primeira carta na lista, mas a 0 da posição do vetor que é realmente a primeira carta.
				int numAlt;
				cin >> numAlt;
				cout << endl;
				cout << "Alterando Carta " << Baralho[numAlt - 1].nome << " :" << endl;
				cout << "Nome    :";
				cin >> Baralho[numAlt-1].nome;
				cout << "Idade   :";
				cin >> Baralho[numAlt - 1].idade;
				cout << "Gols    :";
				cin >> Baralho[numAlt - 1].gols;
				cout << "Titulos :";
				cin >> Baralho[numAlt - 1].titulos;
				cout << "Salario :";
				cin >> Baralho[numAlt - 1].salario;
				cout << endl;

				break;

			case 'e':
			case 'E':
				cout << "Excluir Carta" << endl;
				cout << "-------------" << endl;
				// Primeiro lista as cartas do baralho atual
				for (int i = 0; i < qtdCartas; i++) {

					cout << (i + 1) << ")" << " " << Baralho[i].nome << endl;
				}
				cout << endl;
				cout << "Digite o numero da carta: [ ] \b\b\b";
				// Mesma lógica usada na opcao alterar carta para selecionar a carta.
				// Porém aqui irá mudar a posição da carta, excluir e diminuir o tamanho do vetor.
				int numEx;
				cin >> numEx;
				cout << endl;

				char aux[30];
				strcpy(aux, Baralho[numEx - 1].nome);
				strcpy(Baralho[numEx - 1].nome, Baralho[qtdCartas - 1].nome);
				Baralho[numEx - 1].idade = Baralho[qtdCartas - 1].idade;
				Baralho[numEx - 1].gols = Baralho[qtdCartas - 1].gols;
				Baralho[numEx - 1].titulos = Baralho[qtdCartas - 1].titulos;
				Baralho[numEx - 1].salario = Baralho[qtdCartas - 1].salario;
				qtdCartas--;

				cout << "Carta " << aux << " foi excluida do baralho.\n" << endl;
				
				break;

			case 'l':
			case 'L':
				// Lista as cartas do baralho atual.
				cout << "Cartas no Baralho" << endl;
				cout << "-----------------" << endl;
				for (int i = 0; i < qtdCartas; i++) {
					cout << "#" << (i+1) << " " <<Baralho[i].nome << " " << Baralho[i].idade << " " << Baralho[i].gols
						<< " " << Baralho[i].titulos << " " << Baralho[i].salario << endl;
				}
				cout << endl;
				break;

			case 's':
			case 'S':
				cout << "Voce saiu do programa!" << endl;
				cout << "----------------------" << endl;
				break;

			default:
				cout << "Nenhuma opcao valida!!!" << endl;

			}


		} while ( escolha != 'S' && escolha != 's');


		// Escrevendo as últimas alterações feitas no Vetor Baralho no arquivo Binário. (update_write)
		// OBS: Reescreve o arquivo inteiro, não adiciona informação.
		fout.open("../baralho.data", ios_base::out | ios_base::trunc | ios_base::binary);
		fout.write((char *)&cabecalho, sizeof(char) * 7);
		fout.write((char *)&qtdCartas, sizeof(unsigned short));
		fout.write((char *)&Baralho, sizeof(baralho)*qtdCartas);
		fout.close();
	
	system("pause");

	return 0;
}