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
//level 4: one-one-one digit/three variables- add/minus/multiply
//level 5: one-one-two digit/three variables- add/minus/multiply
//level 6: one-two-two digit/three variables- add/minus/multiply
//level 7: two-two-two digit/three variables- add/minus/multiply
class Timer{
    private:
        time_t start_ts;
    public:
        Timer(){
            start_ts=time(NULL);
        }
        int getElapsedTime(){
            return (time(NULL)-start_ts);
        }
};
char SelectOp(int select){
    switch (select)
    {
    case 0:
        return '+';
        break;
    case 1:
        return '-';
        break;
    case 2:
        return '*';
        break;
    case 3:
        return '/';
        break;
    }
}
int CharToOp(int a, char op, int b){
    switch (op)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    // case '/':
    //     return a / b;
        break;
    }
}

int exercise_generator(int level){
    int ans;
    srand(time(NULL));
    if(level<=3)
    { // two variables
        int a,b,select;
        select=rand() % 3;
        
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
    if (level > 3 && level <= 7)
    {//threee variables
        int a,b,c,select_first,select_second, select_pair;
        switch (level)
        {
        case 4:
            a = rand() % 10;
            b = rand() % 10;
            c = rand() % 10;
            break;
        case 5:
            a = rand() % 10;
            b = rand() % 10;
            c = rand() % 100;
            break;

        case 6:
            a = rand() % 10;
            b = rand() % 100;
            c = rand() % 100;
            break;
        case 7:
            a = rand() % 100;
            b = rand() % 100;
            c = rand() % 100;
            break;
        }

        
        // UI and answer 3*3 combs: M1  (M2: make use of prefix expression)
        select_first = rand() % 3;
        select_second = rand() % 3;
        select_pair = rand() % 2;
        if(select_pair){
            ans = CharToOp(CharToOp(a, SelectOp(select_first), b), SelectOp(select_second), c);
            cout << endl
                 << "(" << a << " " << SelectOp(select_first) << " " << b << ") "
                 << SelectOp(select_second) << " " << c << " = " ;
        }
        else
        {
            ans = CharToOp(a, SelectOp(select_first), CharToOp(b, SelectOp(select_second), c));
            cout << endl
                 << a << " " << SelectOp(select_first) 
                 << " (" << b << " " << SelectOp(select_second) << " " << c << ") = ";
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
    int RA;//reaction time
    string enter;
    ofstream record;
    time_t date=time(NULL);

    record.open("record.txt",ios::app);
    temp = iteration;


    cout<<"level(1~7): ";
    cin>>level;
    if (level <= 0 || level > 7)
        return 0;

    Timer tick_tak;
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
    record<< asctime(localtime(&date));
    record.close();
    return 0;
}