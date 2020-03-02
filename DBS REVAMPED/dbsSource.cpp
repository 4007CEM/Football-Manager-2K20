#include "dbsSource.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>

Players::Players(const std::string &name, int age, const std::string &nationality, int height, double weight, int number, std::string position,
                 std::string morale, int value, int pace, int shooting, int passing, int dribbling, int defending, int physical, int reflexes,
                 int diving, int handling, int skill_position, int overall_points) :
                     name(name),
                     age(age),
                     nationality(nationality),
                     height(height),
                     weight(weight),
                     number(number),
                     position(position),
                     morale(morale),
                     value(value),
                     pace(pace),
                     shooting(shooting),
                     passing(passing),
                     dribbling(dribbling),
                     defending(defending),
                     physical(physical),
                     reflexes(reflexes),
                     diving(diving),
                     handling(handling),
                     skill_position(skill_position),
                     overall_points(overall_points)
{
}


void Players::InitPlayers(std::vector<Players> &source, std::vector<Players> &dest)
{
    for(unsigned int i = 0; i < source.size(); i++)
    {
        dest.push_back(Players(source[i].name, source[i].age, source[i].nationality, source[i].height, source[i].weight, source[i].number, source[i].position, source[i].morale,
                               source[i].value, source[i].pace, source[i].shooting, source[i].passing, source[i].dribbling, source[i].defending, source[i].physical, source[i].reflexes,
                               source[i].diving, source[i].handling, source[i].skill_position, source[i].overall_points));
    }
}

void Players::PrintPlayers(std::vector<Players> &players)
{
    std::cout << std::setw(22) << "Name :" << std::setw(22) << "Position :" << "\n\n";
    for(unsigned int i = 0; i < players.size(); i++)
    {
        std::cout<< std::setw(22) << players[i].name << std::setw(22) << players[i].position << '\n';
    }
}

// Players Players::Selectplayer(std::vector<Players> &players)
// {
//     std::cout << "Name :" << "\n\n";
//     int j = 1;
//     int option;
//     for(unsigned int i = 0; i < players.size(); i++)
//     {
//         std::cout << j << "     " << players[i].name << '\n';
//         j += 1;
//     }
//     std::cin >> option;
//     option + 1;
//     Players select = players[option];
//     return select;
// }


int Players::Playerskill(std::vector<Players> &players, int option)
{
    std::vector<std::string> attacking = {"LS", "CS", "CF", "RS", "LW", "RW", "ST", "LM", "RM"};
    std::vector<std::string> midfielding = {"LAM", "CAM", "RAM", "LCM", "CM", "RCM", "CDM", "LDM", "RDM"};
    std::vector<std::string> defending = {"LWB", "RWB", "LB", "LCB", "CB", "RCB", "RB", "SW"};
    std::string goalkeeper = "GK";

    for (int i = 0; i < attacking.size(); i++)
    {
    //Attacking
        if (players[option].position == attacking[i])
        {
            int attacking_fieldskill = (players[option].pace*0.25) + (players[option].dribbling*0.25) + (players[option].shooting*0.25) + 
                            (players[option].physical*0.10) + (players[option].defending*0.05) + (players[option].passing*0.10);
            return attacking_fieldskill;
        }
    }
    for (int i = 0; i < midfielding.size(); i++)
    {
    //Midfielding
        if (players[option].position == midfielding[i])
        {
            int midfielding_fieldskill = (players[option].pace*0.10) + (players[option].dribbling*0.20) + (players[option].shooting*0.20) + 
                            (players[option].physical*0.10) + (players[option].defending*0.20) + (players[option].passing*0.20);
            return midfielding_fieldskill;

        }
    }
    for (int i = 0; i < defending.size(); i++)
    {
        //Defending
        if (players[option].position == defending[i])
        {
            int defending_fieldskill = (players[option].pace*0.10) + (players[option].dribbling*0.05) + (players[option].shooting*0.05) + 
                            (players[option].physical*0.30) + (players[option].defending*0.30) + (players[option].passing*0.10) + (players[option].reflexes*0.02) + 
                            (players[option].diving*0.02) + (players[option].handling*0.02) + (players[option].skill_position*0.04);
            return defending_fieldskill;
        }
    }
        //Goalkeeping
        if (players[option].position == goalkeeper)
        {
            int goalkeeping_fieldskill = (players[option].pace*0.02) + (players[option].dribbling*0.02) + (players[option].shooting*0.02) + 
            (players[option].physical*0.02) + (players[option].defending*0.02) + (players[option].passing*0.05) + (players[option].reflexes*0.25) + 
            (players[option].diving*0.25) + (players[option].handling*0.20) + (players[option].skill_position*0.15); 
            return goalkeeping_fieldskill;     
        }
    
}


