//
//  main.cpp
//  Intro to CS II Honors Project Test
//
//  Created by Katrina Agatha Bonoan on 5/8/17.
//  Copyright © 2017 Katrina Agatha Bonoan. All rights reserved.
//

#include <iostream>
#include <cctype>

using namespace std;

struct TicTac {
    char choice;
    int row;
    int col;
    bool win;
};

char xORo ();
char check1 (char&);
char check2 (char&);

void displayBoard (string []);

void compTurn1 (string [], char);

TicTac getRowCol (TicTac&);
TicTac check3 (TicTac&);
void uTurn (TicTac, string [], char);

void compTurn2 (TicTac, string [], char);
void pX_1 (string []);
void pO_1 (string []);

TicTac check5 (TicTac&, string []);
void uTurn2 (TicTac&, string [], char);

bool compTurn3 (TicTac, string [], char);
bool pX_2 (string [], TicTac);
bool pO_2 (string [], TicTac);

void uTurn3 (TicTac&, string [], char);

bool compTurn4 (TicTac, string [], char);
bool pX_3 (string [], TicTac);
bool pO_3 (string [], TicTac);

int main () {
    
    cout << "Let's play tic-tac-toe together\n";
    
    TicTac chose;
    chose.choice = xORo();
    
    cout << "Here is the game board\n";
    
    string gB [9];
    int index;
    
    for (index = 0; index < 9; index ++)
    {
        gB[index] = "* ";
    }
    
    displayBoard(gB);
    
    cout << "I, the computer, will go first as an example\n";
    
    compTurn1(gB, chose.choice);
    
    cout << "Now your turn\n";
    
    TicTac u;
    getRowCol(u);
    check3(u);
    check5(u, gB);
    uTurn(u, gB, chose.choice);
    displayBoard(gB);
    
    cout << "My turn\n";
    
    compTurn2(u, gB, chose.choice);
    displayBoard(gB);
    
    cout << "Your turn\n";
    
    uTurn2(u, gB, chose.choice);
    
    cout << "Nice move, but it's my turn\n";
    
    u.win = compTurn3(u, gB, chose.choice);
    displayBoard(gB);
    
    if (u.win == true)
    {
        cout << "\nI win\n\n";
    }
    else
    {
        cout << "Now, what are you going to do?\n";
        
        uTurn3(u, gB, chose.choice);
        
        cout << "I thank you for the good game\n";
        
        u.win = compTurn4(u, gB, chose.choice);
        displayBoard(gB);
        
        if (u.win == true)
        {
            cout << "\nI win\n\n";
        }
    }
    
    return 0;
}

char xORo () {
    
    TicTac userChoice;
    
    cout << "Enter X or O: ";
    cin >> userChoice.choice;
    
    userChoice.choice = toupper(userChoice.choice);
    
    userChoice.choice = check1(userChoice.choice);
    
    userChoice.choice = check2(userChoice.choice);
    
    return userChoice.choice;
    
}

char check1 (char &choice) {
    
    while (!isalpha(choice)) {
        
        cout << "Enter X or O: ";
        cin >> choice;
        
    }
    
    return choice;
    
}

char check2 (char &choice) {
    
    while (choice != 'X' || choice != 'O')
    {
        
        if (choice == 'X')
        {
            break;
        }
        else if (choice == 'O')
        {
            break;
        }
        
        cout << "Enter X or O: ";
        cin >> choice;
        
        choice = toupper(choice);
        
    }
    
    return choice;
    
}

void displayBoard (string gB []) {
    
    cout << gB[0] << gB[1] << gB[2] << endl;
    cout << gB[3] << gB[4] << gB[5] << endl;
    cout << gB[6] << gB[7] << gB[8] << endl;
    
}

void compTurn1 (string gB [], char choice) {
    
    cout << "Enter a row and column: ";
    cout << "3 3\n";
    
    if (choice == 'X')
    {
        gB[8] = "O ";
        
        displayBoard(gB);
    }
    
    if (choice == 'O')
    {
        gB[8] = "X ";
        
        displayBoard(gB);

    }
    
}

TicTac getRowCol (TicTac &u) {
    
    cout << "Enter a row and column: ";
    cin >> u.row >> u.col;
    
    return u;
    
}

