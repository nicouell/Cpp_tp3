/**
 * \file Compte.h
 * \brief Fichier qui contient l'interface de la classe Compte qui sert au maintien et à la manipulation des comptes.
 * \author Nicola Ouellet Version initiale
 * \date 8 avril 2018
 * \version 1.0
 */

#ifndef COMPTE_H_
#define COMPTE_H_

#include "ContratException.h"
#include "Date.h"

class Compte {

/**
 * \class Compte
 * \brief Cette classe sert au maintien et à la manipulation des comptes.
 *
 *             La classe maintient dans un état cohérent ces renseignements.
 *             Elle valide ce qu'on veut lui assigner.
 *  Attributs:   p_noCompte   Le numéro de folio du compte.
 * 				time_t m_temps pour long m_temps
 * \invariant m_temps >= 1er janvier 1970 et >= au 31 décembre 2037
 * \invariant La validité peut être vérifiée avec la méthode statique
 *              bool Date::verifierDate(jour, mois, annee).
 */


public:
	Compte(int p_noCompte, double p_tauxInteret, double p_solde, const std::string& p_description);
	virtual ~Compte();

	int reqNoCompte() const;
	double reqTauxInteret() const;
	double reqSolde() const;
	std::string reqDescription() const;
	util::Date reqDateOuverture() const;
	virtual std::string reqCompteFormate() const;

	void asgTauxInteret(double p_tauxInteret);
	void asgSolde(double p_solde);
	void asgDescription(std::string& p_description);

	virtual double calculerInteret() const = 0;
	virtual Compte* clone() const = 0;


private:
	int m_noCompte; //doit être positif
	double m_tauxInteret;
	double m_solde;
	std::string m_description; //doit être non vide
	util::Date m_dateOuverture; //date à la création du compte
	void verifieInvariant() const;
};

#endif /* COMPTE_H_ */
