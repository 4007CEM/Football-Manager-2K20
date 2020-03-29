#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

class Match_Stats
{
    private:

    static int A_penalty;
    static int A_cornerkick;
    static int A_offside;
    static int A_out;
    static int A_attempt;
    static int A_shotongoal;
    static int A_injury;
    static int A_goal;
    static int A_foul;
    static int A_yellow;
    static int A_red;

    static int B_penalty;
    static int B_cornerkick;
    static int B_offside;
    static int B_out;
    static int B_attempt;
    static int B_shotongoal;
    static int B_injury;
    static int B_goal;
    static int B_foul;
    static int B_yellow;
    static int B_red;

    static std::string user_input;
    static std::string player_event;
    static std::string player_event_question;
    static std::string player_event_option_A;
    static std::string player_event_option_B;
    static std::string player_event_option_C;
    static std::string player_event_option_D;

    static std::string player_A;
    static std::string player_B;

    static std::string tactics;

    static std::vector<std::string> comment;

    static std::map<std::string,std::vector<std::string>> cards_yellow;
    static std::map<std::string,std::vector<std::string>> cards_red;

    public:

    void stats_set(std::string event, std::string input )
    {
        if (event == "user_input")
            user_input = input;
        else if (event == "player_event")
            player_event = input; // When input == EVENT runs player event while loop in interface has to be before match_opportunity mech, maybe use continue in while loop
        else if (event == "player_event_question")
            player_event_question = input;
        else if (event == "player_event_option_A")
            player_event_option_A = input;
        else if (event == "player_event_option_B")
            player_event_option_B = input;
        else if (event == "player_event_option_C")
            player_event_option_C = input;
        else if (event == "player_event_option_D")
            player_event_option_D = input;
        else if (event == "player_A")
            player_A = input;
        else if (event == "player_B")
            player_B = input;
    }
    std::map<std::string,std::vector<std::string>> cards_get(std::string value_get)
    {
        if (value_get == "cards_yellow")
            return cards_yellow;
        else if (value_get == "cards_red")
            return cards_red;
    }
    void cards_set(std::string value_get,std::map<std::string,std::vector<std::string>> input)
    {
        if (value_get == "cards_yellow")
            cards_yellow = input;
        else if (value_get == "cards_red")
            cards_red = input;
    }

    void comment_set(std::string newcomment, bool clear=false)
    {
        comment.push_back(newcomment);
        if (clear == true)
        {
            comment.clear();
        }
    }
    std::vector <std::string> comment_get()
    {
            return comment;
    }
    // use template
    std::string stats_get(std::string value_get, std::string &randSquad)
    {
        if (value_get == "user_input")
            return user_input;
        else if (value_get == "player_event")
           return player_event;
        else if (value_get == "player_event_question")
            return player_event_question;
        else if (value_get == "player_event_option_A")
            return player_event_option_A;
        else if (value_get == "player_event_option_B")
            return player_event_option_B;
        else if (value_get == "player_event_option_C")
            return player_event_option_C;
        else if (value_get == "player_event_option_D")
            return player_event_option_D;
        else if (value_get == "player_A")
            return player_A;
        else if (value_get == "player_B")
            return player_B;

        else if (value_get == "temp")
        {
            std::cout << std::setw(30) << initUser.GetSquad() << std::setw(30) << randSquad << "\n\n"
                      << std::setw(25) << A_penalty << std::setw(20) << " -penalty- "  << std::setw(10) << B_penalty << '\n'
                      << std::setw(25) << A_cornerkick << std::setw(20) << "-cornerkick-: " << std::setw(10) << B_cornerkick << '\n'
                      << std::setw(25) << A_offside << std::setw(20) << " -offside- " << std::setw(10) << B_offside << '\n'
                      << std::setw(25) << A_out << std::setw(20) << " -out- " << std::setw(10) << B_out << '\n'
                      << std::setw(25) << A_attempt << std::setw(20) << " -attempt- " << std::setw(10) << B_attempt << '\n'
                      << std::setw(25) << A_shotongoal << std::setw(20) << " -shotongoal- " << std::setw(10) << B_shotongoal << '\n'
                      << std::setw(25) << A_injury << std::setw(20) << " -injury- " << std::setw(10) << B_injury << '\n'
                      << std::setw(25) << A_foul << std::setw(20) << " -foul- " << std::setw(10) << B_foul << '\n'
                      << std::setw(25) << A_yellow << std::setw(20) << " -yellow- " << std::setw(10) << B_yellow << '\n'
                      << std::setw(25) << A_red << std::setw(20) << " -red- " << std::setw(10) << B_red << '\n'
                      << std::setw(25) << A_goal << std::setw(20) << " -goal- " << std::setw(10) << B_goal << std::endl;
        }
    }

