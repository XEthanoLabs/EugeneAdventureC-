#include "Includes.h"
#include "AdventureGame.h"
#include "Items_Lamp.h"

AdventureGame::AdventureGame( )
{
    // add various rooms
    Room_GrassyField* r = new Room_GrassyField( RoomTypes::GrassyField );
    Rooms.push_back( r );

    // add various items
    m_Items.push_back( ItemBaseClass( ItemType::AXE, 100, RoomTypes::GrassyField, -1, "Axe" ) );
    m_Items.push_back( LampItem( ItemType::LAMP, 10, RoomTypes::GrassyField, -1, "Lamp" ) );

    m_Player.m_nRoom = RoomTypes::GrassyField;

}

void AdventureGame::MainLoop( )
{
    cout << "Welcome to Zorf (c) 2024 by E & E Frazier & Frazer" << endl;

    while ( true )
    {
        // print out room description
        // print out items near you
        // allow user to enter a command
        // process command
        // process enemies
        // loop

        cout << "----------------------------------------------------------------------" << endl;

        //-----------------------------
        // get room description
        //-----------------------------

        // get the current room #
        int currentRoom = m_Player.m_nRoom;

        // get the corresponding room
        RoomBase* pRoom = FindRoomById( currentRoom );

        // show the description
        string szRoomDescription = pRoom->GetDescription( );
        cout << szRoomDescription << endl;

        // get a command from the player
        string cmd;
        cout << "command: ";
        std::getline( cin, cmd, '\n' );
        transform( cmd.begin( ), cmd.end( ), cmd.begin( ), ::toupper );

        // display it
        cout << cmd << endl;

        string szVerb;
        string szObject;
        string szIndirect = "";
        m_Parser.ParseCommand( cmd, szVerb, szObject, szIndirect );


        // parse it?
        if ( cmd == "Q" || cmd == "QUIT" )
        {
            cout << "Quit? Okay, see you next time. Thanks for playing." << endl;
            break;
        }
    }
}
