#include <random>
#include <iostream>
#include "Player.h"

Player::Player() :Object(Object::Type::player, 0, 1, 0)
{

}

void Player::print() const
{
	printName();
	std::cout << " h:" << health << ", SP:" << SP <<  std::endl;
	std::for_each(inventory.begin(), inventory.end(), [](std::pair<Item::Type, Item> item)
		{
			std::cout << "  ";
			item.second.printItem();
			std::cout << std::endl;
		});
}

void Player::levelUp()
{
	level++;
	std::normal_distribution<double> randomHealth(20.0 + level * 5, 5.0);
	health += std::max(1, (int)randomHealth(engine));

	std::normal_distribution<double> randomStrength(3.0 + level, 1.0);
	strength += std::max(1, (int)randomStrength(engine));
	SP += std::max(1, (int)randomStrength(engine));

	//grab new item.
	std::uniform_int_distribution<int> randomItem(0, (int)Item::Type::numTypes - 1);
	std::normal_distribution<double> randomBonus((double)level, (double)level / 2);
	Item found{ (Item::Type)randomItem(engine), std::max(1, (int)randomBonus(engine)) };

	std::cout << "You found a ";
	found.printItem();
	std::cout << "!!!!" << std::endl;
	if (
		auto haveOne{ inventory.find(found.getClassification()) };
		haveOne == inventory.end()
		|| inventory[found.getClassification()].getBonusValue() < found.getBonusValue()
		)
	{
		std::cout << "You keep the shiny new toy!" << std::endl;
		inventory[found.getClassification()] = found;
	}
	else
	{
		std::cout << "You toss aside the ugly old thing!" << std::endl;
	}
}

int Player::getLevel() const
{
	return level;
}

int Player::damage() const
{
	int potentialDamage{ strength };
	if (auto sword{ inventory.find(Item::Type::sword) }; sword != inventory.end())
	{
		potentialDamage += sword->second.getBonusValue();
	}
	std::normal_distribution<double> damageDealt(potentialDamage, 2.0);

	printName();
	std::cout << " deals ";
	return std::max(1, (int)damageDealt(engine));
}

void Player::defense(int damage) 
{
	int AC{ 0 };
	if (auto armor{ inventory.find(Item::Type::armor) }; armor != inventory.end())
	{
		AC += armor->second.getBonusValue();
	}
	if (auto shield{ inventory.find(Item::Type::shield) }; shield != inventory.end())
	{
		AC += shield->second.getBonusValue();
	}
	std::normal_distribution<double> defense(AC, 1.0 / level);
	damage = std::max(0, damage - (int)defense(engine));

	std::cout << damage << " damage to ";
	printName();
	std::cout << "!!!" << std::endl;
	health -= damage;
}

void Player::heal()
{
	if (SP >= 2)
	{


		std::normal_distribution<double> randomHeal(strength, 3.0);
		int  amountHealed{ std::max(1, (int)randomHeal(engine)) };
		printName();
		SP -= 2;
		std::cout << " is healed by " << amountHealed << "hp!" << std::endl;
		health += amountHealed;
	}
	else
	{
		std::cout << "Not enough SP!!!" << std::endl;
	}
}
