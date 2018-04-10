/*
 * CompteTesteur.cpp
 *
 *  Created on: 2018-04-08
 *      Author: etudiant
 */

#include <gtest/gtest.h>
#include "Compte.h"
#include <iostream>

using namespace std;

/**
 * \class CompteTest
 * \brief classe de test permettant de tester la classe abstraite Compte
 */
class CompteTest: public Compte{

public:
	CompteTest(int noCompte, double tauxInteret, double solde, const string& description):
		Compte(noCompte, tauxInteret, solde, description){
	};
	virtual string& reqCompteFormate() const{
		return Compte::reqCompteFormate();
	};
	virtual double calculerInteret(){
		return 0
	}
};
