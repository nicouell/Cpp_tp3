/**
 * \file Client.h
 * \brief Fichier qui contient l'interface de la classe Date qui sert au maintien et � la manipulation des dates.
 * \author Nicola Ouellet Version initiale
 * \date 28 fevrier 2018
 * \version 1.0 sans contrat
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <iostream>
#include "Date.h"
#include "validationFormat.h"


namespace banque{
/**
 * \class Client
 * \brief Cette classe sert au maintien et à la manipulation des clients.
 */


class Client {
public:
	Client(int p_noFolio, const std::string& p_nom, const std::string& p_prenom, const std::string& p_telephone);

	int reqNoFolio();

	std::string reqNom() const;

	std::string reqPrenom() const;

	util::Date reqDateDeNaissance() const;

	std::string reqTelephone() const;
	void asgTelephone(std::string& p_telephone);

	std::string reqClientFormate();

	bool operator==(const Client& p_client) const;
	bool operator<(const Client& p_client) const;



private:
	int m_noFolio;
	std::string m_nom;
	std::string m_prenom;
	std::string m_telephone;
	util::Date m_dateOuverture;
	void verifieInvariant() const;
};
} //namespace

#endif /* CLIENT_H_ */
