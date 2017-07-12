#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	string wordOne, wordTwo, wordTree, wordConc;
	Individuo teste, paiUm, paiDois;
	Populacao testep;
	int geracao = GERACAO;
	int crossover = CROSSOVER/2;//dividido por 2 por produz dois filhos.
	int verificaCross=0;
	int mutacao = MUTATION;
	int geracaoAtual=1;
	int sorteioPaieFilho;
	//int total

	cout<< "Digite a primeira palavra: " << "\n";
	cin >> testep.palavraUm;
	
	cout<< "Digite a segunda palavra: "<< "\n";
	cin >> testep.palavraDois;
	
	cout<< "Digite a terceira palavra: "<< "\n";
	cin >> testep.palavraTres;

	testep.palavraConc = retornaPalavra(testep.palavraUm+testep.palavraDois+testep.palavraTres);

	cout << "\n";
	testep.PopulacaoInicial(testep.palavraConc.length());
	testep.ordenaPopulacao(testep.populacao,0,100);

	while(/*(testep.avaliacaoPopulacao() != true) &&*/ (geracaoAtual < geracao))
	{
		/*---Caso Seja Roleta Ordernar a Populaçao---*/
		//Populacao::ordenaPopulacao(testep.populacao,0,POPULATION);	

		/*---TaxaCrossover---*/
		for(int cross = 0; cross < crossover; cross++)
		{
			paiUm = testep.roleta(); paiDois= testep.roleta();

			while(paiUm.palavraDNA.compare(paiDois.palavraDNA)==0)
			{
				paiDois= testep.roleta();
			}
			//testep.crossoverCiclico(testep.torneio(), testep.torneio());
		//problema na hora de gera os individuos podem sair iguais...............
			verificaCross =  testep.crossoverCiclico(paiUm, paiDois);

		}	

		/*---TaxaMutacao---*/
		for(int mut =0; mut < mutacao; mut++)
		{
			sorteioPaieFilho = sorteioNumero(POPULATION+CROSSOVER);
			testep.populacao[sorteioPaieFilho].mutacaoIndividuo();	
			testep.populacao[sorteioPaieFilho].calculoAptidao(testep.palavraUm,testep.palavraDois,testep.palavraTres,testep.palavraConc);
			testep.populacao[sorteioPaieFilho].stringDna(DNA);
		}
		/*----reinserçao da populacao----*/
		testep.reinsercaoPopulacaoSemElitismo();
		cout<<"\n\n\n-----------------------------------------\n\n\n";
		
		//testep.reinsercaoPopulacaoComElitismo();
		geracaoAtual++;
		testep.totalAptidao= testep.somaAptidaoPopulacao();

		if(testep.avaliacaoPopulacao()==true)
			int a=0;
		
	}

	cout << testep.Avaliado.palavraDNA;

	//getchar();
	return 0;
}

