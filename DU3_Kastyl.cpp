#include <iostream>
#include <string>
#include "zasobnikNeobektove.h"
#include "KastylLib/kastylLib.h"

using namespace std;
using namespace kastylLib;


int main()
{	
	// grafy
	int graf1[5][5] = { {0,1,1,0,0}, {1,0,0,0,0}, {1,0,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0} };
	int graf2[5][5] = { {0,1,1,0,1}, {1,0,1,0,1}, {1,1,0,1,0}, {0,0,1,0,1}, {1,1,0,1,0} };
	int graf3[5][5] = { {0,1,1,0,0}, {1,0,1,0,0}, {1,1,0,1,0}, {0,0,1,0,0}, {0,0,0,0,0} };
	// nabídka grafu pro uuživatele
	cout << "graf 1:" << endl;
	cout << "{{0,1,1,0,0}" << endl;
	cout << " {1,0,0,0,0}" << endl;
	cout << " {1,0,0,0,0}" << endl;
	cout << " {0,0,0,0,0}" << endl;
	cout << " {0,0,0,0,0}}" << endl;
	cout << "graf 2:" << endl;
	cout << "{{0,1,1,0,1}" << endl;
	cout <<" {1,0,1,0,1}" << endl;
	cout <<" {1,1,0,1,0}" << endl;
	cout <<" {0,0,1,0,1}" << endl;
	cout <<" {1,1,0,1,0}}" << endl;
	cout << "graf 3:" << endl;
	cout << "{{0,1,1,0,0}"<< endl;	
	cout <<" {1,0,1,0,0}" << endl;
	cout <<" {1,1,0,1,0}" << endl;
	cout <<" {0,0,1,0,0}" << endl;
	cout <<" {0,0,0,0,0}}" << endl;
	cout << endl;
	cout << "Zadejte 1-3 pro vyber grafu: ";
	// volba grafu a nahrání zvoleného grafu do promměnné "zvolenýGraf"
	int zvolenyGraf[5][5], x, y; // proměnné pro volbu grafu
	cin >> zvolenyGraf[0][4];
	switch (zvolenyGraf[0][4])	{
	case 1: for (x = 0; x < 5; x++)
	{
		for (y = 0; y < 5; y++)
		{
			zvolenyGraf[x][y] = graf1[x][y];
		}
	}
		  break;
	case 2: for (x = 0; x < 5; x++)
	{
		for (y = 0; y < 5; y++)
		{
			zvolenyGraf[x][y] = graf2[x][y];
		}
	}
		  break;
	case 3: for (x = 0; x < 5; x++)
	{
		for (y = 0; y < 5; y++)
		{
			zvolenyGraf[x][y] = graf3[x][y];
		}
	}
		  break;
	default:cout << "Nezadali jste spravnou volbu. Aplikace bude nyni ukoncena!";
		return 0;
	}
	// volba algoritmu 
	cout << "Nyni vyberte alogritmus, jehoz vstupem bude graf, ktery jste prave zvolili: " << endl;
	cout << endl;
	cout << "Pro nalezeni komonenty grafu s nejvetsim poctem vrcholu stiksnete 1 " << endl;
	cout << "Pro overeni existence cesty mezi dvema vrchly stisknete 2 " << endl;
	int zvolenyAlgoritmus, vrcholGrafu;
	cin >> zvolenyAlgoritmus;
	cout << endl;
	// Algoritmus který se spustíse v případě volby algoritmu 1
	if (zvolenyAlgoritmus == 1)     // Algoritmus který se spustíse v případě volby algoritmu 1
	{		
	  	const int pocetVrcholu = 5;
		// info zda byli všechny vrcholy navštívené
		bool all = false;
		// počet komponent
		int comp = 0;
		int counter;
		// deklarace fronty
		Tstruct* pStack;
		// spuštění fronty
		StackInit(&pStack);
		// info kam patří jednotlivé komponenty vrcholu
		int component[pocetVrcholu];
		// spuštení pole
		for (int i = 0; i <= pocetVrcholu - 1; i++) component[i] = 0;
		// cyklus běží dokud nejsou všechny vrcholy navštíveny
		while (!all) {
			comp++;
			for (counter = 0; counter <= pocetVrcholu - 1; counter++)
				if (component[counter] == 0) break;
			// první nenavštívený prvek do fronty
			pStack = StackPush(pStack, counter);
			//označní componentya
			component[counter] = comp;
			
			//  dokud není fronta prázdná nebo všechny vrcholy nejsou označeny jako navšítvené
			while (!StackIsEmpty(pStack) && !all) {
				// pop vrchol z vrcholu fronty
				vrcholGrafu = StackPop(&pStack);
				// přidá všechny nenavštívené sousedy do fronty
				for (int j = 0; j <= pocetVrcholu - 1; j++)
					if (zvolenyGraf[vrcholGrafu][j] && !component[j]) {
						pStack = StackPush(pStack, j);
						// ozn. komponenty
						component[j] = comp;
					}
				// kontrola zda li byly všechny vrcholy navštíveny
				all = true;
				for (int j = 0; j <= pocetVrcholu - 1; j++)
					if (!component[j]) all = false;
			}
		}
		cout << "Pocet komponent grafu: " << comp <<  endl;
		cout << endl;
		// zobrazení komponent grafu a zobrazení komponenty s největším počtem vrcholů
		int komponentaA = 0, komponentaB = 0, komponentaC = 0;
		for (int vrcholGrafu = 1; vrcholGrafu <= comp; vrcholGrafu++) {
			cout << "Vrcholy komponenty cislo " << vrcholGrafu << " jsou: ";
			for (int komponentaGrafu = 0; komponentaGrafu <= pocetVrcholu - 1; komponentaGrafu++)
				if (component[komponentaGrafu] == vrcholGrafu) cout << komponentaGrafu << ", ";
			komponentaA++;   // změní 0 na 1
			if (komponentaB <= komponentaB)
			{
				komponentaB = komponentaA, komponentaC = vrcholGrafu;
			}
			komponentaA = 0;
			cout << endl;
		}		
		cout << "Nejvetsi pocet vrcholu ma komponenta cislo " << komponentaB << endl;
		cout << "---------------------------------------------" << endl;
		cout << endl;
		return 0;
	}  
	// Algoritmus který se spustíse v případě volby algoritmu 1
	else if (zvolenyAlgoritmus == 2)  
	{   
		int vrchol1, vrchol2;   // proměné pro výběr vrcholů
		cout << "vyberte dva vrcholy (0-4): " << endl;
		cout << "prvni vrchol (0-4): " << endl;		
		cin >> vrchol1;
		cout << "druhy vrchol (0-4) " << endl;
		cin >> vrchol2;
		// konstanta počtu vrcholů
		const int n = 5;
		// konstatnta vchod do bludiště
		const int entrance = vrchol1;
		// konstatnta východ z bludiště
		const int ex = vrchol2;
		// deklarace fronty
		Tstruct* pStack;
		// inicializace fronty
		StackInit(&pStack);
		// existence nějake cesty
		bool path = false;
		// pole navšívených vrcholů - deklarace a inicializace 
		bool visited[n];
		for (int i = 0; i <= n - 1; i++) visited[i] = false;
		// processing vertex
		int v = entrance;
		pStack = StackPush(pStack, entrance);
		// označení navšítveného vrcholu
		visited[v] = true;
		//cyklus while dokud není nalezen východ a fronta není prázdná 
		while (v != ex && !StackIsEmpty(pStack)) {
			// můžeme dosáhnout východu z tohoto vrcholu?
			if (zvolenyGraf[v][ex]) {
				// push exit uzel do fronty
				pStack = StackPush(pStack, ex);
				// východ nalezen
				v = ex;
				visited[v] = true;
			}
			else {
				// hledani další cesty
				path = false;
				// nalezení jedné neoznačené cesty k sousednímu vrcholu
				for (int j = 0; j <= n - 1; j++) {
					if (zvolenyGraf[v][j] && !visited[j]) {
						// existence cesty
						path = true;
						// push vertex j into the stack
						pStack = StackPush(pStack, j);
						// and continue from this vertex
						v = j;
						// mark the vertex as visited
						visited[v] = true;
						// leave the for cycle
						break;
					}
				}
				if (!path)
					// next path does not exist
					// pop explored vertex and
					// go back to previous vertex
					v = StackPop(&pStack);
				if (!StackIsEmpty(pStack))
					v = StackShow(pStack);
				else break;
			}
		}
		// zobrazení cesty
		if (!StackIsEmpty(pStack)) {
			v = StackPop(&pStack);
			cout << "Cesta mezi vrcholy existuje." << " ";
		}
		else cout << "Cesta mezi vrcholy neexistuje.";		
		cout << endl;
	}
	
}


