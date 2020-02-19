#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <time.h>
#include <vector> 
#include <chrono>

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

    static int B_penalty;
    static int B_cornerkick;
    static int B_offside;
    static int B_out;
    static int B_attempt;
    static int B_shotongoal;
    static int B_injury;
    static int B_goal;
    //add foul
    public:
    
    void stats_get()
    {
        std::cout << "Player A:"
        "  penalty: "    << A_penalty << 
        ", cornerkick: " << A_cornerkick << 
        ", offside: "    << A_offside << 
        ", out: "        << A_out << 
        ", attempt: "    << A_attempt << 
        ", shotongoal: " << A_shotongoal << 
        ", injury: "     << A_injury << 
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
        
        B_penalty = 0;
        B_cornerkick = 0;
        B_offside = 0;
        B_out = 0;
        B_attempt = 0;
        B_shotongoal = 0;
        B_injury = 0;
        B_goal = 0;
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
    
};

int Match_Stats::A_penalty = 0;
int Match_Stats::A_cornerkick = 0;
int Match_Stats::A_offside = 0;
int Match_Stats::A_out = 0;
int Match_Stats::A_attempt = 0;
int Match_Stats::A_shotongoal = 0;
int Match_Stats::A_injury = 0;
int Match_Stats::A_goal = 0;

int Match_Stats::B_penalty = 0;
int Match_Stats::B_cornerkick = 0;
int Match_Stats::B_offside = 0;
int Match_Stats::B_out = 0;
int Match_Stats::B_attempt = 0;
int Match_Stats::B_shotongoal = 0;
int Match_Stats::B_injury = 0;
int Match_Stats::B_goal = 0;

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
            if (effectivity_type == "attacker") {return attackers_effectivity_B;}
            if (effectivity_type == "deffender") {return deffenders_effectivity_B;}
            if (effectivity_type == "goalkeeper") {return goalkeepers_effectivity_B;}
        }
        if (player == "A")
        {
            if (effectivity_type == "attacker") {return attackers_effectivity_A;}
            if (effectivity_type == "deffender") {return deffenders_effectivity_A;}
            if (effectivity_type == "goalkeeper") {return goalkeepers_effectivity_A;}
        }
    }
};

class Simulation
{
    private:
      
    Match_Stats Stats;
    
//     std::string event_player()
//     {
//         private:
//         int random = rand() % 1;
//         std::string text_header;
//         std::array <std::string> options[3]; 
        
//         public:
        
//         std::string pl_event()
//         {
//             for (i,options,i++)
//             return text_header
//         }
//     }
    
