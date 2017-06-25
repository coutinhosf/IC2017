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

    this->totalAptidao= somaAptidaoPopulacao();
}

void Populacao::crossoverCiclico()
{

}

Individuo Populacao::roleta()
{
    
    int numSorteado,pivoinicio,pivoFinal, pivoMeio, posIndividuoSorteado=0;

    numSorteado = sorteioNumero(this->totalAptidao);
    pivoinicio = 0;
    pivoFinal = POPULATION;


    do //search the element of array;
    {
        pivoMeio = ((pivoinicio + pivoFinal) / 2);
        if (this->populacao[pivoMeio].aptidao > numSorteado)
            pivoFinal = pivoMeio;

        else if (this->populacao[pivoMeio].aptidao <= numSorteado)
            pivoinicio = pivoMeio;

    } while (((pivoinicio + pivoFinal) / 2) != pivoMeio);

    return this->populacao[pivoMeio];
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

int Populacao::somaAptidaoPopulacao()
{
    int totalAptidao=0;

    for (int i = 0; i < POPULATION ; i++)
        totalAptidao += this->populacao->aptidao;
    
    return totalAptidao;

}

void Populacao::ordenaPopulacao(Individuo vet[],int inicio,int fim)
{
    if (fim >= POPULATION)
        fim--;

    int pivo, i, j, meio;
    Individuo aux;
    i = inicio;
    j = fim;

    meio = (int)((i + j) / 2);
    pivo = vet[meio].aptidao;

    do {
        while (vet[i].aptidao < pivo) i = i + 1;
        while (vet[j].aptidao > pivo) j = j - 1;

        if (i <= j) {
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    } while (j > i);

    if (inicio < j) ordenaPopulacao(vet, inicio, j);
    if (i < fim) ordenaPopulacao(vet, i, fim);
}




