// Erik Garcia Montoya.
// 04/29/19

#include "Gladiator.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int main()
{
	 
	srand(time(NULL));
	string start,
		name,
		name2;

	short choice_0,
		choice_1,
		verifier = 0;
	int num_Ppl,
		tracker1,
		tracker2;
	
	vector <Gladiator> Team1;
	vector <Gladiator> Team2;
	Gladiator fighter0(name);
	Gladiator fighter2(name);

	cout << "           You Have Been Chosen to Host the Contest             \n";
	cout << "                  Do You choose to Continue?                    \n";
	cout << "                           1.[YES]                              \n";
	cout << "                           2. [NO]                              \n";
	cin >> choice_0;
	if (choice_0 == 2)
	{
		exit(0);
	}
	cout << "*******************************************\n";
	cout << "*          -=Gladiator Battle 2=-         *\n";
	cout << "*               |Main Menu|               *\n";
	cout << "*                                         *\n";
	cout << "*******************************************\n";

	int reverse = 0;
	
	//Creation of 1st Team
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the name of Fighter number " << i << " for Team 1\n";
		cin >> name;
		Gladiator fighter1(name);
		
		fighter1.display();
		Team1.push_back (fighter1);
	}
	// Creation of 2st Team
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the name of Fighter number " << i << " for Team 2\n";
		cin >> name;
		Gladiator fighter2 = Gladiator (name);
		Team2.push_back(fighter2);
		fighter2.display();

	}
			

	
	do
	{
		cout << "Continue?"
			"1.FIGHT\n" << "4. Exit" << endl;
		cin >> choice_1;

		int chek = 1000;
		for (int i = 0; i < chek; i++)
		{
			if (i % 2 == 0)
			{
				//Glad 1 attack
				cout << "------------------------------\n";
				cout << Team1.front()._name << "'s turn." << endl;

				int i = 0;
				i = (Team1.front().rollDamage());
				Team2.front().takeDamage(i);
				
				tracker1 = Team2.front().getCurHealth();
				if (tracker1 <= 0)
				{
					cout << Team2.front()._name << " has been killed. " << Team1.front()._name
						<< " is the winner.\n";
					cout << "Press any button to continue. Except the off button." << endl;
					cin >> choice_0;//used to pause program until button is pressed
					Team2.erase(Team2.begin());
					if (Team2.empty())
					{
						cout << "Team 1 wins\n";
						break;
					}
				}
			}
			else
			{
				//Glad 2 attack
				cout << "------------------------------\n";
				cout << Team2.front()._name << "'s turn." << endl;

				fighter0 = Team2.front();
				int j = 0;
				j = fighter0.rollDamage();
				Team1.front().takeDamage(j);
				
				tracker2 = (Team1.at(0).getCurHealth());
				if (tracker2 <= 0)
				{
					cout << Team1.front()._name << " has been killed. " << Team2.front()._name
						<< " is the winner.\n";
					Team1.erase(Team1.begin());
					cout << "Press any button to continue. Except the off button." << endl;
					cin >> choice_0;//used to pause program until button is pressed
					if (Team1.empty())
					{
						cout << "Team 2 wins\n";
						break;
					}
				}
			}
		}
	} while (choice_1 != 4);
	return 0;
}

