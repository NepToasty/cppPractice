#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

const int xPlane = 60;
const int yPlane = 60;

const double pi = 3.1415926535;

double sinArray[360];
char matrix[xPlane][yPlane];

class SinPointInSpace
{
public:
    int calculateXYPosition(double rotation);

private:
    int y;
};

int SinPointInSpace::calculateXYPosition(double rotation)
{
    y = (int)(std::sin((rotation * 2.0 * pi) / xPlane) * yPlane / 2.0 + yPlane / 2.0);
    if (y > yPlane - 1)
        y = yPlane - 1;
    return y;
}

void initializeMatrix() // Initilize the Matrix with #
{
    for (int i = 0; i < xPlane; i++)
    {
        for (int j = 0; j < yPlane; j++)
        {
            matrix[i][j] = ' ';
        }
    }
}

void draw() // Draws the matrix onto the serial port
{
    for (int i = 0; i < xPlane; i++)
    {
        for (int j = 0; j < yPlane; j++)
        {
            std::cout << matrix[i][j];
        }
        std::cout << '\n';
        sleep_for(1500us);
    }
    std::cout << '\n';
}

int main()
{
    SinPointInSpace sinus_1;
    SinPointInSpace sinus_2;
    SinPointInSpace sinus_3;

    initializeMatrix();
    for (int j = 0; j < 100; j++)
    {
        for (int i = 0; i < xPlane; i++)
        {
            matrix[i][sinus_1.calculateXYPosition(j + i)] = '#';
            matrix[i][sinus_2.calculateXYPosition(j + i + xPlane * 1 / 3)] = '#';
            matrix[i][sinus_3.calculateXYPosition(j + i + xPlane * 2 / 3)] = '#';
        }
        draw();
        initializeMatrix();
    }

    return 0;
}