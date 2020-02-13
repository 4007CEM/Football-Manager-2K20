#include <iostream>
using namespace std;

//Class for Fan Morale and Team play
class FanMorale{
    private: // Private variables (for encapsulation) - NEED TO MAKE CALCULATED WHEN MATCH OPPORTUNITIES COMPLETE
        int fanMorale;
        int capacity;
        int weatherMult;
        int adMult;
        int leagueID;
        int attempts;
        int goals;
    
    public:
        void updateFanMorale();
        int getFanMorale();
}

class TeamPlay{
    private:
    int teamPlay;
        int teamRating;
        int score;

    public:
        void updateTeamPlay();
        int getTeamPlay();
}

// Morale class inherits Fan TeamPlay class
class Morale: public FanMorale, public TeamPlay{
    protected:
        int morale;
        
    public:
        void updateMorale();
        int getMorale();
}
