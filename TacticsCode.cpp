#include <iostream>
using namespace std;
 
class TacticsFormation { 
Private:
    array<string> formations = {"counter","default","defensive"}
    int attackingFormMult;
    int defaultFormMult;
    int defensiveFormMult;

    int attackingNo;
    int midfieldNo;
    int defenseNo;
    int penalty-bonus;
    int cornerkick-bonus;
    int offside-bonus;
    int out-bonus;
    int attempt-bonus;
    int shotongoal-bonus;
    int injury-bonus;
    int foul-bonus;

    array<string> tactics={"aggressive","balanced","defensive","counter","possesion","random"};
    //array as follows: penalty, cornerkick, offisde, out, attempt, shotongoal, injury, foul
    array<int> tacticStats={0,0,0,0,0,0,0,0};

Public:
    TacticsFormation(attackingNo,midfieldNo,defenseNo){
        updateFormation(attackingNo,midfieldNo,defenseNo);
        tacticStats = {0,0,0,0,0,0,0,0}
    }

    void updateFormation(int aNo, int mNo, int dNo, bool rushGK)  {
        if(aNo + dNo + mNo == 10 && rushGK == false){
            attackingNo = aNo;
            midfieldNo = mNo;
            defensiveNo = dNo;
        }
            attackingMult = (attackingNo - 2)* 0.01 + 1;
            defaultMult = (midfieldNo - 4)* 0.01 + 1;
            defensiveMult = (defensiveNo - 4)* 0.01 + 1;
    }

    array<int> getFormation(){
        return {attackingNo,midfieldNo,defenseNo}
    }

    void updateTactics(int tactic){
        if(tactic==0){ //aggresive
            tacticstats = {penalty_bonus = 90 , cornerkick_bonus = 80 , offside_bonus = 80 , out_bonus = 70 , attempt_bonus = 85 , shotongoal_bonus = 80 , injury_bonus = 80 };
        } else if(tactic==1){ //balanced
            tacticstats = {penalty_bonus = 60 , cornerkick_bonus = 50 , offside_bonus = 45 , out_bonus = 40 , attempt_bonus = 50 , shotongoal_bonus = 40 , injury_bonus = 50};
        } else if(tactic==2){ //defensive
            tacticstats = {penalty_bonus = 0 , cornerkick_bonus = 0 , offside_bonus = 0 , out_bonus = 100 , attempt_bonus = 0 , shotongoal_bonus = 0 , injury_bonus = 10};
        } else if(tactic==3){ //counter
            tacticstats = {penalty_bonus = 103 , cornerkick_bonus = 100 , offside_bonus = 95 , out_bonus = 90 , attempt_bonus = 100 , shotongoal_bonus = 95 , injury_bonus = 90};
        } else if(tactic==4){ //possesion
            tacticstats = {penalty_bonus = 0 , cornerkick_bonus = 60 , offside_bonus = 55 , out_bonus = 45 , attempt_bonus = 65 , shotongoal_bonus = 60 , injury_bonus = 10};
        } else //random!
            tacticstats = {penalty_bonus = 25 , cornerkick_bonus = 40 , offside_bonus = 30 , out_bonus = 20 , attempt_bonus = 60 , shotongoal_bonus = 50 , injury_bonus = 30};
    }
};