    bool event_foul(int bonus_foul,std::string team)
    {
        
        int random = rand() % 101 ;
        int foul = 5 + bonus_foul;
        
        if (random <= 101 * foul / 100)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    // Create foul card system
    
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
            std::cout << "SERIOUS_INJURY" << std::endl;
        }
        else
        {
            int injury_2 = 15 + temporary_injury;
            if (random <= 101 * injury_2 / 100)
            {
                Stats.stats_upload("injury",team);
                // ADD LINE: suspend player for some time in match, add some penalty for injured player
                // ADD LINE: update class for current match stats, VALUE: TEMPORARY_INJURY
                std::cout << "TEMPORARY_INJURY" << std::endl;
            }
            else
            {
                Stats.stats_upload("injury",team);
                // ADD LINE: add some penalty for injured player
                // ADD LINE: update class for current match stats, VALUE: LIGHT_INJURY
                std::cout << "LIGHT_INJURY" << std::endl;
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
            std::cout << "PENALTY_AT, GOAL_AT" << std::endl;
        }
        else
        {
            Stats.stats_upload("penalty",team);
            // ADD LINE: update class for current match stats, VALUE: PENALTY_DEFF
            std::cout << "PENALTY_DEFF" << std::endl;
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
                std::cout << "CORNERKICK_AT, event_shotongoal" << std::endl;
                event_shotongoal(attackers_effectivity, deffenders_effectivity, goalkeepers_effectivity, team);
            }
            else
            {   
                Stats.stats_upload("cornerkick",team);
                Stats.stats_upload("attempt",team);
                // ADD LINE: update class for current match stats, VALUE: CORNERKICK_AT, ATTEMPT_AT
                std::cout << "CORNERKICK_AT, ATTEMPT_AT" << std::endl;
            }
        }
        else
        {
            int penalty = D_Number * 1 / 100 + D_Number;
            if (random <= penalty)
            {
                Stats.stats_upload("cornerkick",team);
                // ADD LINE: update class for current match stats, VALUE: CORNERKICK_DEFF_PENALTY
                std::cout << "CORNERKICK_DEFF_PENALTY, event_penalty" << std::endl;
                event_penalty(attackers_effectivity, goalkeepers_effectivity, team);
            }
            else
            {
              Stats.stats_upload("cornerkick",team);
              // ADD LINE: update class for current match stats, VALUE: CORNERKICK_DEFF
              std::cout << "CORNERKICK_DEFF" << std::endl;
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
                std::cout << "SHOTONGOAL_AT, GOAL_AT" << std::endl;
            }
            else
            {
                Stats.stats_upload("shotongoal",team);
                // ADD LINE: update class for current match stats, VALUE: SHOTONGOAL_AT
                std::cout << "SHOTONGOAL_AT" << std::endl;
            }
        }
        else
        {
            int cornerkick = G_Number * 10 / 100 + G_Number;
            if (random <= cornerkick )
            {
                Stats.stats_upload("shotongoal",team);
                // ADD LINE: update class for current match stats, VALUE: SHOTONGOAL_DEFF_CORNERKICK
                std::cout << "SHOTONGOAL_DEFF_CORNERKICK, event_cornerkick" << std::endl;
                event_cornerkick(attackers_effectivity, deffenders_effectivity, goalkeepers_effectivity, team);
            }
            else
            {
                Stats.stats_upload("shotongoal",team);
                // ADD LINE: update class for current match stats, VALUE: SHOTONGOAL_DEFF
                std::cout << "SHOTONGOAL_DEFF" << std::endl;
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
                std::cout << "ATTEMPT_AT" << std::endl;
            }
        }
        else
        {
            int penalty = D_Number * 1 / 100 + D_Number;
            if(random <= penalty)
            {
                Stats.stats_upload("attempt",team);
                // ADD LINE: update class for current match stats, VALUE: ATTEMPT_DEFF_PENALTY
                std::cout << "ATTEMPT_DEFF_PENALTY, event_penalty" << std::endl;
                event_penalty(attackers_effectivity, goalkeepers_effectivity, team);
            }
            else
            {
                int cornerkick = D_Number * 10 / 100 + penalty;
                if(random <= cornerkick)
                {   
                    Stats.stats_upload("attempt",team);
                    // NOPE ?? ADD LINE: update class for current match stats, VALUE: ATTEMPT_DEFF_CORNERKICK
                    std::cout << " event_cornerkick" << std::endl;
                    event_cornerkick(attackers_effectivity, deffenders_effectivity, goalkeepers_effectivity, team);
                }
                else
                {
                    Stats.stats_upload("attempt",team);
                    // ADD LINE: update class for current match stats, VALUE: ATTEMPT_DEFF
                    std::cout << "ATTEMPT_DEFF" << std::endl;
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
                           int injury_bonus = 0)
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
              {
                  return false;
              }
              
              else if (event_foul(0,playerA) == true) // pass arg
              {
                  std::cout << "Player A has fouled Player B" << std::endl;
                  // ADD LINE: create foul counter function
                  return false;
              }

              // Match opportunity IS generated
              else
              {
                  // Something what says: Add data to playerB stats
                  std::string event = event_auto(); // pass arg
                  std::cout << "Generated for Player B: " << event << std::endl;
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
              { // Match opportunity IS NOT generated
                  
                  return false;
              }
              
              else if (event_foul(0,playerB) == true) // pass arg
              {
                  std::cout << "Player B has fouled Player A" << std::endl;
                  // ADD LINE: create foul counter function
                  return false;
              }
            
              else
              { // Match opportunity IS generated
                  std::string ev_type = event_type();   
                  if (ev_type == "player")
                  {
                      std::cout << "Player event" << std::endl;
                      // Runs player_events function
                      return true;
                  }
                  else
                  {
                      std::string event = event_auto(); // pass arg
                      std::cout << "Generated for Player A: " << event << std::endl;
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

void timer(int milliseconds)
{
   auto start = std::chrono::steady_clock::now();
   while (true)
   {
       // ADD LINE: which enables to close program
       auto end = std::chrono::steady_clock::now();

       if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > milliseconds)
       break;
   }
}

int main()
{
   srand (time(0)); 
   int counter = 0;

   Simulation Minute;
   Match_Stats Stats;

   while (counter != 94)
   {
       std::cout << counter << " min" << std::endl;
       Minute.matchopportunity_mechanics(500,500);
       //timer(200);
       counter += 1;
   }
  
    Stats.stats_get();
    return 0;
}
