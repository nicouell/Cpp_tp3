/**
 * \file Client.cpp
 * \brief Implantation de la classe Client
 *        revision : normes 03-2013
 *        balises Doxygen
 * \author Nicola Ouellet Version initiale
 * \date 28 fevrier 2018
 * \version 1.0 sans contrat
 */

#include "Client.h"
#include <iostream>
#include <sstream>

using namespace std;
namespace banque{

/**
 * \brief constructeur avec parametres
 * 		  On construit un objet Client à partir de valeurs passées en parametres.
 * \param[in] p_noFolio est un entier int qui représente le numéro de folio.
 * \param[in] p_nom est une chaine de carachtère string qui représente le nom du client.
 * \param[in] p_prenom est une chaine de carachtère string qui représente le prénom du client.
 * \param[in] p_telephone est une chaine de carachtère string qui représente le numéro de téléphone du client.
 */


Client::Client(int p_noFolio, const std::string& p_nom,
		const std::string& p_prenom, const std::string& p_telephone):m_noFolio(p_noFolio), m_nom(p_nom), m_prenom(p_prenom), m_telephone(p_telephone)
{
}

/**
 * \brief retourne le numéro correspondant au numéro de folio du client
 * \return un entier int qui représente le numéro de folio du client
 */


int Client::reqNoFolio() {
	return m_noFolio;
}

/**
 * \brief retourne le nom correspondant au nom du client
 * \return une chaine de carachtère string qui représente le nom du client.
 */


std::string Client::reqNom() const {
	return m_nom;
}

/**
 * \brief retourne le prenom correspondant au prenom du client
 * \return une chaine de carachtère string qui représente le prenom du client.
 */


std::string Client::reqPrenom() const {
	return m_prenom;
}

/**
 * \brief retourne une date correspondant a la date d'ouverture du dossié
 * \return un objet Date qui représente la date d'ouverture du dossié.
 */


util::Date Client::reqDateDeNaissance() const {
	return m_dateOuverture;
}

/**
 * \brief retourne le numéro de téléphone correspondant au numéro de téléphone du client
 * \return une chaine de carachtère string qui représente le numéro de téléphone du client.
 */


std::string Client::reqTelephone() const {
	return m_telephone;
}

/**
 * \brief Assigne un numéro de téléphone à l'objet courant
 * \param[in] p_telephone est une chaine de carachtère string qui représente le numéro de téléphone du client.
 */


void Client::asgTelephone(std::string& p_telephone) {
	m_telephone = p_telephone;
}

/**
 * \brief retourne un client formatée dans une chaine de caracères (string)
 * \return un client formatée dans une chaine de caractères
 */


std::string Client::reqClientFormate() {
	ostringstream os;
	os << "Client no de folio: " << reqNoFolio() << endl;
	os << reqPrenom() << " " << reqNom() << endl;
	os << reqTelephone() << endl;
	os << "Date d'ouverture: " << m_dateOuverture.reqDateFormatee() << endl;
	return os.str();
}

/**
 * \brief surcharge de l'opérateur ==
 * \param[in] p_client qui est un client valide
 * \return un booléen indiquant si tous les paramètre sont égales ou pas
 */


bool Client::operator ==(const Client& p_client) const {
	if (m_noFolio == p_client.m_noFolio && m_nom == p_client.m_nom && m_prenom == p_client.m_prenom && m_dateOuverture == p_client.m_dateOuverture && m_telephone == p_client.m_telephone)
		return true;
	else
		return false;
}

/**
 * \brief surcharge de l'opérateur <
 * \param[in] p_client qui est un client valide
 * \return un booléen indiquant si le numéro de folio passé en paramètre est plus petit qu'un autre.
 */


bool Client::operator <(const Client& p_client) const{
	return m_noFolio < p_client.m_noFolio;
}
}
