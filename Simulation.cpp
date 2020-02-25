#include <iostream>
//#include <stdlib.h>
//#include <stdio.h>
#include <string>
#include <time.h>
//#include <vector>
#include <chrono>
// #include <unistd.h>

#include "simulation.h"

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
   Stats.stats_set("player_event","ev");
   while (counter != 2)
   {
       
       std::cout << counter << " min" << std::endl;
       Minute.matchopportunity_mechanics(500,500);

       if (Stats.stats_get("player_event") == "EVENT")
       {
           std::cout << Stats.stats_get("player_event") << std::endl;
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

           Stats.stats_set("player_event","N");            
       }
       //timer(200);
       

       counter += 1;
   }
  
    //Stats.stats_get();
    
    return 0;
}

//    std::this_thread::sleep_for(std::chrono::milliseconds(200));
