#include <iostream>
#include "dbs2.h"
#include "dbsSource.h"

int main()
{
    // here you first put the vector with the data in it then the empty vector

    Players::InitPlayers(ManchesterInfield, InitManchesterInfield);

    // This prints the data
    Players::PrintPlayers(InitManchesterInfield);

    return 0;
}
