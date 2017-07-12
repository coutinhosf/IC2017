#pragma once
#include "stdafx.h"
#define POPULATION 100
#define CROSSOVER 80
#define ELITISMO 20


class Populacao
{
public:
	Individuo populacao[POPULATION+CROSSOVER];
	string palavraUm;
	string palavraDois;
	string palavraTres;
	string palavraConc;
	Individuo Avaliado;
    int totalAptidao;
    int totalPopulacao;
public:
	Populacao();
	~Populacao();
	void PopulacaoInicial(int);
    int crossoverCiclico(Individuo um, Individuo dois);
	Individuo roleta();
	Individuo torneio();
    int somaAptidaoPopulacao();
    void ordenaPopulacao(Individuo vet[], int numInicial, int numFinal);
    void reinsercaoPopulacaoSemElitismo();
    void reinsercaoPopulacaoComElitismo();
	int avaliacaoPopulacao();
	int temIndividuo(Individuo um, Individuo dois);
	void zeraTotalAptidao();
};

