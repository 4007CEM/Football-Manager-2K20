#include <iostream>
#include <windows.h>
//#include "gameFunc.h"
#include "dbsSource.h"
#include "dbsCreation.h"


using namespace std;

int main()
{
    /*
    GameWindow init;
    init.InitWindow();
    */

    Players::InitPlayers(ManchesterUInfield, InitManchesterUInfield);
    // Players::PrintPlayers(LiverpoolSubs);
    // Players::PrintPlayers(ManchesterUInfield); 
    Players::Fieldskill(ManchesterUInfield);


    return 0;
}