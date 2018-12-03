#include <iostream>
#include <vector>

using namespace std;

class Board {
private:
    vector<int> squares;
    char player1;
    char player2;
    int winner;
public:

    //Contructors
    Board(){
        squares.reserve(10);
        player1 = 'X';
        player2 = 'O';
        //Board('X','O'); //Thought this would work but it dumped core
    }
    Board(char p1, char p2){
        player1 = p1;
        player2 = p2;
        squares.reserve(10);
    }

    //See what character is in a square
    char getchar(int square){
        if (square == 1){
            return player1;
        }
        if (square == 2){
            return player2;
        }
        return ' ';
    }

    //return the character associated with a player
    char getplayerchar(int player){
        if (player==1) return player1;
        return player2;
    }

    //Set a square on the board
    void setsquare(int pos, int playerVal){
        squares[pos] = playerVal;
    }

    //GETs a square on the board
    int getsquare(int pos){
            return squares[pos];
    }

    //Set a player's character
    void setchar(int player, char c){
        if(player == 1){
            player1 = c;
        }
        if(player == 2){
            player2 = c;
        }
    }

    //Print the board to the console
    void display(){
        cout << ' ' << getchar(squares[1]) << " | " << getchar(squares[2]) << " | " << getchar(squares[3]) << endl;
        cout << "-----------" << endl;
        cout << ' ' << getchar(squares[4]) << " | " << getchar(squares[5]) << " | " << getchar(squares[6]) << endl;
        cout << "-----------" << endl;
        cout << ' ' << getchar(squares[7]) << " | " << getchar(squares[8]) << " | " << getchar(squares[9]) << endl;
        cout << endl;
    }

    //Returns true if someone has won
    bool checkwin(){
        if(squares[1] == squares[2] && squares[2] == squares [3]){
            if(squares[1] == 1 || squares[1] == 2){
                winner = squares[1];
                return true;
            }
        }
        if(squares[4] == squares[5] && squares[5] == squares [6]){
            if(squares[4] == 1 || squares[4] == 2){
                winner = squares[4];
                return true;
            }
        }
        if(squares[7] == squares[8] && squares[8] == squares [9]){
            if(squares[7] == 1 || squares[7] == 2){
                winner = squares[7];
                return true;
            }

        }
        if(squares[1] == squares[4] && squares[4] == squares [7]){
            if(squares[1] == 1 || squares[1] == 2){
                winner = squares[1];
                return true;
            }

        }
        if(squares[2] == squares[5] && squares[5] == squares [8]){
            if(squares[2] == 1 || squares[2] == 2){
                winner = squares[2];
                return true;
            }
        }
        if(squares[3] == squares[6] && squares[6] == squares [9]){
            if(squares[3] == 1 || squares[3] == 2){
                winner = squares[3];
                return true;
            }
        }
        if(squares[1] == squares[5] && squares[5] == squares [9]){
            if(squares[1] == 1 || squares[1] == 2){
                winner = squares[1];
                return true;
            }
        }
        if(squares[3] == squares[5] && squares[5] == squares [7]){
            if(squares[3] == 1 || squares[3] == 2){
                winner = squares[3];
                return true;
            }
        }
        return false;
    }

    //returns true if the square is empty
    bool squarefree(int pos){
        if(squares[pos] == 0){
            return true;
        }
        return false;
    }

    //returns the value of winner
    int getwinner(){
        return winner;
    }

    //Clears the board
    void clear(){
        for(int i=0; i<10; i++){
            squares[i] = 0;
        }
    }

    void playerTurn(int &squarechoice, int pturn){
        cout << "Please choose a square. (1,2,3;4,5,6;7,8,9)" << endl;
        squarechoice=100;
        while(squarechoice==100){
            cin >> squarechoice;
            if (squarechoice >= 1 && squarechoice <= 9){
                if(squarefree(squarechoice)){
                    setsquare(squarechoice,pturn);
                }
                else{
                    cout<<"ERROR: Square is taken!" << endl;
                    squarechoice = 100;
                }
            }
            else{
                cout<<"ERROR: Not a valid square." << endl <<">>";
            }
        }
    }
};
class Ai {
private:
    //Should be 1 for this use
    int myPlayerValue;//equivalent of pturn
public:
    //constructors
    Ai(){
        myPlayerValue=1;
    }
    Ai(int playerValue){
        myPlayerValue=playerValue;
    }

