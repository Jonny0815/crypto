#include "stdafx.h"
#include "Transaction.h"



Transaction::Transaction()
{	
}

Transaction::Transaction(Wallet* origin_h, Wallet* destination_h, int amount_h, int confirmations_h, Node* n_h, int ID_h)
{
	

	this->origin = origin_h;
	this->destination = destination_h;
	this->amount = amount_h;
	this->ID = ID_h;

	while (sending.size() < confirmations_h)
	{

		vector<Shard*> shards_to_validate;
		for (size_t i = 0; i < confirmations_h - sending.size(); i++)
		{
			Shard* s = new Shard(this);
			receiving.push_back(s);

			cout << "Transaction " << ID << " starts issuing shard" << endl;
			Shard* r = n_h->issue_shard(s);
			cout << "Transaction " << ID << " finished issuing shard" << endl;
			if (r != NULL)
			{
				shards_to_validate.push_back(r);
			}
			else {
				this_thread::sleep_for(1s);
			}


		}

		for (size_t i = 0; i < shards_to_validate.size(); i++)
		{
			if (validate(shards_to_validate.at(i)->receiving) && revalidate(shards_to_validate.at(i)->receiving))
			{
				sending.push_back(shards_to_validate.at(i));
			}
		}



		for (size_t i = 0; i < receiving.size(); i++)
		{
			receiving.at(i)->unlock();
		}

	}
}

Transaction::~Transaction()
{
}

bool Transaction::validate(Transaction* trans_h) {


	if (trans_h == NULL)
	{
		return true;
	}
	else {
		// crypto shinanigans here

		return true;
	}
}

bool Transaction::revalidate(Transaction* trans_h) {

	for (size_t i = 0; i < trans_h->get_sending().size(); i++)
	{
		if (!validate(trans_h->get_sending().at(i)->sending))
		{
			return false;
		}
	}

	return true;
}