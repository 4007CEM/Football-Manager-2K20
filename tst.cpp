#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <time.h>
#include <vector>
#include <chrono>

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
    
    bool event_foul(int bonus_foul)
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
                      int temporary_injury)
    {
        int random = rand() % 101 ;
        int injury_3 = 5 + serious_injury;

        if (random <= 101 * injury_3 / 100)
        {
            // ADD LINE: suspend player for whole match
            // ADD LINE: update class for current match stats, VALUE: SERIOUS_INJURY
            std::cout << "SERIOUS_INJURY" << std::endl;
        }
        else
        {
            int injury_2 = 15 + temporary_injury;
            if (random <= 101 * injury_2 / 100)
            {
                // ADD LINE: suspend player for some time in match, add some penalty for injured player
                // ADD LINE: update class for current match stats, VALUE: TEMPORARY_INJURY
                std::cout << "TEMPORARY_INJURY" << std::endl;
            }
            else
            {
                // ADD LINE: add some penalty for injured player
                // ADD LINE: update class for current match stats, VALUE: LIGHT_INJURY
                std::cout << "LIGHT_INJURY" << std::endl;
            }
        }
    }
 
    void event_penalty(int attackers_effectivity,
                       int goalkeepers_effectivity)
    {
        int A_Number = attackers_effectivity + 500;
        int G_Number = goalkeepers_effectivity + 500;
        int random = rand() % (A_Number + G_Number);

        if (random <= A_Number)
        {
            // ADD LINE: update class for current match stats, VALUE: PENALTY_AT, GOAL_AT
            std::cout << "PENALTY_AT, GOAL_AT" << std::endl;
        }
        else
        {
            // ADD LINE: update class for current match stats, VALUE: PENALTY_DEFF
            std::cout << "PENALTY_DEFF" << std::endl;
        }
    }
   
    void event_cornerkick(int attackers_effectivity,
                          int deffenders_effectivity,
                          int goalkeepers_effectivity)
    {
        int A_Number = attackers_effectivity + 500;
        int D_Number = deffenders_effectivity + 500;
        int random = rand() % (A_Number + D_Number);

        if (random <= A_Number)
        {
            int shotongoal = A_Number * 20 / 100;
            if (random <= shotongoal)
            {
                // ADD LINE: update class for current match stats, VALUE: CORNERKICK_AT
                std::cout << "CORNERKICK_AT, event_shotongoal" << std::endl;
                event_shotongoal(attackers_effectivity, deffenders_effectivity, goalkeepers_effectivity);
            }
            else
            {
                // ADD LINE: update class for current match stats, VALUE: CORNERKICK_AT, ATTEMPT_AT
                std::cout << "CORNERKICK_AT, ATTEMPT_AT" << std::endl;
            }
        }
        else
        {
            int penalty = D_Number * 1 / 100 + D_Number;
            if (random <= penalty)
            {
                // ADD LINE: update class for current match stats, VALUE: CORNERKICK_DEFF_PENALTY
                std::cout << "CORNERKICK_DEFF_PENALTY, event_penalty" << std::endl;
                event_penalty(attackers_effectivity, goalkeepers_effectivity);
            }
            else
            {
              // ADD LINE: update class for current match stats, VALUE: CORNERKICK_DEFF
              std::cout << "CORNERKICK_DEFF" << std::endl;
            }
        }
    }

    void event_shotongoal(int attackers_effectivity,
                          int deffenders_effectivity,
                          int goalkeepers_effectivity)
    {
        int A_Number = attackers_effectivity + 500;
        int G_Number = goalkeepers_effectivity + 500;
        int random = rand() % (A_Number + G_Number + 1);

        if (random <= A_Number)
        {
            int goal = A_Number * 25 / 100;
            if (random <= goal)
            {
                // ADD LINE: update class for current match stats, VALUE: ?SHOTONGOAL_AT, GOAL_AT
                std::cout << "SHOTONGOAL_AT, GOAL_AT" << std::endl;
            }
            else
            {
                // ADD LINE: update class for current match stats, VALUE: SHOTONGOAL_AT
                std::cout << "SHOTONGOAL_AT" << std::endl;
            }
        }
        else
        {
            int cornerkick = G_Number * 10 / 100 + G_Number;
            if (random <= cornerkick )
            {
                // ADD LINE: update class for current match stats, VALUE: SHOTONGOAL_DEFF_CORNERKICK
                std::cout << "SHOTONGOAL_DEFF_CORNERKICK, event_cornerkick" << std::endl;
                event_cornerkick(attackers_effectivity, deffenders_effectivity, goalkeepers_effectivity);
            }
            else
            {
                // ADD LINE: update class for current match stats, VALUE: SHOTONGOAL_DEFF
                std::cout << "SHOTONGOAL_DEFF" << std::endl;
            }
        }
    }

    void event_attempt(int attackers_effectivity,
                       int deffenders_effectivity,
                       int goalkeepers_effectivity)
    {
        int A_Number = attackers_effectivity + 500;
        int D_Number = deffenders_effectivity + 500;
        int random = rand() % (A_Number + D_Number + 1);

        if(random <= A_Number)
        {
            int shotongoal = A_Number * 25 / 100;
            if(random <= shotongoal)
            {
                event_shotongoal(attackers_effectivity, deffenders_effectivity, goalkeepers_effectivity);
            }
            else
            {
                // ADD LINE: update class for current match stats, VALUE: ATTEMPT_AT
                std::cout << "ATTEMPT_AT" << std::endl;
            }
        }
        else
        {
            int penalty = D_Number * 1 / 100 + D_Number;
            if(random <= penalty)
            {
                // ADD LINE: update class for current match stats, VALUE: ATTEMPT_DEFF_PENALTY
                std::cout << "ATTEMPT_DEFF_PENALTY, event_penalty" << std::endl;
                event_penalty(attackers_effectivity, goalkeepers_effectivity);
            }
            else
            {
                int cornerkick = D_Number * 10 / 100 + penalty;
                if(random <= cornerkick)
                {
                    // ADD LINE: update class for current match stats, VALUE: CORNERKICK_DEFF
                    std::cout << "CORNERKICK_DEFF, event_cornerkick" << std::endl;
                    event_cornerkick(attackers_effectivity, deffenders_effectivity, goalkeepers_effectivity);
                }
                else
                {
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
              
              else if (event_foul(0) == true) // pass arg
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
                      event_penalty(attackers_effectivity_B, goalkeepers_effectivity_A);
                  }
                  else if (event == "cornerkick")
                  {
                      event_cornerkick(attackers_effectivity_B, deffenders_effectivity_A, goalkeepers_effectivity_A); 
                  }
                  else if (event == "attempt")
                  {
                      event_attempt(attackers_effectivity_B, deffenders_effectivity_A, goalkeepers_effectivity_A); 
                  }
                  else if (event == "shotongoal")
                  {
                      event_shotongoal(attackers_effectivity_B, deffenders_effectivity_A, goalkeepers_effectivity_A);
                  }
                  else if (event == "injury")
                  {
                      event_injury(0,0); // pass arg
                  }
                  else
                  {
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
              
              else if (event_foul(0) == true) // pass arg
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
                      std::cout << "Generated for Player A: Player events" << std::endl;
                      // Runs player_events function
                      return true;
                  }
                  else
                  {
                      std::string event = event_auto(); // pass arg
                      std::cout << "Generated for Player A: " << event << std::endl;
                      if (event == "penalty")
                      {
                          event_penalty(attackers_effectivity_A, goalkeepers_effectivity_B);
                      }
                      else if (event == "cornerkick")
                      {
                          event_cornerkick(attackers_effectivity_A, deffenders_effectivity_B, goalkeepers_effectivity_B);
                      }
                      else if (event == "attempt")
                      {
                          event_attempt(attackers_effectivity_A, deffenders_effectivity_B, goalkeepers_effectivity_B);
                      }
                      else if (event == "shotongoal")
                      {
                          event_shotongoal(attackers_effectivity_A, deffenders_effectivity_B, goalkeepers_effectivity_B);
                      }
                      else if (event == "injury")
                      {
                          event_injury(0,0); // pass arg
                      }
                      else
                      {
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
   

   while (counter != 94)
   {
       std::cout << counter << " min" << std::endl;
       Minute.matchopportunity_mechanics(500,500);
       timer(200);
       counter += 1;
   }
   return 0;
}
