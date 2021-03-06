// crypto.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Transaction.h"
#include "Wallet.h"

#include <thread>



int main()
{

	

	Node* n1 = new Node;

	vector<thread*> threads;

	
	Wallet* w0 = new Wallet(n1,0);
	vector<Wallet> wallets;

	for (size_t i = 1; i < 50; i++)
	{
		TransInfo* ti = new TransInfo;
		ti->amount = i;
		ti->target = w0;
		ti->ID = i;

		Wallet w(n1,i);

		
		wallets.push_back(w);

		threads.push_back(new thread(&Wallet::new_transaction, &w, ti));



	}


	for (size_t i = 0; i < threads.size(); i++)
	{
		if (threads.at(i)->joinable())
		{
			threads.at(i)->join();
		}
		
	}



	
	delete w0;
	delete n1;

    return 0;
}

