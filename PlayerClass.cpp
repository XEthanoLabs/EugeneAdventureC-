#include "Includes.h"
#include "RoomBase.h"
#include "PlayerClass.h"


PlayerClass::PlayerClass( )
{
	m_nID = CreatureType::You;
	m_nHealth = 100;
	m_nRoom = RoomTypes::GrassyField;
}
