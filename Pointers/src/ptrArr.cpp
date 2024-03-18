#include <iostream>
using namespace std;

int main()
{
    // int luckyNums[5] = {2,3,5,7,9};

    // cout << luckyNums << endl;
    // // cout << luckyNums*2 << endl;
    // cout << &luckyNums[0] <<"-"<<luckyNums<< endl;
    // cout << &luckyNums[2] <<"-"<< luckyNums[2] << endl;
    // cout << &luckyNums[2] << "-"<< luckyNums[2] << "-"<< *(luckyNums +2 ) <<"luckyNums +2: "<< luckyNums +2 << endl;
    // cout << &luckyNums[2] << "-"<< luckyNums[2] << "-"<< *(&luckyNums +2 ) << endl;

    int luckyNums[5];

    for (int i=0; i<=4; i++){
        cout << "Number :";
        cin >> luckyNums[i];
    }

    for (int i=0; i<=4; i++){
        cout <<luckyNums+i <<" = "<<*(luckyNums+i)<<", ";
    }

    system("pause>0");

    return 0;
}