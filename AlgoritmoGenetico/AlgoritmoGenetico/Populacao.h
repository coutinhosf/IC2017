#include "stdafx.h"

#pragma once
class Populacao
{
public:
	Individuo populacao[100];
	string palavraUm;
	string palavraDois;
	string palavraTres;
	string palavraConc;
    int totalAptidao;
public:
	Populacao();
	~Populacao();
	void PopulacaoInicial(int);
	void crossoverCiclico();
	Individuo roleta();
	Individuo torneio();
    int somaAptidaoPopulacao();
    void ordenaPopulacao(Individuo vet[], int numInicial, int numFinal);
};

