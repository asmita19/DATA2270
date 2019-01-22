//Asmita Dhakal 
//Data Structures 2270
//Assignment 1
//Recitation 103

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//#1:
int insertIntoSortedArray(int myArray[], int numEntries, int newValue){
    int first;
    int second;
    double tempo;
    
    for(first = 0; first < numEntries; first++){
        tempo = myArray[first];
        if(newValue < myArray[first]){
            break;
        }
    }
    
    for(second = numEntries; second >= first; second--){
        tempo = myArray[1 + second];
        myArray[1 + second] = myArray[second];
    }
    
    myArray[first] = newValue;
    return numEntries + 1;
}

//#2:
struct User{
    string username;
    float gpa;
    int age;
}

void addUser(vector<User> *users, string _username, float _gpa, int _age){
    
    struct User allUsers;
    
    allUsers.username = _username;
    allUsers.gpa = _gpa;
    allUsers.age = _age;
    
    users -> push_back(allUsers);
}

void printList(const vector<User> users){
    for(int i = 0; i < users.size(); i++){
        cout<<users[i].username<<" ["<<users[i].gpa<<"]"<<" age: "<<users[i].age<<endl;
    }
}

//#3:
class Movie{
    private:
        string title;
        int year;
        double rating;
    public:
        Movie();
        Movie(string tit, int ye, double rat);
        void setTitle(string tit);
        string getTitle();
        void setYear(int ye);
        int getYear();
        void setRating(double rat);
        double getRating();
};
Movie::Movie(){
    title = "unknown";
    year = 2018;
    rating = 0.0;
}
Movie::Movie(string tit, int ye, double rat){
    title = tit;
    year = ye;
    rating = rat;
}
void Movie::setTitle(string tit){
    title = tit;
}
string Movie::getTitle(){
    return title;
}
void Movie::setYear(int ye){
    year = ye;
}
int Movie::getYear(){
    return year;
}
void Movie::setRating(double rat){
    rating = rat;
}
double Movie::getRating(){
    return rating;
}

//main:
int main(int argc, char*argv[]){
    //#1:
    int index = 0;
    int myArray[100];
    ifstream myfile("assignment_1_problem_1.txt");
    if(myfile.is_open()){
        string line;
        int a = 0;
        while(getline(myfile, line)){
            a = stoi(line);
            index = insertIntoSortedArray(myArray, index, a);
            for(int i = 0; i < index; i++){
                cout<<myArray[i]<<",";
            }
            cout<<endl;
        }
    }else{
        cout<<"The file didn't open."<<endl;
    }
    return 0;
    
    //#2:
    vector<User>users;
    
    string username;
    float gpa;
    int age;
    
    ifstream myfile("info.csv");
    if(myfile.is_open()){
        int counter = 0;
        string line;
        while(getline(myfile, line)){
            //string stream = include sstream
            stringstream ss;
            //puts stringstream ss into line
            ss<<line;
            string item;    
            getline(ss, item, ',');
            allusers[counter].username = item;
            
            getline(ss, item, ',');
            allusers[counter].gpa = stof(item);
            
            getline(ss, item, ',');
            allusers[counter].age = stoi(item);
            
            counter++;
        }
        myfile.close();
    }
}