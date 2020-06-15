#include <iostream>
#include "Item.h"

Item::Item(Type classification, int bonusValue) : classification{ classification }, bonusValue{bonusValue}
{
}

Item::Type Item::getClassification() const
{
	return classification;
}

int Item::getBonusValue() const
{
	return bonusValue;
}

/*void Item::printItem()
{
	switch (getClassification())
	{
	case Item::Type::armor:
		std::cout << "Armor";
		break;
	case Item::Type::shield:
		std::cout << "Shield";
		break;
	case Item::Type::sword:
		std::cout << "Sword";
		break;
	}
	std::cout << "+" << getBonusValue();
}*/

std::ostream& operator<<(std::ostream& output, const Item& thing)
{
	switch (thing.getClassification())
	{
	case Item::Type::armor:
		output << "Armor";
		break;
	case Item::Type::shield:
		output << "Shield";
		break;
	case Item::Type::sword:
		output << "Sword";
		break;
	}
	output << "+" << thing.getBonusValue();
	return output;
}

bool operator<(const Item& thing1, const Item& thing2)
{
	if (thing1.getBonusValue() < thing2.getBonusValue())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int& operator+=(Item& thing1, const Item& thing2)
{
	thing1.bonusValue += thing2.bonusValue;
	return thing1.bonusValue;
}
