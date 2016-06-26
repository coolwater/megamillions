/**
 * Author: Cool Water
 * Date: June 25, 2016
 * Description: Mega Millions Lottery - Ticket Generator
 * Usage: ./lottery <n> - 'n' for number of tickets (default: 10)
 * Purpose: Brushing up C++ programming after 12 years of respite!
 */
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;
using std::cout;
using std::setw;

#define MEGABASKET_SIZE 15
#define BALLBASKET_SIZE 75

class MegaBallBasket {

    // draw a Mega ball from a set of balls numbers 1 through 15
    static int numDrawn;
    static int megaballs[MEGABASKET_SIZE];

public:
    MegaBallBasket() {
        numDrawn = 0;
        // fill the basket with mega balls
        for (int i=0; i<MEGABASKET_SIZE; i++)
            megaballs[i] = i+1;
    } 

    int draw() {
        int randIdx = rand() % (MEGABASKET_SIZE - numDrawn);
        for (int i=randIdx; i<MEGABASKET_SIZE; i++) {
            if (megaballs[i] != -1) {
               numDrawn++;
               int drawnBall = megaballs[i];
               megaballs[i] = -1;
               return drawnBall;
            }
        }
    }
};

class BallBasket {
    // draw a ball from a set of balls numbers 1 through 75
    static int numDrawn;
    static int balls[BALLBASKET_SIZE];

public:
    BallBasket() {
        numDrawn = 0;
        // fill the basket with mega balls
        for (int i=0; i<BALLBASKET_SIZE; i++)
            balls[i] = i+1;
    } 

    int draw() {
        int randIdx = rand() % (BALLBASKET_SIZE - numDrawn);
        for (int i=randIdx; i<BALLBASKET_SIZE; i++) {
            if (balls[i] != -1) {
               numDrawn++;
               int drawnBall = balls[i];
               balls[i] = -1;
               return drawnBall;
            }
        }
    }
};

class Lottery {
public:
    // draw five Balls and one MegaBall
    int draw(int ticket) {
        // auto variables - baskets are reinitialized after every draw
        MegaBallBasket mbb;
        BallBasket bb;

        cout << "Mega Millions Ticket #" << setw(3) << ticket << ": ";
        cout << setw(3) << bb.draw() << " ";
        cout << setw(3) << bb.draw() << " ";
        cout << setw(3) << bb.draw() << " ";
        cout << setw(3) << bb.draw() << " ";
        cout << setw(3) << bb.draw() << " MEGA: ";
        cout << setw(3) << mbb.draw() << "\n";
    }
};

int MegaBallBasket::numDrawn = 0;
int MegaBallBasket::megaballs[] = {0};
int BallBasket::numDrawn = 0;
int BallBasket::balls[] = {0};

int main(int argc, char *argv[])
{
    Lottery lottery;
    int numTickets = 10; 

    cout << "Mega Millions Lottery - Ticket Generator (2016)\n";

    if (argc != 2)
        cout << "Usage: " << argv[0] << " <n> - 'n' for number of tickets (default: 10)\n";

    if (argc == 2) {
        numTickets = atoi(argv[1]);
    }
    cout << "Number of lottery tickets requested: " << numTickets << "\n";

    cout << "Initializing the random number generator\n";
    srand (time(NULL));

    for (int i=0; i<numTickets; i++)
        lottery.draw(i+1);

    return 0;
}
