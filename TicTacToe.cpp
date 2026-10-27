#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

char arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void Display();
void Input(int);
bool CheckWin();

int main()
{
    Display();
    for (int turn = 0; turn < 9; turn++)
    {
        int num = turn % 2;
        Input(num);
        if (CheckWin())
        {
            cout << "Player " << (num == 0 ? 'O' : 'X') << " Wins!" << endl;
            return 0;
        }
    }
    cout << "It's a Draw!" << endl;
    return 0;
}
void Input(int num)
{
    int n;
    while (true)
    {
        cout << "Player " << (num == 0 ? 'O' : 'X') << ", Enter the Index of Box to have Your Turn (1-9): ";
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
    if (num == 0)
    {
        arr[n - 1] = 'O';
    }
    else if (num == 1)
    {
        arr[n - 1] = 'X';
    }
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
