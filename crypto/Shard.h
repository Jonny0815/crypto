#pragma once

class Transaction;


class Shard
{
public:
	Shard(Transaction* rec_h);
	~Shard();

	Transaction* receiving; // confirmation will be send to this transaction
	Transaction* sending; // confirmation will be send from this transaction

	void unlock() { locked = false; }
	bool get_locked() { return locked; }
	void set_next(Shard* s_h) { next = s_h; }
	void set_prev(Shard* s_h) { prev = s_h; }
	Shard* get_next() { return next; }
	Shard* get_prev() { return prev; }

private:
	bool locked;
	Shard* next;
	Shard* prev;
};

