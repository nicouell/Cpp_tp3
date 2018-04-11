/*
 * Cheque.cpp
 *
 *  Created on: 2018-04-11
 *      Author: etudiant
 */

#include "Cheque.h"

using namespace std;
namespace banque {

Cheque::Cheque(int p_noCompte, double p_tauxInteret, double p_solde,
		int p_nombreTransactions, double p_tauxInteretMinimum,
		const string& p_description): Compte(p_noCompte, p_tauxInteret, p_solde, p_description),
			m_nombreTransactions(p_nombreTransactions), m_tauxInteretMinimum(p_tauxInteretMinimum){

	PRECONDITION(p_nombreTransactions <= 40);
	PRECONDITION(p_tauxInteret >= p_tauxInteretMinimum);

	POSTCONDITION(m_nombreTransactions == p_nombreTransactions);
	POSTCONDITION(m_tauxInteretMinimum == p_tauxInteretMinimum);

	INVARIANTS();
}

Cheque::~Cheque() {}

double Cheque::calculerInteret() const {
	double interet = 0;
	if(this->reqSolde() > 0){
		if(this->reqNombreTransactions() >= 0 && this->reqNombreTransactions() <= 10){
			interet = this->reqTauxInteretMinimum()*this->reqSolde()*0.01;
		}
		else if(this->reqNombreTransactions() >= 11 && this->reqNombreTransactions() <= 25){
			interet = this->reqTauxInteret()*this->reqSolde()*0.004;
		}
		else if(this->reqNombreTransactions() >= 26 && this->reqNombreTransactions() <= 35){
			interet = this->reqTauxInteret()*this->reqSolde()*0.008;
		}
		else if(this->reqNombreTransactions() > 35){
			interet = this->reqTauxInteret()*this->reqSolde()*0.01;
		}
	}
	else{
		interet = 0;
	}
	return interet;
}

std::string Cheque::reqCompteFormate() const {
	ostringstream os;
	os << "Compte Cheque" << endl;
	os << Compte::reqCompteFormate() << endl;
	os << "nombre de transactions: " << m_nombreTransactions << endl;
	os << "Taux d'interet minimum: " <<  m_tauxInteretMinimum << endl;
	os << "Interet: " << calculerInteret() <<"$" << endl;
	return os.str();
}

Compte* Cheque::clone() const {
	return new Cheque(*this);
}

void Cheque::asgNombreTransactions(int p_nombreTransactions) {
	m_nombreTransactions = p_nombreTransactions;

	PRECONDITION(p_nombreTransactions <= 40);
	POSTCONDITION(m_nombreTransactions == p_nombreTransactions);
	INVARIANTS();
}

double Cheque::reqTauxInteretMinimum() const {
	return m_tauxInteretMinimum;
}

int Cheque::reqNombreTransactions() const {
	return m_nombreTransactions;
}

void Cheque::verifieInvariant() const {
	INVARIANT(m_nombreTransactions <= 40);
	INVARIANT(m_tauxInteretMinimum <= this->reqTauxInteret());
}

} /* namespace banque */
