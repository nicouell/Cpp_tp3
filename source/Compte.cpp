/*
 * Compte.cpp
 *
 *  Created on: 2018-04-07
 *      Author: etudiant
 */

#include "Compte.h"
#include <iostream>
#include <sstream>

Compte::Compte(int p_noCompte, double p_tauxInteret, double p_solde, const std::string& p_description):
			  m_noCompte(p_noCompte), m_tauxInteret(p_tauxInteret), m_solde(p_solde), m_description(p_description)
{

}

Compte::~Compte() {
	// TODO Auto-generated destructor stub
}

int Compte::reqNoCompte() const {
	return m_noCompte;
}

double Compte::reqTauxInteret() const {
	return m_tauxInteret;
}

double Compte::reqSolde() const {
	return m_solde;
}

std::string Compte::reqDescription() const {
	return m_description;
}

util::Date Compte::reqDateOuverture() const {
	return m_dateOuverture;
}

std::string Compte::reqCompteFormate() const {
	std::ostringstream os;
	return os.str();
}

void Compte::asgTauxInteret(double p_tauxInteret) {
}

void Compte::asgSolde(double p_solde) {
}

void Compte::asgDescription(std::string& p_description) {
}

double Compte::calculerInteret() {
}

Compte* Compte::clone() const {
}
