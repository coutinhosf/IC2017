// stdafx.cpp : source file that includes just the standard includes
// AlgoritmoGenetico.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

string retornaPalavra(string word)
{
    std::string::iterator it;
	list<char> lista;
	char t;
	string retorno;

	for(int i = 0; i< word.length(); i++)
	{
		for(int j = i+1; j < word.length();j++ )
		{
			if(word[j] != '*')
			{
				if(word[i] == word[j])
					word[j] = '*';
			}	
		}
	}

	for(it = word.begin(); it != word.end(); it++)
	{
		if(*it != '*')
			retorno += *it;	
	}

return retorno;
}

int sorteioNumero(int tetoNumero)
{
	 //srand((unsigned)time(NULL)*tamanhoPalavra);
	 return (rand() % tetoNumero+0);
}

int buscaBinaria(size_t vet[])
{
    


    return 0;
}