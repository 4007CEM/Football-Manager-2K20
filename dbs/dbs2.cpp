#include "dbs.h"
#include <stdlib.h>
Player players[18] =
{
    //{"Dani Alves", 32, "British", 180, 78, 7, "GK", "GOOD", 91, 72, 67, 87, 45} Example
    //Regulars - 11 players including goal keeper
    //Arsenal:
    {"P. Aubameyang", 30, "Gabonese", 187, 80, 14, "LM", "GOOD", 57000000, 94, 85, 75, 80, 37, 88 },
    {"A. Lacazette", 28, "French", 175, 73, 9, "ST", "GOOD",  46000000, 82, 85, 75, 86, 40, 86 },
    {"B. Leno", 27, "German", 190, 83, 1, "GK", "GOOD", 26000000, 56, 78, 81, 84, 83, 84 }, //Goalkeeper uses GK Speed, GK Kicking, GK Handling, GK Positioning and GK Diving: ATM (can change)
    {"Sokratis", 31, "Greek", 186, 85, 5, "RCB", "GOOD", 23000000, 72, 51, 52, 60, 84, 84 },
    {"M. Ozil", 30, "German", 180, 76, 10, "CAM", "GOOD", 29500000, 70, 72, 86, 84, 24, 84 },
    {"N. Pepe", 24, "Ivorian", 183, 73, 19, "RM", "GOOD", 34500000, 91, 81, 75, 85, 33, 83 },
    {"David Luiz", 32, "Brazilian", 189, 86, 23, "LCB", "GOOD", 16500000, 61, 65, 74, 70, 82, 83 },
    {"L. Torreira", 23, "Uruguayan", 168, 64, 11, "RDM", "GOOD", 27000000, 75, 67, 77, 80, 81, 82 },
    {"G. Xhaka", 26, "Swiss", 185, 82, 34, "LDM", "GOOD", 21500000, 51, 67, 81, 71, 69, 81},
    {"Nacho Monreal", 33, "Spanish", 180, 77, 18, "LB", "GOOD", 5500000, 63, 61, 71, 74, 80, 79 },
    {"A. Maitland-Niles", 21, "British", 177, 71, 15, "RB", "GOOD", 9500000, 85, 59, 70, 76, 68, 75},
    //Subs - 7 players
    {"Dani Ceballos", 22, "Spanish", 179, 70, 8, "SUB", "GOOD", 19500000, 69, 67, 79, 84, 68, 81 },
    {"H. Mkhitaryan", 30, "Armenian", 177, 75, 7, "SUB", "GOOD", 17000000, 78, 76, 78, 83, 55, 81 },
    {"Hector Bellerin", 24, "Spanish", 178, 74, 2, "SUB", "GOOD", 17500000, 92, 51, 70, 78, 76, 80 },
    {"S. Kolasinac", 26, "Bosnian", 183, 85, 31, "SUB", "GOOD", 13500000, 75, 62, 72, 73, 75, 79  }, 
    {"S. Mustafi", 27, "German", 184, 82, 20, "SUB", "GOOD", 13000000, 60, 57, 63, 61, 77, 79 },
    {"K. Tierney", 22, "Scottish", 178, 78, 3, "SUB", "GOOD", 11000000, 88, 59, 70, 74, 71, 76 },
    {"R. Holding", 23, "British", 189, 75, 16, "SUB", "GOOD", 10000000, 60, 34, 59, 64, 77, 76 }

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
