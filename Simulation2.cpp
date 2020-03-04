#include "Simulation2.h"


/**
*       And here you write all of the code in your methods / define
*       Indent the code correctly pls otherwise it is not readable
*/

bool Match_Opportunities::cards_counter(std::string player_name)
{
    std::map<std::string,std::vector<std::string>> cards_yellow = Stats.cards_get("cards_yellow");
    std::vector<std::string> to_red;
    std::vector<std::string> new_yellow;
    bool changed = false;

    //Iterate over the map using c++11 range based for loop
    for (std::pair<std::string,std::vector<std::string>> element : cards_yellow)
    {
        new_yellow.clear();
        to_red.clear();
        // Accessing KEY from element
        std::string team = element.first;
        // Accessing VALUE from element.
        std::vector<std::string> player = element.second;

        for (unsigned int i = 0; i < player.size(); i++)
        {
            if (player[i] == player_name)
            {
                event_red(team, player[i]);
                player.erase(player.begin() + i);
                com = Comment.comment_get("FOUL_DOUBLE_YELLOW");
                Stats.comment_set(com);
                changed = true;
            }
            else
            {
                new_yellow.push_back(player[i]);
            }
        }
        cards_yellow[team] = new_yellow;
    }
    Stats.cards_set("cards_yellow",cards_yellow);
    return changed;
}