TicTac check3 (TicTac &u) {
    
    while (u.row < 1 || u.row > 3)
    {
        cout << "Enter a valid row and column: ";
        cin >> u.row >> u.col;
    }
    
    while (u.col < 1 || u.col > 3)
    {
        cout << "Enter a valid row and column: ";
        cin >> u.row >> u.col;
    }
    
    return u;
    
}

void uTurn (TicTac u, string gB [], char choice) {
    
    if (choice == 'X')
    {
        if (u.row == 1 && u.col == 1)
        {
            gB[0] = "X ";
        }
        else if (u.row == 1 && u.col == 2)
        {
            gB[1] = "X ";
        }
        else if (u.row == 1 && u.col == 3)
        {
            gB[2] = "X ";
        }
        else if (u.row == 2 && u.col == 1)
        {
            gB[3] = "X ";
        }
        else if (u.row == 2 && u.col == 2)
        {
            gB[4] = "X ";
        }
        else if (u.row == 2 && u.col == 3)
        {
            gB[5] = "X ";
        }
        else if (u.row == 3 && u.col == 1)
        {
            cout << "3 1 else/if\n";
            gB[6] = "X ";
        }
        else if (u.row == 3 && u.col == 2)
        {
            gB[7] = "X ";
        }
        else if (u.row == 3 && u.col == 3)
        {
            gB[8] = "X ";
        }
    }
    else if (choice == 'O')
    {
        if (u.row == 1 && u.col == 1)
        {
            gB[0] = "O ";
        }
        else if (u.row == 1 && u.col == 2)
        {
            gB[1] = "O ";
        }
        else if (u.row == 1 && u.col == 3)
        {
            gB[2] = "O ";
        }
        else if (u.row == 2 && u.col == 1)
        {
            gB[3] = "O ";
        }
        else if (u.row == 2 && u.col == 2)
        {
            gB[4] = "O ";
        }
        else if (u.row == 2 && u.col == 3)
        {
            gB[5] = "O ";
        }
        else if (u.row == 3 && u.col == 1)
        {
            gB[6] = "O ";
        }
        else if (u.row == 3 && u.col == 2)
        {
            gB[7] = "O ";
        }
        else if (u.row == 3 && u.col == 3)
        {
            gB[8] = "O ";
        }
    }
    
}

void compTurn2 (TicTac u, string gB [], char choice) {
    
    if (choice == 'X')
    {
        pX_1(gB);
        
    }
    else if (choice == 'O')
    {
        pO_1(gB);
    }

}

void pX_1 (string gB []) {
    
    //pattern 1
    if (gB[5] == "X ")
    {
        gB[7] = "O ";
    }
    //pattern 2
    else if (gB[7] == "X ")
    {
        gB[4] = "O ";
    }
    //pattern 3
    else if (gB[4] == "X ")
    {
        gB[0] = "O ";
    }
    //pattern 4
    else if (gB[6] == "X ")
    {
        gB[0] = "O ";
    }
    //pattern 5
    else if (gB[3] == "X ")
    {
        gB[2] = "O ";
    }
    //pattern 6
    else if (gB[0] == "X ")
    {
        gB[6] = "O ";
    }
    //pattern 7
    else if (gB[1] == "X ")
    {
        gB[4] = "O ";
    }
    //pattern 8
    else if (gB[2] == "X ")
    {
        gB[6] = "O ";
    }
    
}

void pO_1 (string gB []) {
    
    //pattern 1
    if (gB[5] == "O ")
    {
        gB[7] = "X ";
    }
    //pattern 2
    else if (gB[7] == "O ")
    {
        gB[4] = "X ";
    }
    //pattern 3
    else if (gB[4] == "O ")
    {
        gB[0] = "X ";
    }
    //pattern 4
    else if (gB[6] == "O ")
    {
        gB[0] = "X ";
    }
    //pattern 5
    else if (gB[3] == "O ")
    {
        gB[2] = "X ";
    }
    //pattern 6
    else if (gB[0] == "O ")
    {
        gB[6] = "X ";
    }
    //pattern 7
    else if (gB[1] == "O ")
    {
        gB[4] = "X ";
    }
    //pattern 8
    else if (gB[2] == "O ")
    {
        gB[6] = "X ";
    }
    
}

