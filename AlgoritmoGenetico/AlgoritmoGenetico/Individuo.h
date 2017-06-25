#include "stdafx.h"
#include <string>
#include <map>

using namespace std;
#pragma once
class Individuo
{
public:
	 int dna[10];
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
};

