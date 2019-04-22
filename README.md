NOTE: Made entirely by myself and not inspired by a tutorial.

Author: Marion Veloria (contact via mvel605@aucklanduni.ac.nz)

Date Started: 25/7/18

Title: Advanced Basketball Stat Calculator

Description: Analytic data has taken over the NBA and consequently it has changed the way we view the game.  Stats such as PER (Player Efficiency Rating), EFG (Effective Field Goal Percentage) and TS (True Shooting Percentage) have allowed us to better quantify the impact a player has on the game instead of the conventional stats of points, rebounds and assists.  Because of this I decided to make a calculator that takes a player's stats and calculate the player's advanced statistics using C.

Requirements: As a mac user I used XCode to write my c program and nano which can be used on your terminal to compile my program.  For windows or others I suggest using some sort of Linux compiler.  My program accepts a text file of the player's stats an example can be seen below or the exampleFile.txt in this repository.  It is important to note that the text file must be in this exact format in order for the program to run properly.

Example Text File (# = comments and should not be added to the actual file you use)

Note: the first word is the stat, and the number that follows is the value of that stat, then a comment

Note: example execution of program ./project file.txt (I used gcc -o project project.c to compile my program)

MP,1, #Minutes Played

PTS,2, #Points

TRB,3, #Total Rebounds

DRB,4, #Defensive Rebounds

ORB,5, #Offensive Rebounds

AST,6, #Assists

STL,7, #Steals

BLK,8, #Blocks

FG,9, #Field Goals Made

FGA,10, #Field Goals Attempted

FT,11, #Free Throws Made

FTA,12, #Free Throws Attempted

TOV,13, #Turnovers

PF,14, #Personal Fouls

team_AST,15, #Team Assists 

team_FG,16, #Team Field Goals Made

lg_ft,17, #League Average Free Throws Made

lg_FTA,18,#League Average Free Throws Attempted

lg_FG,19, #League Average Field Goald Made

lg_FGA,20, #League Average Field Goals Attempted

lg_PF,21, #League Average Personal Fouls

lg_PTS,22, #League Average Points

lg_AST,23, #League Average Assists

lg_TRB,24, #League Average Total Rebounds

lg_ORB,25, #League Average Offensive Rebounds

lg_TOV,26, #League Average Turnovers

lg_PPG,27, #League Average Points Per Game

lg_aPER,28, #League Average Pace Adjusted PER

team_PPG,29, #Team Points Per Game

opp_PPG,30, #Opponents Points Per Game

threePoints,31, #Three Pointers Made
