#pragma once

#include "Shard.h"

#include <list>

using namespace std;

class Transaction;

class Node
{
public:
	Node();
	~Node();


	Shard* issue_shard(Shard*);
	

private:
	list<Shard*> shards;
	
};

