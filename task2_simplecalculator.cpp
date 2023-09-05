#include <iostream>
using namespace std;

class simplecalculator
{
public:
     float num1, num2;
    void setnumbers()
    {
        cout << "please enter number 1 : " << endl;
        cin >> num1;
        cout << "please enter number 2 : " << endl;
        cin >> num2;
    }

public:
    void setoperation() {
      
       int operation;
        cout << " please select an operation \n enter 1 for addition \n enter 2 for substraction \n enter 3 for multiplication \n enter 4 for division \n ";
        cin >> operation;

          switch (operation){
    
    case 1 : 
    cout << " addition of number1 and number2 is : " << endl
                 << num1 + num2;
        break;
    case 2 :
          cout << "substraction of number1 and number2 is : " << endl
                 << num1 - num2 ;
            break ;
    case 3 : 
     cout << " multiplication of number1 and number2 is : " << endl
                 << num1 * num2; 
                 break ;
    case 4 : 
    cout << " division of number1 and number2 is : " << endl
                 << num1/num2;
                 break ;             

    default:cout << " please enter a correct number of operation ." ;
        break;
    } }
};

int main()
{   cout << "                   TASK - SIMPLE CALCULATOR                        " << endl ;
    simplecalculator calculation1;
    calculation1.setnumbers();
    calculation1.setoperation();
    
    return 0;
}