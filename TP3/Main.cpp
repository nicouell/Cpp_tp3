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
using namespace util;
using namespace banque;

int main(){
	Date date1();
	Client client1(1500, "Nicola", "Ouellet", "418 581-4094");
	cout << client1.reqClientFormate();
	return 0;
}


