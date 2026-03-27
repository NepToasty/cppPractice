#include <iostream>
#include <random>
#include <limits>

// gloabal variables
const int arrayPlaneSize = 29;
const int arrayCount = 9;
int arrayPlayerMap[arrayCount];
int ticTacToePlane[arrayPlaneSize] = {1, 4, 1, 4, 1, 7, 5, 6, 5, 6, 5, 7, 1, 4, 1, 4, 1, 7, 5, 6, 5, 6, 5, 7, 1, 4, 1, 4, 1}; // Creates a fresh play field

void drawPlane(int draw[], int size) // Will draw the play plane
{
    for (int i = 0; i < size; i++)
    {
        switch (draw[i])
        {
        case 1:
            std::cout << "   ";
            break;
        case 2:
            std::cout << " x ";
            break;
        case 3:
            std::cout << " O ";
            break;
        case 4:
            std::cout << "|";
            break;
        case 5:
            std::cout << "---";
            break;
        case 6:
            std::cout << "+";
            break;
        case 7:
            std::cout << '\n';
            break;
        }
    }
}

void enemyLogic() // The enemy logic
{
    bool temp = 0;
    int toCheckAgainst;
    while (temp == 0) // Run as long as one spot has been found for the enemy to place down their symbol
    {
        // Random logic
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 8);

        toCheckAgainst = dis(gen);

        // Maps a O to a random spot onto the grid
        if (arrayPlayerMap[toCheckAgainst] == 1)
        {
            arrayPlayerMap[toCheckAgainst] = 3;
            temp = true;
        }
    }
}

void mapPlaneToNewVal() // Maps new data to plane
{
    int tempCounterArray = 0;
    for (int i = 0; i < arrayPlaneSize; i++) // Maps the players array to the draw plane
    {
        if (ticTacToePlane[i] == 1)
        {
            ticTacToePlane[i] = arrayPlayerMap[tempCounterArray];
            tempCounterArray++;
        }
        else if (ticTacToePlane[i] == 2 || ticTacToePlane[i] == 3)
        {
            tempCounterArray++;
        }
    }
}

void startUpGame() // Configures arrays and draws the map
{
    for (int i = 0; i < arrayCount; i++) // Fills the player map with empty spaces up
    {
        arrayPlayerMap[i] = 1;
    }
    mapPlaneToNewVal();
    drawPlane(ticTacToePlane, arrayPlaneSize); // Draws the plane
    std::cout << '\n';
}

int playWonGame()
{
    for (int playWonCon = 1; playWonCon < 4; playWonCon++)
    {
        if ((arrayPlayerMap[0] == playWonCon && arrayPlayerMap[1] == playWonCon && arrayPlayerMap[2] == playWonCon) ||
            (arrayPlayerMap[3] == playWonCon && arrayPlayerMap[4] == playWonCon && arrayPlayerMap[5] == playWonCon) ||
            (arrayPlayerMap[6] == playWonCon && arrayPlayerMap[7] == playWonCon && arrayPlayerMap[8] == playWonCon) ||
            (arrayPlayerMap[0] == playWonCon && arrayPlayerMap[4] == playWonCon && arrayPlayerMap[8] == playWonCon) ||
            (arrayPlayerMap[2] == playWonCon && arrayPlayerMap[4] == playWonCon && arrayPlayerMap[6] == playWonCon) ||
            (arrayPlayerMap[0] == playWonCon && arrayPlayerMap[3] == playWonCon && arrayPlayerMap[6] == playWonCon) ||
            (arrayPlayerMap[1] == playWonCon && arrayPlayerMap[4] == playWonCon && arrayPlayerMap[7] == playWonCon) ||
            (arrayPlayerMap[2] == playWonCon && arrayPlayerMap[5] == playWonCon && arrayPlayerMap[8] == playWonCon))
        {
            return playWonCon;
        }
    }
    return 1;
}

void gameRun()
{
    int runCount = 0;
    int numberPlane;
    while (true)
    {
        while (true) // Let the player enter a number between 1 and 9
        {
            std::cout << "Enter a number between 1 - 9: ";
            std::cin >> numberPlane;
            if (std::cin.fail() || numberPlane < 1 || numberPlane > 9)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
                std::cout << "This is not a valid number";
            }
            else
            {
                if (arrayPlayerMap[numberPlane - 1] > 1)
                {
                    std::cout << "The entered number is already occupied!" << '\n';
                }
                else
                {
                    arrayPlayerMap[numberPlane - 1] = 2;
                    break;
                }
            }
        }
        // Checks if either player has won the game
        if (playWonGame() == 2)
        {
            mapPlaneToNewVal();
            drawPlane(ticTacToePlane, arrayPlaneSize); // Draws the plane
            std::cout << '\n';
            std::cout << "You won the game";
            break;
        }
        if (runCount == 4)
        {
            mapPlaneToNewVal();
            drawPlane(ticTacToePlane, arrayPlaneSize); // Draws the plane
            std::cout << '\n';
            std::cout << "The game tied";
            break;
        }
        enemyLogic();
        mapPlaneToNewVal();
        drawPlane(ticTacToePlane, arrayPlaneSize); // Draws the plane
        std::cout << '\n';
        runCount++;
        if (playWonGame() == 3)
        {
            mapPlaneToNewVal();
            drawPlane(ticTacToePlane, arrayPlaneSize); // Draws the plane
            std::cout << '\n';
            std::cout << "You lost the game";
            break;
        }
    }
}

int main()
{
    startUpGame();
    gameRun();
    return 0;
}