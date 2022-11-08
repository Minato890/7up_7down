#include <iostream>
#include <string>
#include <time.h>
using namespace std;

//----------------------------------------------------------------
//PAYOUT
// LUCKY 7 - 4 : 1
// 7 UP - 1 : 1
// 7 DOWN - 1 : 1


//make a class dice
class dice{    
    public:
    //randomize()- returns a number between 1 and 6
    int roll(){
        int number = 0;
        srand(time(0));
        number = ((rand()%10))%6;
        if(number%6==0){
            number = 6;
        }
        return number;
    }
};


//checkIfWon
int checkIfWon(int sumOfNumbersOnTop){
    if(sumOfNumbersOnTop == 7){
        return 1;
    }
    else if(sumOfNumbersOnTop > 7){
        return 2;
    }
    else if(sumOfNumbersOnTop < 7){
        return 3;
    }
}

//print balance

// take input 7up,7down and lucky 7
void gameOn(){

    dice d1,d2;

    float on7up, on7down, on7;
    float balance = 0, profit = 0, loss = 0;    

    while(true)
    {    
        int num1 = d1.roll();
        int num2 = d2.roll();
        int total = num1 + num2;
        
        cout << "PLACE YOUR BETS :" << endl;
        cout << endl;

        cout << "7 UP : " << endl; 
        cin >> on7up;
        cout << "7 DOWN : " << endl; 
        cin >> on7down;
        cout << "EQUAL 7 : " << endl; 
        cin >> on7;
        cout << endl;

        balance = on7up + on7down + on7;
        cout << "YOUR BET : " << balance << " $"<< endl;
        cout << endl; 

        cout << "######"<< endl;
        cout << "# " << total;
        if(total/10 == 0) cout << "  #" <<endl;
        else cout << " #" << endl;
        cout << "######"<< endl;
        cout << endl;

        if(checkIfWon(total) == 1){//equal to 7
            //balance += (4*on7up - (on7up + on7down));
            profit = 4*on7up;
            loss = (on7up + on7down);
        }
        else if(checkIfWon(total) == 2){//greater than 7
            //balance += (on7up - (on7 + on7down));
            profit = on7up;
            loss = (on7 + on7down);
        }
        else if(checkIfWon(total) == 3){//less than 7
            //balance += (on7down - (on7 + on7up));
            profit = on7down;
            loss = (on7 + on7up);
        }

        balance += (profit - 2*loss);
        cout << "YOU WON : " << profit << " $" << endl;
        cout << "YOU LOST : " << loss << " $" << endl;
        cout << "BALANCE : " << balance << " $" << endl;

        cout << "| PRESS Q to quit | OTHERWISE PRESS ANY KEY |" << endl;
        char temp;
        cin >> temp;

        if(temp == 'Q'){
            break;
        }
        else gameOn();
    }
}

int main(){

    cout << endl;
    cout << "PAYOUT" << endl;
    cout << "LUCKY 7 - 4 : 1" << endl;
    cout << "7 UP - 1 : 1" << endl;
    cout << "7 DOWN - 1 : 1" << endl;
    cout << endl;

    gameOn();

    return 0;
}

