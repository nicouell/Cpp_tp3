/*
 * CompteChequeTesteur.cpp
 *
 *  Created on: 2018-04-11
 *      Author: etudiant
 */

#include <gtest/gtest.h>
#include "Cheque.h"

using namespace std;
using namespace banque;

TEST(Epargne, constructeurAvecParametreValide){
	Cheque t_cheque(1500, 1.5, 5000, 25, 0.2, "description");
	ASSERT_EQ(1500, t_cheque.reqNoCompte());
	ASSERT_EQ(1.5, t_cheque.reqTauxInteret());
	ASSERT_EQ(5000, t_cheque.reqSolde());
	ASSERT_EQ(25, t_cheque.reqNombreTransactions());
	ASSERT_EQ(0.2, t_cheque.reqTauxInteretMinimum());
	ASSERT_EQ("description", t_cheque.reqDescription());
}


