/*
 * ClientTesteur.cpp
 *
 *  Created on: 2018-04-11
 *      Author: etudiant
 */

#include <gtest/gtest.h>
#include "Client.h"

using namespace std;
using namespace banque;

TEST(Client, constructeurAvecParametreValide){
	Client t_client(1500, "ouellet", "nicola", "581 246-4094");
	ASSERT_EQ(1500, t_client.reqNoFolio());
	ASSERT_EQ("ouellet", t_client.reqNom());
	ASSERT_EQ("nicola", t_client.reqPrenom());
	ASSERT_EQ("581 246-4094", t_client.reqTelephone());
}

TEST(Client, constructeurAvecParametreInvalide){
	ASSERT_THROW(Client t_client(500, "ouellet", "nicola", "581 246-4094"), PreconditionException);
	ASSERT_THROW(Client t_client(500, "ouellet", "nic0la", "581 246-4094"), PreconditionException);
	ASSERT_THROW(Client t_client(500, "ouel1et", "nicola", "581 246-4094"), PreconditionException);
}

class UnClient: public ::testing::Test{
public:
	UnClient():
		t_client(1500, "ouellet", "nicola", "581 246-4094"){
	}
	Client t_client;
};
