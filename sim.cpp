#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector> 

int percent(int value, int percentage)
// Calculate percentage
{
  return value * percentage / 100;
}

// Change to void
std::string event_penalty(int attackers_effectivity = 0,
                          int goalkeepers_effectivity = 0)
{
  int A_Number = attackers_effectivity + 500;
  int G_Number = goalkeepers_effectivity + 500;
  int random = rand() % (A_Number + G_Number);
  
  if (random <= A_Number)
  {
    // ADD LINE: update class for current match stats, VALUE: PENALTY_AT, GOAL_AT
    return "goal, events before + penalty"; //Something
  }
  else
  {
    // ADD LINE: update class for current match stats, VALUE: PENALTY_DEFF
    return "shotongoal, events before + penalty"; //Something
  }
}

// Change to void
std::string event_cornerkick(int attackers_effectivity = 0,
                             int deffenders_effectivity = 0,
                             int goalkeepers_effectivity = 0)
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
      return "shotongoal function, events before + cornerkick";
    }
    else
    {
      // ADD LINE: update class for current match stats, VALUE: CORNERKICK_AT, ATTEMPT_AT
      return "attempt, cornerkick, events before ";
    }
  }
  else
  {
    int penalty = D_Number * 1 / 100 + D_Number;
    if (random <= penalty)
    {
      // ADD LINE: update class for current match stats, VALUE: CORNERKICK_DEFF_PENALTY
      return "penalty function, events before + cornerkick";
    }
    else
    {    
      // ADD LINE: update class for current match stats, VALUE: CORNERKICK_DEFF
      return "cornerkick, events before";
    }
  }
}

// Change to void
std::string event_shotongoal(int attackers_effectivity = 0,
                             int deffenders_effectivity = 0,
                             int goalkeepers_effectivity = 0)
{
  int A_Number = attackers_effectivity + 500;
  int G_Number = goalkeepers_effectivity + 500;

  if (random <= A_Number)
  { 
  int goal = A_Number * 25 / 100;
    if (random <= goal)
    {
      // ADD LINE: update class for current match stats, VALUE: ?SHOTONGOAL_AT, GOAL_AT
      return "AG goal, shotongoal + events before";
    }
    else
    {
      // ADD LINE: update class for current match stats, VALUE: SHOTONGOAL_AT
      return "AS shotongoal + events before";
    }
  }
  else
  {
  int cornerkick = G_Number * 10 / 100 + G_Number;
    if (random <= cornerkick )
    {
      // ADD LINE: update class for current match stats, VALUE: SHOTONGOAL_DEFF_CORNERKICK
      return "DC cornerkick function, events before + shotongoal";
    }
    else
    {
      // ADD LINE: update class for current match stats, VALUE: SHOTONGOAL_DEFF
      return "DS shotongoal + events before";
    }
   }
}

// Change to void
std::string event_attempt(int attackers_effectivity = 0,
                          int deffenders_effectivity = 0,
                          int goalkeepers_effectivity = 0
                          )
{ 
  int A_Number = attackers_effectivity + 500;
  int D_Number = deffenders_effectivity + 500;
  int random = rand() % (A_Number + D_Number);
  
  if(random <= A_Number)
  {
    int shotongoal = A_Number * 25 / 100;
    if(random <= shotongoal)
    {
      return "AS shotongoal function";
    }
    else
    {
      // ADD LINE: update class for current match stats, VALUE: ATTEMPT_AT
      return "AA attempt";
    }
  }  
  else 
  {
    int penalty = D_Number * 1 / 100 + D_Number;
      if(random <= penalty)
      {      
        // ADD LINE: update class for current match stats, VALUE: ATTEMPT_DEFF_PENALTY
        return "DP penalty function, attempt+1";
      }
      else
      {
        int cornerkick = D_Number * 10 / 100 + penalty;
        if(random <= cornerkick)
        {    
          // ADD LINE: update class for current match stats, VALUE: CORNERKICK_DEFF
          return "DC cornerkick function, attempt+1";
        }
        else
        {
          // ADD LINE: update class for current match stats, VALUE: ATTEMPT_DEFF
          return "DA attempt deff";          
        }
      }
    }
}
  
