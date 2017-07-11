#include "StdAfx.h"
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

void Populacao::crossoverCiclico(Individuo paiUm, Individuo paiDois)
{
    int numInicio,numFinal,pos;
    Individuo filhoUm, filhoDois;
    std::map<int,int> numCiclo;
    
    //coloca -1 no DNA do individuo para iniciar o Crossover...
    filhoUm.iniciaIndividuo();
    filhoDois.iniciaIndividuo();
    
    //Inicia o Crossover na Posicao 0 no vetor do Pai 1  e pega o proximo valor a achar na mesma posicao do Pai 2... 
    numCiclo[0] = paiUm.dna[0];
    numInicio = paiUm.dna[0];
    numFinal = paiDois.dna[0];
    
   //Acha o ciclo dos valores entre os dois Pais...
    while (numInicio != numFinal)
    {
        pos = paiUm.procuraValorDna(numFinal);
        numCiclo[pos] = numFinal;
        numFinal = paiDois.dna[pos];

        //copia para os filhos nas mesmas posiçoes dos pais os valores dos vetores deles. Pai 1 -> filho 1, Pai 2 -> filho 2...
        filhoUm.dna[pos] = numFinal;
        filhoDois.dna[pos] = paiDois.dna[pos];
    }

    for (int i = 0; i < DNA; i++)
    {
        if (filhoUm.dna[i] == -1)
        {
            filhoUm.dna[i] = paiDois.dna[i];
            filhoDois.dna[i] = paiUm.dna[i];
        }
    }
    populacaoPaiseFilhos.push_back(filhoUm);
    populacaoPaiseFilhos.push_back(filhoDois);


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

void Populacao::reinsercaoPopulacaoSemElitismo()
{
    
    


}

void Populacao::reinsercaoPopulacaoComElitismo()
{
}



