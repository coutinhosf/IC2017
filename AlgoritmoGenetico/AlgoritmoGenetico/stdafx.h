// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

//#include "targetver.h"
//#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <list>
#include <string>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include "Individuo.h"
#include "Populacao.h"
#include <map>
#include <math.h>
#define DNA 10
#define CROSSOVER 80
#define MUTATION 20
#define RATIOMUTATION 10
#define TOURNAMENT 3 
#define GERACAO 200
// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
using namespace std;

// TODO: reference additional headers your program requires here
string retornaPalavra(string);
int sorteioNumero(int);