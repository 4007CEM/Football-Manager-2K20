#include<Vector>
#define "Shop.h"
#include "dbsSource.cpp"
#include "dbsSource.h"

Shop::array<Players> get_for_sale()
{ 
    return forSale;
}

Shop::get_earnings()
{
    return earnings;
}

Shop::sell_player(Players a,Squad aSquad)
{ // check for player in the squad, remove him, compensate user
    for(int i=0;i<aSquad.inField.size();i++)
    {
        if(inField[i] == a) 
        {
            inField.erase(inField.begin() + i);
            forSale.push_back(a);
            earnings += a.value;
            break;
        }//end if
    }//end for
}

Shop::train_player(Players a, int choice)
{ // Choices are as follows: 0 attack, 1 midfield, 2 defense, else goalkeeper
    if(choice == 0) a.pace, a.shooting += 10; 
    else if(choice == 1) a.passing, a.dribbling += 10;
    else if(choice == 2) a.defending, a.physical += 10;
    else a.reflexes, a.diving, a.handling += 10;
}

Shop::round_money(float amount)
{ // rounds to nearest 2nd decimal place   
    float money = (int)(money * 100 + 0.5);
    return (float)money / 100;
}
