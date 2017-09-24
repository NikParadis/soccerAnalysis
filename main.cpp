//
//  main.cpp
//  PremierLeagueStats
//
//  Created by Nikolas Paradis on 2016-12-25.
//  Copyright © 2016 Nikolas Paradis. All rights reserved.
//

//
//  main.cpp
//  SoccerStats
//
//  Created by Nikolas Paradis on 2016-12-24.
//  Copyright © 2016 Nikolas Paradis. All rights reserved.
//

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    
     cout << setw(25) << "Points:" << setw(10) << "Wins:" << setw(10) << "Ties:" << setw(10) << "Losses:" << setw(15) << "Goals Scored:" << setw(18) << "Goals Conceded:" << setw(15) << "Games Played:" << setw(18) << "% Scores First:" << setw(15) << "% Comebacks:" << setw(18) << "Clean Sheets:" << setw(15) << endl;
    
    for (int a=0; a<20; a++){
        
    // Reads in all data from files
    ifstream fin("Prem_2016.txt");
    if (!fin)
        cout << "Unable to open file" << endl;
    ifstream finGt("Goal_Times_2016.txt");
    if (!finGt)
        cout << "Unable to open file" << endl;
   // ofstream fout("Prem_2016_Stats");

  //fout << "Team: " << endl << setw(25) << "Points:" << setw(10) << "Wins:" << setw(10) << "Ties:" << setw(10) << "Losses:" << setw(15) << "Goals Scored:" << setw(18) << "Goals Conceded:" << setw(15) << "Games Played:" << endl;

  // Variables to be read in and kept track of
  string homeTeam, awayTeam, date, teamName;

  int numGame, goalsHome, goalsAway, shotsOnTargetHome, shotOnTargetAway,
      shotsHome, shotsAway, touchesHome, touchesAway, passesHome, passesAway,
      tacklesHome, tacklesAway, clearancesHome, clearancesAway, cornersHome,
      cornersAway, attendanceHome;

  double posessionHome, posessionAway;

  // ensure input from user is correct
  do {
    cout << "Team: " ;
    cin >> teamName;
  } while (teamName != "Man_Utd" && teamName != "Man_City" &&
           teamName != "West_Ham" && teamName != "Arsenal" &&
           teamName != "Everton" && teamName != "Tottenham" &&
           teamName != "Crystal_Palace" && teamName != "Leicester" &&
           teamName != "Liverpool" && teamName != "Southampton" &&
           teamName != "Swansea" && teamName != "Norwich" &&
           teamName != "Watford" && teamName != "Chelsea" &&
           teamName != "West_Brom" && teamName != "Bournemouth" &&
           teamName != "Stoke" && teamName != "Aston_Villa" &&
           teamName != "Newcastle" && teamName != "Sunderland");

  int wins = 0, ties = 0, losses = 0, goalsScored = 0, goalsConceded = 0,
      gamesPlayed = 0;

  while (fin >> numGame >> homeTeam >> awayTeam >> goalsHome >> goalsAway >>
         posessionHome >> posessionAway >> shotsOnTargetHome >>
         shotOnTargetAway >> shotsHome >> shotsAway >> touchesHome >>
         touchesAway >> passesHome >> passesAway >> tacklesHome >>
         tacklesAway >> clearancesHome >> clearancesAway >> cornersHome >>
         cornersAway >> attendanceHome >> date) { // opens001

    // after read data in, simple increment to keep track of major stats
    // and ensure correct input
    if (homeTeam == teamName || awayTeam == teamName) { // opens003
      if (homeTeam == teamName) {
        if (goalsHome > goalsAway)
          wins++;
        else if (goalsHome == goalsAway)
          ties++;
        else
          losses++;

        for (int i = 0; i < goalsHome; i++) {
          goalsScored++;
        }

        for (int l = 0; l < goalsAway; l++) {
          goalsConceded++;
        }
      }

      if (awayTeam == teamName) {
        if (goalsAway > goalsHome)
          wins++;
        else if (goalsAway == goalsHome)
          ties++;
        else
          losses++;

        for (int k = 0; k < goalsAway; k++) {
          goalsScored++;
        }

        for (int m = 0; m < goalsHome; m++) {
          goalsConceded++;
        }
      }
      gamesPlayed++;
    } // closes003
  }   // closes001

  // Output the major stats
  /*cout << "Team: " << teamName << endl
       << "Points: " << wins * 3 + ties << endl
       << "wins: " << wins << endl
       << "ties: " << ties << endl
       << "losses: " << losses << endl
       << "Goals scored: " << goalsScored << endl
       << "Goals conceded: " << goalsConceded << endl
       << "Games played: " << gamesPlayed << endl;*/
        
    //cout << setw(22) << wins * 3 + ties << setw(10) << wins << setw(10) << ties << setw(10) << losses << setw(15) << goalsScored << setw(18) << goalsConceded << setw(15) << gamesPlayed << endl;
    
    //fout << teamName << endl << setw(22) << wins * 3 + ties << setw(10) << wins << setw(10) << ties << setw(10) << losses << setw(15) << goalsScored << setw(18) << goalsConceded << setw(15) << gamesPlayed << endl;
    
  // Variables to keep track of in second file, Goal_Times_2016
  int homeScoredFirst = 0, awayScoredFirst = 0, homeScoredFirstHalf = 0,
      homeScoredSecondHalf = 0, awayScoredFirstHalf = 0,
      awayScoredSecondHalf = 0, homeComebackToWin = 0, awayComebackToWin = 0,
      homeEqualize = 0, awayEqualize = 0, homeCleanSheets = 0,
      awayCleanSheets = 0, awayBlewLead = 0, homeBlewLead = 0,
      teamScoredFirst = 0, teamConcededFirst = 0, teamScoredFirstHalf = 0,
      teamScoredSecondHalf = 0, teamConcededFirstHalf = 0,
      teamConcededSecondHalf = 0, teamCameBackToWin = 0, teamBlewLead = 0,
      teamEqualized = 0, teamGotEqualizedOn = 0, teamCleanSheets = 0, count = 0,
      gameNumber = 0, homeGoals, awayGoals, firstHomeGoal, firstAwayGoal,
      othergoals;
  // end variable are being read in, others are to keep track for
  // satistical analysis

  string teamHome, teamAway, newDate;

  while (count < 380) { // opens1000
    int goalTimeHome[7] = {0};
    int goalTimeAway[7] = {0};

    finGt >> gameNumber >> teamHome >> teamAway >> homeGoals;

    if (homeGoals != 0) {
      finGt >> firstHomeGoal;
      goalTimeHome[0] = firstHomeGoal;
      for (int i = 1; i < homeGoals; i++) {
        finGt >> othergoals;
        goalTimeHome[i] = othergoals;
      }
    }

    finGt >> awayGoals;

    if (awayGoals != 0) {
      finGt >> firstAwayGoal;
      goalTimeAway[0] = firstAwayGoal;
      for (int g = 1; g < awayGoals; g++) {
        finGt >> othergoals;
        goalTimeAway[g] = othergoals;
      }
    }

    finGt >> newDate;

    // Error checking on array if needed
    /*cout << gameNumber << endl;

    for (int f = 0; f < 7; f++) {
      cout << goalTimeAway[f] << " ";
    }
    cout << endl;
    for (int y = 0; y < 7; y++) {
      cout << goalTimeHome[y] << " ";
    }
    cout << endl;*/

    // Clean Sheets
    if (homeGoals == 0) {
      awayCleanSheets++;
      if (teamName == teamAway) {
        teamCleanSheets++;
      }
    }

    if (awayGoals == 0) {
      homeCleanSheets++;
      if (teamName == teamHome) {
        teamCleanSheets++;
      }
    }

    // First half conceding and scoring
    if (goalTimeHome[0] <= 45 && goalTimeHome[0] != 0) {
      homeScoredFirstHalf++;
      if (teamName == teamHome) {
        teamScoredFirstHalf++;
      }
      if (teamName == teamAway) {
        teamConcededFirstHalf++;
      }
    }

    if (goalTimeAway[0] <= 45 && goalTimeAway[0] != 0) {
      awayScoredFirstHalf++;
      if (teamName == teamAway) {
        teamScoredFirstHalf++;
      }
      if (teamName == teamHome) {
        teamConcededFirstHalf++;
      }
    }

    // second half conceding and scoring
    if (goalTimeHome[0] > 45 && goalTimeHome[0] <= 90) {
      homeScoredSecondHalf++;
      if (teamName == teamHome) {
        teamScoredSecondHalf++;
      }
      if (teamName == teamAway) {
        teamConcededSecondHalf++;
      }
    }

    if (goalTimeAway[0] > 45 && goalTimeAway[0] <= 90) {
      awayScoredSecondHalf++;
      if (teamName == teamAway) {
        teamScoredSecondHalf++;
      }
      if (teamName == teamHome) {
        teamConcededSecondHalf++;
      }
    }

    // Scoring and conceding first
    if (goalTimeHome[0] != 0) {
      if (goalTimeAway[0] == 0 || goalTimeHome[0] < goalTimeAway[0]) {
        homeScoredFirst++;
        if (teamName == teamHome) {
          teamScoredFirst++;
        }
        if (teamName == teamAway) {
          teamConcededFirst++;
        }
      }
    }

    if (goalTimeAway[0] != 0) {
      if (goalTimeHome[0] == 0 || goalTimeAway[0] < goalTimeHome[0]) {
        awayScoredFirst++;
        if (teamName == teamAway) {
          teamScoredFirst++;
        }
        if (teamName == teamHome) {
          teamConcededFirst++;
        }
      }
    }

    // Equalizers for and against
    if (homeGoals == awayGoals != 0) {
      if (goalTimeHome[0] < goalTimeAway[0]) {
        awayEqualize++;
        if (teamName == teamHome) {
          teamGotEqualizedOn++;
        }
        if (teamName == teamAway) {
          teamEqualized++;
        }
      }

      else if (goalTimeAway[0] < goalTimeHome[0]) {
        homeEqualize++;
        if (teamName == teamAway) {
          teamGotEqualizedOn++;
        }
        if (teamName == teamHome) {
          teamEqualized++;
        }
      }
    }

    // Blowing Leads and coming back
    if (homeGoals != 0 && awayGoals != 0 && homeGoals > awayGoals) {
      if (goalTimeAway[0] < goalTimeHome[0]) {
        awayBlewLead++;
        homeEqualize++;
        homeComebackToWin++;
        if (teamName == teamAway) {
          teamBlewLead++;
          teamGotEqualizedOn++;
        }
        if (teamName == teamHome) {
          teamCameBackToWin++;
          teamEqualized++;
        }
      }
    }

    if (homeGoals != 0 && awayGoals != 0 && awayGoals > homeGoals) {
      if (goalTimeHome[0] < goalTimeAway[0]) {
        homeBlewLead++;
        awayComebackToWin++;
        awayEqualize++;
      }
      if (teamName == teamHome) {
        teamBlewLead++;
        teamGotEqualizedOn++;
      }
      if (teamName == teamAway) {
        teamCameBackToWin++;
        teamEqualized++;
      }
    }

    count++;
  } // closes 1000

  /*cout << "Away teams score first " << double(awayScoredFirst) / count * 100
       << "% of the time" << endl;
  cout << "Home teams score first " << double(homeScoredFirst) / count * 100
       << "% of the time" << endl;
  cout << teamName << " scores first "
       << double(teamScoredFirst) / gamesPlayed * 100 << "% of the time"
       << endl;
  cout << "Away teams blow the lead " << double(awayBlewLead) / count * 100
       << "% of the time" << endl;
  cout << "Home teams blow the lead " << double(homeBlewLead) / count * 100
       << "% of the time" << endl;
  cout << teamName << " blows the lead "
       << double(teamBlewLead) / gamesPlayed * 100 << "% of the time" << endl;
  cout << teamName << " came back to win "
       << double(teamCameBackToWin) / gamesPlayed * 100 << "% of the time"
       << endl;*/
        
  cout << setw(22) << wins * 3 + ties << setw(10) << wins << setw(10) << ties << setw(10) << losses << setw(15) << goalsScored << setw(18) << goalsConceded << setw(15) << gamesPlayed << setw(17) << setprecision(4) << teamScoredFirst/double(gamesPlayed) * 100 << setw(16) << (teamEqualized + teamCameBackToWin)/double(gamesPlayed) * 100 << setw(18) << teamCleanSheets << endl;
            }
    
  return 0;
}
