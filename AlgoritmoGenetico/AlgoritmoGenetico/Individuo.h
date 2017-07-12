#include "stdafx.h"
#include <string>
#include <map>
#define DNA 10

using namespace std;
#pragma once
class Individuo
{
public:
	 int dna[DNA];
	 int aptidao;
	 string palavraDNA;

public:
	 Individuo(void);
	~Individuo(void);
	void calculoAptidao(string,string,string,string);
	void sorteioDNA();
	void stringDna(int);
	void mutacaoIndividuo();
    bool funcaoIndividuoMaior(Individuo um, Individuo dois);
    int procuraValorDna(int valor);
    void iniciaIndividuo();
};

