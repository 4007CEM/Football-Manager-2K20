#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <time.h>
#include <vector>
#include <array>
// rename file to match opportunities
// split classes to files
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
    
    std::string user_input;
    std::string player_event;
    std::string player_event_question;
    std::string player_event_option_A;
    std::string player_event_option_B;
    std::string player_event_option_C;
    std::string player_event_option_D;
    
    std::string player_A;
    std::string player_B;
    
    public:
    
    Simulation sim;

    void stats_set(std:string event, std::string input )
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
        else if (event == "player_A")
            return = player_A;
        else if (event == "player_B")
            return = player_B;
        
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

    void stats_upload(std::string event, std::string team)
    {
        //ADD LINE: pass event,team to comment class or pass it from Simulation class
        if (event=="penalty" && team=="A")
        A_penalty+= 1;
        else if (event=="cornerkick" && team=="A")
        A_cornerkick+= 1;
        else if (event=="offside" && team=="A")
        A_offside+= 1;
        else if (event=="out" && team=="A")
        A_out+= 1;
        else if (event=="attempt" && team=="A")
        A_attempt+= 1;
        else if (event=="shotongoal" && team=="A")
        A_shotongoal+= 1;
        else if (event=="injury" && team=="A")
        A_injury+= 1;
        else if (event=="goal" && team=="A")
        A_goal+= 1;
        else if (event=="foul" && team=="A")
        A_foul++;
        else if (event=="yellow" && team=="A")
        A_yellow++; 
        else if (event=="red" && team=="A")
        A_red++; 
        
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

//     SERIOUS_INJURY
//     TEMPORARY_INJURY
//     LIGHT_INJURY
//     PENALTY_AT
//     PENALTY_DEFF
//     GOAL_AT
//     CORNERKICK_AT
//     ATTEMPT_DEFF_PENALTY
//     ATTEMPT_DEFF
//     ATTEMPT_AT
//     ATTEMPT_DEFF_CORNERKICK
//     CORNERKICK_DEFF_PENALTY
//     CORNERKICK_DEFF
//     SHOTONGOAL_AT
//     SHOTONGOAL_DEFF_CORNERKICK
//     SHOTONGOAL_DEFF
//     ATTACK_BONUS    
//     MID_BONUS   
//     GOAL_BONUS  
//     DEFF_BONUS
//     ATTACK_BONUS_STYLE
//     MID_BONUS_STYLE
//     DEFF_BONUS_STYLE
//     NO_BONUS_STYLE
//     GOAL_PENALTY_STYLE

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

//int Match_Stats::user_input;

class Rating // temp class
{
    private:
    
    int attackers_effectivity_A = 100; // of playeraA
    int deffenders_effectivity_A = 100; // of playerA
    int goalkeepers_effectivity_A = 100; // of playerA

    int attackers_effectivity_B = 100; // of playeraB
    int deffenders_effectivity_B = 100; // of playerB
    int goalkeepers_effectivity_B = 100; // of playerB
    
    public:
   
    int getEffectivity(std::string player, std::string effectivity_type)
    {
        if (player == "B")
        {
            if (effectivity_type == "attacker")
                return attackers_effectivity_B;
            if (effectivity_type == "deffender")
                return deffenders_effectivity_B;
            if (effectivity_type == "goalkeeper")
                return goalkeepers_effectivity_B;
        }
        if (player == "A")
        {
            if (effectivity_type == "attacker")
                return attackers_effectivity_A;
            if (effectivity_type == "deffender")
                return deffenders_effectivity_A;
            if (effectivity_type == "goalkeeper")
                return goalkeepers_effectivity_A;
        }
    }
};

class Simulation
{
    private:
      
    Match_Stats Stats;
   
    
    bool event_foul(int bonus_foul,std::string team)
    {
        
        int random = rand() % 101 ;
        int foul = 5 + bonus_foul;
        
        if (random <= 101 * foul / 100)
        {
            Stats.stats_upload("foul",team);
            if (random <= 101 * 70 / 100)
            {
                //ADD LINE: name = get random name from team
                //ADD LINE: pass name to Match_Stats class
                return true;
            }
            else if(random <= 101 * 90 / 100) 
            {
                Stats.stats_upload("yellow",team);
                //ADD LINE: name = get random name from team
                //ADD LINE: pass name to Match_Stats class
                return true;
            }
            else
            {
                Stats.stats_upload("red",team);
                //ADD LINE: name = get random name from team
                //ADD LINE: pass name to Match_Stats class
                return true;
            }
        }
        else
            return false;
    }
    
    
    void event_injury(int serious_injury,
                      int temporary_injury,
                      std::string team)
    {
        int random = rand() % 101 ;
        int injury_3 = 5 + serious_injury;

        if (random <= 101 * injury_3 / 100)
        {
            Stats.stats_upload("injury",team);
            // ADD LINE: suspend player for whole match
            // ADD LINE: update class for current match stats, VALUE: SERIOUS_INJURY
        }
        else
        {
            int injury_2 = 15 + temporary_injury;
            if (random <= 101 * injury_2 / 100)
            {
                Stats.stats_upload("injury",team);
                // ADD LINE: suspend player for some time in match, add some penalty for injured player
                // ADD LINE: update class for current match stats, VALUE: TEMPORARY_INJURY
            }
            else
            {
                Stats.stats_upload("injury",team);
                // ADD LINE: add some penalty for injured player
                // ADD LINE: update class for current match stats, VALUE: LIGHT_INJURY
            }
        }
    }
 
    void event_penalty(int attackers_effectivity,
                       int goalkeepers_effectivity,
                       std::string team)
    {
        int A_Number = attackers_effectivity + 500;
        int G_Number = goalkeepers_effectivity + 500;
        int random = rand() % (A_Number + G_Number);

        if (random <= A_Number)
        {
            Stats.stats_upload("penalty",team);
            Stats.stats_upload("goal",team);
            // ADD LINE: update class for current match stats, VALUE: PENALTY_AT, GOAL_AT
        }
        else
        {
            Stats.stats_upload("penalty",team);
            // ADD LINE: update class for current match stats, VALUE: PENALTY_DEFF
        }
    }
   
    void event_cornerkick(int attackers_effectivity,
                          int deffenders_effectivity,
                          int goalkeepers_effectivity,
                          std::string team)
    {
        int A_Number = attackers_effectivity + 500;
        int D_Number = deffenders_effectivity + 500;
        int random = rand() % (A_Number + D_Number);

        if (random <= A_Number)
        {
            int shotongoal = A_Number * 20 / 100;
            if (random <= shotongoal)
            {
                Stats.stats_upload("cornerkick",team);
                // ADD LINE: update class for current match stats, VALUE: CORNERKICK_AT
                event_shotongoal(attackers_effectivity, deffenders_effectivity, goalkeepers_effectivity, team);
            }
            else
            {   
                Stats.stats_upload("cornerkick",team);
                Stats.stats_upload("attempt",team);
                // ADD LINE: update class for current match stats, VALUE: CORNERKICK_AT, ATTEMPT_AT
            }
        }
        else
        {
            int penalty = D_Number * 1 / 100 + D_Number;
            if (random <= penalty)
            {
                Stats.stats_upload("cornerkick",team);
                // ADD LINE: update class for current match stats, VALUE: CORNERKICK_DEFF_PENALTY
                event_penalty(attackers_effectivity, goalkeepers_effectivity, team);
            }
            else
            {
              Stats.stats_upload("cornerkick",team);
              // ADD LINE: update class for current match stats, VALUE: CORNERKICK_DEFF
            }
        }
    }

    void event_shotongoal(int attackers_effectivity,
                          int deffenders_effectivity,
                          int goalkeepers_effectivity,
                          std::string team)
    {
        int A_Number = attackers_effectivity + 500;
        int G_Number = goalkeepers_effectivity + 500;
        int random = rand() % (A_Number + G_Number + 1);

        if (random <= A_Number)
        {
            int goal = A_Number * 25 / 100;
            if (random <= goal)
            {
                Stats.stats_upload("shotongoal",team);
                Stats.stats_upload("goal",team);
                // ADD LINE: update class for current match stats, VALUE: ?SHOTONGOAL_AT, GOAL_AT
            }
            else
            {
                Stats.stats_upload("shotongoal",team);
                // ADD LINE: update class for current match stats, VALUE: SHOTONGOAL_AT
            }
        }
        else
        {
            int cornerkick = G_Number * 10 / 100 + G_Number;
            if (random <= cornerkick )
            {
                Stats.stats_upload("shotongoal",team);
                // ADD LINE: update class for current match stats, VALUE: SHOTONGOAL_DEFF_CORNERKICK
                event_cornerkick(attackers_effectivity, deffenders_effectivity, goalkeepers_effectivity, team);
            }
            else
            {
                Stats.stats_upload("shotongoal",team);
                // ADD LINE: update class for current match stats, VALUE: SHOTONGOAL_DEFF
            }
        }
    }

    void event_attempt(int attackers_effectivity,
                       int deffenders_effectivity,
                       int goalkeepers_effectivity,
                       std::string team)
    {
        int A_Number = attackers_effectivity + 500;
        int D_Number = deffenders_effectivity + 500;
        int random = rand() % (A_Number + D_Number + 1);

        if(random <= A_Number)
        {
            int shotongoal = A_Number * 25 / 100;
            if(random <= shotongoal)
            {
                event_shotongoal(attackers_effectivity, deffenders_effectivity, goalkeepers_effectivity, team);
            }
            else
            {
                Stats.stats_upload("attempt",team);
                // ADD LINE: update class for current match stats, VALUE: ATTEMPT_AT
            }
        }
        else
        {
            int penalty = D_Number * 1 / 100 + D_Number;
            if(random <= penalty)
            {
                Stats.stats_upload("attempt",team);
                // ADD LINE: update class for current match stats, VALUE: ATTEMPT_DEFF_PENALTY
                event_penalty(attackers_effectivity, goalkeepers_effectivity, team);
            }
            else
            {
                int cornerkick = D_Number * 10 / 100 + penalty;
                if(random <= cornerkick)
                {   
                    Stats.stats_upload("attempt",team);
                    // NOPE ?? ADD LINE: update class for current match stats, VALUE: ATTEMPT_DEFF_CORNERKICK
                    event_cornerkick(attackers_effectivity, deffenders_effectivity, goalkeepers_effectivity, team);
                }
                else
                {
                    Stats.stats_upload("attempt",team);
                    // ADD LINE: update class for current match stats, VALUE: ATTEMPT_DEFF
                }
            }
        }
    }
    std::string event_type()
    {
        // Decide to whom event will be processed.
        int event = rand() % 101; // From 0 to 100
        // Decide if event will be auto event or player event
        if (event <= 5)
        {
            return "player";
        }
        else
        {
            return "auto";
        }
    }
    
    std::string event_auto(int penalty_bonus = 0, int cornerkick_bonus = 0, int offside_bonus = 0,
                           int out_bonus = 0, int attempt_bonus = 0,int shotongoal_bonus = 0,
                           int injury_bonus = 0)//import from sanushans code
    {
        // This function returns event which is decided automatically

        // ALL EVENTS:
        // penalty
        // cornerkick
        // offside
        // out
        // attempt
        // shotongoal
        // injury

        // Bonus checker
        // Max bonus = 100
        // Min bonus = 0

        if (penalty_bonus > 100 || cornerkick_bonus > 100 || offside_bonus > 100
            || out_bonus > 100 || attempt_bonus > 100 || shotongoal_bonus > 100
            || injury_bonus > 100)
        {
            std::cerr << "Error: event_auto = Bonus can't be over 100!" << std::endl;
            return 0;
        }
        if (penalty_bonus < 0 || cornerkick_bonus < 0 || offside_bonus < 0
            || out_bonus < 0 || attempt_bonus < 0 || shotongoal_bonus < 0
            || injury_bonus < 0)
        {
            std::cerr << "Error: event_auto = Bonus can't be less then 0!" << std::endl;
            return 0;
        }

        while (true)
        {
            int event = rand() % 992; // From 0 to 991

            if (event >= 0 and event <= penalty_bonus)
            {
                return "penalty";
            }
            else if (event >= 101 and event <= 150 + cornerkick_bonus)
            {
                return "cornerkick";
            }
            else if (event >= 251 and event <= 260 + offside_bonus)
            {
                return "offside";
            }
            else if (event >= 361 and event <= 410 + out_bonus)
            {
                return "out";
            }
            else if (event >= 511 and event <= 660 + attempt_bonus)
            {
                return "attempt";
            }
            else if (event >= 761 and event <= 790 + shotongoal_bonus)
            {
                return "shotongoal";
            }
            else if (event >= 891 and event <= 891 + injury_bonus)
            {
                return "injury";
            }
            else
            {
                continue;
            }
        }
    }

    std::string matchopportunity_player(int playerA_possesion, int playerB_possesion)
    {
        int total_possesion = playerA_possesion + playerB_possesion;
        int random_possesion = rand() % total_possesion;

        if (random_possesion <= playerA_possesion)
        {
            return "playerA";
        }
        else
        {
            return "playerB";
        }
    }

  public:
   
      void event_answer(std::string event, std::string answer, std::string player_name)
      {
          if (event == "player_action")
              if(answer == "A")
              {
                  //ADD LINE: set bonus for attacking effectivity with bonus
                  //ADD LINE: upload commentator value: ATTACK_BONUS
              }
              else if(answer == "B")
              {
                  //ADD LINE: set bonus for MID effectivity with bonus
                  //ADD LINE: upload commentator value: MID_BONUS
              }              
              else if(answer == "C")
              {
                  //ADD LINE: set bonus for deff effectivity with bonus
                  //ADD LINE: upload commentator value: DEFF_BONUS
              }
              else if(answer == "D")
              {
                  //ADD LINE: set bonus for gokp effectivity with bonus
                  //ADD LINE: upload commentator value: GOAL_BONUS
              }
          else if (event == "player_bonus")
          {
              int bonus = rand() % 5 + 6; // random in the range 6-10
              if(answer == "A")
              {
                  //ADD LINE: set bonus for attacking effectivity with bonus
                  //ADD LINE: upload commentator value: ATTACK_BONUS
              }
              else if(answer == "B")
              {
                  //ADD LINE: set bonus for MID effectivity with bonus
                  //ADD LINE: upload commentator value: MID_BONUS
              }              
              else if(answer == "C")
              {
                  //ADD LINE: set bonus for deff effectivity with bonus
                  //ADD LINE: upload commentator value: DEFF_BONUS
              }
              else if(answer == "D")
              {
                  //ADD LINE: set bonus for gokp effectivity with bonus
                  //ADD LINE: upload commentator value: GOAL_BONUS
              }              
          }
          else if (event == "player_style")
          {
              std::string player_pos = //ADD LINE: get player possesion
              if(answer == "A" && player_pos == (for (int i = 0; i < pos.attacking; i++)) )
              {
                  //ADD LINE: set bonus for attacking effectivity with bonus
                  //ADD LINE: upload commentator value: ATTACK_BONUS_STYLE
              }
              else if(answer == "B" && player_pos == (for (int i = 0; i < pos.midfielding; i++)) )
              {
                  //ADD LINE: set bonus for midf effectivity with bonus
                  //ADD LINE: upload commentator value: MID_BONUS_STYLE
              }              
              else if(answer == "C" && player_pos == (for (int i = 0; i < pos.defending; i++)) )
              {
                  //ADD LINE: set bonus for deff effectivity with bonus
                  //ADD LINE: upload commentator value: DEFF_BONUS_STYLE
              }
              else if(answer == "D") 
                  //ADD LINE: upload commentator value: NO_BONUS_STYLE 
              else
              {
                  //ADD LINE: set PENALTY for player_pos effectivity -10
                  //ADD LINE: upload commentator value: GOAL_PENALTY_STYLE
              }
          }
      
      }
      //std::vector<std::vector<std::string>> questions = {"que"}{"opt"}
      std::string event_option(std::string event)
      {
          if (event == "player_action")
              return "Shoot", "Pass","Hold","Lets Player Decide";
          else if (event == "player_bonus")
              return "Attack", "Midfield", "Defense", "Goalkeeper";
          else if (event == "player_style")
              return "Play Aggresively", "Play For Posesion", "Play Defensively", "Play As Usual"          
      }
  
      void event_player()
      {
         int random_player = rand() % 11;
          while(true)
          {
             if(Players[random_player].position != "GK")
             {
                 std::string player_name = players[random_player].name; //VINCENT
                 break;
             }
          }
          
          std::string question11 = "Your trainer instincts tell you to do something. You called player " + player_name + " to tell him what to do next. What he should do?";
          std::string question10 = player_name + " is asking you what he should do?";
          std::string question9  = player_name + " wants to play more aggresive, what do you think? ";
          std::string question8  = player_name + " wants to play more defensively, what do you think? ";
          std::string question12 = player_name + " wants to play more for posesion, what do you think? ";
  
          std::vector<std::string> question_vec = {
          "question 1_1 0",
          "question 1_2 1",
          "question 1_3 2",
          "question 1_4 3",
          "It seems that your team needs to focus more on one type of possesion? Which one should it be?",
          "Opposition is pressuring you, which area should you focus on?",
          "Your team is holding back, where on the field will you reinforce?",
          "You believe that one of the positions needs a boost, which one do you want to strengthen?",
          question8,
          question9,
          question10,
          question11, 
          question12};
          
          std::string event;
          std::string question;
          std::vector<std::string> event_vec = {"player_action","player_bonus","player_style"}; 
          
          int random = rand() % 3; //0,1,2
          
          for (size_t i = 0; i < event_vec.size(); i++) // or ++i
          {
              if (event_vec[random] == event_vec[i])
              {
                 event = event_vec[random];
                 break;
              }
          }        
          if (event == "player_action")
          {
              int random_event = rand() % 4; // random_event in the range 0-3
              question = question_vec[random_event];
          }    

          else if (event == "player_bonus")
          {
              int random_event = rand() % 4 + 4; // random_event in the range 4-7
              question = question_vec[random_event];
          }  

          else if (event == "player_style")
          {               
              int random_event = rand() % 5 + 8; // random_event in the range 8-12              
              question = question_vec[random_event];
          } 
           
          Stats.stats_set("player_event_question",question);
          
          std::string option_A, std::string option_B, std::string option_C, std::string option_D = event_option(event);
          Stats.stats_set("player_event_option_A",option_A);
          Stats.stats_set("player_event_option_B",option_B);
          Stats.stats_set("player_event_option_C",option_C);
          Stats.stats_set("player_event_option_D",option_D);     
          
          Stats.stats_set("player_event","EVENT");
      }  
      
      bool matchopportunity_mechanics(int playerA_possesion, int playerB_possesion) // Use for game loop
      {
          std::string playerA = "A";
          std::string playerB = "B";
          
          std::string player = matchopportunity_player(playerA_possesion,playerB_possesion);
          
          //ADD LINE: Call something what will returns all information about playerB/playerA, bonuses and penalties
          Rating Effectivity;
          
          int attackers_effectivity_A = Effectivity.getEffectivity("attacker", "A"); // of playeraA
          int deffenders_effectivity_A = Effectivity.getEffectivity("deffender", "A"); // of playerA
          int goalkeepers_effectivity_A = Effectivity.getEffectivity("goalkeeper", "A"); // of playerA
          
          int attackers_effectivity_B = Effectivity.getEffectivity("attacker", "B"); // of playeraB
          int deffenders_effectivity_B = Effectivity.getEffectivity("deffender", "B"); // of playerB
          int goalkeepers_effectivity_B = Effectivity.getEffectivity("goalkeeper", "B"); // of playerB

          if (player == "playerB")
          {
              

              int random = rand() % 101;

              // Match opportunity IS NOT generated

              if (random <= 40 ) // + or -, depends on bonus
                  return false;

              
              else if (event_foul(0,playerA) == true) // pass arg
                  return false;

              // Match opportunity IS generated
              else
              {
                  // Something what says: Add data to playerB stats
                  std::string event = event_auto(); // pass arg
                  if (event == "penalty")
                  {
                      event_penalty(attackers_effectivity_B, goalkeepers_effectivity_A,playerB);
                  }
                  else if (event == "cornerkick")
                  {
                      event_cornerkick(attackers_effectivity_B, deffenders_effectivity_A, goalkeepers_effectivity_A,playerB); 
                  }
                  else if (event == "attempt")
                  {
                      event_attempt(attackers_effectivity_B, deffenders_effectivity_A, goalkeepers_effectivity_A,playerB); 
                  }
                  else if (event == "shotongoal")
                  {
                      event_shotongoal(attackers_effectivity_B, deffenders_effectivity_A, goalkeepers_effectivity_A,playerB);
                  }
                  else if (event == "injury")
                  {
                      event_injury(0,0,playerB); // pass arg
                  }
                  else
                  {
                      Stats.stats_upload(event,playerB);
                      // ADD LINE: update class for current match stats, VALUE: EVENT
                      return true;
                  }
              }
          }

          else // Player A
          {
              // Call something what will returns all information about playerA, bonuses and penalties
              int random = rand() % 101;
                            
              if (random <= 40 ) // + or -, depends on bonus
              // Match opportunity IS NOT generated               
                  return false;
              
              else if (event_foul(0,playerB) == true) // pass arg
                  return false;
              
            
              else
              { // Match opportunity IS generated
                  std::string ev_type = event_type();   
                  if (ev_type == "player")
                  {
                      event_player();
                      return true;
                  }
                  else
                  {
                      std::string event = event_auto(); // pass arg
                      if (event == "penalty")
                      {
                          event_penalty(attackers_effectivity_A, goalkeepers_effectivity_B,playerA);
                      }
                      else if (event == "cornerkick")
                      {
                          event_cornerkick(attackers_effectivity_A, deffenders_effectivity_B, goalkeepers_effectivity_B,playerA);
                      }
                      else if (event == "attempt")
                      {
                          event_attempt(attackers_effectivity_A, deffenders_effectivity_B, goalkeepers_effectivity_B,playerA);
                      }
                      else if (event == "shotongoal")
                      {
                          event_shotongoal(attackers_effectivity_A, deffenders_effectivity_B, goalkeepers_effectivity_B,playerA);
                      }
                      else if (event == "injury")
                      {
                          event_injury(0,0,playerA); // pass arg
                      }
                      else
                      {
                          Stats.stats_upload(event,playerA);
                          // ADD LINE: update class for current match stats, VALUE: EVENT
                          return true;
                      }
                  }
              }
         }
      }
};
