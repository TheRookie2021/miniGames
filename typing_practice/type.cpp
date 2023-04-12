#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
using namespace std;

class Timer{
private:
    time_t StartTime;

public:
    void setTimer()
    {
        StartTime=time(NULL);
    }
    time_t getStartTime(){
        return StartTime;
    }
    time_t getTimeElapse()
    {
        return time(NULL)-StartTime;
    }
};

int main(){
    string answer("abcdefghijklmnopqrstuvwxyz");
    string buffer;
    Timer t;
    time_t RA;
    ofstream record;
    //setting: append record
    record.open("record.txt",ios::app);
    
    //core
    cout<<"start now!\n";
    t.setTimer();
    getline(cin,buffer);
    RA=t.getTimeElapse();
    cout<<RA<<"sec\n";
    
    //UI
    record << "reaction time:\t" << RA << "sec\t, ";
    if(answer.compare(buffer)!=0)
    {
        cout << "\x1B[31m";
        cout << "Incorrect";
        cout << "\033[0m\t\t"
             << "\n";
        record << "Incorrect" << endl;
    }
    else{
        cout << "\x1B[32m";
        cout << "Correct";
        cout << "\033[0m\t\t"
             << "\n";
        record << "Correct" << endl;
    }   
    
    return 0;
}