TicTac check5 (TicTac &u, string gB []) {
    
    if (u.row == 1 && u.col == 1 && gB[0] != "* ")
    {
        cout << "That spot is covered. Try a different one\n";
        cout << "Enter a row and column: ";
        cin >> u.row >> u.col;
    }
    else if (u.row == 1 && u.col == 2 && gB[1] != "* ")
    {
        cout << "That spot is covered. Try a different one\n";
        cout << "Enter a row and column: ";
        cin >> u.row >> u.col;
    }
    else if (u.row == 1 && u.col == 3 && gB[2] != "* ")
    {
        cout << "That spot is covered. Try a different one\n";
        cout << "Enter a row and column: ";
        cin >> u.row >> u.col;
    }
    else if (u.row == 2 && u.col == 1 && gB[3] != "* ")
    {
        cout << "That spot is covered. Try a different one\n";
        cout << "Enter a row and column: ";
        cin >> u.row >> u.col;
    }
    else if (u.row == 2 && u.col == 2 && gB[4] != "* ")
    {
        cout << "That spot is covered. Try a different one\n";
        cout << "Enter a row and column: ";
        cin >> u.row >> u.col;
    }
    else if (u.row == 2 && u.col == 3 && gB[5] != "* ")
    {
        cout << "That spot is covered. Try a different one\n";
        cout << "Enter a row and column: ";
        cin >> u.row >> u.col;
    }
    else if (u.row == 3 && u.col == 1 && gB[6] != "* ")
    {
        cout << "That spot is covered. Try a different one\n";
        cout << "Enter a row and column: ";
        cin >> u.row >> u.col;
    }
    else if (u.row == 3 && u.col == 2 && gB[7] != "* ")
    {
        cout << "That spot is covered. Try a different one\n";
        cout << "Enter a row and column: ";
        cin >> u.row >> u.col;
    }
    else if (u.row == 3 && u.col == 3 && gB[8] != "* ")
    {
        cout << "That spot is covered. Try a different one\n";
        cout << "Enter a row and column: ";
        cin >> u.row >> u.col;
    }
    
    return u;
    
}

void uTurn2 (TicTac &u, string gB [], char choice) {
    
    if (u.row == 2 && u.col ==3)
    {
        getRowCol(u);
        check3(u);
        check5(u, gB);
        uTurn(u, gB, choice);
        displayBoard(gB);
    }
    else if (u.row == 3 && u.col == 2)
    {
        getRowCol(u);
        check3(u);
        check5(u, gB);
        uTurn(u, gB, choice);
        displayBoard(gB);
    }
    else if (u.row == 2 && u.col == 2)
    {
        getRowCol(u);
        check3(u);
        check5(u, gB);
        uTurn(u, gB, choice);
        displayBoard(gB);
    }
    else if (u.row == 3 && u.col == 1)
    {
        getRowCol(u);
        check3(u);
        check5(u, gB);
        uTurn(u, gB, choice);
        displayBoard(gB);
    }
    else if (u.row == 2 && u.col == 1)
    {
        getRowCol(u);
        check3(u);
        check5(u, gB);
        uTurn(u, gB, choice);
        displayBoard(gB);
    }
    else if (u.row == 1 && u.col == 1)
    {
        getRowCol(u);
        check3(u);
        check5(u, gB);
        uTurn(u, gB, choice);
        displayBoard(gB);
    }
    else if (u.row == 1 && u.col == 2)
    {
        getRowCol(u);
        check3(u);
        check5(u, gB);
        uTurn(u, gB, choice);
        displayBoard(gB);
    }
    else if (u.row == 1 && u.col == 3)
    {
        getRowCol(u);
        check3(u);
        check5(u, gB);
        uTurn(u, gB, choice);
        displayBoard(gB);
    }
    
}

bool compTurn3 (TicTac u, string gB [], char choice) {
    
    if (choice == 'X')
    {
        u.win = pX_2(gB, u);
    }
    else if (choice == 'O')
    {
        u.win = pO_2(gB, u);
    }
    
    return u.win;
    
}

