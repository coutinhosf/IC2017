#pragma once
#include "stdafx.h"
#define POPULATION 100
#define CROSSOVER 80


class Populacao
{
public:
	Individuo populacao[POPULATION+CROSSOVER];
	string palavraUm;
	string palavraDois;
	string palavraTres;
	string palavraConc;
    int totalAptidao;
    int totalPopulacao;
    list<Individuo> populacaoPaiseFilhos;
public:
	Populacao();
	~Populacao();
	void PopulacaoInicial(int);
    void crossoverCiclico(Individuo um, Individuo dois);
	Individuo roleta();
	Individuo torneio();
    int somaAptidaoPopulacao();
    void ordenaPopulacao(Individuo vet[], int numInicial, int numFinal);
    void reinsercaoPopulacaoSemElitismo();
    void reinsercaoPopulacaoComElitismo();
};

