#include <random>
#include <iostream>
#include "Object.h"
std::random_device Object::seed;
std::default_random_engine Object::engine(seed());

Object::Object(Type name, int strength, int health, int level) : name{ name }, strength{ strength }, health{ health }, level{ level }
{
}

/*void Object::printName() const
{
	std::cout << "L:" << level << " ";
	switch (name)
	{
	case Object::Type::player:
		std::cout << "Player";
		break;
	case Object::Type::slime:
		std::cout << "Slime";
		break;
	case Object::Type::orc:
		std::cout << "Orc";
		break;
	case Object::Type::sprite:
		std::cout << "Sprite";
		break;
	case Object::Type::dragon:
		std::cout << "Dragon";
		break;
	}
}*/

bool Object::isDead()
{
	return health <= 0;
}

std::ostream& operator<<(std::ostream& output, const Object& thing)
{
	output << "Level: " << thing.level << " ";
	switch (thing.name)
	{
	case Object::Type::player:
		output << "Player";
		break;
	case Object::Type::slime:
		output << "Slime";
		break;
	case Object::Type::orc:
		output << "Orc";
		break;
	case Object::Type::sprite:
		output << "Sprite";
		break;
	case Object::Type::dragon:
		output << "Dragon";
		break;
	}
	return output;
}


