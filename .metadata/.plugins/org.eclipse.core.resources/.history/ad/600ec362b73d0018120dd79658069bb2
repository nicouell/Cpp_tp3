/*
 * CompteEpargneTesteur.cpp
 *
 *  Created on: 2018-04-10
 *      Author: etudiant
 */

#include <gtest/gtest.h>
#include "Epargne.h"

using namespace std;
using namespace banque;

TEST(Epargne, constructeurAvecParametreValide){
	Epargne t_epargne(1500, 1.5, 5000, "description");
	ASSERT_EQ(1500, t_epargne.reqNoCompte());
	ASSERT_EQ(1.5, t_epargne.reqTauxInteret());
	ASSERT_EQ(5000, t_epargne.reqSolde());
	ASSERT_EQ("description", t_epargne.reqDescription());
}

TEST(Epargne, ConstructeurAvecPrametreInvalide){
	ASSERT_THROW(Epargne t_epargne(1500, 0.0, 5000, "description"), PreconditionException);
	ASSERT_THROW(Epargne t_epargne(1500, 5.0, 5000, "description"), PreconditionException);
}

class UnCompteEpargne: public ::testing::Test{
public:
	UnCompteEpargne():
		t_epargne(1500, 1.5, 5000, "description"){
	}
	Epargne t_epargne;
};

TEST_F(UnCompteEpargne, calculerInteret){
	ASSERT_EQ(t_epargne.reqSolde()*t_epargne.reqTauxInteret()*0.01, t_epargne.calculerInteret());
}

TEST_F(UnCompteEpargne, reqCompteFormate){
	double interet = t_epargne.calculerInteret();
	stringstream ss;
	ss << interet;
	string str = ss.str();
	ASSERT_EQ("Compte Epargne\nnumero: 1500\nDescription: description\nDate d'ouverture: "+ t_epargne.reqDateOuverture().reqDateFormatee() +"\nTaux d'interet: 1.5\nSolde: 5000$\nInteret: " + str + "$\n" , t_epargne.reqCompteFormate());
}
