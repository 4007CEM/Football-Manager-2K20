#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <time.h>
#include <vector>
#include <map>

class Commentator
{
    private:
    
    const std::map<std::string, std::vector<std::string> > comments = {
    { "SERIOUS_INJURY", { "Comment1", "Comment2", "Comment3" } },
    { "TEMPORARY_INJURY", { "Comment1", "Comment2", "Comment3" } },
    { "LIGHT_INJURY", { "Comment1", "Comment2", "Comment3" } },
    { "PENALTY_AT", { "Comment1", "Comment2", "Comment3" } },
    { "PENALTY_DEFF", { "Comment1", "Comment2", "Comment3" } },
    { "GOAL_AT", { "Comment1", "Comment2", "Comment3" } },
    { "CORNERKICK_AT", { "Comment1", "Comment2", "Comment3" } },
    { "ATTEMPT_DEFF_PENALTY", { "Comment1", "Comment2", "Comment3" } },
    { "ATTEMPT_DEFF", { "Comment1", "Comment2", "Comment3" } },
    { "ATTEMPT_AT", { "Comment1", "Comment2", "Comment3" } },
    { "ATTEMPT_DEFF_CORNERKICK", { "Comment1", "Comment2", "Comment3" } },
    { "CORNERKICK_DEFF_PENALTY", { "Comment1", "Comment2", "Comment3" } },
    { "CORNERKICK_DEFF", { "Comment1", "Comment2", "Comment3" } },
    { "SHOTONGOAL_AT", { "Comment1", "Comment2", "Comment3" } },
    { "SHOTONGOAL_DEFF_CORNERKICK", { "Comment1", "Comment2", "Comment3" } },
    { "SHOTONGOAL_DEFF", { "Comment1", "Comment2", "Comment3" } },
    { "ATTACK_BONUS", { "Comment1", "Comment2", "Comment3" } },  
    { "MID_BONUS", { "Comment1", "Comment2", "Comment3" } },   
    { "GOAL_BONUS", { "Comment1", "Comment2", "Comment3" } },  
    { "DEFF_BONUS", { "Comment1", "Comment2", "Comment3" } },
    { "ATTACK_BONUS_STYLE", { "Comment1", "Comment2", "Comment3" } },
    { "MID_BONUS_STYLE", { "Comment1", "Comment2", "Comment3" } },
    { "DEFF_BONUS_STYLE", { "Comment1", "Comment2", "Comment3" } },
    { "NO_BONUS_STYLE", { "Comment@@@1", "Comment@@@2", "Comment@@@3" } },
    { "GOAL_PENALTY_STYLE", { "Comment1", "Comment2", "Comment3" } },
    { "ACTION_NOTHING", { "Comment1", "Comment2", "Comment3" } }
    }; //ADD from last options in player event
   
    public:
    
    std::string comment_get(std::string key)    
    {
         int random = rand() % 3 ;
         return comments.at(key)[random];
    }
};
