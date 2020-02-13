#ifndef DBS_H_INCLUDED
#define DBS_H_INCLUDED

#include <iostream>

struct Player
{
    //PLAYER BIO
    std::string name;
    int age;
    std::string nationality;
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
    int overall_point;
};

void PrintDetails();


#endif // DBS_H_INCLUDED
