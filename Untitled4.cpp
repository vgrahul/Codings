#define MAXTEAMS 10
#define MAXGAMES 18
#include <stdio.h>
struct team
{
char name [15];
int pld;
int w;
int d;
int l;
int pts;
int games[MAXGAMES];
};
struct game
{
char hometeam [15];
char awayteam [15];
int homegoals;
int awaygoals;
};
void createleague(struct team leagueteams[]);
void displayleague(struct team leagueteams[]);
int main (void)
{
struct team leagueteams[MAXTEAMS];
printf("**********************************\n");
printf("Welcome To The Premier League\n\n");
printf("Type 10 Teams To Create The League");
printf("\n**********************************\n");
createleague(leagueteams);
displayleague(leagueteams);
}
void createleague(struct team leagueteams[])
{
int t;
int g;
for (t=0;t<MAXTEAMS;t++)
{
printf("\nEnter Team:");
scanf("%s",leagueteams[t].name);
leagueteams[t].pld = 0;
leagueteams[t].w=0;
leagueteams[t].d=0;
leagueteams[t].l=0;
leagueteams[t].pts=0;
}
for (g=0;g<MAXGAMES;g++)
{
leagueteams[t].games[MAXTEAMS] = 0;
}
}
void displayleague(struct team leagueteams[])
{
printf("\n\nPremier League Table\n");
printf("\n---------------------------------------------------\n");
printf("\t\t Name P W D L Pts\n");
printf("-----------------------------------------------------\n");
int d;
for (d=0;d<MAXTEAMS;d++)
{
printf("%15s %3d %3d %3d %3d %3d\n", leagueteams[d].name,
leagueteams[d].pld, leagueteams[d].w, leagueteams[d].d,
leagueteams[d].l, leagueteams[d].pts);
}
}
