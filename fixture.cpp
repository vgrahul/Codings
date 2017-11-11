 #include <iostream>
 #include<stdio.h>
    #include <sstream>
    #include <string>
    #include <vector>

using namespace std;

typedef struct team
{
    string name;
    int attack;
    int defence;
    int points;
} team;

typedef struct group
{
    string teamOne;
    string teamTwo;
} group;

void teaminput(team *A);
void Fixture(team& teamA, team& teamB);

int main()
{
    int NumberOfTeams;

    cout << "Welcome to the World Cup Simulator" << endl;
    cout << "\nPlease select the number of teams participating";
    cout << "\n(please note, the required number of teams per group is 4; with";
    cout << "\n the number of groups corresponding to each selection shown below)." << endl;
    cout << "\n 8 (2 groups)";
    cin >> NumberOfTeams;


    if (NumberOfTeams == 8)
    {

        team A;
        teaminput(&A);
        team B;
        teaminput(&B);
        team C;
        teaminput(&C);
        team D;
        teaminput(&D);

        vector<team> groupOne;
        groupOne.push_back(A);
        groupOne.push_back(B);
        groupOne.push_back(C);
        groupOne.push_back(D);

        team E;
        teaminput(&E);
        team F;
        teaminput(&F);
        team G;
        teaminput(&G);
        team H;
        teaminput(&H);

        vector<team> groupTwo;
        groupTwo.push_back(E);
        groupTwo.push_back(F);
        groupTwo.push_back(G);
        groupTwo.push_back(H);

        for (auto teamA = groupOne.begin(); teamA != groupOne.end(); teamA++)
        {
            for (auto teamB = groupTwo.begin(); teamB != groupTwo.end(); teamB++)
            {
                Fixture(*teamA, *teamB);
            }
        }


        cout << "\n" << A.name << "\n" << A.attack << "\n" << A.defence;
    }
    return 0;
}

void teaminput(team *A)
{
    team A;
    string x;
    int y;
    for (int i = 0; i < 4; i++)
    {
        cout << "\nPlease enter team " << i + 1 << " data." << endl;

        cout << "\nTeam Name\t\t\t: \t";
        cin >> x;
        A->name = x;//TeamName

        cout << "Attack Level\t\t: \t";
        cin >> y;
        A->attack = y; //AttackLevel

        cout << "Defence Level\t\t: \t";
        cin >> y;
        A->defence = y;//DefenceLevel
    }
}

void Fixture(team& teamA, team& teamB)
{
    //string teamA, teamB;
    int teamAattack, teamBattack = 0;
    int teamAdefence, teamBdefence = 0;
    int teamAgoals = 0, teamBgoals = 0; // previously you were only initializing teamB' variables
    int teamApoints = 0, teamBpoints = 0;

    if (teamA.attack - teamB.defence > 0)
        teamAgoals = teamA.attack - teamB.defence;
    if (teamB.attack - teamA.defence > 0)
        teamBgoals = teamB.attack - teamA.defence;

    if (teamAgoals > teamBgoals)
    {
        teamA.points = teamA.points + 3;
    }
    else if (teamBgoals > teamAgoals)
    {
        teamB.points = teamB.points + 3;
    }
    else if (teamAgoals == teamBgoals)
    {
        teamA.points = teamA.points + 1;
        teamB.points = teamB.points + 1;
    }
}
