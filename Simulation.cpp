#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <time.h>
#include <vector>
#include <array>
#include <map>

#include "Match_Stats.h"
#include "Rating.h"
#include "Commentator.h"
// rename file to match opportunities
// split classes to files

Match_Stats Stats;
Rating Effectivity;
Commentator Comment;
std::string com;

class Match_Opportunities
{
    private:
       
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
                com = Comment.comment_get("FOUL");
                Stats.stats_set("comment",com);
                return true;
            }
            else if(random <= 101 * 90 / 100) 
            {
                Stats.stats_upload("yellow",team);
                //ADD LINE: name = get random name from team
                //ADD LINE: pass name to Match_Stats class
                com = Comment.comment_get("FOUL_YELLOW");
                Stats.stats_set("comment",com);
                return true;
            }
            else
            {
                Stats.stats_upload("red",team);
                //ADD LINE: name = get random name from team
                //ADD LINE: pass name to Match_Stats class
                com = Comment.comment_get("FOUL_RED");
                Stats.stats_set("comment",com);
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
            com = Comment.comment_get("SERIOUS_INJURY");
            Stats.stats_set("comment",com);
        }
        else
        {
            int injury_2 = 15 + temporary_injury;
            if (random <= 101 * injury_2 / 100)
            {
                Stats.stats_upload("injury",team);
                // ADD LINE: suspend player for some time in match, add some penalty for injured player
            com = Comment.comment_get("TEMPORARY_INJURY");
            Stats.stats_set("comment",com);
            }
            else
            {
                Stats.stats_upload("injury",team);
                // ADD LINE: add some penalty for injured player
            com = Comment.comment_get("LIGHT_INJURY");
            Stats.stats_set("comment",com);
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
            // ADD LINE: update class for current match stats, VALUE: PENALTY_AT, GOAL_AT  NOT SURE
            com = Comment.comment_get("GOAL_PENALTY");
            Stats.stats_set("comment",com);
        }
        else
        {
            Stats.stats_upload("penalty",team);
            com = Comment.comment_get("PENALTY_DEFF");
            Stats.stats_set("comment",com);
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
                com = Comment.comment_get("CORNERKICK_AT");
                Stats.stats_set("comment",com);
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
                com = Comment.comment_get("CORNERKICK_DEFF_PENALTY");
                Stats.stats_set("comment",com);                
                event_penalty(attackers_effectivity, goalkeepers_effectivity, team);
            }
            else
            {
              Stats.stats_upload("cornerkick",team);
              com = Comment.comment_get("CORNERKICK_DEFF");
              Stats.stats_set("comment",com);  
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
                com = Comment.comment_get("SHOTONGOAL_AT");
                Stats.stats_set("comment",com);
            }
        }
        else
        {
            int cornerkick = G_Number * 10 / 100 + G_Number;
            if (random <= cornerkick )
            {
                Stats.stats_upload("shotongoal",team);
                com = Comment.comment_get("SHOTONGOAL_DEFF_CORNERKICK");
                Stats.stats_set("comment",com);
                event_cornerkick(attackers_effectivity, deffenders_effectivity, goalkeepers_effectivity, team);
            }
            else
            {
                Stats.stats_upload("shotongoal",team);
                com = Comment.comment_get("SHOTONGOAL_DEFF");
                Stats.stats_set("comment",com);
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
                com = Comment.comment_get("ATTEMPT_AT");
                Stats.stats_set("comment",com);
            }
        }
        else
        {
            int penalty = D_Number * 1 / 100 + D_Number;
            if(random <= penalty)
            {
                Stats.stats_upload("attempt",team);
                com = Comment.comment_get("ATTEMPT_DEFF_PENALTY");
                Stats.stats_set("comment",com);
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
                    com = Comment.comment_get("ATTEMPT_DEFF");
                    Stats.stats_set("comment",com);
                }
            }
        }
    }
    std::string event_type()
    {
        // Decide to whom event will be processed.
        int event = rand() % 101; // From 0 to 100
        // Decide if event will be auto event or player event
        if (event <= 5) //5
        {
            return "player";
        }
        else
        {
            return "auto"; //auto
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

    void event_player()
    {
     int random_player = rand() % 11;
     std::string player_name = "ADAM PLAYER"; //DELL

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

      event = event_vec[random];   

      if (event == "player_action")
      {
          int random_event = rand() % 4; // random_event in the range 0-3
          question = question_vec[random_event];
          std::vector <std::string> options {"Shoot", "Pass","Hold","Lets Player Decide"};
          Stats.stats_set("player_event_option_A",options[0]);
          Stats.stats_set("player_event_option_B",options[1]);
          Stats.stats_set("player_event_option_C",options[2]);
          Stats.stats_set("player_event_option_D",options[3]);                  
      }    

      else if (event == "player_bonus")
      {
          int random_event = rand() % 4 + 4; // random_event in the range 4-7
          question = question_vec[random_event];
          std::vector <std::string> options {"Attack", "Midfield", "Defense", "Goalkeeper"};
          Stats.stats_set("player_event_option_A",options[0]);
          Stats.stats_set("player_event_option_B",options[1]);
          Stats.stats_set("player_event_option_C",options[2]);
          Stats.stats_set("player_event_option_D",options[3]);                  
      }  

      else if (event == "player_style")
      {               
          int random_event = rand() % 5 + 8; // random_event in the range 8-12              
          question = question_vec[random_event];    
          std::vector <std::string> options {"Play Aggresively", "Play For Posesion", "Play Defensively", "Play As Usual"};   
          Stats.stats_set("player_event_option_A",options[0]);
          Stats.stats_set("player_event_option_B",options[1]);
          Stats.stats_set("player_event_option_C",options[2]);
          Stats.stats_set("player_event_option_D",options[3]);    
      } 

      Stats.stats_set("player_event_question",question);   
      Stats.stats_set("player_event","EVENT"); 
      std::cout <<"From player_event method "<< Stats.stats_get("player_event") << std::endl;
    }  
    
    void event_answer(std::string event, std::string answer, std::string player_name)
    {
      std::vector<std::string> pos = {"CHANGE"};

      if (event == "player_action")
      {
          int random = rand() % 101;
          if (random <= 60)
          {
          event_shotongoal(0,0,0,"A");
          }
          else
          std::cout << "NONE" << std::endl;
          //ADD LINE: upload commentator value: ACTION_NOTHING
      }
      else if (event == "player_bonus")
      {
          int bonus = rand() % 5 + 6; // random in the range 6-10
          if(answer == "A")
          {
              std::cout << "A" << std::endl;
              //ADD LINE: set bonus for attacking effectivity with bonus
              //ADD LINE: upload commentator value: ATTACK_BONUS
          }
          else if(answer == "B")
          {
              std::cout << "B" << std::endl;
              //ADD LINE: set bonus for MID effectivity with bonus
              //ADD LINE: upload commentator value: MID_BONUS
          }              
          else if(answer == "C")
          {
              std::cout << "C" << std::endl;
              //ADD LINE: set bonus for deff effectivity with bonus
              //ADD LINE: upload commentator value: DEFF_BONUS
          }
          else if(answer == "D")
          {
              std::cout << "D" << std::endl;
              //ADD LINE: set bonus for gokp effectivity with bonus
              //ADD LINE: upload commentator value: GOAL_BONUS
          }              
      }
      else if (event == "player_style")
      {
          std::string player_pos = "CHANGE";//ADD LINE: get player possesion
          if (answer == "A")
          {         
              for (std::size_t i = 0; i < pos.size(); i++) // pos.attacking
              {
                  if(player_pos == "CHANGE" )
                  {
                      std::cout << "A" << std::endl;
                      //ADD LINE: set bonus for attacking effectivity with bonus Stats.stats_set
                      //ADD LINE: upload commentator value: ATTACK_BONUS_STYLE
                  }
                  else
                  {
                      std::cout << "PEN" << std::endl;
                      //ADD LINE: set PENALTY for player_pos effectivity -10
                      //ADD LINE: upload commentator value: GOAL_PENALTY_STYLE
                  }                      
              }
          }

          else if(answer == "B")
          {
              for (std::size_t i = 0; i < pos.size(); i++) //pos.midfielding
              {
                  if(player_pos == "CHANGE" )
                  {
                      std::cout << "B" << std::endl;
                      //ADD LINE: set bonus for midf effectivity with bonus
                      //ADD LINE: upload commentator value: MID_BONUS_STYLE
                  }  
                  else
                  {
                      std::cout << "PEN" << std::endl;
                      //ADD LINE: set PENALTY for player_pos effectivity -10
                      //ADD LINE: upload commentator value: GOAL_PENALTY_STYLE
                  }                      
              }
          }
          if (answer == "C")
          {
              for (std::size_t i = 0; i < pos.size(); i++) //pos.defending
              {
                  if(player_pos == "CHANGE" )
                  {
                      std::cout << "C" << std::endl;
                      //ADD LINE: set bonus for deff effectivity with bonus
                      //ADD LINE: upload commentator value: DEFF_BONUS_STYLE
                  }
                  else
                  {
                      std::cout << "PEN" << std::endl;
                      //ADD LINE: set PENALTY for player_pos effectivity -10
                      //ADD LINE: upload commentator value: GOAL_PENALTY_STYLE
                  }                          
              }
          }
          else if(answer == "D") 
              std::cout << "D" << std::endl;
              //ADD LINE: upload commentator value: NO_BONUS_STYLE 
      }

    }
    //std::vector<std::vector<std::string>> questions = {"que"}{"opt"}
  public:
//       Match_Stats Stats;
//       Rating Effectivity;
      
      bool matchopportunity_mechanics(int playerA_possesion, int playerB_possesion) // Use for game loop
      {
           
          std::string playerA = "A";
          std::string playerB = "B"; // WTF?????
          
          std::string player = matchopportunity_player(playerA_possesion,playerB_possesion);
          
          //ADD LINE: Call something what will returns all information about playerB/playerA, bonuses and penalties
          
          
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
                  // ADD LINE: update commentator class with no value     
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
              // // ADD LINE: update commentator class with no value           
                  return false;
              
              else if (event_foul(0,playerB) == true) // pass arg
                  return false;
              
            
              else
              { // Match opportunity IS generated
                  std::string ev_type = event_type();   
                  if (ev_type == "player")
                  {
                      event_player();
                      std::cout <<"From matchopportunity_mechanics method "<< Stats.stats_get("player_event") << std::endl;
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
