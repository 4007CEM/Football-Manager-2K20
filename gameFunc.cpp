#include <iostream>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <iomanip>
#include "gameFunc.h"
#include <stdlib.h>


// in order to define your method for a class you need to include the name of the file which is: #include gameFunc.h from above

int Simulation::percent(int value, int percentage)
// Calculate percentage
{
  return value * percentage / 100;
}


std::string Simulation::event_injury(int serious_injury = 0, int temporary_injury = 0)
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


std::string Simulation::event_penalty(int attackers_effectivity = 0, int goalkeepers_effectivity = 0)
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

std::string Simulation::event_cornerkick(int attackers_effectivity = 0, int deffenders_effectivity = 0, int goalkeepers_effectivity = 0)
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



























/**
*       Don't do anything here
*/

Game::Game():
    time1(0),
    time2(0),
    total_time(0),
    your_score(0),
    opponent_score(0),
    status(GameStatus::NONE)
{
}

GameWindow::GameWindow() :
    firstname(""),
    lastname(""),
    fullName(""),
    select_country
    {
        "ITALY",
        "SPAIN",
        "GERMANY",
        "ENGLAND",
        "FRANCE"
    },
    select_league
    {
        "SERIE A",
        "SERIE B",
        "LaLiga",
        "SegundaDivision",
        "Bundesliga",
        "Bundesliga 2",
        "Premier League",
        "Ligue 1",
        "Ligue 2"
    },
    select_squad
    {
        {"Juventus F.C.", "Inter Milan", "S.S.C. Napoli", "Atalanta B.C.", "A.C. Milan", "A.S. Roma", "ACF Fiorentina"},
        {"SS Lazio", "Benevento Calcio", "S.S.D. Palermo", "Delfino Pescara", "F.C. Crotone", "Torino F.C."},
        {"FC Barcelona", "Atletico Bilbao", "Valencia CF", "Sevilla FC", "Real Sociedad", "Real Betis", "Atletico Madrid", "Real Madrid"},
        {"Girona FC", "Granada CF", "Malaga CF"},
        {"FC Bayern Munich", "Borussia Dortmund", "FC Schalke", "FC Koln", "RB Leipzig"},
        {"VfB Stuttgart", "Hamburger SV", "FC Nurnberg", "Holstein Kiel"},
        {"Liverpool F.C.", "Manchester United F.C.", "Arsenal F.C.", "Chelsea F.C.", "Tottenham Hotspur F.C.", "Crystal Palace F.C.", "Everton F.C.", "Manchester City", "Leicester City"},
        {"Paris-Saint-Germain F.C.", "FC Nantes", "As Monaco", "OGC Nice", "Toulouse FC"},
        {"Le Havre", "AS Nancy", "FC Lorient", "RC Lens"}
    }

{
}


MainWindow::MainWindow() :
    pressed(false),
    Options
    {
        "UEFA",
        "Kick Off",
        "Transfers",
        "Squad",
        "Exit"
    },
    SubOptions1
    {
        "Buy Player",
        "Sell Player"
    },
    SubOptions2
    {
        "View Squad",
        "Switch Players"
    }


{
}


void GameWindow::InitWindow()
{

    SetConsoleTitleA("Soccer Manager 2k20.exe");
    ShowConsoleCursor(false);
    char effect[10];

    for(int tick1 = 3; tick1 > 0; tick1--)
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        std::cout << std::setw(65);
        std::cout << "SM 2K20";

        for(int tick2 = 4; tick2 > 0; tick2--)
        {
            Sleep(550);
            strcpy(effect, ".");
            std::cout << effect;
        }
        system("CLS");
    }
    MainWindow init;
    init.MainMenu();

    /*
    while(firstname == "" && lastname == "")
    {
        std::cout "Type "
    }
    */


}


void GameWindow::ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void MainWindow::MainMenu()
{
    SetConsoleTitleA("Soccer Manager 2k20.exe");

    ShowConsoleCursor(false);

    int pointer = 0;

    while(true)
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        for(int i = 0; i < COUNT; i++)
        {

            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << Options[i] << '\t';
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << Options[i] << '\t';
            }
        }

        while(true)
        {
            if (GetAsyncKeyState(VK_LEFT) != 0)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 4;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_RIGHT) != 0)
            {
                pointer += 1;

                if (pointer == COUNT)
                {
                    pointer = 0;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                switch (pointer)
                {
                    case int(MenuOptions::UEFA):
                    {
                        pressed = true;
                        while (pressed)
                        {
                            system("CLS");
                            if (GetAsyncKeyState(VK_ESCAPE) != 0)
                            {
                                MainMenu();
                            }
                        }
                    }
                    case int(MenuOptions::KickOff):
                    {
                        pressed = true;
                        while (pressed)
                        {
                            system("CLS");
                            if (GetAsyncKeyState(VK_ESCAPE) != 0)
                            {
                                MainMenu();
                            }

                        }
                    }
                    case int(MenuOptions::Transfers):
                    {
                        pressed = true;
                        while (pressed)
                        {
                            system("CLS");
                            if (GetAsyncKeyState(VK_ESCAPE) != 0)
                            {
                                MainMenu();
                            }
                        }

                    }
                    case int(MenuOptions::Squad):
                    {
                        pressed = true;
                        while (pressed)
                        {
                            system("CLS");
                            if (GetAsyncKeyState(VK_ESCAPE) != 0)
                            {
                                MainMenu();
                            }
                        }
                    }
                    case int(MenuOptions::Exit):
                    {
                        pressed = true;
                        exit(0);
                    }
                }
            }
        }
        Sleep(150);
    }
}
