/*
 * Epargne.cpp
 *
 *  Created on: 2018-04-10
 *      Author: etudiant
 */

#include "Epargne.h"

using namespace std;
namespace banque {


Epargne::Epargne(int p_noCompte, double p_tauxInteret, double p_solde,
		const std::string& p_description): Compte(p_noCompte, p_tauxInteret, p_solde, p_description) {

	PRECONDITION(p_tauxInteret >= 0.1 && p_tauxInteret <= 3.5);
}

Epargne::~Epargne() {}

double Epargne::calculerInteret() const{
	return this->reqTauxInteret()*this->reqSolde()*0.01;
}

string Epargne::reqCompteFormate() const {
	ostringstream os;
	os << "Compte Epargne" << endl;
	os << Compte::reqCompteFormate() << endl;
	os << "Interet: " << this->calculerInteret() << "$"<< endl;
	return os.str();
}

Compte* Epargne::clone() const {
	return new Epargne(*this);
}

} /* namespace banque */
