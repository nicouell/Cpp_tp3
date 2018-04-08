/*
 * validationFormat.h
 *
 *  Created on: 2018-02-13
 *      Author: etudiant
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

namespace util{

bool validerFormatNom(const std::string& p_nom);
bool validerTelephone(const std::string& p_telephone);
bool validerFormatFichier(std::istream& p_is);

} //namespace util

#endif /* VALIDATIONFORMAT_H_ */
