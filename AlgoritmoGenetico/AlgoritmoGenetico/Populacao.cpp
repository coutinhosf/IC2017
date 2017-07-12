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
	this->totalPopulacao = 0;
	for (int i = 0;i < POPULATION;i++)
	{
		this->populacao[i].sorteioDNA();
		this->populacao[i].calculoAptidao(this->palavraUm,this->palavraDois,this->palavraTres,this->palavraConc);
		this->populacao[i].stringDna(DNA);
		this->totalPopulacao++;
	}

    this->totalAptidao= somaAptidaoPopulacao();
}

int Populacao::crossoverCiclico(Individuo paiUm, Individuo paiDois)
{	
	int somaTotalDna=0;
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
    while (numInicio != numFinal && somaTotalDna < 10)
    {
        pos = paiUm.procuraValorDna(numFinal);
        numCiclo[pos] = numFinal;
        numFinal = paiDois.dna[pos];

        //copia para os filhos nas mesmas posiçoes dos pais os valores dos vetores deles. Pai 1 -> filho 1, Pai 2 -> filho 2...
        filhoUm.dna[pos] = numFinal;
        filhoDois.dna[pos] = paiDois.dna[pos];
		somaTotalDna++; 
    }

    for (int i = 0; i < DNA; i++)
    {
        if (filhoUm.dna[i] == -1)
        {
            filhoUm.dna[i] = paiDois.dna[i];
            filhoDois.dna[i] = paiUm.dna[i];
        }
    }

  //  populacaoPaiseFilhos.push_back(filhoUm);
	this->populacao[totalPopulacao] = filhoUm;
	this->populacao[totalPopulacao].calculoAptidao(this->palavraUm,this->palavraDois,this->palavraTres,this->palavraConc);
	this->populacao[totalPopulacao].stringDna(DNA);
	totalPopulacao++;

   // populacaoPaiseFilhos.push_back(filhoDois);
	this->populacao[totalPopulacao] = filhoDois;
	this->populacao[totalPopulacao].calculoAptidao(this->palavraUm,this->palavraDois,this->palavraTres,this->palavraConc);
	this->populacao[totalPopulacao].stringDna(DNA);
	totalPopulacao++;

	return Populacao::temIndividuo(this->populacao[totalPopulacao-2], this->populacao[totalPopulacao-1]);

}

Individuo Populacao::roleta()
{
    
    int numSorteado,somatorio=0,pivoinicio,pivoFinal, pivoMeio, posIndividuoSorteado=0;

    numSorteado = sorteioNumero(this->totalAptidao);
    pivoinicio = 0;
    pivoFinal = POPULATION;

	//ordena populaçao para a Roleta.
	if(this->totalPopulacao < 101)
		ordenaPopulacao(this->populacao,0,POPULATION);
	
	for(int i=0; i < POPULATION;i++)
	{
		somatorio += this->populacao[i].aptidao;

		if(somatorio > numSorteado)
		{
			posIndividuoSorteado = i;
			break;
		}

	}

    return this->populacao[posIndividuoSorteado];
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
	zeraTotalAptidao();

    int totalAptidao=0;

    for (int i = 0; i < POPULATION ; i++)
	{
		totalAptidao += this->populacao[i].aptidao;
	}
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
	this->ordenaPopulacao(this->populacao, 0, this->totalPopulacao);
	this->totalPopulacao= POPULATION;
}

void Populacao::reinsercaoPopulacaoComElitismo()
{
	this->ordenaPopulacao(this->populacao,ELITISMO,this->totalPopulacao);
	this->totalPopulacao= POPULATION;
}

int Populacao::avaliacaoPopulacao()
{
	int finded=0;
	for(int i = 0; i<POPULATION; i++)
	{
		if(this->populacao[i].aptidao == 0)
		{
			this->Avaliado = this->populacao[i];
			finded=1;
			break;
		}				
	}

	if(finded == 0)
		return 0;
	else
		return 1;
}

int Populacao::temIndividuo(Individuo um, Individuo dois)
{
	for(int i = 0; i<POPULATION;i++)
	{
		if(this->populacao[i].palavraDNA.compare(um.palavraDNA) == 0 || this->populacao[i].palavraDNA.compare(dois.palavraDNA) == 0)
			return 1;
	}
	
	return 0;

}

void Populacao::zeraTotalAptidao()
{
	this->totalAptidao=0;
}
