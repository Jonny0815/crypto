#include "stdafx.h"
#include "Node.h"


Node::Node()
{
	shards.push_back(new Shard(NULL));
	shards.push_back(new Shard(NULL));
}


Node::~Node()
{
}

Shard* Node::issue_shard(Shard* new_shard_h) {

	
 
	if (shards.size() == 0)
	{
		

		shards.push_back(new_shard_h);
		cout << "Node shard.size 0, actual size :" << shards.size() << endl;
		return NULL;
	}
	else {

		for (list<Shard*>::iterator it = shards.begin(); it != shards.end(); it++)
		{
			
			if ((*it)->receiving != new_shard_h->sending && !(*it)->get_locked())
			{
				(*it)->sending = new_shard_h->receiving;
				(*it)->set_next(new_shard_h);
				new_shard_h->set_prev((*it));
				shards.push_back(new_shard_h);
				cout << "sucessfull return shard, actual size: " << shards.size() << endl;
				return (*it);
			}
			
		
		}

		shards.push_back(new_shard_h);
		cout << "somehow landed on the end, actual size " << shards.size() << endl;
		return NULL;

	}

	

}