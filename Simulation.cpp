#include <iostream>
#include <string>
#include <time.h>
#include <chrono>


#include "Match_Opportunities.h"

Match_Opportunities Minute;

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

   while (counter != 94)
   {
       
       std::cout << counter << " min" << std::endl;
       Minute.matchopportunity_mechanics(500,500);
     
       if (Stats.stats_get("player_event") == "EVENT")
       {
           std::string x1 = Stats.stats_get("player_event_question");
           std::cout << x1 <<std::endl;
           std::string x2 = Stats.stats_get("player_event_option_A");
           std::cout << x2 <<std::endl;
           std::string x3 = Stats.stats_get("player_event_option_B");
           std::cout << x3 <<std::endl;
           std::string x4 = Stats.stats_get("player_event_option_C");
           std::cout << x4 <<std::endl;
           std::string x5 = Stats.stats_get("player_event_option_D");
           std::cout << x5 <<std::endl;
           std::string input;
           std::cin >> input;
           Stats.stats_set("input",input);  

           Stats.stats_set("player_event","NO");            
       }
       
       std::vector<std::string> comment = Stats.comment_get();
       if (comment.size() != 0)
       {
           for (unsigned int i = 0; i < comment.size(); i++)
           {
               std::cout << comment[i] << std::endl;
           }
         Stats.comment_set("",true);
       }
       
       timer(200);
       counter += 1;
   }
    std::cout << "\n" << "END RESULTS:" << "\n" << std::endl;
    Stats.stats_get("temp");
    
    return 0;
}
