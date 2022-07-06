#include <iostream>
using namespace std;
int main() {
    int x,y;
    int countX = 0, countO = 0;
    char field[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '} };

    for(int i = 0; i < 9; i++){

        for(int j = 0; j < 3; j++){
            for(int i = 0; i < 3; i++){
                if (field[i][j] == 'X' || field[j][i] == 'X'){
                    countX++;
                } else if (field[i][j] == 'O' || field[j][i] == 'O'){
                    countO++;
                }
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
        cout << "Enter the coordinates of the cell: ";
        cin >> x >> y;
        if (x > 2 || y > 2){
            cout << "Error!";
            i--;
        } else if (field[x][y] == ' ') {
            if (i % 2 == 0){
                field[x][y] = 'X';
            } else {
                field[x][y] = 'Y';
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
