#include <iostream>
#define "Morale.h"
using namespace std;

FanMorale::updateFanMorale()
{
  fanMorale = (capacity / 1000) * (1 + adMult) * (weatherMult) + 100 * (leagueID + 1) + 10 * (attempts + goals);
}

FanMorale::getFanMorale()
{
  return fanMorale;
}

TeamPlay::updateTeamPlay()
{
  teamPlay = score*100 + teamRating;
}

TeamPlay::getTeamPlay()
{
  return teamPlay
}

Morale::updateMorale()
{
  updateFanMorale():
  updateTeamPlay();
  morale = (getTeamPlay() + getFanMorale()) / 2;
}

Morale::getMorale()
{
  return morale;
}
