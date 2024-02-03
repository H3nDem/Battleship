#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// TODO : add a highscore system ? + GUI of the game



// === Game settings ===
const short mapHeight = 4;
const short mapWidth = 4;
const short numberOfShips = 1;



// === Declared functions ===
void play(bool shipsMap[mapHeight][mapWidth]);
void gameOver(int turns, bool shipsMap[mapHeight][mapWidth]);
void retry(bool shipsMap[mapHeight][mapWidth]);

void resetMap(bool shipsMap[mapHeight][mapWidth]);
void placeShips(bool shipsMap[mapHeight][mapWidth]);
void printShipMap(bool arr[][mapWidth]);

int generateRandomNumber();
int generateRandomNumber(int maxValue);
int generateRandomNumber(int minValue, int maxValue);





// === Functions defined ===
int main() {
    srand(time(nullptr)); // Initialize the seed random
    bool shipsMap[mapHeight][mapWidth] = {0};
    placeShips(shipsMap);
    printShipMap(shipsMap);
    play(shipsMap);
    return 0;
}


// Runs the battleship game.
void play(bool shipsMap[mapHeight][mapWidth]) {
    int shipsHit = 0;
    int turns = 0;
    while (shipsHit < numberOfShips) {
        int row, column;
        cout << "x: " << '\n';
        cin >> row;

        cout << "y: " << '\n';
        cin >> column;

        if (shipsMap[row][column]) { // If we hit a ship
            shipsMap[row][column] = 0;
            shipsHit++;
            cout << "Hit! " << (numberOfShips-shipsHit) << " left.\n\n";
        } else {
            cout << "Miss\n\n";
        }
        turns++;
    }
    gameOver(turns, shipsMap);
}
// Triggers when the game ends, sums up number.
void gameOver(int turns, bool shipsMap[mapHeight][mapWidth]) {
    cout << "Victory!\n";
    cout << "You won in " << turns << " turns\n";
    retry(shipsMap);
}
// Asks the player if they want to retry.
void retry(bool shipsMap[mapHeight][mapWidth]) {
    char retryAnsw;
    cout << "Do you wish to retry ? (y/n): ";
    cin >> retryAnsw;
    if (retryAnsw == 'y') {
        resetMap(shipsMap);
        play(shipsMap);
    } else if (retryAnsw == 'n') {

    } else {
        cout << "Please answer with y or n\n";
        retry(shipsMap);
    }
}


// Replaces the ships on the map.
void resetMap(bool shipsMap[mapHeight][mapWidth]) {
    shipsMap[mapHeight][mapWidth] = {0};
    placeShips(shipsMap);
    printShipMap(shipsMap);
}
// Places the ships on the map.
void placeShips(bool shipsMap[mapHeight][mapWidth]) {
    int placedShip = 0;
    while (placedShip < numberOfShips) {
        int height = generateRandomNumber(mapHeight);
        int width = generateRandomNumber(mapWidth);
        if (shipsMap[height][width] == false) {
            shipsMap[height][width] = true;
            placedShip++;
        }
    }
}
// Prints the map.
void printShipMap(bool arr[][mapWidth]){
	for (int i=0; i < mapHeight; ++i){
	    for(int j=0; j < mapWidth; ++j){
	        cout << arr[i][j] << ' ';
		}
    cout << '\n';
	}
	cout << '\n';
}


// Generate a completely random number.
int generateRandomNumber() {
    int nb = rand(); // rand() : Generate always the same number, use % to set the upper limit
    return nb;
}
// Generate a number between 0 and the max value.
int generateRandomNumber(int maxValue) {
    int nb = rand() % maxValue;
    return nb;
}
// Generate a number between the min value and the max value.
int generateRandomNumber(int minValue, int maxValue) {
    int nb = (rand() % (maxValue - minValue + 1)) + minValue;
    return nb;
}
