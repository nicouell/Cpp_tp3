/*
 * Main.cpp
 *
 *  Created on: 2018-04-04
 *      Author: etudiant
 */

#include <iostream>
#include "Client.h"
#include "Epargne.h"
#include "Cheque.h"

using namespace std;
using namespace util;
using namespace banque;

int main() {

	cout << "Bienvenue a l'outil client" << endl;
	cout << "------------------------------------" << endl;

	bool validation = false;
	int noFolio;
	string nom;
	string prenom;
	string telephone;
	Date date(19, 10, 1994);
	int jours;
	int mois;
	int annee;


	cout << endl;
	while(!validation){
		cout << "Entrez le numero de folio du client [1000, 10000[" << endl;
		cin >> noFolio;
		if(noFolio <= 1000 or noFolio > 10000){
			cout << "Le numéro de folio n'est pas entre 1000 et 10000 exclusivement" << endl;
		}
		else{
			validation = true;
		}
	}

	validation = false;

	cout << endl;
	getline(cin, prenom);
	while(!validation){
		cout << "Entrez le prénom: " << endl;
		getline(cin, prenom);
		if(validerFormatNom(prenom)){
			validation = true;
		}
		else{
			cout << "Le prénom n'est pas valide";
		}
	}

	validation = false;

	cout << endl;
	while(!validation){
		cout << "Entrez le nom: " << endl;
		getline(cin, nom);
		if(validerFormatNom(nom)){
			validation = true;
		}
		else{
			cout << "Le nom n'est pas valide";
		}
	}

	validation = false;


	cout << endl;
	while(!validation){
		cout << "Entrez le numero de telephone XXX CCC-CCCC: " << endl;
		getline(cin, telephone);
		if(validerTelephone(telephone)){
			validation = true;
		}
		else{
			cout << "Le numéro de téléphone n'est pas valide";
		}
	}

	validation = false;


	cout << endl;
	while(!validation){
		cout << "Entrez le jour de la date de naissance format(jj): ";
		cin >> jours;
		cout << "Entrez le mois de la date de naissance format(mm): ";
		cin >> mois;
		cout << "Entrez l'annee de la date de naissance format(aaaa): ";
		cin >> annee;

		if (date.validerDate(jours,mois,annee)){
			validation = true;
		}
		else{
			cout << "La date de Naissance est Invalide."<< endl;
			cout << endl;
		}
	}

	validation = false;


	cout << endl;

	cout << "Fichier client" << endl;
	cout << "-----------------------------------" << endl;

	Client nicola(noFolio, nom, prenom, telephone, date);
	cout << nicola.reqClientFormate() << endl;

	cout << "-----------------------------------" << endl;


	string typeDeCompte;
	string quitterOuRester;
	int noCompte;
	double tauxInteret;
	double solde;
	int nombreTransaction;
	bool quit = false;

	cin.ignore();

	while(!quit){
		cout << "Voulez-vous créer un compte cheque ou un compte epargne ?" << endl;
		getline(cin, typeDeCompte);

		if(typeDeCompte == "cheque"){
			cout << "Création d'un compte Chèque" << endl;
			cout << "-----------------------------------" << endl;
			while(!validation){
				cout << "Entrez le numéro de compte désiré:" << endl;
				cin >> noCompte;
				if(noCompte > 0){
					validation = true;
				}
				else{
					cout << "Le numéro de compte doit être plus grand que zéro" << endl;
				}
			}

			validation = false;

			cout << "Entrez le solde du compte" << endl;
			cin >> solde;

			cout << endl;

			while(!validation){
				cout << "Entrez le taux d'intéret du compte:" << endl;
				cin >> tauxInteret;
				if(tauxInteret >= 0.1 && tauxInteret < 100){
					validation = true;
				}
				else{
					cout << "Le taux d'interet doit être entre 0.1 et 100" << endl;
				}
			}

			validation = false;

			while(!validation){
				cout << "Entrez le nombre de transactions du compte cheque: " << endl;
				cin >> nombreTransaction;
				if(nombreTransaction > 0 && nombreTransaction <= 40){
					validation = true;
				}
				else{
					cout << "Le nombre de transactions doit être entre 1 et 40" << endl;
				}
			}

			validation = false;

			Cheque chequeID(noCompte, tauxInteret, solde, nombreTransaction);
			nicola.ajouterCompte(chequeID);
			cout << nicola.reqReleves() << endl;

		}
		else if(typeDeCompte == "epargne"){
			cout << "Création d'un compte Epargne" << endl;
			cout << "-----------------------------------" << endl;
			while(!validation){
				cout << "Entrez le numéro de compte désiré:" << endl;
				cin >> noCompte;
				if(noCompte > 0){
					validation = true;
				}
				else{
					cout << "Le numéro de compte doit être plus grand que zéro" << endl;
				}
			}

			validation = false;

			cout << "Entrez le solde du compte" << endl;
			cin >> solde;

			cout << endl;

			while(!validation){
				cout << "Entrez le taux d'intéret du compte:" << endl;
				cin >> tauxInteret;
				if(tauxInteret >= 0.1 && tauxInteret < 3.5){
					validation = true;
				}
				else{
					cout << "Le taux d'interet doit être entre 0.1 et 3.5" << endl;
				}
			}

			validation = false;

			Epargne epargneID(noCompte, tauxInteret, solde);
			nicola.ajouterCompte(epargneID);
			cout << nicola.reqReleves() << endl;

		}
		cin.ignore();
		cout << "-----------------------------------" << endl;
		cout << "Si vous voulez quitter écrivez quit sinon écrivez rester ?" << endl;
		getline(cin, quitterOuRester);
		if(quitterOuRester == "quit"){
			quit = true;
		}
		else{
			quit = false;
		}
	}

	cout << "Au revoir et à la prochaine.";
	return 0;

}

