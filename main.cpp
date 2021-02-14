/*
 * Marc D. Holman
 * CIS 2542 - Advanced C++ Programming
 * 1 / 25 / 2020
 * Assignment # 1 - Data Type: Struct
 *
 * Description:  The program allows user to enter
 * name, number, and score data for three players.
 * Players are then displayed, along with stats, in
 * tabular format with number and name of the top
 * player noted.
 *
 * NOTE:  I have limited use of global entities to the
 * 'NUM_PLAYERS' constant.  Pointer to Player struct array is
 *  passed from function to function instead.
 *
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// *<-------------- Constants and function prototypes  <*--------------------

// declare constant variable for number of players
const int NUM_PLAYERS = 3;

// create a struct to hold individual player data
struct Player {
    string name;
    int number;
    int points;
};

void loadPlayers(struct Player *players);

void displayTable(struct Player *players);

int get_total_points(struct Player *players);

int get_top_player(Player *players);

int get_player_number();

int get_player_points();

string get_player_name();


// *-------->  Function bodies  *<---------------- //


int get_player_points()
{
    // declare an input variable
    // keep asking until a valid integer is entered
    int points{};

    do{
       cout << "Player Points: " << endl;
       cin >> points;
    } while (points < 0);

    return points;
}

int get_player_number()
{
    // declare an input variable
    // keep asking until a valid integer is entered
    int playerNumber{};

    do {
        cout << "Player Number: " << endl;
        cin >> playerNumber;
    } while (playerNumber < 0);

    return playerNumber;
}

int get_total_points(struct Player *players)
{
    int total_points = 0;

    for(int index = 0; index < NUM_PLAYERS; index++)
    {
        total_points += players[index].points;
    }

    return total_points;
}

string get_player_name()
{
    string name{};
    cout << "Enter Player Name: " << endl;
    cin >> name;
    return name;

}

int get_top_player(Player *players)
{
    int bestScore = players[0].points;
    int bestIndex = 0;
    int i;
    for(i = 1; i < NUM_PLAYERS; i++)
    {
        if(players[i].points > bestScore)
        {
            bestIndex = i;
            bestScore = players[i].points;
        }
    }

    return bestIndex;
}

// functions
void loadPlayers(struct Player *players) {
    cout << "Please enter data for three players: " << endl;

    for (int index = 0; index < NUM_PLAYERS; index++) {
        //char name[10];

        // get player name
        string playerName = get_player_name();
        players[index].name = playerName;

        // get player number
        int number = get_player_number();   // _
        players[index].number = number;

        // get player points
        int points = get_player_points(); // _
        players[index].points = points;
    }
}




void displayTable(struct Player *players) {
    cout << "SOCCER PLAYERS" << endl;
    cout << "Name" << setw(10) << "Number" << setw(10) << "Points" << endl;
    cout << "============================" << endl;
    cout << left << setw(15);


    for(int index = 0; index < NUM_PLAYERS; index++)
    {
        cout << left << setw(15);
        cout << players[index].name;

        cout << setw(10);
        cout << players[index].number;

        cout << setw(10);
        cout << players[index].points;

        cout << endl;

    }

    cout << endl;

    cout << "Total Points earned by Team: "  << endl;
    cout << get_total_points(players) << endl;

    cout << "Top Earner: " << endl;
    int topPlayerIndex = get_top_player(players);
    cout << "Number " << players[topPlayerIndex].number;
    cout << " " << players[topPlayerIndex].name << endl;


}


int main() {
    // allocate space for an array of Player structs
   Player player[NUM_PLAYERS];

   // user enters a list of players
    loadPlayers(player);

    // display player name, number, and points
    // in tabular format, also noting top earner and total points for team.
    displayTable(player);


    return 0;
}

/*
 * Successful execution with valid data followed by example of invalid points
 * and/or score:
 *
 * Please enter data for three players:
Enter Player Name:
Jervis
Player Number:
1
Player Points:
23
Enter Player Name:
Jenkins
Player Number:
2
Player Points:
67
Enter Player Name:
Jake
Player Number:
4
Player Points:
37

SOCCER PLAYERS
 Name    Number    Points
============================
Jervis         1         23
Jenkins        2         67
Jake           4         37
Total Points earned by Team:
127
Top Earner:
Number 2 Jenkins

Process finished with exit code 0

 Invalid score/points entry:

 Enter Player Name:
Jervis
Player Number:
-32
Player Number:
32
Player Points:
-4
Player Points:
12
Enter Player Name:
Jenkins
Player Number:
12
Player Points:
34
Enter Player Name:
Jake
Player Number:
19
Player Points:
53

SOCCER PLAYERS
 Name    Number    Points
============================
Jervis         32        12
Jenkins        12        34
Jake           19        53

Total Points earned by Team:
99
Top Earner:
Number 19 Jake



 */


