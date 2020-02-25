#ifndef DBS_H_INCLUDED
#define DBS_H_INCLUDED

#include <iostream>
#include <vector>




class Players
{
private:
    //PLAYER BIO
    const std::string name;
    int age;
    const std::string nationality;
    int height;
    double weight;
    int number;
    std::string position;
    std::string morale;
    int value;

    //PLAYER SKILLS
    int pace;
    int shooting;
    int passing;
    int dribbling;
    int defending;
    int physical;
    //GOALKEEPERS
    int reflexes;
    int diving;
    int handling;
    int skill_position;
    int overall_points;

public:

    Players(const std::string &name,int age, const std::string &nationality, int height, double weight, int number, std::string position,
            std::string morale, int value, int pace, int shooting, int passing, int dribbling, int defending, int physical, int reflexes,
            int diving, int handling, int skill_position, int overall_points);

    static void InitPlayers(std::vector<Players> &source, std::vector<Players> &dest);

    static void PrintPlayers(std::vector<Players> &players);

    static void Fieldskill(std::vector<Players> &players);

};


class Squad
{
public:
    std::string squad_name, league, manager;
    const int noInField, noSub;

public:
    Squad(const std::string &squad_name, const std::string &league, const std::string &manager, const int noInField, const int noSub);


};



//  class Positions
//  {
//     public:
//     std::vector<std::string> attacking;
//     std::vector<std::string> midfielding;
//     std::vector<std::string> defending;
//     std::string goalkeeper;

//     Positions()
//     {
//             attacking = {"LS", "CS", "CF", "RS", "LW", "RW", "ST"};
//             midfielding = {"LAM", "CAM", "RAM", "LM", "LCM", "CM", "RCM", "RM"};
//             defending = {"LWB", "LDM", "CDM", "RDM", "RWB", "LB", "LCB", "CB", "RCB", "RB", "SW"};
//             goalkeeper = "GK";
//             int attacking_effectivity = 0;
//     }

//     int attackingcalc(std::vector<Players> &players)
//     {
//         for (unsigned int j = 0; j < attacking.size(); j++) 
//         {
//             std::string pos = attacking[j];
//             if (players[i].position == pos)
//             {
//                 int fieldskill = (players[i].pace*0.25) + (players[i].dribbling*0.25) + (players[i].shooting*0.25) + 
//                 (players[i].physical*0.10) + (players[i].defending*0.05) + (players[i].passing*0.10);
//                 attacking_effectivity += fieldskill;

//             }
//         }
//     }

//  };


// Positions pos;







#endif // DBS_H_INCLUDED
