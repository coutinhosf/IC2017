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
public:
	Populacao();
	~Populacao();
	void PopulacaoInicial(int);
	void crossoverCiclico();
	void roleta();
	Individuo torneio();
};

