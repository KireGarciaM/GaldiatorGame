#include <string>

//Fighter in the ring
class Gladiator {
private:
	int _dmgMin,//The lowest amount of damage a gladiator can inflict with a successful attack
		_dmgRange,//The most damage ABOVE Minimum Damage that the gladiator can inflict with a single, non-critical hit
		_evasion, //The % chance (0-100) that the gladiator will completely avoid incoming damage when defending
		_critical,//The % chance (0-100) that the gladiator will inflict twice (2x) the rolled damage when attacking the opponent (known as a crit)
		_maxHealth,//The amount of HP a gladiator will start each fight with
		_curHealth;//The amount of HP a gladiator has left before they have died and lost the fight

public:
	//How the gladiator is referenced to the user, provided somehow in the constructor
	std::string _name;

	//Called upon creation; prevent any uninitialized values from being available
	Gladiator(std::string name);//Constructor
				//Use this to obtain all information on our gladiators, including their name.
				//Confirmation of the created gladiator is permitted but NOT required.

	//Accessor for health
	int getCurHealth() { return _curHealth; }

	void prepareForNewFight() { _curHealth = _maxHealth; }

	//Calculates a damage roll based on dmgMin, dmgRange, and crit
	//This would be a good place to display a crit notification
	int rollDamage();

	//Displays gladiator's stats, in one or two lines so it's pleasing in a list
	void display();

	//Returns whether the gladiator was killed by the damage or not
	bool takeDamage(int dmgAmt);

};
