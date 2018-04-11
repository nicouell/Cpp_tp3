/*
 * Epargne.h
 *
 *  Created on: 2018-04-10
 *      Author: etudiant
 */

#ifndef EPARGNE_H_
#define EPARGNE_H_
#include "Compte.h"

namespace banque {

/*
 *
 */
class Epargne: public Compte{
public:
	Epargne(int p_nocompte, double p_tauxInteret, double p_solde, const std::string& p_description="Epargne");
	virtual ~Epargne();

	virtual double calculerInteret() const;
	virtual std::string reqCompteFormate() const;
	virtual Compte* clone() const;
};

} /* namespace banque */

#endif /* EPARGNE_H_ */
