#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <tuple>

int percent(int value, int percentage)
// Calculate percentage
{
  return value * percentage / 100;
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

std::string event_auto(int penalty_bonus = 0, int cornerkick_bonus = 0, int offside_bonus = 0,
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
    int event = rand() % 1001; // From 0 to 1000
    
    if (event >= 0 and event <= 3 + penalty_bonus)
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
    else if (event >= 891 and event <= 896 + injury_bonus)
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
              return event_auto();
            }
        }
      else
        {
          return event_auto();
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
 int num = 0;

 while (counter != 95)
   {
   std::string result = matchopportunity(10000,10000); 
   
     if (result != "nothing")
     {
       std::cout << counter << " min -> " << num << ": " << result <<std::endl; 
       num += 1; 
     }
     else 
     {
       std::cout << counter << " min -> x" << std::endl;
     }             
     counter += 1;
     }
}
