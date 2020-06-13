#ifndef PLAYER_H
#define PLAYER_H


#include "Object.h"
#include "Item.h"
class Player :
	public Object
{
public:
	Player();
	void print() const;
	void levelUp();

	int getLevel() const;
	int damage() const;
	void defense(int damage);
	void heal();

private:
	std::map<Item::Type, Item> inventory;
	int SP{ 0 };
};

#endif // !PLAYER_H