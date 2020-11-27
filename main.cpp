#include <iostream>
#include <fstream>
#include<string>

//http://www.cplusplus.com/reference/string/string/getline/
//https://stackoverflow.com/questions/9469264/c-cin-only-reads-the-first-word
//http://patorjk.com/software/taag/#p=display&h=3&v=3&f=Big%20Money-ne&t=College%20Report
//https://www.cppbuzz.com/
//https://answers.yahoo.com/question/index?qid=20130217220526AAisrh4

using namespace std;

void enterNewStudent(string inFilename, int *studentCount, int *inStateTuition, int *outStateTuition){
getchar();
ofstream inFile(inFilename.c_str(), ios::app);
string name;
cout << "\n Enter Student's Name: ";
getline(cin, name);

inFile << endl << name;

int state=-1;
cout << endl << "1 for In State tuition: ";
cout << endl << "2 for Out of State tuition: " << endl;
cout << endl << "Enter here: ";
cin >> state;

if(state==1)
inFile << " | In State";
else if(state==2)
inFile << " | Out Of State";
else
inFile <<" | NA";

string major;
cout << endl << "Enter Major: ";
// cin >> major; //preventing the first word of the major from being read
cin.get(); // helps capture the first word 
getline(cin, major); // reads rest of line

inFile << " | Major: " << major;

int degreeYears;
cout << endl << "How many years of college does your degree require? ";
cin >> degreeYears;

inFile << " | Years: " << degreeYears;

string minor;
cout << endl << "Enter Minor: ";
// cin >> minor; //this was preventing the first word of the minor from being read
cin.get(); // helps caputre the first word
getline(cin, minor); // reads rest of line

inFile << " | Minor: " << minor;

double gpa;
cout << endl << "Enter GPA: ";
cin >> gpa;

inFile << " | GPA: " << gpa;

int tutionFees;
cout << endl << "Enter Tution: $";
cin >> tutionFees;

inFile << " | Tution: $" << tutionFees;

//choice for a dorm or not with prices
char dormChoice;
cout << endl << "Do you plan on living on campus? y/n: ";
cin >> dormChoice;

int dormPlan = 0;

if(dormChoice=='Y' || dormChoice=='y'){
char dorm;
cout << endl << " # Select Which Dorm You Would Like #";
cout << endl << "A -> 2 bedrooms/1 bath - $575/month";
cout << endl << "B -> studio/1 bath - $750/month";
cout << endl << "C -> 4 bedrooms/2 baths - $475/month";
cout << endl << "D -> 1 bedroom/1 bath - $975/month";

cout << endl << endl << "Please note that each dorm is accounting for 1 person per room. This includes a shared living room and kitchen with up to 2 baths. Main difference between a one bedroom dorm and a studio is the studio is all one big room.";

cout << endl << endl << "Select any alphabet ( A, B, C, D ) : ";
cin >> dorm;

switch(dorm){     	
case 'A':
case 'a': dormPlan = 575; break;
case 'B':
case 'b': dormPlan = 750; break;
case 'C':
case 'c': dormPlan =  475; break;
case 'D':
case 'd' : dormPlan =  975; break;
default: cout << endl << "Invalid Choice..";
}

if(dormPlan != 0)
inFile << " | Dorm Plan: "<< dormPlan;
}
else
inFile << " | Dorm Plan: None";

// choice for food plan with prices
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
case 'a': foodPlan = 675; break;
case 'B':
case 'b': foodPlan = 1250; break;
case 'C':
case 'c': foodPlan =  1475; break;
case 'D':
case 'd' : foodPlan =  1700; break;
default: cout << endl << "Invalid Choice..";
}

if(foodPlan !=0 )
inFile << " | Food Plan: " << foodPlan;

if(state==1){
*inStateTuition = *inStateTuition + tutionFees + foodPlan + (dormPlan*4);
}
else if(state==2){
*outStateTuition = *outStateTuition + tutionFees + foodPlan + (dormPlan*4);
}

}
else 
inFile << " | Food Plan: None";

*studentCount = *studentCount + 1;
inFile.close();
}

/*
function generate the final report by adding total fees details
Argument1: inFilename
Argument2: Pointer to studnetCount
*/
void generateReport(const string inFilename, const int *studentCount, const int *inStateTuition, const int *outStateTuition){
if(*studentCount==0){
cout << endl << "Error: There should be atleast one record to generate report.";
}
else{
ofstream inFile(inFilename.c_str(), ios::app);
inFile << endl << "Tuition Paid for In-State Students per semester: " << *inStateTuition;
inFile << endl << "Tuition Paid for Out-of-State Students per semester : " << *outStateTuition;
inFile << endl << "Currently we have: " << *studentCount << " student enrolled";
inFile.close();
cout << endl << "Success: " << inFilename << " generated ";		
}
	
}

//program runs from this function
int main(int argc, char** argv) {
	
int choice = 0;
string inFileName = "student_report.txt";
int studentCount =0;
int inStateTuition = 0;
int outStateTuition =0;

//empty inFile if it already exist
ofstream inFile(inFileName.c_str(), ios::out);
inFile.close();

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
case 1: enterNewStudent(inFileName, &studentCount, &inStateTuition, &outStateTuition);
	break;
case 2: generateReport(inFileName, &studentCount, &inStateTuition, &outStateTuition);
	break;
case -1: cout << endl << "Thank you";
	break;
default: cout << endl << "Invalid Choice.."; getchar();
	
}
	
}

return 0;
}

