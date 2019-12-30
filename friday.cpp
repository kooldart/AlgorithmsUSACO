/*
ID: kadriud1
LANG: C++
TASK: friday
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    ofstream fout("friday.out");
    ifstream fin("friday.in");

    int startYear = 1900;
    int startDay = 0;

    int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int days[7];
    fill(days, days+7, 0);

    int goalYear;

    fin >> goalYear;

    int day = 0, lastDay = 0, last_month = 13;

    for (int i = 0; i < goalYear; i++){
        int year = startYear + i;
        if (year % 100 == 0){
            if (year % 400 == 0)
                months[1] = 29;
        }
        else if (year % 4 == 0)
            months[1] = 29;
        else
            months[1] = 28;

        for (int j = 0; j < 12; j++){
            day = ((last_month + lastDay) % 7);
            days[day]++;
            last_month = (months[j]);
            lastDay = day;
        }
    }

    fout << days[6] << ' ';
    fout << days[0] << ' ';
    fout << days[1] << ' ';
    fout << days[2] << ' ';
    fout << days[3] << ' ';
    fout << days[4] << ' ';
    fout << days[5] << endl;

    //for (int i = 0; i < 7; i++)
      //  cout << days[i] << ' ';

    return 0;
}
