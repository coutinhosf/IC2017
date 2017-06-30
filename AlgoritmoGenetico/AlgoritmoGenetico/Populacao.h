#pragma once
#include "stdafx.h"

class Populacao
{
public:
	Individuo populacao[100];
	string palavraUm;
	string palavraDois;
	string palavraTres;
	string palavraConc;
    int totalAptidao;
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
};

