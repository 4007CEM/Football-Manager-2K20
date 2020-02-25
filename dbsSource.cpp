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


void Players::Fieldskill(std::vector<Players> &players)
{
    std::vector<std::string> attacking = {"LS", "CS", "CF", "RS", "LW", "RW", "ST", "LM", "RM", "CAM"};
    std::vector<std::string> midfielding = {"LAM", "CAM", "RAM", "LCM", "CM", "RCM"};
    std::vector<std::string> defending = {"LWB", "LDM", "CDM", "RDM", "RWB", "LB", "LCB", "CB", "RCB", "RB", "SW"};
    std::string goalkeeper = "GK";

    int attacking_effectivity = 0;
    std::map<int , std::string> sorted_players;
    int key = 1;


    for(unsigned int i = 0; i < players.size(); i++)
    {
        //Attacking
        for (unsigned int j = 0; j < attacking.size(); j++) 
        {
            std::string pos = attacking[j];
            if (players[i].position == pos)
            {
                int fieldskill = (players[i].pace*0.25) + (players[i].dribbling*0.25) + (players[i].shooting*0.25) + 
                (players[i].physical*0.10) + (players[i].defending*0.05) + (players[i].passing*0.10);
                attacking_effectivity += fieldskill;
                sorted_players[key] = players[i].name, players[i].position;

                std::cout << key << " The attackers are: " << sorted_players[key] << "              Fieldskill is: " << fieldskill << std::endl;

                key += 1;

            }
        }
        //Midfielding
        for (unsigned int j = 0; j < midfielding.size(); j++) 
        {
            std::string pos = midfielding[j];
            if (players[i].position == pos) 
            {
             int fieldskill = (players[i].pace*0.10) + (players[i].dribbling*0.20) + (players[i].shooting*0.20) + 
             (players[i].physical*0.10) + (players[i].defending*0.20) + (players[i].passing*0.20);
             attacking_effectivity += fieldskill;
             sorted_players[key] = players[i].name;

            std::cout << key << " The midfielders are: " << sorted_players[key] << "              Fieldskill is: " << fieldskill << std::endl;

             key += 1;

                
        }
        }
        // //Defending
        for (unsigned int j = 0; j < defending.size(); j++) 
        {
            std::string pos = defending[j];
            if (players[i].position == pos) 
            {
            int fieldskill = (players[i].pace*0.10) + (players[i].dribbling*0.05) + (players[i].shooting*0.05) + 
           (players[i].physical*0.30) + (players[i].defending*0.30) + (players[i].passing*0.10) + (players[i].reflexes*0.02) + 
           (players[i].diving*0.02) + (players[i].handling*0.02) + (players[i].skill_position*0.04);
            attacking_effectivity += fieldskill;
            sorted_players[key] = players[i].name;

            std::cout << key << " The defenders are: " << sorted_players[key] << "              Fieldskill is: " << fieldskill << std::endl;

            key += 1;


            }
        }
        // Goalkeeping
        if (players[i].position == goalkeeper)
        {
            int fieldskill = (players[i].pace*0.02) + (players[i].dribbling*0.02) + (players[i].shooting*0.02) + 
            (players[i].physical*0.02) + (players[i].defending*0.02) + (players[i].passing*0.05) + (players[i].reflexes*0.25) + 
            (players[i].diving*0.25) + (players[i].handling*0.20) + (players[i].skill_position*0.15);
            // std::cout << fieldskill << std::endl;
            attacking_effectivity += fieldskill;
            sorted_players[key] = players[i].name;

            std::cout << key << " The goalkeeper is: " << sorted_players[key]<< "              Fieldskill is: " << fieldskill  << std::endl;
        }
    }
}





Squad::Squad(const std::string &squad_name, const std::string &league, const std::string &manager, const int noInField, const int noSub) :
    squad_name{squad_name},
    league{league},
    manager(manager),
    noInField{noInField},
    noSub{noSub}
{
}