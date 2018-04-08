/*
 * validationFormat.cpp

 *
 *  Created on: 2018-02-13
 *      Author: etudiant
 */

#include "validationFormat.h"
#include <fstream>


using namespace std;
namespace util{

bool validerFormatNom (const std::string& p_nom)
{
  int i  = 0;
  while (p_nom[i])
  {
      if (!(isalpha(p_nom[i]))){
	  if(p_nom[i] != ' '){
	    return false;
	}
      }
      i++;
  }
  return true;
}

bool validerTelephone (const std::string& p_telephone)
{
  string codeRege = p_telephone.substr(0, 3);
  string codeLocal = p_telephone.substr(4, 8);
  int longueurNum = p_telephone.length();
  unsigned int longueurLocal = codeLocal.length();
  string codeTel[] = {"403", "780", "604", "236", "250", "778", "902", "204", "204", "506", "902", "905", "519", "289", "705", "613",
  "807", "416", "647", "438", "514", "450", "579", "418", "581", "819", "306", "709", "867", "800", "866", "877", "888", "855"};

  if(longueurNum != 12){
      return false;
  }


  if(p_telephone[3] != ' '){
      return false;
  }

  for (unsigned int i = 0; i < longueurLocal; ++i){
     if(!(isdigit(codeLocal[i]))){
	 if(codeLocal[3] != '-'){
	     return false;
	 }
     }
  }

  unsigned int sizeCodeTel = sizeof(codeTel)/sizeof(*codeTel);

  for(unsigned int i = 0; i < sizeCodeTel; ++i){
      if((codeRege == codeTel[i]) or (p_telephone[0] == '9')){
	  return true;
      }
  }

  return false;

}

bool validerFormatFichier (std::istream& p_is)
{
  string liste[] = {};
  int i = 0;
  int ligneDebutCompte = 5;
  string ligne;
  string cheque = "cheque";
  string epargne = "epargne";
  while(getline(p_is, ligne)){
      if((i <= 1) and (!(validerFormatNom(ligne)))){
	  return false;
      }
      if(i == 2){
	  int longueurDate = ligne.length();
	  if (longueurDate == 10){
	     if((!(isdigit(ligne[0]))) or (!(isdigit(ligne[3]))) or (!(isdigit(ligne[6]))) or (!(isdigit(ligne[9])))){
		return false;
	     }
	  }
	  else if (longueurDate == 9){
	     if((!(isdigit(ligne[0]))) or (!(isdigit(ligne[3]))) or (!(isdigit(ligne[5]))) or (!(isdigit(ligne[8])))){
		return false;
	     }
	  }
	  else if (longueurDate == 8){
	      if((!(isdigit(ligne[0]))) or (!(isdigit(ligne[2]))) or (!(isdigit(ligne[4]))) or (!(isdigit(ligne[7])))){
		return false;
	     }

	  }
      }

      if((i == 3) and (!(validerTelephone(ligne)))){
	  return false;
      }
      if(i == ligneDebutCompte){
	  if(ligne == cheque){
	     ligneDebutCompte = i + 7;
	  }
	  else if(ligne == epargne){
	     ligneDebutCompte = i + 6;
	  }
	  else{
	      return false;
	  }
      }
      i++;
  }
  if (i != ligneDebutCompte){
      return false;
  }
  return true;
}

}//namespace util
