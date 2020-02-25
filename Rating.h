#include <iostream>
#include <string>

class Rating // temp class
{
    private:
    
    int attackers_effectivity_A = 100; // of playeraA
    int deffenders_effectivity_A = 100; // of playerA
    int goalkeepers_effectivity_A = 100; // of playerA

    int attackers_effectivity_B = 100; // of playeraB
    int deffenders_effectivity_B = 100; // of playerB
    int goalkeepers_effectivity_B = 100; // of playerB
    
    public:
    
    int getEffectivity(std::string player, std::string effectivity_type)
    {
        if (player == "B")
        {
            if (effectivity_type == "attacker")
                return attackers_effectivity_B;
            if (effectivity_type == "deffender")
                return deffenders_effectivity_B;
            if (effectivity_type == "goalkeeper")
                return goalkeepers_effectivity_B;
        }
        if (player == "A")
        {
            if (effectivity_type == "attacker")
                return attackers_effectivity_A;
            if (effectivity_type == "deffender")
                return deffenders_effectivity_A;
            if (effectivity_type == "goalkeeper")
                return goalkeepers_effectivity_A;
        }
    }
};
