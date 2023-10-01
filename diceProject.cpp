#include <iostream>
#include <cstdlib>
#include <string>
#include <Windows.h>
using namespace std;

int main(){
    
    HANDLE window1 = GetStdHandle(STD_OUTPUT_HANDLE);

    string player1, player2, // for user input name
    player1_result, player2_result; // for storing dice roll statement if a certian perameter is met

    
    unsigned seed;
    seed = time(0);
    srand(seed);

    int player1_dice = rand() % 20 + 1;
    int player2_dice = rand() % 20 + 1;


    // get both players name if left black set to default name
    cout << "Enter name for player1: ";
    getline(cin, player1);
    if(player1 == "")
    {
        player1 = "Player1";
    }

    cout << "Enter name player2: ";
    getline(cin, player2);
    if(player2 == "")
    {
        player2 = "Player2";
    }

    cout << player1 << " Vs " << player2 << endl;
    

    //stores a string result for both players
    if(player1_dice == 1)
    {
        
        player1_result = " Critical failure\n";
        SetConsoleTextAttribute(window1, 4);
        cout << player1 << player1_result;
    }
    else if(player1_dice == 20)
    {
        SetConsoleTextAttribute(window1, 2);
        player1_result = " Critical Success\n";
        cout << player1 << player1_result;
    }

    
    if(player2_dice == 1)
    {
        player2_result = " Critical failure\n";
        SetConsoleTextAttribute(window1, 4);
        cout << player2 << player2_result;
    }
    else if(player2_dice == 20)
    {
       SetConsoleTextAttribute(window1, 2);
        player2_result = " Critical Success\n";
        cout << player2 << player2_result;
    }

    SetConsoleTextAttribute(window1, 7);
    cout << player1 << " rolled a " << player1_dice << endl;
    cout << player2 << " rolled a " << player2_dice << endl;
    
    
    if(player1_dice > player2_dice)
    {
        cout << player1 << " wins" << player1_result <<endl;
    }
    else if(player1_dice < player2_dice)
    {
        cout << player2 << " wins" << player2_result <<endl;
    }
    else{
        cout << "Draw"<< endl;
    }
    
    
}