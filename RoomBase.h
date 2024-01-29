#pragma once

#include "Includes.h"

enum Exits
{
	N = 1,
	S, // = 2, etc
	E,
	W,
	U,
	D,
	NW,
	SW,
	NE,
	SE
};

enum RoomTypes
{
	GrassyField = 100,
	EntryToHouse = 101,
	// etc
};

class Unrelated; // forward declaration

class RoomBase
{
public:

	RoomBase( int id )
	{
		m_nID = id;
	}

	int m_nID;
	map<int, int> m_Exits; // eg: "N" (1 in enum) maps to a room #

	virtual string GetDescription() // const means "I promise to the compiler I won't change any data members in this class when this func is called"
	{
		return "You're in a non-descript room. By defintion, I can't describe it. Deal.";
	}

	RoomBase operator + (const RoomBase& rbOther)
	{
		RoomBase rbNew(0); // pass in a zero to start off with
		rbNew.m_nID = this->m_nID + rbOther.m_nID;
		return rbNew;
	}

	void Foo()
	{
		string s = GetDescription(); // will this call the derived class or the base class only? Good question!
		cout << "answer: " << s << endl;
	}
};

class Room_GrassyField : public RoomBase
{
public:

	// constructor
	Room_GrassyField(int id)
		: RoomBase(id) // <- this constructor is called, but passes these args to the BASE CLASS constructor. it chains it!
	{
	}

	virtual string GetDescription()
	{
		return "You're in a grassy field. The sky is blue and there are some crickets nearby.";
	}

};
