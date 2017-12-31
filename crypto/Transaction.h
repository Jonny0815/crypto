#pragma once

#include "Shard.h"
#include "Node.h"
#include <vector>
#include <thread>

using namespace std;


class Wallet;

class Transaction
{
public:
	Transaction();
	Transaction(Wallet* origin_h, Wallet* destination_h, int amount_h, int confirmations_h, Node* n_h, int ID_h);
	~Transaction();

	bool validate(Transaction* trans_h);
	bool revalidate(Transaction* trans_h);

	vector<Shard*> get_sending() { return sending; }
	Wallet* get_origin() { return origin; }

	void add_receiving(Shard* s_h) { receiving.push_back(s_h); }

private:
	Wallet* origin;
	Wallet* destination;
	int amount;
	int weight;
	int ID;

	vector<Shard*> sending;
	vector<Shard*> receiving;



};

