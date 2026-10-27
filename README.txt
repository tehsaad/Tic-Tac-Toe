TIC-TAC-TOE (C++ Console Game)
==============================

ABOUT
-----
A two-player Tic-Tac-Toe game that runs in the terminal / command prompt.
Player O goes first, then Player X. Players take turns until someone
gets three in a row, or all 9 boxes are filled (a draw).

WHAT YOU NEED
-------------
A C++ compiler, for example g++ (MinGW on Windows, or the built-in
g++ on Linux / macOS).

HOW TO COMPILE
--------------
Open a terminal in the folder that contains the code file, then run:

    g++ main.cpp -o tictactoe

(If your code file has a different name, use that name instead of main.cpp.)

HOW TO RUN
----------
    Windows:        tictactoe.exe
    Linux / macOS:  ./tictactoe

HOW TO PLAY
-----------
1. The board is shown with boxes numbered 1 to 9:

        1 | 2 | 3
        4 | 5 | 6
        7 | 8 | 9

2. Player O starts. Type the number of the box you want and press Enter.
3. The board updates with your mark (O or X).
4. The other player then takes a turn. Keep going in turns.
5. You win by getting three of your marks in a straight line:
   across, down, or diagonally.
6. If all 9 boxes are filled and nobody has a line, the game is a draw.

RULES AND MESSAGES
------------------
- Typing letters or symbols shows "Invalid input, enter a number."
  and asks again.
- Typing a number outside 1-9, or choosing a box that is already taken,
  shows "Invalid or taken box, try again." and asks again.
- The game ends with "Player O Wins!", "Player X Wins!" or "It's a Draw!".
- To quit early, close the window or press Ctrl + C.

FILES
-----
main.cpp    - the game source code
README.txt  - these instructions
