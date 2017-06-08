#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	string wordOne, wordTwo, wordTree, wordConc;
	Individuo teste;
	Populacao testep;

	cout<< "Digite a primeira palavra: " << "\n";
	cin >> testep.palavraUm;
	
	cout<< "Digite a segunda palavra: "<< "\n";
	cin >> testep.palavraDois;
	
	cout<< "Digite a terceira palavra: "<< "\n";
	cin >> testep.palavraTres;

	testep.palavraConc = retornaPalavra(testep.palavraUm+testep.palavraDois+testep.palavraTres);

	for (int i = 0;i < DNA;i++)
		cout << teste.dna[i];

	cout << "\n";
	testep.PopulacaoInicial(testep.palavraConc.length());
	
	for (int i = 0;i < 100;i++)
	{
		//	cout << testep.populacao[i].dna[j]<< "\n";	
		testep.populacao[i].stringDna(wordConc.length());
		cout << "Numero em string :" << testep.populacao[i].palavraDNA << "\n";
	}
	//getchar();
	return 0;
}