    void makeMove(int turn,Board &b){
        int movePos;
        bool foundMove = false;
        int playerchar = 2;
        cout << playerchar << endl;
        //Keep the player from winning
        //Horizontals
        //Left row
        if(!foundMove && b.squarefree(1) && b.getsquare(2)==playerchar && b.getsquare(3)==playerchar){
            movePos=1;
            foundMove=true;
        }
        if(!foundMove && b.squarefree(4) && b.getsquare(5)==playerchar && b.getsquare(6)==playerchar){
            movePos=4;
            foundMove=true;
        }
        if(!foundMove && b.squarefree(7) && b.getsquare(8)==playerchar && b.getsquare(9)==playerchar){
            movePos=7;
            foundMove=true;
        }
        //Middle Row
        if(!foundMove &&  b.getsquare(1)==playerchar &&b.squarefree(2) && b.getsquare(3)==playerchar){
            movePos=2;
            foundMove=true;
        }
        if(!foundMove &&  b.getsquare(4)==playerchar &&b.squarefree(5) && b.getsquare(6)==playerchar){
            movePos=5;
            foundMove=true;
        }
        if(!foundMove &&  b.getsquare(7)==playerchar &&b.squarefree(8) && b.getsquare(9)==playerchar){
            movePos=8;
            foundMove=true;
        }
        //Right row
        if(!foundMove &&  b.getsquare(1)==playerchar && b.getsquare(2)==playerchar && b.squarefree(3)){
            movePos=3;
            foundMove=true;
        }
        if(!foundMove &&  b.getsquare(4)==playerchar && b.getsquare(5)==playerchar && b.squarefree(6)){
            movePos=6;
            foundMove=true;
        }
        if(!foundMove &&  b.getsquare(7)==playerchar && b.getsquare(8)==playerchar && b.squarefree(9)){
            movePos=9;
            foundMove=true;
        }
        //Verticals
        //Top
        if(!foundMove &&  b.getsquare(1)==playerchar && b.getsquare(4)==playerchar && b.squarefree(7)){
            movePos=7;
            foundMove=true;
        }
        if(!foundMove &&  b.getsquare(2)==playerchar && b.getsquare(5)==playerchar && b.squarefree(8)){
            movePos=8;
            foundMove=true;
        }
        if(!foundMove &&  b.getsquare(3)==playerchar && b.getsquare(6)==playerchar && b.squarefree(9)){
            movePos=9;
            foundMove=true;
        }
        //Middle
        if(!foundMove &&  b.getsquare(1)==playerchar && b.squarefree(4) && b.getsquare(7)==playerchar){
            movePos=4;
            foundMove=true;
        }
        if(!foundMove &&  b.getsquare(2)==playerchar && b.squarefree(5) && b.getsquare(8)==playerchar){
            movePos=5;
            foundMove=true;
        }
        if(!foundMove &&  b.getsquare(3)==playerchar && b.squarefree(6) && b.getsquare(9)==playerchar){
            movePos=6;
            foundMove=true;
        }
        //Lower
        if(!foundMove && b.squarefree(1) && b.getsquare(4)==playerchar && b.getsquare(7)==playerchar){
            movePos=1;
            foundMove=true;
        }
        if(!foundMove && b.squarefree(2) && b.getsquare(5)==playerchar && b.getsquare(8)==playerchar){
            movePos=2;
            foundMove=true;
        }
        if(!foundMove && b.squarefree(3) && b.getsquare(6)==playerchar && b.getsquare(9)==playerchar){
            movePos=3;
            foundMove=true;
        }
        //Diagonals
        //Lefts
        cout << foundMove << "|" << b.squarefree(7) << "|" << b.getsquare(5) << "|" << b.getsquare(3) << "|" << playerchar << endl;
        if(!foundMove && b.squarefree(7) && b.getsquare(5)==playerchar && b.getsquare(3)==playerchar){
            movePos=7;
            foundMove=true;
        }
        if(!foundMove && b.squarefree(1) && b.getsquare(5)==playerchar && b.getsquare(9)==playerchar){
            movePos=1;
            foundMove=true;
        }
        //Middle
        if(!foundMove && b.getsquare(1)==playerchar && b.squarefree(5) && b.getsquare(9)==playerchar){
            movePos=5;
            foundMove=true;
        }
        if(!foundMove && b.getsquare(7)==playerchar && b.squarefree(5) && b.getsquare(3)==playerchar){
            movePos=5;
            foundMove=true;
        }
        //Rights
        if(!foundMove && b.getsquare(7)==playerchar && b.getsquare(5)==playerchar && b.squarefree(3)){
            movePos=3;
            foundMove=true;
        }
        if(!foundMove && b.getsquare(1)==playerchar && b.getsquare(5)==playerchar && b.squarefree(9)){
            movePos=9;
            foundMove=true;
        }
        //If able, follow the sequence provided
        if(!foundMove){
            for(int i = 1; i < 10; i++){
                if(!foundMove && b.squarefree(i)){
                    movePos=i;
                    foundMove=true;
                }
            }
        }
        //actually make the move
        b.setsquare(movePos,myPlayerValue);

        return;
    }
};

