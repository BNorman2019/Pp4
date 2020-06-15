#ifndef ITEM_H
#define ITEM_H


class Item
{
public:
	Item() {};
	enum class Type { sword, armor, shield, numTypes };
	Item(Type classification, int bonusValue);

	Type getClassification() const;
	int getBonusValue() const;

	void printItem();

	friend  std::ostream& operator<<(std::ostream& output, const Item& thing);
	friend bool operator<(const Item& thing1, const Item& thing2);
	friend int& operator+=(Item& thing1, const Item& thing2);
private:
	Type classification;
	int bonusValue;
};

#endif // !ITEM_H