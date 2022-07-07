#include <iostream>
using namespace std;
int main() {
    int x,y;
    int countX = 0, countO = 0;
    char field[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '} };

    for(int i = 0; i < 9; i++){

        for(int Y = 0; Y < 3; Y++){
            for (int X = 0; X < 3; X++) {
                if (field[Y][X] == 'X') countX++;
                else if (field[Y][X] == 'O') countO++;

            }
            if (countX == 3 || countO == 3){
                break;
            } else {
                countO = 0;
                countX = 0;
            }

            for (int X = 0; X < 3; X++) {
                if (field[X][Y] == 'X') countX++;
                else if (field[X][Y] == 'O') countO++;

            }
            if (countX == 3 || countO == 3){
                break;
            } else {
                countO = 0;
                countX = 0;
            }
        }

        if (countX == 3 || countO == 3){
            break;
        }
        cout << "Enter the coordinates of the cell: X:";
        cin >> x;
        cout << "Y: ";
        cin >> y;
        if (x > 2 || y > 2){
            cout << "Error!";
            i--;
        } else if (field[x][y] == ' ') {
            if (i % 2 == 0){
                field[x][y] = 'X';
            } else {
                field[x][y] = 'O';
            }
        } else {
            cout << "The cage is already occupied. Enter the coordinates again.";
            i--;
        }
    }

    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3;j++){
            cout << field[i][j] << " ";
        }
        cout << endl;
    }

    if (countX == 3){
        cout << "The crosses won";
    } else if (countO == 3){
        cout << "The noughts won";
    }
}
