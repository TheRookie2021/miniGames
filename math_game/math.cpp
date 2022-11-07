#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <ctime>
using namespace std;

//level 1: one-one digit/two variables- add/minus/multiply/
//level 2: one-two digit/two variables- add/minus/multiply/
//level 3: two-two digit/two variables- add/minus/multiply/
//level 4: one-two digit/three variables- add/minus/multiply
class Timer{
    private:
        time_t start_ts;
    public:
        Timer(){
            start_ts=time(NULL);
            cout <<"start!"<<start_ts<<endl;
        }
        int getElapsedTime(){
            return (time(NULL)-start_ts);
        }
};
int exercise_generator(int level){
    int ans;
    srand(time(NULL));
    if(level<=3)
    { // two variables
        int a,b,select;
        switch (level)
        {//setting digit of variables
        case 1:
            a = rand() % 10, b = rand() % 10;
            break;
        case 2:
            a = rand() % 100, b = rand() % 10;
            break;
        case 3:
            a = rand() % 100, b = rand() % 100;
            break;
        }

        // UI and answer
        select=rand() % 3;
        if (select== 0)
        { // add
            cout << endl
                 << a << " + " << b << " = ";
            ans = a + b;
        }
        else if (select == 1)
        { // minus
            cout << endl;
            select=rand()%2;
            if (select)
            {
                cout << a << " - " << b << " = ";
                ans = a - b;
            }
            else
            {
                cout << b << " - " << a << " = ";
                ans = b - a;
            }
        }
        else if (select % 3 == 2)
        { // multiply
            cout << endl
                 << a << " * " << b << " = ";
            ans = a * b;
        }
    }

    return ans;
}

int main(){
    int level;
    int point=0;
    int iteration=10;
    int temp;
    int ans;
    string enter;
    ofstream record;
    record.open("record.txt",ios::app);


    cout<<"level(1~3): ";
    cin>>level;
    if (level <= 0)
        return 0;
    temp = iteration;

    Timer tick_tak;
    int RA;//reaction time
    while (temp--)
    {
        ans=exercise_generator(level);
        
        cin>>enter;
        // system("Color 01"); //sh: 1: Color: not found

        if (stoi(enter) == ans)
        {
            point++;
            
            //ANSI escape color codes :
            cout << "\x1B[32m";
            cout<<"correct";
            cout<<"\033[0m\t\t"<<"\n";
            //
        }
        else
        {
            
        // system("Color 03");
           cout << "\x1B[31m";
           cout << "incorrect, answer is " << ans;
           cout << "\033[0m\t\t"
                << "\n";
        }
        cout<<"------------";
    }
    RA = tick_tak.getElapsedTime();

    cout << "\nthis is your scores: " << point << "/" << iteration << endl;
    cout << "time: " << RA << endl;
    record << "level:\t" << level << "\tscores:\t" << point << "\t/\t" << iteration ;
    record << "\treaction time:\t" << RA << "\t";
    time_t date=time(NULL);
    record<< asctime(localtime(&date));
    record.close();
    return 0;
}