int main()
{
    int option = 1;
    Board b;
    do{
        cout << "-Tic Tac Toe-" << endl;
        cout << "1 - Play Game." << endl;
        cout << "2 - Play against the Sultan." << endl;
        cout << "3 - Set Characters." << endl;
        cout << "0 - Exit" << endl;
        cin >> option;

        //1-Play Game
        if (option == 1) {

            int pturn = 1;
            int count = 0;

            do{
                b.display();
                int squarechoice;

                do{
                    if(pturn == 1){
                        cout << "Turn: Player 1. ";
                        //AI input
                        //write to square
                    }
                    else if(pturn == 2){
                        cout << "Turn: Player 2. ";
                        //Player input
                        //Write to square
                    }

                    //player input
                    b.playerTurn(squarechoice,pturn);

                }while(squarechoice < 1 || squarechoice > 9);

                //update player turn
                if(pturn == 1){
                    pturn = 2;
                }
                else if(pturn == 2){
                    pturn = 1;
                }
                //pturn = (pturn%2)+1;

                //update total turns taken
                count++;
                cout << "Turn number: " << count << endl;
            }while(b.checkwin() == false && count < 9);
            b.display();

            if(b.getwinner() != 0){
                cout << endl << endl << endl << endl;
                cout << "****************" << endl;
                cout << "*Player " << b.getwinner() << " Wins!*" << endl;
                cout << "****************" << endl;
                cout << endl << endl << endl << endl;
            }
            else{
                cout << endl << endl << endl << endl;
                cout << "****************" << endl;
                cout << "*   Tie Game   *" << endl;
                cout << "****************" << endl;
                cout << endl << endl << endl << endl;
            }
            b.clear();
        }

        //2-Play Ai
        if (option == 2){
            Ai sultan;
            int turn=1;
            int squarechoice;
            int pturn=1;
            //while game is not won and there are still moves to make
            while(!b.checkwin() && turn<10){

                //take the Sultan's turn
                //or take the player's turn
                if(turn%2==1) {
                    cout << "It is the Sultan's turn." << endl;
                    //Display the board
                    b.display();
                    sultan.makeMove(turn,b);
                }
                else {
                    cout << "It is your turn." << endl;
                    //Display the board
                    b.display();
                    b.playerTurn(squarechoice,pturn);
                }

                //increase the turn number
                turn++;
                if(pturn==1) pturn = 2;
                else pturn = 1;
            }
            //Display the board
            b.display();
            //Output the winner, if there is one
            if(b.checkwin()){
                cout << endl << endl << endl << endl;
                cout << "****************" << endl;
                cout << "*Player " << b.getwinner() << " Wins!*" << endl;
                cout << "****************" << endl;
                cout << endl << endl << endl << endl;
            }
            else{
                cout << endl << endl << endl << endl;
                cout << "****************" << endl;
                cout << "*   Tie Game   *" << endl;
                cout << "****************" << endl;
                cout << endl << endl << endl << endl;
            }
            //Clear the board
            b.clear();
        }

        //3-Set Characters
        else if (option == 3) {
            int pchoice;
            char cchoice;
            do{

                cout << "Please select a player (1/2): ";
                cin >> pchoice;

                if(pchoice == 1 || pchoice == 2){
                    cout << "Please enter a character: ";
                    cin >> cchoice;
                    b.setchar(pchoice,cchoice);
                }

                else{
                    cout << "ERROR: Did not select 1 or 2. Please try again." << endl;
                }
            }while(pchoice != 1 && pchoice != 2);
        }
    }while(option != 0);
    return 0;
}
