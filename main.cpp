#include <iostream>
#include <string.h>
using namespace std;

void type_checker( long long int credit_card_no){
    int credit_no_array[20]={0};
    int no_of_digits=0;
    // this part where the long integer is separated in digits and saved into arrays
    while(credit_card_no !=0){
        credit_no_array[no_of_digits]=credit_card_no%10;
        credit_card_no=credit_card_no/10;
        no_of_digits++;
    }
    //end of separation
    cout<<"no of digits= "<<no_of_digits;
    if(/*no_of_digits == 16 || no_of_digits==13*/1) {
        //checking credit card type
        bool state= false;
        if (credit_no_array[no_of_digits - 1] == 5) {
            cout <<endl<<"your card type : Master Card"<<endl;
            state= true;
        }

        else if (credit_no_array[no_of_digits - 1] == 4) {
            cout <<endl<<"your card type : VISA"<<endl;
            state= true;
        }

        else if (credit_no_array[no_of_digits - 1] == 3 && credit_no_array[no_of_digits - 2] == 7) {
            cout <<endl<<"your card type : American express"<<endl;
            state= true;
        }
        else if (credit_no_array[no_of_digits - 1] == 6) {
            cout <<endl<<"your card type : Discovery Card"<<endl;
            state= true;
        }
        else{
            cout<<endl<<"check the first digit"<<endl;
            state= false;
        }
        //type checker end
        if (state){
            int sum_2_double=0;
            int sum_odd_place=0;
            //get the sum of the digit in odd place from right to left
            for(int i=0;i<no_of_digits;i+=2){
               sum_odd_place+=credit_no_array[i];
            }
            //end of getting the sum of odd place
            cout<<endl<<"sum of odd place= "<<sum_odd_place<<endl;
            //get the doubled sum
            int doubled=0;
            int temp=0;
            for(int i=1;i<no_of_digits;i+=2){
                doubled=credit_no_array[i]*2;
                if (doubled%10==0){
                    if (doubled==10){
                        sum_2_double+=1;
                    }
                    else {
                        sum_2_double += doubled;
                    }
                }
                else{
                    temp=doubled;
                    doubled=temp%10;
                    temp=temp/10;
                    doubled+=temp%10;
                    sum_2_double+=doubled;
                }
            }
            cout<<endl<<"sum of double place= "<<sum_2_double<<endl;
            //end of getting double sum
            if ((sum_2_double+sum_odd_place)%10==0){
                cout <<endl<< "the credit card is valid"<<endl;
            }
            else{
                cout <<endl<< "the credit card not valid"<<endl;
            }
        }
    }
    else {
            cout<<endl<<"credit card number not valid"<<endl;
    }
}
int main() {
    long long int credit_card_no=0;
    while(1) {
        cout << "please enter credit card no:";
        cin >> credit_card_no;
        cout << "your credit card:" << credit_card_no << endl;
        type_checker(credit_card_no);
        char choice;
        cout <<endl<<"if you want to continue press (y) if not press (n) your choice: "<<endl;
        cin >> choice;
        if (choice=='n'||choice=='N'){
            break;
        }
        else{
            /*do nothing*/
        }
    }
}
