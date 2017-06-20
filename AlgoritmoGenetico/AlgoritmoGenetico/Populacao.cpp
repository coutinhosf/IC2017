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

list<Individuo> Populacao::torneio()
{
    list<Individuo> sorteados;
    Individuo teste;
    
    for (int i = 0; i < TOURNAMENT;i++)
    {
        sorteados.push_back(this->populacao[sorteioNumero(POPULATION)]);
    }

   /* while (sorteados.size() > 2)
    {
     
    }*/
        
    return sorteados;
}




