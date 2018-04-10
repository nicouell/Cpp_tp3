/*
 * CompteTesteur.cpp
 *
 *  Created on: 2018-04-08
 *      Author: etudiant
 */

#include <gtest/gtest.h>
#include "Compte.h"
#include "Date.h"
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
	virtual string reqCompteFormate() const{
		return Compte::reqCompteFormate();
	};
	virtual double calculerInteret() const{
		return 0;
	};
	virtual Compte* clone() const{
		return 0;
	};
};

/**
 * \class UnCompte
 * \brief class de test permettant de tester la classe abstraite Compte
 */
class UnCompte: public ::testing::Test{

public:
	UnCompte():
		t_compte(1234, 0.3, 2000, "description"){
	}
	CompteTest t_compte;
};

/**
 * \brief Test du Constructeur Compte(int noCompte, double tauxInteret, double solde, const string& description))
 *        cas valide:
 *         ConstructeurAvecParametre :
 *        cas invalide Aucun d'identifié
 */
TEST(Compte, constructeurAvecParametre){
	CompteTest compteTest(1000, 0.2, 2500, "description");
	ASSERT_EQ(1000, compteTest.reqNoCompte());
	ASSERT_EQ(0.2, compteTest.reqTauxInteret());
	ASSERT_EQ(2500, compteTest.reqSolde());
	ASSERT_EQ("description", compteTest.reqDescription());
	ASSERT_EQ(util::Date(), compteTest.reqDateOuverture());
}




















