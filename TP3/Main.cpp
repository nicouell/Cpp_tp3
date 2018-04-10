/*
 * Main.cpp
 *
 *  Created on: 2018-04-04
 *      Author: etudiant
 */

#include <iostream>
#include "Client.h"
#include "Compte.h"

using namespace std;

int main(){
	util::Date date1();
	banque::Client client1(1500, "Nicola", "Ouellet", "418 581-4094");
	cout << client1.reqClientFormate();
	Compte compte(1234, 0.3, 1000, "cheque");
	cout << compte.reqCompteFormate();
	return 0;
}


