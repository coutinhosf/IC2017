#include "stdafx.h"
#include "Populacao.h"


Populacao::Populacao()
{
}


Populacao::~Populacao()
{
}

void Populacao::PopulacaoInicial(int tamanhoPalavra)
{
	for (int i = 0;i < POPULATION;i++)
	{
		this->populacao[i].sorteioDNA();
		this->populacao[i].calculoAptidao(this->palavraUm,this->palavraDois,this->palavraTres,this->palavraConc);
	//	this->populacao[i].mutacaoIndividuo();
		//srand((unsigned)time(NULL)*i);
	}
}

void Populacao::crossoverCiclico()
{
}

void Populacao::roleta()
{
}

void Populacao::torneio()
{

	//this->populacao[i];


}




