/*-----------------------------------------------------------
Pr. No : 11
Title : Department maintains a student information. The file contains roll number, name, division and address.
 Allow user to add, delete information of student. Display information of particular employee. If record of student 
 does not exist an appropriate message is displayed. If it is, then the system displays the student details. 
 Use sequential file to main the data.
 all->o(n)

------------------------------------------------------------*/

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class student {
    int roll;
    char name[10];
    char div;
    char add[10];

public:
    void create(); 
    void display(); 
    int search(); 
    void Delete(); 
};

void student::create() {
    char ans;
    ofstream fout; 
    fout.open("stud.dat", ios::out);  // Open in text mode
    do {
        cout << "\n\tEnter Roll No of Student: ";
        cin >> roll;
        cout << "\n\tEnter Name of Student: ";
        cin >> name;
        cout << "\n\tEnter Division of Student: ";
        cin >> div;
        cout << "\n\tEnter Address of Student: ";
        cin >> add;

        // Write each field as text to the file
        fout << roll << "\t" << name << "\t" << div << "\t" << add << endl;
        cout << "\n\tDo you want to add more records? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    fout.close();
}

void student::display() {
    ifstream fin;
    fin.open("stud.dat", ios::in);  // Open in text mode
    cout << "\n\tThe Content of File are:\n";
    cout << "\n\tRoll\tName\tDiv\tAddress";
    int roll;
    char name[10], div, add[10];
    while (fin >> roll >> name >> div >> add) {//take info from file
        cout << "\n\t" << roll << "\t" << name << "\t" << div << "\t" << add;
    }
    fin.close();
}

int student::search() {
    int r, i = 0;
    ifstream fin;
    fin.open("stud.dat", ios::in);  // Open in text mode
    cout << "\n\tEnter Roll No: ";
    cin >> r;

    int roll;
    char name[10], div, add[10];
    while (fin >> roll >> name >> div >> add) {
        if (roll == r) {
            cout << "\n\tRecord Found...\n";
            cout << "\n\tRoll\tName\tDiv\tAddress";
            cout << "\n\t" << roll << "\t" << name << "\t" << div << "\t" << add;
            return i;
        }
        i++;
    }
    fin.close();
    return 0;
}

void student::Delete() {
    int r;
    cout << "\n\tEnter Roll No to Delete: ";
    cin >> r;

    fstream finout;
    finout.open("stud.dat", ios::in | ios::out);

    ofstream temp("temp.dat"); // temp file for updated data
    bool found = false;

    while (finout >> roll >> name >> div >> add) {
        if (roll == r) {
            found = true;
            cout << "\n\tRecord with Roll No " << r << " Deleted Successfully!";
            continue; // skip writing this record
        }
        temp << roll << " " << name << " " << div << " " << add << endl;
    }

    finout.close();
    temp.close();

    remove("stud.dat");
    rename("temp.dat", "stud.dat");

    if (!found) {
        cout << "\n\tRecord Not Found!";
    }
}


int main() {
    student obj;
    int ch, key;
    char ans;
    do {
        cout << "\n\t***** Student Information *****";
        cout << "\n\t1. Create\n\t2. Display\n\t3. Delete\n\t4. Search\n\t5. Exit";
        cout << "\n\tEnter Your Choice: ";
        cin >> ch;
        switch (ch) {
            case 1: obj.create(); break;
            case 2: obj.display(); break;
            case 3: obj.Delete(); break;
            case 4: key = obj.search(); break;
            case 5: break;
        }
        cout << "\n\tDo You Want to Continue in Main Menu (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}