int Players::Fieldskill(std::vector<Players> &players)
{
     std::map<int,int> attack ={ 
    { 0,-100 },
    { 1,-10  },
    { 2, 0   },
    { 3, 10  },
    { 4, 20  },
    { 5, 30  },
    { 6, 40  },
    { 7, 50  },
    { 8, 60  },
    { 9, 70  },
    { 10, 80 }
    };
    
    std::map<int,int> midfield ={ 
    { 0,-100 },
    { 1,-20  },
    { 2,-10  },
    { 3, 0  },
    { 4, 10  },
    { 5, 20  },
    { 6, 30  },
    { 7, 40  },
    { 8, 50  },
    { 9, 60  },
    { 10, 70 }
    };

    std::map<int,int> defence ={ 
    { 0,-100 },
    { 1,-20  },
    { 2,-10  },
    { 3, 0  },
    { 4, 10  },
    { 5, 20  },
    { 6, 30  },
    { 7, 40  },
    { 8, 50  },
    { 9, 60  },
    { 10, 70 }
    };
  
    //Positions converted:
    std::vector<std::string> attacking = {"LS", "CS", "CF", "RS", "LW", "RW", "ST", "LM", "RM"};
    std::vector<std::string> midfielding = {"LAM", "CAM", "RAM", "LCM", "CM", "RCM", "CDM", "LDM", "RDM"};
    std::vector<std::string> defending = {"LWB", "RWB", "LB", "LCB", "CB", "RCB", "RB", "SW"};
    std::string goalkeeper = "GK";


    int attackers = 0;
    int midfielders = 0;
    int defenders = 0;
    int goalkeepers = 0;

    int attackers_average_skill = 0;
    int midfielders_average_skill = 0;
    int defenders_average_skill = 0;
    int goalkeeper_average_skill = 0;
    for(unsigned int i = 0; i < players.size(); i++)
    {
        // Attacking
        for (unsigned int j = 0; j < attacking.size(); j++) 
        {
            std::string pos = attacking[j];
            if (players[i].position == pos)
            {
                int attacking_fieldskill = Players::Playerskill(players, i);
                attackers_average_skill += attacking_fieldskill;
                attackers++;
            }
        } 
        //Midfielding
        for (unsigned int j = 0; j < midfielding.size(); j++) 
        {
            std::string pos = midfielding[j];
            if (players[i].position == pos)
            {
                int midfielding_fieldskill = Players::Playerskill(players, i);
                midfielders_average_skill += midfielding_fieldskill;
                midfielders++;
            }
        } 
        //Defending
        for (unsigned int j = 0; j < defending.size(); j++) 
        {
            std::string pos = defending[j];
            if (players[i].position == pos)
            {
                int defending_fieldskill = Players::Playerskill(players, i);
                defenders_average_skill += defending_fieldskill;
                defenders++;

            }
        } 
        //Goalkeeping
        if (players[i].position == goalkeeper)
        {
                int goalkeeping_fieldskill = Players::Playerskill(players, i);
                goalkeeper_average_skill += goalkeeping_fieldskill;
                goalkeepers++;
        }
    }
    
    attackers_average_skill = attackers_average_skill/attackers;
    midfielders_average_skill = midfielders_average_skill/midfielders;
    defenders_average_skill = defenders_average_skill/defenders;

    int attack_bonus = attack.at(attackers);
    int attacking_effectivity = (attackers_average_skill/100)* attack_bonus + attackers_average_skill;

    int midfield_bonus = midfield.at(midfielders);
    int midfielding_effectivity = (midfielders_average_skill/100)* midfield_bonus + midfielders_average_skill;

    int defenders_bonus = defence.at(defenders);
    int defending_effectivity = (defenders_average_skill/100)* defenders_bonus + defenders_average_skill;

    int goalkeeping_effectivity = (goalkeeper_average_skill/100)* goalkeeper_average_skill;

    int field_effectivity = attacking_effectivity + midfielding_effectivity + defending_effectivity + goalkeeping_effectivity;

    return field_effectivity;
}



Squad::Squad(const std::string &squad_name, const std::string &league, const std::string &manager, const int noInField, const int noSub) :
    squad_name{squad_name},
    league{league},
    manager(manager),
    noInField{noInField},
    noSub{noSub}
{
}