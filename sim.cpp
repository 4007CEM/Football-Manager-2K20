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
std::string event_injury(int serious_injury = 0,
                         int temporary_injury = 0)
{
  int random = rand() % 101 ;
  
  int injury_3 = 5 + serious_injury;
  if (random <= 101 * injury_3 / 100)
  {
    // ADD LINE: suspend player for whole match
    // ADD LINE: update class for current match stats, VALUE: SERIOUS_INJURY
    return "serious_injury";
  }
  else 
  {
    int injury_2 = 15 + temporary_injury;
    if (random <= 101 * injury_2 / 100)
    {
    // ADD LINE: suspend player for some time in match, add some penalty for injured player
    // ADD LINE: update class for current match stats, VALUE: TEMPORARY_INJURY
    return "temporary_injury";    
    }
    else
    {
    // ADD LINE: add some penalty for injured player
    // ADD LINE: update class for current match stats, VALUE: LIGHT_INJURY
    return "light_injury";    
    }

  }
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
  int random = rand() % (A_Number + G_Number + 1);

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
  int random = rand() % (A_Number + D_Number + 1);
  
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
  
std::string event_type()
// Decide to whom event will be processed. 
{
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
  //// This function returns event which is decided automatically 
    
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
  
  while (true)
  {
    int event = rand() % 992; // From 0 to 991
    
    if (event >= 0 and event <= penalty_bonus)
      {   
        return "penalty";
      }
    else if (event >= 104 and event <= 150 + cornerkick_bonus)
      {
        return "cornerkick";
      }
    else if (event >= 251 and event <= 270 + offside_bonus)
      {
        return "offside";
      }
    else if (event >= 371 and event <= 420 + out_bonus)
      {
        return "out";
      }
    else if (event >= 521 and event <= 660 + attempt_bonus)
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

bool matchopportunity_mechanics(int playerA_possesion, int playerB_possesion)
{
  std::string player = matchopportunity_player(playerA_possesion,playerB_possesion);
  
  if (player == "playerB")
  {
  // Call something what will returns all information about playerB, bonuses and penalties
  int random = rand() % 101;
    
    // Match opportunity IS NOT generated
    if (random <= 40 ) // + or -, depends on bonus
    {   
      return false;
    }
    
    // Match opportunity IS generated
    else 
    {
    // Something what says: Add data to playerB stats
    std::string event = event_auto(); // pass arg
      std::cout << "Player B: " << event << std::endl;
      if (event == "penalty")
      {
        event_penalty(); // pass arg
      }
      else if (event == "cornerkick")
      {
        event_cornerkick(); // pass arg
      }
      else if (event == "attempt")
      {
        event_attempt(); // pass arg
      }
      else if (event == "shotongoal")
      {
        event_shotongoal(); // pass arg
      }
      else if (event == "injury")
      {
        event_injury(); // pass arg
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
    {
      // Match opportunity IS NOT generated
      return false;
    }
    
    // Match opportunity IS generated
    else
    {
      std::string ev_type = event_type();
      if (ev_type == "player")
      {
        std::cout << "Player A: Player event " << std::endl;
      // Runs player_events function
      return true;
      }
      else
      {
      // Something what says: Add data to playerA stats
      std::string event = event_auto(); // pass arg
        std::cout << "Player A: " << event << std::endl;
        if (event == "penalty")
        {
          event_penalty(); // pass arg
        }
        else if (event == "cornerkick")
        {
          event_cornerkick(); // pass arg
        }
        else if (event == "attempt")
        {
          event_attempt(); // pass arg
        }
        else if (event == "shotongoal")
        {
          event_shotongoal(); // pass arg
        }
        else if (event == "injury")
        {
          event_injury(); // pass arg
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

int main()
{
 srand (time(0));  // initialize random seed, HAS TO STAY TO MAKE RAND WORKS
 int counter = 0;

 while (counter != 95)
   {
   std::cout << counter << " min" << std::endl;
   matchopportunity_mechanics(10000,10000);       
   counter += 1;
   }             
}

