#include "stdafx.h"
#include "Wallet.h"


Wallet::Wallet(Node* n_h, int ID_h)
{
	networknode = n_h;
	ID = ID_h;

	cout << "Created Wallet ID: " << ID << endl;

}


Wallet::~Wallet()
{
}

void Wallet::new_transaction(TransInfo* ti_h) {

	int confirmations = 1;

	//TODO adapting confrimations

	cout << "Wallet " << ID << ": started new transaction" << endl;

	transactions.push_back(new Transaction(this,ti_h->target,ti_h->amount,confirmations,networknode,ti_h->ID));

}