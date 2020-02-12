#ifndef GAMEFUNC_H_INCLUDED
#define GAMEFUNC_H_INCLUDED

#include <string>
#include <array>
#include <vector>


const int SIZE1 = 5;
const int SIZE2 = 9;

enum class GameStatus{NONE, PLAYING, WIN, LOSE, PAUSE, ABANDON, EXIT};

class Simulation : public Game
{
public:
    // Change to void
    std::string Simulation::event_injury(int serious_injury = 0, int temporary_injury = 0);
    std::string Simulation::event_penalty(int attackers_effectivity = 0, int goalkeepers_effectivity = 0);
    std::string Simulation::event_cornerkick(int attackers_effectivity = 0, int deffenders_effectivity = 0, int goalkeepers_effectivity = 0);
    std::string Simulation::event_shotongoal(int attackers_effectivity = 0, int deffenders_effectivity = 0, int goalkeepers_effectivity = 0);
    std::string Simulation::event_attempt(int attackers_effectivity = 0, int deffenders_effectivity = 0, int goalkeepers_effectivity = 0);
    
    std::string Simulation::event_type();
    std::string Simulation::event_auto(int penalty_bonus = 0, int cornerkick_bonus = 0, int offside_bonus = 0,
                           int out_bonus = 0, int attempt_bonus = 0,int shotongoal_bonus = 0,
                           int injury_bonus = 0); // Update after tactics will be coded
                           
    std::string Simulation::matchopportunity_player(int playerA_possesion, int playerB_possesion);
    bool Simulation::matchopportunity_mechanics(int playerA_possesion, int playerB_possesion); // Use for game loop
    
}

class Game
{
    int time1, time2, total_time;
    int your_score, opponent_score;
    GameStatus status;

public:
    Game();
    void Run();

    int GetTime();
    void SetTime1(int time);

    int GetTotalTime();
    void SetTotalTime(int total_time);

    int GetYourScore();
    void SetYourScore(int your_score);

    int GetOpponentScore();
    void SetOpponentScore(int opponent_score);

    GameStatus GetStatus();
    void SetStatus(GameStatus status);

};



enum class CountryOption{ITALY, SPAIN, GERMANY, ENGLAND, FRANCE};

enum class LeagueOption{SERIE_A, SERIE_B, LaLiga, SegundaDivision, Bundesliga, Bundesliga2, Premier_League, Ligue1, Ligue2};



class GameWindow
{
    std::string firstname, lastname, fullName;
    std::array<std::string, SIZE1> select_country;
    std::array<std::string, SIZE2> select_league;
    std::vector<std::vector<std::string>> select_squad;

public:
    GameWindow();

    void ShowConsoleCursor(bool showFlag);
    void InitWindow();

    std::string GetUsername();
    void SetUsername(std::string username);

    std::string GetSelectCountry();
    void SetSelectCountry(std::string select_country);

    std::string GetSelectLeague();
    void SetSelectLeague(std::string select_league);

    std::string GetSelectTeam();
    void SetSelect_team(std::string select_team);



};


enum class MenuOptions{UEFA, KickOff, Transfers, Squad = 3, BuyPlayer = 0, SellPlayer = 1, ViewSquad = 0, SwitchPlayers = 1, Exit = 4};


const int COUNT = 5;
const int COUNT2 = 2;
const int COUNT3 = 2;


class MainWindow : public GameWindow
{
    bool pressed;
    std::array<std::string, COUNT> Options;
    std::array<std::string, COUNT2> SubOptions1;
    std::array<std::string, COUNT3> SubOptions2;

public:
    MainWindow();

    void MainMenu();

    void KickOff();

    void UEFA();

    void Transfers(std::string buy_option, std::string sell_option);
    bool BuyPlayer(std::string search_name);
    bool SellPlayer(std::string search_name, int amount);

    void Squad(std::string view_option, std::string switch_option);
    void ViewSquad();
    bool SwitchPlayer(std::string name);

    void Status();
};





#endif // GAMEFUNC_H_INCLUDED
