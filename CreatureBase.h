#pragma once
#include "Includes.h"
using namespace std;

enum CreatureType
{
	You = 1,
	Ogre,
	Goblin,
	Dwarf,
	Dragon,
	Troll,
	Gabriel,
	Princess,
	Zorf,
	AyoCheetah
};

class CreatureBase
{
public:

	int m_nID;
	int m_nHealth;
	int m_nRoom;

	virtual string GetDescription()
	{
		return "Should not get here.";
	}

};

class Enemy : CreatureBase
{
protected:

	int m_nAngerLevel;
	int m_nDamageMultiplier; // how strong they are
	int m_nTurnsBetweenHits;
	bool m_bActivelyWantsToKillYou;
	int m_nTurn;

	virtual void TakeTurn( )
	{
		// override this
	}
};

class Troll : public Enemy
{
	virtual string GetDescription()
	{
		if (!m_bActivelyWantsToKillYou)
		{
			return "A disgusting, drooling Troll is here. Minding his own business, apparently. He seems to be looking up stocks on his iPhone?";
		}

		if (m_nAngerLevel < 10)
		{
			return "There's a sort of angry Troll next to you, smacking his club into his hand, menacingly...";
		}

		return "There's a royal pissed off Troll in front of you, and he's really stinky too";
	}

	virtual void TakeTurn()
	{
		if (m_nTurn == 0)
		{
			Attack();
			m_nTurn = m_nTurnsBetweenHits;
			return;
		}

		// just waiting around?
	}

	virtual void Attack()
	{
		cout << "The Troll attacks you! WHOMP goes his club!" << endl;
		int damage = rand() % 20;
		damage *= m_nDamageMultiplier;
		if (damage == 0)
		{
			cout << "... on the ground? The troll missed? (he looks embarassed)" << endl;
		}
		else
		{
			cout << "The troll hit you for " << damage << " hit points";
		}
	}


};
