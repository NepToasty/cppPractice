#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
#include <random>

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

const double pi = 3.141592653589793;

const int xMatrixSize = 300;
const int yMatrixSize = 20;

int matrix[yMatrixSize][xMatrixSize];

/*We just hold |xMatrixSize| vectores worth of rain drops
               |xMatrixSize|
*/

float rainX[xMatrixSize];
float rainY[xMatrixSize];

double sinLUT[360];
double cosLUT[360];

double toRad(double deg) // Converts deg to rad
{
    return (deg / 360.0) * 2.0 * pi;
}

void createTrigLUT() // Computes the LUT for sin and cos
{
    for (int i = 0; i < 360; i++)
    {
        sinLUT[i] = std::sin(toRad(i));
        cosLUT[i] = std::cos(toRad(i));
    }
}

void initializeMatrix() // initilize the drawing matrix to 0's
{
    for (int y = 0; y < yMatrixSize; y++)
    {
        for (int x = 0; x < xMatrixSize; x++)
        {
            matrix[y][x] = 0;
        }
    }
}

void initializeRain() // At startup we place the raindrops randomly onto the xy plane
{
    for (int i = 0; i < xMatrixSize; i++)
    {
        rainX[i] = i;
        // Random logic
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, yMatrixSize);

        rainY[i] = dis(gen);
    }
}

void clearMatrix() // Clear out the matrix
{
    for (int y = 0; y < yMatrixSize; y++)
    {
        for (int x = 0; x < xMatrixSize; x++)
        {
            matrix[y][x] = 0;
        }
    }
}

void draw() // Draws the points onto the serial port
{
    for (int y = 0; y < yMatrixSize; y++)
    {
        for (int x = 0; x < xMatrixSize; x++)
        {
            if (matrix[y][x] == 0)
            {
                std::cout << " ";
            }
            else
            {
                std::cout << "#";
            }
        }
        std::cout << '\n';
        sleep_for(1ms);
    }
    std::cout << '\n';
}

void updateRain(int angleDeg) // Updates each vector
{
    while (angleDeg < 0)
        angleDeg += 360;
    while (angleDeg >= 360)
        angleDeg -= 360;

    // Moves the rain droplet down the xy direction
    float dx = sinLUT[angleDeg];
    float dy = cosLUT[angleDeg];

    for (int i = 0; i < xMatrixSize; i++) // boundry check
    {
        rainX[i] += dx;
        rainY[i] += dy;

        if (rainY[i] >= yMatrixSize)
        {
            rainY[i] = 0;

            // Random logic
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, xMatrixSize);

            rainX[i] = dis(gen);
        }

        if (rainX[i] < 0)
        {
            rainX[i] = xMatrixSize - 1;
        }

        if (rainX[i] >= xMatrixSize)
        {
            rainX[i] = 0;
        }
    }
}

void writeRainToMatrix() // marks the points to be drawn
{
    for (int i = 0; i < xMatrixSize; i++)
    {
        int drawX = round(rainX[i]);
        int drawY = round(rainY[i]);

        if (drawX >= 0 && drawX < xMatrixSize && drawY >= 0 && drawY < yMatrixSize)
        {
            matrix[drawY][drawX] = 1;
        }
    }
}

int main()
{
    int rainAngle = 20; // 0 = straight down, positive = down-right

    createTrigLUT();
    initializeMatrix();
    initializeRain();

    while (true)
    {
        clearMatrix();
        updateRain(rainAngle);
        writeRainToMatrix();
        draw();
        
    }
}