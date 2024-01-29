#include "CommandParser.h"

bool iswhitespace( char c )
{
    if ( c == ' ' || c == '\t' )
    {
        return true;
    }
    return false;
}

void trimWhitespace( string& s )
{
    if ( s.size( ) == 0 )
    {
        return;
    }

    int frontIndex = 0;
    int endIndex = (int)s.size( ) - 1;
    while ( iswhitespace( s[frontIndex] ) )
    {
        frontIndex++;
    }
    if ( frontIndex >= endIndex )
    {
        s = "";
        return;
    }
    while ( iswhitespace( s[endIndex] ) )
    {
        endIndex--;
    }
    if ( endIndex <= frontIndex )
    {
        s = "";
        return;
    }
    string out = s.substr( frontIndex, 1 + endIndex - frontIndex );
    s = out;
}

// split an input string into separate words. Takes into account any character in szDelims will cause a break
vector<string> splitString( string s, const string& szDelims )
{
    vector<string> szSplits;
    size_t pos = 0;
    while (
        (pos = s.find_first_of( szDelims )) != std::string::npos
        )
    {
        string token = s.substr( 0, pos );
        trimWhitespace( token );

        if ( token.size( ) > 0 )
        {
            szSplits.push_back( token );
        }

        s.erase( 0, pos + 1 );
    }
    if ( s.size( ) > 0 )
    {
        szSplits.push_back( s );
    }
    return szSplits;
}


CommandParser::CommandParser( )
{
    m_VerbMap = {
        { VB_N, "N" }
    };
}

void CommandParser::ParseCommand( const string szCommand, Verbs& eVerb, string& szObject, string& szIndirectObject )
{
	// lets assume (for now) the command is always "verb, object" as two words unless "with" is added, and then 4th word is indirect object
	// examples:
	// N, S, E, W
	// GO + N, S, E, W
	// LOOK
	// GET [ITEM]
	// DROP [ITEM]
	// LOOK [ITEM]
	// LOOK (around)
	// LIGHT [ITEM]
	// DOUSE [ITEM]
	// KILL/HIT/STRIKE/PUNCH/STAB [ITEM]
	// RUN/FLEE
	// CLIMB [ITEM]
	// CLIMB
	// DIG


    vector<string> szWords = splitString( szCommand, " " );
    if ( szWords.size( ) == 1 )
    {
        return;
    }

    if ( szWords.size( ) == 2 )
    {
        szObject = szWords[1];
    }
}
