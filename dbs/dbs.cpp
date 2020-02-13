#include "dbs.h"
#include <stdlib.h>
Player players[18] =
{
    //{"Dani Alves", 32, "British", 180, 78, 7, "GK", "GOOD", 91, 72, 67, 87, 45} Example
    //Regulars - 11 players including goal keeper
    //Manchester United:
    {"De Gea", 28, "Spanish", 192, 82, 1, "GK", "GOOD", 56000000, 58, 81, 84, 85, 90, 89 }, //Goalkeeper uses GK Speed, GK Kicking, GK Handling, GK Positioning and GK Diving: ATM (can change)
    {"P. Pogba", 26, "French", 191, 84, 6, "LDM", "GOOD",  72500000, 74, 81, 86, 85, 66, 88 },
    {"A. Martial", 23, "French", 184, 76, 9, "ST", "GOOD", 34500000, 89, 81, 72, 86, 41, 83 },
    {"M. Rashford", 21, "British", 186, 70, 10, "LM", "GOOD", 35500000, 92, 82, 73, 84, 45, 83 },
    {"H. Maguire", 26, "British", 194, 100, 5, "LCB", "GOOD", 23000000, 50, 53, 64, 69, 81, 82 },
    {"J. Lingard", 26, "British", 175, 62, 14, "CAM", "GOOD", 24000000, 80, 78, 76, 83, 58, 82 },
    {"V. Lindelof", 24, "Swedish", 187, 80, 2, "RCB", "GOOD", 22000000, 74, 50, 72, 72, 82, 81 },
    {"L. Shaw", 23, "British", 181, 75, 23, "LB", "GOOD", 20000000, 82, 54, 75, 80, 80, 81 },
    {"A. Wan-Bissaka", 21, "British", 183, 72, 29, "RB", "GOOD", 17500000, 87, 50, 63, 78, 80, 79 },
    {"S. McTominay", 22, "Scottish", 193, 88, 39, "RDM", "GOOD", 11500000, 61, 65, 72, 72, 74, 77 },
    {"Andreas Pereira", 23, "Brazilian", 178, 71, 15, "RM", "GOOD", 11500000, 73, 74, 78, 78, 66, 77},
    //Subs - 7 players
    {"Juan Mata", 31, "Spanish", 170, 63, 8, "SUB", "GOOD", 19500000, 62, 74, 83, 83, 36, 82 },
    {"A. Sanchez", 30, "Chillean", 169, 62, 7, "SUB", "GOOD", 21000000, 81, 78, 77, 85, 44, 82 },
    {"N. Matic", 30, "Serbian", 194, 85, 31, "SUB", "GOOD", 14500000, 48, 68, 77, 72, 80, 81 },
    {"S. Romero", 32, "Argentinian", 192, 86, 22, "SUB", "GOOD", 9000000, 45, 81, 76, 79, 79, 80  }, //Goalkeeper sub
    {"C. Smalling", 29, "British", 194, 81, 12, "SUB", "GOOD", 12500000, 69, 47, 58, 58, 79, 80 },
    {"Fred", 26, "Brazilian", 169, 64, 17, "SUB", "GOOD", 15000000, 76, 73, 75, 80, 74, 79 },
    {"A. Young", 33, "British", 175, 65, 18, "SUB", "GOOD", 4000000, 70, 66, 74, 75, 73, 77 }

};


void PrintDetails()
{
    for(int i = 0; i < 18; i++)
    {

        std::cout << "Name: " << players[i].name << '\n'
                  << "Age: "  <<  players[i].age << '\n'
                  << "Natiionality: " << players[i].nationality << '\n'
                  << "Height: " << players[i].height << '\n'
                  << "Weight: " << players[i].weight << '\n'
                  << "Player's number: " << players[i].number << '\n'
                  << "Position: " << players[i].position << '\n'
                  << "Morale: " << players[i].morale << '\n'
                  << "Value: " << players[i].value << '\n' //value is in millions
                  << "Pace : " << players[i].pace << '\n'
                  << "Shooting : " << players[i].shooting << '\n'
                  << "Passing: " << players[i].passing << '\n'
                  << "Dribbling: " << players[i].dribbling << '\n'
                  << "Defending: " << players[i].defending << '\n'
                  << "Overall: " << players[i].overall_point << '\n'
                  << "-------------------------------------------" << '\n';
    }
}