bool pX_2 (string gB [], TicTac u)
{
    //pattern 1
    if (gB[6] == "X " && gB[7] == "O " && gB[8] == "O " && gB[4] == "* " && gB[5] == "X ")
    {
        gB[4] = "O ";
    }
    else if (gB[6] == "* " && gB[7] == "O " && gB[8] == "O ")
    {
        gB[6] = "O ";
        u.win = true;
    }
    //pattern 2
    else if (gB[8] == "O " && gB[7] == "X " && gB[4] == "O " && gB[0] == "X ")
    {
        gB[5] = "O ";
    }
    else if (gB[8] == "O " && gB[4] == "O " && gB[0] == "* ")
    {
        gB[0] = "O ";
        u.win = true;
    }
    //pattern 3
    else if (gB[8] == "O " && gB[4] == "X " && gB[0] == "O " && gB[6] == "* ")
    {
        gB[6] = "O ";
    }
    else if (gB[8] == "O " && gB[4] == "X " && gB[0] == "O " && gB[2] == "* ")
    {
        gB[2] = "O ";
    }
    //pattern 4
    else if (gB[8] == "O " && gB[6] == "X " && gB[0] == "O " && gB[4] == "X " && gB[2] == "* ")
    {
        gB[2] = "O ";
    }
    else if (gB[8] == "O " && gB[0] == "O " && gB[4] == "* ")
    {
        gB[4] = "O ";
        u.win = true;
    }
    //pattern 5
    else if (gB[8] == "O " && gB[3] == "X " && gB[2] == "O " && gB[5] == "X " && gB[4] == "* ")
    {
        gB[4] = "O ";
    }
    else if (gB[8] == "O " && gB[2] == "O " && gB[4] == "* ")
    {
        gB[4] = "O ";
        u.win = true;
    }
    //pattern 6
    else if (gB[8] == "O " && gB[0] == "X " && gB[6] == "O " && gB[7] == "X " && gB[2] == "* ")
    {
        gB[2] = "O ";
    }
    else if (gB[8] == "O " && gB[6] == "O " && gB[7] == "* ")
    {
        gB[7] = "O ";
        u.win = true;
    }
    //pattern 7
    else if (gB[8] == "O " && gB[1] == "X " && gB[4] == "O " && gB[0] == "X " && gB[2] == "* ")
    {
        gB[2] = "O ";
    }
    else if (gB[8] == "O " && gB[4] == "O " && gB[0] == "* ")
    {
        gB[0] = "O ";
        u.win = true;
    }
    //pattern 8
    else if (gB[8] == "O " && gB[2] == "X " && gB[6] == "O " && gB[7] == "X " && gB[0] == "* ")
    {
        gB[0] = "O ";
    }
    else if (gB[8] == "O " && gB[6] == "O " && gB[7] == "* ")
    {
        gB[7] = "O ";
        u.win = true;
    }
    
    return u.win;
    
}

bool pO_2 (string gB [], TicTac u)
{
    //pattern 1
    if (gB[6] == "O " && gB[7] == "X " && gB[8] == "X " && gB[4] == "* " && gB[5] == "O ")
    {
        gB[4] = "X ";
    }
    else if (gB[6] == "* " && gB[7] == "X " && gB[8] == "X ")
    {
        gB[6] = "X ";
        u.win = true;
    }
    //pattern 2
    else if (gB[8] == "X " && gB[7] == "O " && gB[4] == "X " && gB[0] == "O ")
    {
        gB[5] = "X ";
    }
    else if (gB[8] == "X " && gB[4] == "X " && gB[0] == "* ")
    {
        gB[0] = "X ";
        u.win = true;
    }
    //pattern 3
    else if (gB[8] == "X " && gB[4] == "O " && gB[0] == "X " && gB[6] == "* ")
    {
        gB[6] = "X ";
    }
    else if (gB[8] == "X " && gB[4] == "O " && gB[0] == "X " && gB[2] == "* ")
    {
        gB[2] = "X ";
    }
    //pattern 4
    else if (gB[8] == "X " && gB[6] == "O " && gB[0] == "X " && gB[4] == "O " && gB[2] == "* ")
    {
        gB[2] = "X ";
    }
    else if (gB[8] == "X " && gB[0] == "X " && gB[4] == "* ")
    {
        gB[4] = "X ";
        u.win = true;
    }
    //pattern 5
    else if (gB[8] == "X " && gB[3] == "O " && gB[2] == "X " && gB[5] == "O " && gB[4] == "* ")
    {
        gB[4] = "X ";
    }
    else if (gB[8] == "X " && gB[2] == "X " && gB[4] == "* ")
    {
        gB[4] = "X ";
        u.win = true;
    }
    //pattern 6
    else if (gB[8] == "X " && gB[0] == "O " && gB[6] == "X " && gB[7] == "O " && gB[2] == "* ")
    {
        gB[2] = "X ";
    }
    else if (gB[8] == "X " && gB[6] == "X " && gB[7] == "* ")
    {
        gB[7] = "X ";
        u.win = true;
    }
    //pattern 7
    else if (gB[8] == "X " && gB[1] == "O " && gB[4] == "X " && gB[0] == "O " && gB[2] == "* ")
    {
        gB[2] = "X ";
    }
    else if (gB[8] == "X " && gB[4] == "X " && gB[0] == "* ")
    {
        gB[0] = "X ";
        u.win = true;
    }
    //pattern 8
    else if (gB[8] == "X " && gB[2] == "O " && gB[6] == "X " && gB[7] == "O " && gB[0] == "* ")
    {
        gB[0] = "X ";
    }
    else if (gB[8] == "X " && gB[6] == "X " && gB[7] == "* ")
    {
        gB[7] = "X ";
        u.win = true;
    }
    
    return u.win;
    
}

