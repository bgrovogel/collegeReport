#include <iostream>
#include <fstream>
#include<string>

using namespace std;

void addStudent(string filename, int *studentCount, int *inStateFees, int *outStateFees){
getchar();
ofstream file(filename.c_str(), ios::app);
string name;
cout << endl << "\n Enter Student's Name: ";
getline(cin, name);

file << endl << name;

int state=-1;
cout << endl << "Press 1 for In-State or 2 for Out-Of-State tuition prices: ";
cin >> state;

if(state==1)
file << " | In-State";
else if(state==2)
file << " | Out-Of-State";
else
file <<" | NA";

string major;
cout << endl << "Enter Major: ";
cin >> major;
getline(cin, major);
//dealing with some minor issues here not reading first word
file << " | Major: " << major;

int degreeYears;
cout << endl << "How many years of college does your degree require? ";
cin >> degreeYears;

file << " | Years: " << degreeYears;

string minor;
cout << endl << "Enter Minor: ";
cin >> minor;
getline(cin, minor);
//also not reading first word
file << " | Minor: " << minor;

double gpa;
cout << endl << "Enter GPA: ";
cin >> gpa;

file << " | GPA: " << gpa;

int tutionFees;
cout << endl << "Enter Tution: $";
cin >> tutionFees;

file << " | Tution: " << tutionFees;

char choice;
cout << endl << "Do you want to enroll for a food plan? y/n : ";
cin >> choice;

int foodPlan = 0;

if(choice=='Y' || choice=='y'){
char plan;
cout << endl << " # Select Optional Food Plan #";
cout << endl << "A -> 7 meals a week - $675/semester";
cout << endl << "B -> 14 meals a week - $1250/semester";
cout << endl << "C -> 19 meals a week - $1475/semester";
cout << endl << "D -> unlimited meals - $1700/semester";

cout << endl << "Select any alphabet ( A, B, C, D ) : ";
cin >> plan;

switch(plan){     	
case 'A':
case 'a': foodPlan = 675;   break;
case 'B':
case 'b': foodPlan = 1250; break;
case 'C':
case 'c': foodPlan =  1475; break;
case 'D':
case 'd' : foodPlan =  1700; break;
default: cout<<endl<<"Invalid Choice..";
}

if(foodPlan!=0)
file << " | Food Plan: " << plan;
else
file << " | Food Plan: None" << plan;

if(state==1){
*inStateFees = *inStateFees + tutionFees + foodPlan;
}
else if(state==2){
*outStateFees = *outStateFees + tutionFees + foodPlan;
}

}
*studentCount = *studentCount + 1;
file.close();
}

/*
function generate the final report by adding total fees details
Argument1: filename
Argument2: Pointer to studnetCount
*/
void generateReport(const string filename, const int *studentCount, const int *inStateFees, const int *outStateFees){
if(*studentCount==0){
cout << endl << "Error: There should be atleast one record to generate report.";
}
else{
ofstream file(filename.c_str(), ios::app);
file << endl << "Tuition Paid for In-State Students per semester: " << *inStateFees;
file << endl << "Tuition Paid for Out-of-State Students per semester : " << *outStateFees;
file.close();
cout << endl << "Success: " << filename << " generated ";		
}
	
}


//program runs from this function
int main(int argc, char** argv) {
	
int choice = 0;
string fileName = "student_report.txt";
int studentCount =0;
int inStateFees = 0;
int outStateFees =0;

//empty file if it already exist
ofstream file(fileName.c_str(), ios::out);
file.close();

while(choice!=-1){
cout << R"( 
  /$$$$$$          /$$/$$                                  /$$$$$$$                                       /$$    
 /$$__  $$        | $| $$                                 | $$__  $$                                     | $$    
| $$  \__/ /$$$$$$| $| $$ /$$$$$$  /$$$$$$  /$$$$$$       | $$  \ $$ /$$$$$$  /$$$$$$  /$$$$$$  /$$$$$$ /$$$$$$  
| $$      /$$__  $| $| $$/$$__  $$/$$__  $$/$$__  $$      | $$$$$$$//$$__  $$/$$__  $$/$$__  $$/$$__  $|_  $$_/  
| $$     | $$  \ $| $| $| $$$$$$$| $$  \ $| $$$$$$$$      | $$__  $| $$$$$$$| $$  \ $| $$  \ $| $$  \__/ | $$    
| $$    $| $$  | $| $| $| $$_____| $$  | $| $$_____/      | $$  \ $| $$_____| $$  | $| $$  | $| $$       | $$ /$$
|  $$$$$$|  $$$$$$| $| $|  $$$$$$|  $$$$$$|  $$$$$$$      | $$  | $|  $$$$$$| $$$$$$$|  $$$$$$| $$       |  $$$$/
 \______/ \______/|__|__/\_______/\____  $$\_______/      |__/  |__/\_______| $$____/ \______/|__/        \___/  
                                  /$$  \ $$                                 | $$                                 
                                 |  $$$$$$/                                 | $$                                 
                                  \______/                                  |__/             )" << "\n";
cout << endl << "1 Enter Student Details";
cout << endl << "2 Generate .txt Report";
cout << endl << "-1 Exit";
cout << "\n\n Enter your choice : ";
cin >> choice;

switch(choice){
case 1: addStudent(fileName, &studentCount, &inStateFees, &outStateFees);
	break;
case 2: generateReport(fileName, &studentCount, &inStateFees, &outStateFees);
	break;
case -1: cout << endl << "Thank you";
	break;
default: cout << endl << "Invalid Choice.."; getchar();
	
}
	
}

return 0;
}