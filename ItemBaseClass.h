#pragma once

#include "includes.h"

enum ItemType
{
	LAMP,
	KEYS,
	MATCHES,
	GASCAN,
	SWORD,
	AXE,
	DAGGER,
	CLOTHES,
	LOCKPICK
};

class ItemBaseClass
{
public:

	ItemType m_nID;
	int m_nWeight;
	int m_nRoom;
	int m_nCarriedByID;
	string m_szDescription;


public:

	ItemBaseClass(ItemType id, int w, int r, int c, string d)
	{
		m_nID = id;
		m_nWeight = w;
		m_nRoom = r;
		m_nCarriedByID = c;
		m_szDescription = d;
	}

	virtual string GetDescription()
	{
		return m_szDescription;
	}

	virtual string DoCommand(string szCommand)
	{
		// who cares
		return "";
	}
};
