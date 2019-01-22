//Asmita Dhakal 
//Data Structures 2270
//Assignment 0
//Recitation 103

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std; 

struct Student{
    //TD, Name, Major
    int ID;
    string name;
    string major;
    Student(){}
    Student(int id, string n, string m){
        ID = id;
        name = n;
        major = m;
    }
};


class Date{
    private:
        int month;
        int day;
        int year;
    public:
        Date(int m, int d, int y){
            
            month = m;
            day = d;
            year = y;
        }
        void printData(){
            cout<<month<<" "<<day<<" "<<year<<endl;
        }
        void setMonth(int m){
            if(m > 0 && m < 13){
                month = m;
            }else{
                cout<<"Month out of Range!"<<endl;
            }
        }
        void setYear(int y){
            if(y > 0 && y < 2019){
                year = y;
            }else{
                cout<<"Year out of Range!"<<endl;
            }
        }
        void setDay(int d){
            if(d > 0 && d < 31){
                day = d;
            }else{
                cout<<"Day out of Range!"<<endl;
            }
        }
};

int main(){
    
    Date d(39, 15, -2018);
    
    d.setMonth(39);//Month will not be updated
    d.setYear(-2018);
    d.setDay(15);
    d.setMonth(12);//MOnth will be updated
    d.printData();//helps doidplay private attribute
    
    
    //create instance of Student called s
    Student s;
    s.ID = 5; //setting the ID property for Student s to 5
    s.name = "bob";
    s.major = "skiing";
    Student s2(6, "jimmy", "swimming");//setting the attribute of Student s2 with a construct
    cout<<s.ID<<" "<<s.name<<" "<<s.major<<endl;
    cout<<s2.ID<<" "<<s2.name<<" "<<s2.major<<endl;

    
    //arrays
    int a[10];//array of 10 arrays
    for(int i = 0; i < 10; i++){
        a[i] = i;
        cout<<a[i]<<endl;
    }
    cout<<"a = "<<a<<endl;
    
    //array of Students
    //this will be populated manually
    Student allStudents[10];
    
    allStudents[0].ID = 1;
    allStudents[0].name = "Jessica";
    allStudents[0].major = "COmpSci";
    
    allStudents[1].ID = 2;
    allStudents[1].name = "Mia";
    allStudents[1].major = "COmp";
    
    allStudents[2].ID = 3;
    allStudents[2].name = "Alexa";
    allStudents[2].major = "TAM";
    //verify cantents of allStudents array
    for(int i = 0; i < 3; i++){
        cout<<allStudents[i].ID<<" "<<allStudents[i].name<<" "<<allStudents[i].major<<endl;}
        
    //streams
    ifstream myfile("student.txt");
    cout<<"First we will print the String Stream"<<endl<<endl;
    if(myfile.is_open()){
        //read the file
        string line;
        int counter = 0;
        while(getline(myfile, line)){
            cout<<line<<endl;
            //string stream = include sstream
            stringstream ss;
            //write line into string stream
            ss<<line;
            string item;
            
            getline(ss, item, ',');
            allStudents[counter].ID = stoi(item);
            //how do i read name?
            getline(ss, item, ',');
            allStudents[counter].name = item;
            
            getline(ss, item);
            allStudents[counter].major = item;
            
            counter++;
        }
    }
    
}