#pragma once
#include "Includes.h"

enum Verbs
{
	VB_N,
	VB_S,
	VB_E,
	VB_W,
	VB_UP,
	VB_DOWN,
	VB_CLIMB,
	VB_DIG,
	VB_QUIT,
	VB_LOOK,

};

class CommandParser
{
	map<string, Verbs> m_VerbMap;

public:

	CommandParser( );
	void ParseCommand( const string szCommand, Verbs& eVerb, string& szObject, string& szIndirectObject );
};

