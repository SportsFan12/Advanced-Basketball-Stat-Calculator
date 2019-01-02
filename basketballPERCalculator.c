/*
 Author: Marion Veloria
 Started: 25/7/18
 Vision: As a basketball fanatic I wanted to make a c program
         that will calculate a players PER, TS or EFG which has become popular
         and used by most NBA teams to analyse player performance.
         A file containing the required stats is to be provided by the user.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//game stats
char *MP;
char *PTS;
char *TRB;
char *DRB;
char *ORB;
char *AST;
char *STL;
char *BLK;
char *FG;
char *FGA;
char *FT;
char *FTA;
char *TOV;
char *PF;
char *team_AST;
char *team_FG;

//for calculation (game stats)
double iMP;
double iPTS;
double iTRB;
double iDRB;
double iORB;
double iAST;
double iSTL;
double iBLK;
double iFG;
double iFGA;
double iFT;
double iFTA;
double iTOV;
double iPF;
double iteam_AST;
double iteam_FG;

//league average stats
char *lg_FT;
char *lg_FTA;
char *lg_FG;
char *lg_FGA;
char *lg_PF;
char *lg_PTS;
char *lg_AST;
char *lg_TRB;
char *lg_ORB;
char *lg_TOV;
char *lg_PPG;
char *lg_aPER;

//for calculation (league average stats)
double ilg_FT;
double ilg_FTA;
double ilg_FG;
double ilg_FGA;
double ilg_PF;
double ilg_PTS;
double ilg_AST;
double ilg_TRB;
double ilg_ORB;
double ilg_TOV;
double ilg_PPG;
double ilg_aPER;

//last calculations variables
char *team_PPG;
double iteam_PPG;
char *opp_PPG;
double iopp_PPG;
char *three_Points;
double ithree_Points;

//calculated value
double uPER;
double aPER;
double PER;


//makes each call look visually cleare by seperating them
int symbols() {
    printf("****************************************************************************** \n");
    return 1; //no effect just for function purposes
}

//calculation of EFG via basketball-reference.com
int efgCalculation () {
    double efg = (iFG + 0.5 * ithree_Points) / iFGA;
    symbols();
    printf("Your EFG %.2f \n", efg);
    symbols();
    
    return 1; //no effect just for function purposes
}

//efg information via wikipedia
int efgInformation () {
    symbols();
    printf("Effective Field Goal percentage is a statistic that adjusts field goal \npercentage to account for the fact that three-point field goals count for \nthree points while field goals only count for two points. \n");
    symbols();
    return 1; //no effect just for function purposes
}

//calculation of TS via basketball-reference.com
int tsCalculation () {
    double tsa = iFGA + 0.44 * iFTA;
    double ts = iPTS / (2 * tsa);
    symbols();
    printf("Your TS %.2f \n", ts);
    symbols();
    
    return 1; //no effect just for function purposes
}

//ts information via wikipedia
int tsInformation () {
    symbols();
    printf("In basketball, true shooting percentage is an APBRmetrics statistic that \nmeasures a player's efficiency at shooting the ball.[1] It is intended to \nmore accurately calculate a player's shooting than field goal percentage, \nfree throw percentage, and three-point field goal \npercentage taken individually.  \n");
    symbols();
    return 1; //no effect just for function purposes
}

//calculation of PER via basketball-reference.com
int perCalculation () {
    double factor = (2/3) - (0.5 * (ilg_AST/ilg_FG)) / (2 * (ilg_FG/ilg_FT));
    double VOP = ilg_PTS / (ilg_FGA - ilg_ORB + ilg_TOV + 0.44 * ilg_FTA);
    double DRB_ = (ilg_TRB - ilg_ORB) / ilg_TRB;
    
    uPER = (1/iMP) *
     (ithree_Points
     + (2/3) * iAST
     + (2 - factor * (iteam_AST / iteam_FG)) * iFG
     + (iFT * 0.5 * (1 + (1 - (iteam_AST / iteam_FG)) + (2/3) * (iteam_AST / iteam_FG)))
     - VOP * iTOV
     - VOP * DRB_ * (iFGA - iFG)
     - VOP * 0.44 * (0.44 + (0.56 * DRB_)) * (iFTA - iFT)
     + VOP * (1 - DRB_) * (iTRB - iORB)
     + VOP * DRB_ * iORB
     + VOP * iSTL
     + VOP * DRB_ * iBLK
     - iPF * ((ilg_FT / ilg_PF) - 0.44 * (ilg_FTA / ilg_PF) * VOP));
    
    double pace = 2 * ilg_PPG / (iteam_PPG + iopp_PPG);
    
    aPER = pace * uPER;
    
    PER = aPER * (15/ilg_aPER);
    
    symbols();
    printf("Your PER %.2f \n", PER);
    symbols();
    
    return 1; //no effect just for function purposes
}

//per information via basketball-reference.com
int perInfo () {
    symbols();
    printf("The Player Efficiency Rating (PER) is a per-minute rating developed \nby ESPN.com columnist John Hollinger.In John's words, The PER sums up \nall a player's positive accomplishments, subtracts the negative \naccomplishments, and returns a per-minute rating of a player's performance. \n");
    symbols();

    return 1; //no effect just for function purposes
}

//converts strings to int for calculation
int converter () {
    iMP = atof(MP);
    iPTS = atof(PTS);
    iTRB = atof(TRB);
    iDRB = atof(DRB);
    iORB = atof(ORB);
    iAST = atof(AST);
    iSTL = atof(STL);
    iBLK = atof(BLK);
    iFG = atof(FG);
    iFGA = atof(FGA);
    iFT = atof(FT);
    iFTA = atof(FTA);
    iTOV = atof(TOV);
    iPF = atof(PF);
    iteam_AST = atof(team_AST);
    iteam_FG = atof(team_FG);
    
    ilg_FT = atof(lg_FT);
    ilg_FTA = atof(lg_FTA);
    ilg_FG = atof(lg_FG);
    ilg_FGA = atof(lg_FGA);
    ilg_PF = atof(lg_PF);
    ilg_PTS = atof(lg_PTS);
    ilg_AST = atof(lg_AST);
    ilg_TRB = atof(lg_TRB);
    ilg_ORB = atof(lg_ORB);
    ilg_TOV = atof(lg_TOV);
    ilg_PPG = atof(lg_PPG);
    ilg_aPER = atof(lg_aPER);
    iteam_PPG = atof(team_PPG);
    iopp_PPG = atof(opp_PPG);
    ithree_Points = atof(three_Points);

    return 1; //no effect just for function purposes
}

int main (int argc, char **argv) {
    FILE *textFile;
    textFile = fopen(argv[1], "r");
    //reading textFile contents to str
    char str[500];
    int counter = 0;
    do {
        char c = fgetc(textFile);
        if (c == EOF) break;
        //process each line
        while (c != EOF){
            str[counter++] = c;
            c = fgetc(textFile);
        }
    } while (true);
    //tokenizing
    char *token, *pos;
    pos = str;
    const char delimeters[5] = " ,";
    char *mpCheck, *ptsCheck, *rbCheck, *astCheck, *stlCheck;
    char *blkCheck, *fgCheck, *ftCheck, *tovCheck, *pfCheck;
    char *teamCheck, *lgCheck, *team_ppgCheck, *opp_ppgCheck;
    char *three_pointsCheck;
    int ptsCount = 0;
    int rbCount = 0;
    int astCount = 0;
    int fgCount = 0;
    int ftCount = 0;
    int tovCount = 0;
    int pfCount = 0;
    int teamCount = 0;
    int lgCount = 0;
    token = strsep(&pos, delimeters);
    //assign values in str/file to specific variables for calculation
    while(token != NULL) {
        //checks token for specific string
        mpCheck = strstr(token, "MP");
        ptsCheck = strstr(token, "PTS");
        rbCheck = strstr(token, "RB");
        astCheck = strstr(token, "AST");
        stlCheck = strstr(token, "STL");
        blkCheck = strstr(token, "BLK");
        fgCheck = strstr(token, "FG");
        ftCheck = strstr(token, "FT");
        tovCheck = strstr(token, "TOV");
        pfCheck = strstr(token, "PF");
        teamCheck = strstr(token, "team");
        lgCheck = strstr(token, "lg");
        team_ppgCheck = strstr(token, "team_PPG");
        opp_ppgCheck = strstr(token, "opp_PPG");
        three_pointsCheck = strstr(token, "threePoints");
        //assigniing MP
        if (mpCheck != NULL) {
            token = strsep(&pos, delimeters);
            MP = token;
        }
        //assigniing PTS
        if ((ptsCheck != NULL) && (ptsCount == 0)) {
            token = strsep(&pos, delimeters);
            PTS = token;
            ptsCount++; //this counteracts both PTS and and lg_PTS being selected by ptsCheck
        }
        //assigniing TRB
        if ((rbCheck != NULL) && (rbCount == 0)) {
            token = strsep(&pos, delimeters);
            TRB = token;
            rbCount++; //this counteracts TRB, ORB, DRB, lg_TRB, lg_ORB being selected by rbCheck
        }
        //assigniing DRB
        if ((rbCheck != NULL) && (rbCount == 1)) {
            token = strsep(&pos, delimeters);
            token = strsep(&pos, delimeters);
            DRB = token;
            rbCount++;
        }
        //assigniing ORB
        if ((rbCheck != NULL) && (rbCount == 2)) {
            token = strsep(&pos, delimeters);
            token = strsep(&pos, delimeters);
            ORB = token;
            rbCount++;
        }
        //assigniing AST
        if ((astCheck != NULL) && (astCount == 0)) {
            token = strsep(&pos, delimeters);
            AST = token;
            astCount++; //this counteracts AST, team_AST and lg_AST being selected by astCheck
        }
        //assigniing STL
        if (stlCheck != NULL) {
            token = strsep(&pos, delimeters);
            STL = token;
        }
        //assigniing BLK
        if (blkCheck != NULL) {
            token = strsep(&pos, delimeters);
            BLK = token;
        }
        //assigniing FG
        if ((fgCheck != NULL) && (fgCount == 0)) {
            token = strsep(&pos, delimeters);
            FG = token;
            fgCount++; //this counteracts FG, FGA, team_FG, lg_FG and lg_FGA being selected by fgCheck
        }
        //assigniing FGA
        if ((fgCheck != NULL) && (fgCount == 1)) {
            token = strsep(&pos, delimeters);
            token = strsep(&pos, delimeters);
            FGA = token;
            fgCount++;
        }
        //assigniing FT
        if ((ftCheck != NULL) && (ftCount == 0)) {
            token = strsep(&pos, delimeters);
            FT = token;
            ftCount++; //this counteracts FT, FTA, lg_FT and lg_FTA being selected by ftCheck
        }
        //assigniing FTA
        if ((ftCheck != NULL) && (ftCount == 1)) {
            token = strsep(&pos, delimeters);
            token = strsep(&pos, delimeters);
            FTA = token;
            ftCount++;
        }
        //assigniing TOV
        if ((tovCheck != NULL) && (tovCount == 0)) {
            token = strsep(&pos, delimeters);
            TOV = token;
            tovCount++; //this counteracts TOV and lg_TOV being selected by ftCheck
        }
        //assigniing PF
        if ((pfCheck != NULL) && (pfCount == 0)) {
            token = strsep(&pos, delimeters);
            PF = token;
            pfCount++; //this counteracts PF and lg_PF being selected by pfCheck
        }
        //assigniing team_AST
        if ((teamCheck != NULL) && (teamCount == 0)) {
            token = strsep(&pos, delimeters);
            team_AST = token;
            teamCount++; //this counteracts team_AST and team_FG being selected by teamCheck
        }
        //assigniing team_FG
        if ((teamCheck != NULL) && (teamCount == 1)) {
            token = strsep(&pos, delimeters);
            token = strsep(&pos, delimeters);
            team_FG = token;
            teamCount++;
        }
        //assigniing lg_FT
        if ((lgCheck != NULL) && (lgCount == 0)) {
            token = strsep(&pos, delimeters);
            lg_FT = token;
            lgCount++; //this counteracts all the lg stats from being selected by lgCheck
        }
        //assigniing lg_FTA
        if ((lgCheck != NULL) && (lgCount == 1)) {
            token = strsep(&pos, delimeters);
            token = strsep(&pos, delimeters);
            lg_FTA = token;
            lgCount++;
        }
        //assigniing lg_FG
        if ((lgCheck != NULL) && (lgCount == 2)) {
            token = strsep(&pos, delimeters);
            token = strsep(&pos, delimeters);
            lg_FG = token;
            lgCount++;
        }
        //assigniing lg_FGA
        if ((lgCheck != NULL) && (lgCount == 3)) {
            token = strsep(&pos, delimeters);
            token = strsep(&pos, delimeters);
            lg_FGA = token;
            lgCount++;
        }
        //assigniing lg_PF
        if ((lgCheck != NULL) && (lgCount == 4)) {
            token = strsep(&pos, delimeters);
            token = strsep(&pos, delimeters);
            lg_PF = token;
            lgCount++;
        }
        //assigniing lg_PTS
        if ((lgCheck != NULL) && (lgCount == 5)) {
            token = strsep(&pos, delimeters);
            token = strsep(&pos, delimeters);
            lg_PTS = token;
            lgCount++;
        }
        //assigniing lg_AST
        if ((lgCheck != NULL) && (lgCount == 6)) {
            token = strsep(&pos, delimeters);
            token = strsep(&pos, delimeters);
            lg_AST = token;
            lgCount++;
        }
        //assigniing lg_TRB
        if ((lgCheck != NULL) && (lgCount == 7)) {
            token = strsep(&pos, delimeters);
            token = strsep(&pos, delimeters);
            lg_TRB = token;
            lgCount++;
        }
        //assigniing lg_ORB
        if ((lgCheck != NULL) && (lgCount == 8)) {
            token = strsep(&pos, delimeters);
            token = strsep(&pos, delimeters);
            lg_ORB = token;
            lgCount++;
        }
        //assigniing lg_TOV
        if ((lgCheck != NULL) && (lgCount == 9)) {
            token = strsep(&pos, delimeters);
            token = strsep(&pos, delimeters);
            lg_TOV = token;
            lgCount++;
        }
        //assigniing lg_PPG
        if ((lgCheck != NULL) && (lgCount == 10)) {
            token = strsep(&pos, delimeters);
            token = strsep(&pos, delimeters);
            lg_PPG = token;
            lgCount++;
        }
        //assigniing lg_aPER
        if ((lgCheck != NULL) && (lgCount == 11)) {
            token = strsep(&pos, delimeters);
            token = strsep(&pos, delimeters);
            lg_aPER = token;
            lgCount++;
        }
        //assigniing team_PPG
        if (team_ppgCheck != NULL) {
            token = strsep(&pos, delimeters);
            team_PPG = token;
        }
        //assigniing opp_PPG
        if (opp_ppgCheck != NULL) {
            token = strsep(&pos, delimeters);
            opp_PPG = token;
        }
        //assigniing three_Points
        if (three_pointsCheck != NULL) {
            token = strsep(&pos, delimeters);
            three_Points = token;
        }
        
        token = strsep(&pos, delimeters); //reset
    }
    
    converter();
    
    //visualIntro
    goto loop;
    int endLoop = 0;
    int returnValue = 0;
    loop: while ((endLoop == 0) || (!returnValue)) {
        int userInput;
        printf("\n");
        printf("PER Calculation, Enter 1 \nPER Information, Enter 2\nEFG Calculation, Enter 3 \nEFG Information, Enter 4 \nTS Calculation, Enter 5 \nTS Information, Enter 6 \nExit, Enter 7 \n\nYour Entry: ");
        //prevents infinite loop if user chooses a non int number e.g char
        returnValue = scanf("%d", &userInput);
        while(getchar() !='\n') {
            continue;
        }
        printf("\n");
        //if user enters per calculation (1)
        if (userInput == 1) {
            perCalculation();
            goto loop;
        }
        //if user enters per information (2)
        else if (userInput == 2) {
            perInfo();
            goto loop;
        }
        
        //if user enters efg calculation (3)
        else if (userInput == 3) {
            efgCalculation();
            goto loop;
        }
        
        //if user enters efg information (4)
        else if (userInput == 4) {
            efgInformation();
            goto loop;
        }
        
        //if user enters ts calculation (5)
        else if (userInput == 5) {
            tsCalculation();
            goto loop;
        }
        
        //if user enters ts information (6)
        else if (userInput == 6) {
            tsInformation();
            goto loop;
        }
        
        //if user enters exit (7)
        else if (userInput == 7) {
            endLoop = 1;
            symbols();
            printf("Thank You for using this program, see you next Time! \n");
            symbols();
            printf("\n");
            goto loop;
        }
        //if user enters invalid entry
        else {
            symbols();
            printf("Please enter valid command \n");
            symbols();
            goto loop;
        }
    }
}
