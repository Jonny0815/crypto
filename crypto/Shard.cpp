#include "stdafx.h"
#include "Shard.h"


Shard::Shard(Transaction* rec_h)
{
	if (rec_h == NULL)
	{
		locked = false;
	}
	else {

		locked = true;

	}
	receiving = rec_h;
	

}


Shard::~Shard()
{
}
