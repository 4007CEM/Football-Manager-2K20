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
            //std::cout << "Attackers: " << players[option].name << "     Fieldskill: " << attacking_fieldskill << std::endl;
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
     std::map<int,float> attack ={ 
    { 0,-1.00 },
    { 1,-0.10  },
    { 2, 0   },
    { 3, 0.10  },
    { 4, 0.20  },
    { 5, 0.30  },
    { 6, 0.40  },
    { 7, 0.50  },
    { 8, 0.60  },
    { 9, 0.70  },
    { 10, 0.80 }
    };
    
    std::map<int,float> midfield ={ 
    { 0,-1.00 },
    { 1,-0.20  },
    { 2,-0.10  },
    { 3, 0  },
    { 4, 0.10  },
    { 5, 0.20  },
    { 6, 0.30  },
    { 7, 0.40  },
    { 8, 0.50  },
    { 9, 0.60  },
    { 10, 0.70 }
    };

    std::map<int,float> defence ={ 
    { 0,-1.00 },
    { 1,-0.20  },
    { 2,-0.10  },
    { 3, 0  },
    { 4, 0.10  },
    { 5, 0.20  },
    { 6, 0.30  },
    { 7, 0.40  },
    { 8, 0.50  },
    { 9, 0.60  },
    { 10, 0.70 }
    };

    std::map<int,float> goalkeeper_map ={
    { 0, -1.00 },
    { 1, 0 }
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
    goalkeeper_average_skill = goalkeeper_average_skill/goalkeepers;

    float attack_bonus = attack.at(attackers);
    int attacking_effectivity = (attackers_average_skill * attack_bonus) + attackers_average_skill;

    float midfield_bonus = midfield.at(midfielders);
    int midfielding_effectivity = (midfielders_average_skill * midfield_bonus) + midfielders_average_skill;

    float defenders_bonus = defence.at(defenders);
    int defending_effectivity = (defenders_average_skill * defenders_bonus) + defenders_average_skill;

    float goalkeeper_bonus = goalkeeper_map.at(goalkeepers);
    int goalkeeping_effectivity = (goalkeeper_average_skill * goalkeeper_bonus) + goalkeeper_average_skill;

    int field_effectivity = attacking_effectivity + midfielding_effectivity + defending_effectivity + goalkeeping_effectivity;
    std::cout << "Attackers Average Skill: " << attackers_average_skill << std::endl;
    std::cout << "Midfielders Average Skill: " << midfielders_average_skill << std::endl;
    std::cout << "Defenders Average Skill: " << defenders_average_skill << std::endl;
    std::cout << "Goalkeeper Average Skill: " << goalkeeper_average_skill << "\n" << std::endl;
    // std::cout << "\nAttacking Bonus: " << attack_bonus << std::endl;
    // std::cout << "Effectivity: " << attacking_effectivity << std::endl;
    // std::cout << "Formation: " << defenders << "-" << midfielders << "-" << attackers << std::endl;
    // std::cout << "Overall field_effectivity: " << field_effectivity << "\n" << std::endl;
    std::cout << "Attackers effectivity: " << attacking_effectivity << std::endl;
    std::cout << "Midfielders effectivity: " << midfielding_effectivity << std::endl;
    std::cout << "Defenders effectivity: " << defending_effectivity << std::endl;
    std::cout << "Goalkeeper effectivity: " << goalkeeping_effectivity << std::endl;

    std::cout << "\nOverall field_effectivity: " << field_effectivity << "\n" << std::endl;
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