void uTurn3 (TicTac &u, string gB [], char choice) {
    
    if (u.row == 3 && u.col == 1)
    {
        getRowCol(u);
        check3(u);
        check5(u, gB);
        uTurn(u, gB, choice);
        displayBoard(gB);
    }
    else if (u.row == 1 && u.col == 1)
    {
        getRowCol(u);
        check3(u);
        check5(u, gB);
        uTurn(u, gB, choice);
        displayBoard(gB);
    }
    else if (u.row == 1 && u.col == 3)
    {
        getRowCol(u);
        check3(u);
        check5(u, gB);
        uTurn(u, gB, choice);
        displayBoard(gB);
    }
    else if (u.row == 2 && u.col == 2)
    {
        getRowCol(u);
        check3(u);
        check5(u, gB);
        uTurn(u, gB, choice);
        displayBoard(gB);
    }
    else if (u.row == 2 && u.col == 3)
    {
        getRowCol(u);
        check3(u);
        check5(u, gB);
        uTurn(u, gB, choice);
        displayBoard(gB);
    }
    else if (u.row == 3 && u.col == 2)
    {
        getRowCol(u);
        check3(u);
        check5(u, gB);
        uTurn(u, gB, choice);
        displayBoard(gB);
    }
    
}

bool compTurn4 (TicTac u, string gB [], char choice) {
    
    if (choice == 'X')
    {
        u.win = pX_3(gB, u);
    }
    else if (choice == 'O')
    {
        u.win = pO_3(gB, u);
    }
    
    return u.win;
    
}

bool pX_3 (string gB [], TicTac u)
{
    
    //pattern 1
    if (gB[7] == "O " && gB[4] == "O " && gB[1] == "* ")
    {
        gB[1] = "O ";
        u.win = true;
    }
    else if (gB[8] == "O " && gB[4] == "O " && gB[0] == "* ")
    {
        gB[0] = "O ";
        u.win = true;
    }
    //pattern 2
    else if (gB[8] == "O " && gB[5] == "O " && gB[2] == "* ")
    {
        gB[2] = "O ";
        u.win = true;
    }
    else if (gB[5] == "O " && gB[4] == "O " && gB[3] == "* ")
    {
        gB[3] = "O ";
        u.win = true;
    }
    //pattern 3
    else if (gB[0] == "O " && gB[6] == "O " && gB[3] == "* ")
    {
        gB[3] = "O ";
        u.win = true;
    }
    else if (gB[3] == "O " && gB[8] == "O " && gB[7] == "* ")
    {
        gB[7] = "O ";
        u.win = true;
    }
    else if (gB[0] == "O " && gB[2] == "O " && gB[1] == "* ")
    {
        gB[1] = "O ";
        u.win = true;
    }
    else if (gB[2] == "O " && gB[8] == "O " && gB[5] == "* ")
    {
        gB[5] = "O ";
        u.win = true;
    }
    //pattern 4
    else if (gB[0] == "O " && gB[2] == "O " && gB[1] == "* ")
    {
        gB[1] = "O ";
        u.win = true;
    }
    else if (gB[2] == "O " && gB[8] == "O " && gB[5] == "* ")
    {
        gB[5] = "O ";
        u.win = true;
    }
    //pattern 5
    else if (gB[8] == "O " && gB[4] == "O " && gB[0] == "* ")
    {
        gB[0] = "O ";
        u.win = true;
    }
    else if (gB[2] == "O " && gB[4] == "O " && gB[6] == "* ")
    {
        gB[6] = "O ";
        u.win = true;
    }
    //pattern 6
    else if (gB[6] == "O " && gB[2] == "O " && gB[4] == "* ")
    {
        gB[4] = "O ";
        u.win = true;
    }
    else if (gB[2] == "O " && gB[8] == "O " && gB[5] == "* ")
    {
        gB[5] = "O ";
        u.win = true;
    }
    //pattern 7
    else if (gB[2] == "O " && gB[4] == "O " && gB[6] == "* ")
    {
        gB[6] = "O ";
        u.win = true;
    }
    else if (gB[2] == "O " && gB[8] == "O " && gB[5] == "* ")
    {
        gB[5] = "O ";
        u.win = true;
    }
    //pattern 8
    else if (gB[0] == "O " && gB[6] == "O " && gB[3] == "* ")
    {
        gB[3] = "O ";
        u.win = true;
    }
    else if (gB[0] == "O " && gB[8] == "O " && gB[4] == "* ")
    {
        gB[4] = "O ";
        u.win = true;
    }
    
    return u.win;
    
}

