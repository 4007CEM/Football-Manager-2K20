#include <iostream>
#include <string>
#include <vector>

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
    
    static std::string comment;
    
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
        else if (event == "comment")               
            comment = input;
    }
    
    std::string stats_get(std::string value_get)
    {
        if (value_get == "user_input")                 
            return user_input;
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
        else if (value_get == "comment")               
            return comment;
        else if (value_get == "temp")
        {
        std::cout << "Player A:"
        "  penalty: "    << A_penalty << 
        ", cornerkick: " << A_cornerkick << 
        ", offside: "    << A_offside << 
        ", out: "        << A_out << 
        ", attempt: "    << A_attempt << 
        ", shotongoal: " << A_shotongoal << 
        ", injury: "     << A_injury << 
        ", foul: "       << A_foul << 
        ", yellow: "     << A_yellow <<
        ", red: "        << A_red << 
        ", goal: "       << A_goal << 
        std::endl;

        std::cout << "Player B:"
        "  penalty: "    << B_penalty << 
        ", cornerkick: " << B_cornerkick << 
        ", offside: "    << B_offside << 
        ", out: "        << B_out << 
        ", attempt: "    << B_attempt << 
        ", shotongoal: " << B_shotongoal << 
        ", injury: "     << B_injury << 
        ", foul: "       << B_foul << 
        ", yellow: "     << B_yellow <<
        ", red: "        << B_red << 
        ", goal: "       << B_goal << 
        std::endl;
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
 
std::string Match_Stats::user_input = "NO";
std::string Match_Stats::player_event = "NO";
std::string Match_Stats::player_event_question = "NO";
std::string Match_Stats::player_event_option_A = "NO";
std::string Match_Stats::player_event_option_B = "NO";
std::string Match_Stats::player_event_option_C = "NO";
std::string Match_Stats::player_event_option_D = "NO";

std::string Match_Stats::player_A = "NO";
std::string Match_Stats::player_B = "NO";
std::string Match_Stats::tactics = "NO";
std::string Match_Stats::comment = "NO";
