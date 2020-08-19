#include "Gladiator.h"
#include <iostream>

Gladiator::Gladiator(std::string name)
{
	_name = name;
	_dmgMin = rand()%7+8;
	_dmgRange = rand()%7+16;
	_evasion = (rand()%3 * 5) + 5;
	_critical = (rand()%3 * 5) + 5;
	_maxHealth = 150 + 50 * rand()%3;
	_curHealth = _maxHealth;
}

int Gladiator::rollDamage()
{
	int dmg = rand()%(_dmgRange+1)+_dmgMin;
	if(rand()%100 < _critical) 
	{
		std::cout << "Critical!\n";
		dmg *= 2;
	}
	return dmg;
}

void Gladiator::display()
{
	std::cout << _name << ": " << _curHealth << '/' << _maxHealth << " " <<
		_dmgMin << '-' << _dmgMin + _dmgRange << " Crit-" << _critical <<
		"% Evade-" << _evasion << "%\n";
}

bool Gladiator::takeDamage(int dmgAmt)
{
	if(rand()%100 > _evasion)
	{
		std::cout << "Evaded!\n";
		return false;
	}
	_curHealth -= dmgAmt;
	return _curHealth > 0;
}
