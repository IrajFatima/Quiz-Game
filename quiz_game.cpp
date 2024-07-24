#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include <set>
#include <new>
#include <random>  
#include <climits>
#include <fstream>
#include <unordered_map>
using namespace std;


void load_questions(const string &filename, vector<string> &questions, vector<string> &options, vector<int> &answers) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open the file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        string question = line;
        while (question.empty()) {
            if (!getline(file, line)) {
                cerr << "Unexpected end of file while reading question." << endl;
                return;
            }
            question += " " + line;
        }
        questions.push_back(question);

        string option1, option2;
        if (!getline(file, option1) || !getline(file, option2)) {
            cerr << "Unexpected end of file while reading options." << endl;
            return;
        }
        options.push_back(option1);
        options.push_back(option2);

        int answer;
        if (!(file >> answer) || (answer != 1 && answer != 2)) {
            cerr << "Invalid answer format." << endl;
            return;
        }
        answers.push_back(answer);

        file.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}



int main(){
    vector<string> questions;
    vector<string> options;
    vector<int> answers;
    load_questions("questions.txt",questions,options,answers);
    while(true){
        int score=0;
        int ans;
        cout<<"<------(  Lets begin the quiz  )------>"<<endl<<endl;
        cout<<"Enter the best possible option number : "<<endl<<endl;
        for(int i=0,j=0;i<questions.size();i++){
            cout<<i+1<<". "<<questions[i]<<endl;
            cout<<"1. "<<options[j++]<<endl<<"2. "<<options[j++]<<endl;
            cout<<"Enter option number : "<<endl;
            cin>>ans;
            while(ans<=0 || ans>2){
                cout<<"Enter valid choice between 1 and 2 : ";
                cin>>ans;
            }
            if(ans==answers[i]){
                cout<<endl<<"Congratulations! You Got It Correct 🤩"<<endl<<endl;
                score++;
            }
            else
                cout<<endl<<"Alas! You Got It Wrong 😕"<<endl<<endl;   
        }
        cout<<endl<<endl<<"<----QUIZ IS COMPLETED---->"<<endl<<endl;
        cout<<"Your score : "<<score<<endl;
        if(score<=questions.size()/2)
            cout<<"You couldn't score more than a the half. Better luck next time! 🥱"<<endl;
        else    
            cout<<"Amazing! Keep it uppp. 🎉🎊"<<endl;
        cout<<endl<<"To restart the game, enter 1 --OR-- To exit the game enter 2 :  "<<endl;
        int temp;
        cin>>temp;
        while(temp<=0 || temp>2){
            cout<<"Enter valid choice between 1 and 2 : ";
            cin>>temp;
        }
        if(temp==2)
            break;

    }
}