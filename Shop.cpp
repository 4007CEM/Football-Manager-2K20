#include<iostream>
#include<algorithms>
#include<Vector>
#include "dbsSource.cpp"
#include "dbsSource.h"

class Shop
{
private:
    vector<Players> forSale;
    float earnings;

public:
    Shop(earnings)
    {
        earnings = round(earnings);
        for(int i = 0; i < forSale.size(); i++)
        {
            forSale[i] = 0;//fill forSale array
        }
    }

    array<Players> get_for_sale()
    { 
        return forSale;
    }

    float get_earnings()
    {
        return earnings;
    }

    void sell_player(Players a,Squad aSquad)
    {
        earnings += a.value;
        for(int i=0;i<aSquad.inField.size();i++)
        {
            if(inField[i] == a)
            {
                inField.erase(inField.begin() + i);
                forSale.push_back(a);
                break;
            }
        }
    }

    void train_player(Players a, int choice)
    {
        if(choice == 0)
        {
            a.pace, a.shooting += 10;
        } 
        else if(choice == 1)
        {
            a.passing, a.dribbling += 10;
        }
        else if(choice == 2)
        {
            a.defending, a.physical += 10;
        }
        else
        {
            a.reflexes, a.diving, a.handling += 10;
        }
    }

    float round_money(float amount)
    {   
        float money = (int)(money * 100 + 0.5);
        return (float)money / 100;
    }
}
