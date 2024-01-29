#pragma once

#include "PlayerClass.h"
#include "RoomBase.h"
#include "CreatureBase.h"
#include "ItemBaseClass.h"
#include "Items_Lamp.h"
#include "CommandParser.h"

class AdventureGame
{
	vector<RoomBase*> Rooms;
	vector<CreatureBase*> Creatures;
    PlayerClass m_Player;
    vector<ItemBaseClass> m_Items; // these are ALL the items in the adventure game. some are carried.
    CommandParser m_Parser;

    RoomBase* FindRoomById( int id )
    {
        for ( RoomBase* r : Rooms )
        {
            if ( r->m_nID == id )
            {
                return r;
            }
        }
        return NULL;
    }

public:

	AdventureGame( );
	void MainLoop( );
};

