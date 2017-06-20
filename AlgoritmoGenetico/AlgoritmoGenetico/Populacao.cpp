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

Individuo Populacao::torneio()
{
    list<Individuo> sorteados;
    Individuo ind;
    
    for (int i = 0; i < TOURNAMENT;i++)
    {
        sorteados.push_back(this->populacao[sorteioNumero(POPULATION)]);
    }
   
    while (sorteados.size() > 1)
    {
        
         if (sorteados.begin()->aptidao < sorteados.back().aptidao)
             sorteados.pop_front();
         else
             sorteados.pop_back();
    }
        
    ind = *sorteados.begin();
    return ind;
}




