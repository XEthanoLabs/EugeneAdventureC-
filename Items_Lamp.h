#pragma once
#include "ItemBaseClass.h"

class LampItem : public ItemBaseClass
{
public:

	int m_nGasLevel;
	bool m_bLit;

	LampItem( ItemType id, int w, int r, int c, string d)
		: ItemBaseClass( id, w, r, c, d )
	{
	}

	virtual string GetDescription()
	{
		if (!m_bLit)
		{
			return "An old rusty lamp.";
		}

		if (m_nGasLevel < 30)
		{
			return "A guttering, almost-out lamp.";
		}

		return "A brightly lit lamp.";
	}

	virtual string DoCommand(string szCommand)
	{
		if (szCommand == "LIGHT")
		{
			// has to be carried by you, and not in any room, to be lit
			if (m_nCarriedByID != 1)
			{
				return "You're not carrying a lamp.";
			}

			if (m_bLit)
			{
				return "It's already lit. You're gonna burn your fingers.";
			}

			if (m_nGasLevel == 0)
			{
				return "It's outta lamp oil.";
			}

			m_bLit = true;
			if (m_nGasLevel < 30)
			{
				return "It's lit, but not for long. It doesn't have that much fuel.";
			}
			else
			{
				return "It's lit.";
			}
		}

		if (szCommand == "FILL")
		{
			// are you carrying any lamp fuel?
		}

		// don't understand this command
		return "I don't know how to do that to the lamp";

	}

};