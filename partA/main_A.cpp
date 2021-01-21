#include <iostream>
#include "date_wrap.h"
using std::cout;
using std::endl;


int main ()
{
    mtm::DateWrap date1(30, 11, 2020);
    mtm::DateWrap date2(5, 9, 2017);
    
    cout << date1 << endl; // output: "30/11/2020"
    cout << date1 + 4 << endl; // output: "4/12/2020"
    cout << 3 + date1 << endl; // output: "3/12/2020"
    date1++;
    cout << date1 << endl; // output: "1/12/2020"
    date1 += 7;
    cout << date1 << endl; // output: "8/12/2020"
    cout << (date1 > mtm::DateWrap(29, 11, 2020)) << endl; // output: "1"
    cout << (date1 <= mtm::DateWrap(29, 11, 2020)) << endl; // output: "0"
    cout << (date1 == mtm::DateWrap(30, 11, 2020)) << endl; // output: "0"
    //date1 += (-3); // throw exception NegativeDays
    //date1 = date1 + (-3); // throw exception NegativeDays
    

    return 0;

}