bool event_decide()
// Decide to whom event will be processed. 
// PLAYER = TRUE
// AUTOMATIC = FALSE
{
  int event_for = rand() % 101; // From 0 to 100
  
  // Decide if event will be auto event or player event
  if (event_for <= 5)
  {
    return true;
  }
  else
  {
    return false;
  }
}

std::string event_event(int penalty_bonus = 0, int cornerkick_bonus = 0, int offside_bonus = 0,
                           int out_bonus = 0, int attempt_bonus = 0,int shotongoal_bonus = 0,
                           int injury_bonus = 0)
{
  //// This function returns event which is decided automatically 
  
  // Bonus checker
  // Max bonus = 100
  // Min bonus = 0
  if (penalty_bonus > 100 or cornerkick_bonus > 100 or offside_bonus > 100
      or out_bonus > 100 or attempt_bonus > 100 or shotongoal_bonus > 100
      or injury_bonus > 100)
    {
      std::cerr << "Error: event_auto = Bonus can't be over 100!" << std::endl; 
      return 0; 
    }
  if (penalty_bonus < 0 or cornerkick_bonus < 0 or offside_bonus < 0
      or out_bonus < 0 or attempt_bonus < 0 or shotongoal_bonus < 0
      or injury_bonus < 0)
    {
      std::cerr << "Error: event_auto = Bonus can't be less then 0!" << std::endl; 
      return 0; 
    }
  
  // Events initialization
  char penalty[] = "penalty";
  char cornerkick[] = "cornerkick";
  char offside[] = "offside";
  char out[] = "out";
  char attempt[] = "attempt";
  char shotongoal[] = "shotongoal";
  char injury[] = "injury";
  char nothing[] = "nothing";
  
  while (true)
  {
    int event = rand() % 997; // From 0 to 996
    
    if (event >= 0 and event <= penalty_bonus)
      {   
        std::string result(penalty);
        return result;
      }
    else if (event >= 104 and event <= 150 + cornerkick_bonus)
      {
        std::string result(cornerkick);
        return result;
      }
    else if (event >= 251 and event <= 270 + offside_bonus)
      {
        std::string result(offside);
        return result;
      }
    else if (event >= 371 and event <= 420 + out_bonus)
      {
        std::string result(out);
        return result;
      }
    else if (event >= 521 and event <= 660 + attempt_bonus)
      {
        std::string result(attempt);
        return result;
      }
    else if (event >= 761 and event <= 790 + shotongoal_bonus)
      {
        std::string result(shotongoal);
        return result;
      }
    else if (event >= 891 and event <= 891 + injury_bonus)
      {
        std::string result(injury);
        return result;
      }
    else
      {
        std::string result(nothing);
        continue;
      }
  } 
} 
  
std::string matchopportunity_decide(int playerA_possesion, int playerB_possesion)
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

std::string matchopportunity(int playerA_possesion, int playerB_possesion)
{
  int random = rand() % 101;
  
  if (random <= 60)
    {
      std::string player = matchopportunity_decide(playerA_possesion, playerB_possesion);
      if (player == "playerA")
        {
          bool event = event_decide();
          if (event == true)
            {
              return "create player events";
            }
          else
            {
              return event_event(0);
            }
        }
      else
        {
          return event_event(0);
        }
    }
  else
    {
      return "nothing";
    }
}

int main()
{
 
 srand (time(0));  // initialize random seed, HAS TO STAY TO MAKE RAND WORKS
 
 int counter = 0;


 while (counter != 5)
   {
     std::cout << "---------------------" << std::endl;
     std::cout << event_attempt() << std::endl;
     std::cout << "---------------------" << std::endl;
     counter += 1;
     
     }
}
