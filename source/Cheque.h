/*
 * Cheque.h
 *
 *  Created on: 2018-04-11
 *      Author: etudiant
 */

#ifndef CHEQUE_H_
#define CHEQUE_H_
#include "Compte.h"

namespace banque {

/*
 *
 */
class Cheque: public Compte {
public:
	Cheque(int p_noCompte, double p_tauxInteret, double p_solde, int p_nombreTransactions,
			double p_tauxInteretMinimum = 0.1, const std::string& p_description = "Cheque");
	virtual ~Cheque();

 	virtual double calculerInteret() const;
	virtual std::string reqCompteFormate() const;
	virtual Compte* clone() const;

	void asgNombreTransactions(int p_nombreTransactions);
	double reqTauxInteretMinimum() const;
	int reqNombreTransactions() const;


private:
	int m_nombreTransactions;
	double m_tauxInteretMinimum;
	void verifieInvariant() const;
};

} /* namespace banque */

#endif /* CHEQUE_H_ */
