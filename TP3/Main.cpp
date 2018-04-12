/*
 * Main.cpp
 *
 *  Created on: 2018-04-04
 *      Author: etudiant
 */

#include <iostream>
#include "Client.h"
#include "Epargne.h"
#include "Cheque.h"

using namespace std;
using namespace util;
using namespace banque;

int main(){
	Date date1();
	Client client1(1500, "Nicola", "Ouellet", "418 581-4094", Date(19, 10, 1994));
	cout << client1.reqClientFormate();

	Epargne epargne1(1522, 0.5, 1000, "Epargne");
	cout << epargne1.reqCompteFormate();
	epargne1.asgSolde(2000);
	cout << epargne1.reqCompteFormate();

	Cheque cheque1(1500, 1.5, 5000, 25, 0.2, "Cheque");
	cout << cheque1.reqCompteFormate();
	cheque1.asgSolde(2000);
	cout << cheque1.reqCompteFormate();


	return 0;
}


