#pragma once
#include "Transaction.h"
#include "Node.h"

#include <vector>


using namespace std;

struct TransInfo
{
	int amount;
	Wallet* target;
	int ID;
};

class Wallet
{
public:
	Wallet(Node*, int);
	~Wallet();

	void new_transaction(TransInfo* ti_h);
	int get_amount() { return amount; };
	vector<Transaction*> get_transactions() { return transactions; }


private:
	int amount;
	vector<Transaction*> transactions;
	Node* networknode;
	int ID;

};

