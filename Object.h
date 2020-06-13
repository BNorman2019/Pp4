#ifndef OBJECT_H
#define OBJECT_H

#include <map>
#include <random>


class Object
{
public:
	static std::random_device seed;
	static std::default_random_engine engine;
	enum class Type { player, slime, orc, sprite, dragon, numTypes };
	
	Object() {}
	Object(Type name, int strength, int health, int level);
	
	void printName() const;
	bool isDead();


protected:
	Type name;
	int strength{ 0 };
	int health{ 0 };
	int level{ 0 };
	
};
#endif // !OBJECT_H

