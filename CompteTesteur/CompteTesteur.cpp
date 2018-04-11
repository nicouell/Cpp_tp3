/*
 * CompteTesteur.cpp
 *
 *  Created on: 2018-04-08
 *      Author: etudiant
 */

#include <gtest/gtest.h>
#include "Compte.h"
#include "Date.h"

using namespace std;
using namespace banque;

/**
 * \class CompteTest
 * \brief classe de test permettant de tester la classe abstraite Compte
 */
class CompteTest: public Compte{

public:
	CompteTest(int noCompte, double tauxInteret, double solde, const string& description):
		Compte(noCompte, tauxInteret, solde, description){
	};
	virtual double calculerInteret() const{
		return 0;
	};
	virtual Compte* clone() const{
		return 0;
	};
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

TEST(Compte, ConstructeurAvecNoCompteInvalide){
	ASSERT_THROW(CompteTest compteTest(-2, 0.3, 1500, "description"), ContratException);
}

TEST(Compte, ConstructeurAvecDescriptionInvalide){
	ASSERT_THROW(CompteTest compteTest(5000, 0.3, 1500, ""), ContratException);
}

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


TEST_F(UnCompte, reqNoCompte){
	ASSERT_EQ(1234, t_compte.reqNoCompte());
}

TEST_F(UnCompte, reqTauxInteret){
	ASSERT_EQ(0.3, t_compte.reqTauxInteret());
}

TEST_F(UnCompte, reqSolde){
	ASSERT_EQ(2000, t_compte.reqSolde());
}

TEST_F(UnCompte, reqDercription){
	ASSERT_EQ("description", t_compte.reqDescription());
}

TEST_F(UnCompte, reqDateOuverture){
	ASSERT_EQ(util::Date(), t_compte.reqDateOuverture());
}

TEST_F(UnCompte, reqCompteFormate){
	ASSERT_EQ("numero: 1234\nDescription: description\nDate d'ouverture: "+ t_compte.reqDateOuverture().reqDateFormatee() +"\nTaux d'interet: 0.3\nSolde: 2000$" , t_compte.reqCompteFormate());
}

TEST_F(UnCompte, asgTauxInteret){
	t_compte.asgTauxInteret(3.1);
	ASSERT_EQ(3.1, t_compte.reqTauxInteret());
}

TEST_F(UnCompte, asgSolde){
	t_compte.asgSolde(2000);
	ASSERT_EQ(2000, t_compte.reqSolde());
}

TEST_F(UnCompte, asgDescriptionValide){
	t_compte.asgDescription("cheque");
	ASSERT_EQ("cheque", t_compte.reqDescription());
}

TEST_F(UnCompte, asgDescriptionInvalide){
	ASSERT_THROW(t_compte.asgDescription(""), PreconditionException);
}





