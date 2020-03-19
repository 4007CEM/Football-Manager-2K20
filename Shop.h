#include "dbsSource.cpp"
#include "dbsSource.h"

//Class for the shop (between games)
Class Shop
{
private:
  vector<Players> forSale; // Players for sale
  float earnings; // Money gained from winning games/selling players

public:
  array<Players> get_for_sale(); // retrieves all players for sale
  float get_earnings(); // retrieves earnings
  void sell_player(Players a,Squad aSquad); // sells a given player for money
  void train_player(Players a, int choice); // train a player depending on their position (attack, midfield, defense, goal) 
  float round_money(float amount); //rounds float to 2 decimal places
}
