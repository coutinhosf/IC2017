#include "StdAfx.h"
#include "Individuo.h"

using namespace std;
Individuo::Individuo(void)
{
}

Individuo::~Individuo(void)
{
}

void Individuo::calculoAptidao(string palavraUm, string palavraDois, string palavraTres, string palavraConc)
{
	int valorPalavraUm =0;
	int valorPalavraDois = 0;
	int valorPalavraTres = 0;
	int elevadoPalavra = 0;

	map<char, int> mapaPalavra;
	
	for(int i=0;i<palavraConc.length();i++)
	{
		mapaPalavra[palavraConc[i]] = i;
	}

	elevadoPalavra = palavraUm.length() - 1;

	for(int i =0 ; i < palavraUm.length();i++)
	{
		valorPalavraUm += this->dna[mapaPalavra[palavraUm[i]]] * pow(10,elevadoPalavra); 	
		elevadoPalavra--;
	}

	elevadoPalavra = palavraDois.length() - 1;

	for (int i = 0; i < palavraDois.length();i++)
	{
		valorPalavraDois += this->dna[mapaPalavra[palavraDois[i]]] * pow(10, elevadoPalavra);
		elevadoPalavra--;
	}

	elevadoPalavra = palavraTres.length() - 1;

	for (int i = 0; i < palavraTres.length();i++)
	{
		valorPalavraTres += this->dna[mapaPalavra[palavraTres[i]]] * pow(10, elevadoPalavra);
		elevadoPalavra--;
	}

	this->aptidao = abs(((valorPalavraUm+ valorPalavraDois) - valorPalavraTres));
}

void Individuo::sorteioDNA()
{
	bool boolean;
	int contadorIgualdade=0;
	int numeroSorteado;
	int mapDna[DNA];

	for (size_t i = 0; i < DNA; i++)
	{
		mapDna[i] = 0;
	}

	for (int i = 0;i < DNA;i++)
	{
		
		this->dna[i] = (rand() % 10);
		boolean = false;
		
		if (i == 0)
		{
			mapDna[this->dna[i]] = 1;
		}

		if (i > 0)
		{
			do
			{
				if (mapDna[this->dna[i]] == 0)
				{
					boolean = true;
					mapDna[this->dna[i]] = 1;
				}
				else
				{
					this->dna[i] = (rand() % 10);
					boolean = false;
				}

			} while (boolean == false);
			
	  }//if(i>1)
		
	}	
}


void Individuo::stringDna(int tamPalavra)
{
	char buffer[2];
	for (int i = 0; i < tamPalavra;i++)
	{
		if (this->dna[i] != -1)
		{
			itoa(this->dna[i], buffer, 10);
			this->palavraDNA += buffer;
		}
    }
	//buffer.~char();
	this->palavraDNA;
}

void Individuo::mutacaoIndividuo()
{
	int posicaoUm, posicaoDois, auxiliar;
	
	posicaoUm = sorteioNumero(DNA);

	do
	{
		posicaoDois = sorteioNumero(DNA);

	} while (posicaoUm == posicaoDois);

	auxiliar = this->dna[posicaoUm];
	this->dna[posicaoUm] = this->dna[posicaoDois];
	this->dna[posicaoDois] = auxiliar;
	
}


