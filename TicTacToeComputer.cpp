#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

char arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void Display();
void Input();
void ComputerMove();
int FindMove(char);
bool CheckWin();

int main()
{
    cout << "You are O, Computer is X" << endl;
    Display();
    for (int turn = 0; turn < 9; turn++)
    {
        int num = turn % 2;
        if (num == 0)
        {
            Input();
        }
        else
        {
            ComputerMove();
        }
        if (CheckWin())
        {
            if (num == 0)
                cout << "You Win!" << endl;
            else
                cout << "Computer Wins!" << endl;
            return 0;
        }
    }
    cout << "It's a Draw!" << endl;
    return 0;
}
void Input()
{
    int n;
    while (true)
    {
        cout << "Player O, Enter the Index of Box to have Your Turn (1-9): ";
        if (!(cin >> n))
        {
            if (cin.eof())
                exit(0);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, enter a number." << endl;
            continue;
        }
        if (n < 1 || n > 9 || arr[n - 1] == 'O' || arr[n - 1] == 'X')
        {
            cout << "Invalid or taken box, try again." << endl;
            continue;
        }
        break;
    }
    arr[n - 1] = 'O';
    Display();
}
// Returns the index of a box where 'mark' would complete a line, or -1
int FindMove(char mark)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[i] != 'O' && arr[i] != 'X')
        {
            char saved = arr[i];
            arr[i] = mark;
            bool wins = CheckWin();
            arr[i] = saved;
            if (wins)
                return i;
        }
    }
    return -1;
}
void ComputerMove()
{
    int move = FindMove('X'); // 1. Win if possible
    if (move == -1)
    {
        move = FindMove('O'); // 2. Block the player
    }
    if (move == -1)
    {
        if (arr[4] != 'O' && arr[4] != 'X') // 3. Take the center
            move = 4;
        else if (arr[0] != 'O' && arr[0] != 'X') // 4. Take a corner
            move = 0;
        else if (arr[2] != 'O' && arr[2] != 'X')
            move = 2;
        else if (arr[6] != 'O' && arr[6] != 'X')
            move = 6;
        else if (arr[8] != 'O' && arr[8] != 'X')
            move = 8;
        else if (arr[1] != 'O' && arr[1] != 'X') // 5. Take a side
            move = 1;
        else if (arr[3] != 'O' && arr[3] != 'X')
            move = 3;
        else if (arr[5] != 'O' && arr[5] != 'X')
            move = 5;
        else
            move = 7;
    }
    arr[move] = 'X';
    cout << "Computer chose box " << move + 1 << endl;
    Display();
}
bool CheckWin()
{
    // Rows
    for (int i = 0; i < 9; i += 3)
    {
        if ((arr[i] == arr[i + 1]) && (arr[i + 1] == arr[i + 2]))
            return true;
    }
    // Columns
    for (int i = 0; i < 3; i++)
    {
        if ((arr[i] == arr[i + 3]) && (arr[i + 3] == arr[i + 6]))
            return true;
    }
    // Diagonals
    if (arr[0] == arr[4] && arr[4] == arr[8])
        return true;
    if (arr[2] == arr[4] && arr[4] == arr[6])
        return true;
    return false;
}
void Display()
{

    cout << "-------------------" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << arr[0] << "  |  " << arr[1] << "  |  " << arr[2] << "  |" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|-----|-----|-----|" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << arr[3] << "  |  " << arr[4] << "  |  " << arr[5] << "  |" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|-----|-----|-----|" << endl;
    cout << "|     |     |     |" << endl;
    cout << "|  " << arr[6] << "  |  " << arr[7] << "  |  " << arr[8] << "  |" << endl;
    cout << "|     |     |     |" << endl;
    cout << "-------------------" << endl;
}