    void stats_upload(std::string event, std::string team)
    {
        //ADD LINE: pass event,team to comment class or pass it from Simulation class
        if (event=="penalty" && team=="A") A_penalty+= 1;
        else if (event=="cornerkick" && team=="A") A_cornerkick+= 1;
        else if (event=="offside" && team=="A") A_offside+= 1;
        else if (event=="out" && team=="A") A_out+= 1;
        else if (event=="attempt" && team=="A") A_attempt+= 1;
        else if (event=="shotongoal" && team=="A") A_shotongoal+= 1;
        else if (event=="injury" && team=="A") A_injury+= 1;
        else if (event=="goal" && team=="A") A_goal+= 1;
        else if (event=="foul" && team=="A") A_foul++;
        else if (event=="yellow" && team=="A") A_yellow++;
        else if (event=="red" && team=="A") A_red++;

        else if (event=="penalty" && team=="B")
        B_penalty++;
        else if (event=="cornerkick" && team=="B")
        B_cornerkick++;
        else if (event=="offside" && team=="B")
        B_offside++;
        else if (event=="out" && team=="B")
        B_out++;
        else if (event=="attempt" && team=="B")
        B_attempt++;
        else if (event=="shotongoal" && team=="B")
        B_shotongoal++;
        else if (event=="injury" && team=="B")
        B_injury++;
        else if (event=="goal" && team=="B")
        B_goal++;
        else if (event=="foul" && team=="B")
        B_foul++;
        else if (event=="yellow" && team=="B")
        B_yellow++;
        else if (event=="red" && team=="B")
        B_red++;
    }
    void stats_reset()
    {
        A_penalty = 0;
        A_cornerkick = 0;
        A_offside = 0;
        A_out = 0;
        A_attempt = 0;
        A_shotongoal = 0;
        A_injury = 0;
        A_goal = 0;
        A_foul = 0;
        A_yellow = 0;
        A_red = 0;
        B_penalty = 0;
        B_cornerkick = 0;
        B_offside = 0;
        B_out = 0;
        B_attempt = 0;
        B_shotongoal = 0;
        B_injury = 0;
        B_goal = 0;
        B_foul = 0;
        B_yellow = 0;
        B_red = 0;
        user_input = "NO";
        player_event = "NO";
        player_event_question = "NO";
        player_event_option_A = "NO";
        player_event_option_B = "NO";
        player_event_option_C = "NO";
        player_event_option_D = "NO";

        player_A = "NO";
        player_B = "NO";
        tactics = "NO";
        comment = {};
        cards_yellow = {
                       { "A", {} },
                       { "B", {} }
                       };
        cards_red = {
                    { "A", {} },
                    { "B", {} }
                    };
        }
};

int Match_Stats::A_penalty = 0;
int Match_Stats::A_cornerkick = 0;
int Match_Stats::A_offside = 0;
int Match_Stats::A_out = 0;
int Match_Stats::A_attempt = 0;
int Match_Stats::A_shotongoal = 0;
int Match_Stats::A_injury = 0;
int Match_Stats::A_goal = 0;
int Match_Stats::A_foul = 0;
int Match_Stats::A_yellow = 0;
int Match_Stats::A_red = 0;

int Match_Stats::B_penalty = 0;
int Match_Stats::B_cornerkick = 0;
int Match_Stats::B_offside = 0;
int Match_Stats::B_out = 0;
int Match_Stats::B_attempt = 0;
int Match_Stats::B_shotongoal = 0;
int Match_Stats::B_injury = 0;
int Match_Stats::B_goal = 0;
int Match_Stats::B_foul = 0;
int Match_Stats::B_yellow = 0;
int Match_Stats::B_red = 0;

std::string Match_Stats::user_input;
std::string Match_Stats::player_event;
std::string Match_Stats::player_event_question;
std::string Match_Stats::player_event_option_A;
std::string Match_Stats::player_event_option_B;
std::string Match_Stats::player_event_option_C;
std::string Match_Stats::player_event_option_D;

std::string Match_Stats::player_A;
std::string Match_Stats::player_B;
std::string Match_Stats::tactics;
std::vector<std::string> Match_Stats::comment = {};
std::map<std::string,std::vector<std::string> > Match_Stats::cards_yellow = {
    { "A", {} },
    { "B", {} }
};
std::map<std::string,std::vector<std::string> > Match_Stats::cards_red = {
    { "A", {} },
    { "B", {} }
};