bool pO_3 (string gB [], TicTac u) {
    
    //pattern 1
    if (gB[7] == "X " && gB[4] == "X " && gB[1] == "* ")
    {
        gB[1] = "X ";
        u.win = true;
    }
    else if (gB[8] == "X " && gB[4] == "X " && gB[0] == "* ")
    {
        gB[0] = "X ";
        u.win = true;
    }
    //pattern 2
    else if (gB[8] == "X " && gB[5] == "X " && gB[2] == "* ")
    {
        gB[2] = "X ";
        u.win = true;
    }
    else if (gB[5] == "X " && gB[4] == "X " && gB[3] == "* ")
    {
        gB[3] = "X ";
        u.win = true;
    }
    //pattern 3
    else if (gB[0] == "X " && gB[6] == "X " && gB[3] == "* ")
    {
        gB[3] = "X ";
        u.win = true;
    }
    else if (gB[6] == "X " && gB[8] == "X " && gB[7] == "* ")
    {
        gB[7] = "X ";
        u.win = true;
    }
    else if (gB[0] == "X " && gB[2] == "X " && gB[1] == "* ")
    {
        gB[1] = "X ";
        u.win = true;
    }
    else if (gB[2] == "X " && gB[8] == "X " && gB[5] == "* ")
    {
        gB[5] = "X ";
        u.win = true;
    }
    //pattern 4
    else if (gB[0] == "X " && gB[2] == "X " && gB[1] == "* ")
    {
        gB[1] = "X ";
        u.win = true;
    }
    else if (gB[2] == "X " && gB[8] == "X " && gB[5] == "* ")
    {
        gB[5] = "X ";
        u.win = true;
    }
    //pattern 5
    else if (gB[8] == "X " && gB[4] == "X " && gB[0] == "* ")
    {
        gB[0] = "X ";
        u.win = true;
    }
    else if (gB[2] == "X " && gB[4] == "X " && gB[6] == "* ")
    {
        gB[6] = "X ";
        u.win = true;
    }
    //pattern 6
    else if (gB[6] == "X " && gB[2] == "X " && gB[4] == "* ")
    {
        gB[4] = "X ";
        u.win = true;
    }
    else if (gB[2] == "X " && gB[8] == "X " && gB[5] == "* ")
    {
        gB[5] = "X ";
        u.win = true;
    }
    //pattern 7
    else if (gB[2] == "X " && gB[4] == "X " && gB[6] == "* ")
    {
        gB[6] = "X ";
        u.win = true;
    }
    else if (gB[2] == "X " && gB[8] == "X " && gB[5] == "* ")
    {
        gB[5] = "X ";
        u.win = true;
    }
    //pattern 8
    else if (gB[0] == "X " && gB[6] == "X " && gB[3] == "* ")
    {
        gB[3] = "X ";
        u.win = true;
    }
    else if (gB[0] == "X " && gB[8] == "X " && gB[4] == "* ")
    {
        gB[4] = "X ";
        u.win = true;
    }
    
    return u.win;
    
}
