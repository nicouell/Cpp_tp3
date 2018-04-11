/*
 * Cheque.cpp
 *
 *  Created on: 2018-04-11
 *      Author: etudiant
 */

#include "Cheque.h"

namespace banque {

Cheque::Cheque(int p_noCompte, double p_tauxInteret, double p_solde,
		int p_nombreTransactions, double p_tauxInteretMinimum,
		const std::string& p_description): Compte(p_noCompte, p_tauxInteret, p_solde, p_description),
			m_nombreTransactions(p_nombreTransactions), m_tauxInteretMinimum(p_tauxInteretMinimum){

	PRECONDITION(p_nombreTransactions <= 40);
	PRECONDITION(p_tauxInteret >= p_tauxInteretMinimum);

	POSTCONDITION(m_nombreTransactions == p_nombreTransactions);
	POSTCONDITION(m_tauxInteretMinimum == p_tauxInteretMinimum);

	INVARIANTS();
}

Cheque::~Cheque() {}

double Cheque::calculerInteret() const {
}

std::string Cheque::reqCompteFormate() const {
}

Compte* Cheque::clone() const {
}

void Cheque::asgNombreTransactions(int p_nombreTransactions) {
}

double Cheque::reqTauxInteretMinimum() const {
}

int Cheque::reqNombreTransactions() const {
}

void Cheque::verifieInvariant() const {
	INVARIANT(m_nombreTransactions <= 40);
	INVARIANT(m_tauxInteretMinimum >= 0.1);
}

} /* namespace banque */
