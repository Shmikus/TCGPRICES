// TCGPRICES.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include<fstream>
#include <sstream>
#include <vector>
#include "Header.h"
#include <windows.h>


using namespace std;

void InqueryInput(string &name, string&setNumber)
{
    ofstream out("C:\\Users\\MARQU\\Desktop\\searchquery.txt");
    out << name + " " + setNumber;
    out.close();
}

int main()
{
    
    string name;
    string setNumber;
    cout << "Input you what card you would like to research first and then its number in the set" << endl;
    cin >> name;
    cin >> setNumber;
    InqueryInput(name, setNumber);

    system("explorer  C:\\Users\\MARQU\\Desktop\\PythonApplication5.exe ");
    system("pause");
    
    
    PokemonCard card;
    
    ifstream file("C:\\Users\\MARQU\\Desktop\\NewTextDocument.csv");
    if (!file.is_open()) {
        cerr<<"ERROR"<< endl;
            return 1;
    }

    string token;
    string token2;
    getline(file, token);
    
    string DateSold;
    float price;
   

    if (file.good())
    {
       
       getline(file, token ,',');
        while (file.good())
        { 
        getline(file, DateSold, ',');
       
        getline(file, token2, '\n');
        try {
            price = stof(token2);
            std::tm parsedDate = { 0 };
            std::istringstream ss(DateSold);
            ss >> std::get_time(&parsedDate, "%m/%d/%Y");

            if (!ss.fail()) {
                
                
                card.AddStats(price, parsedDate);
            }
            else {
                // Parsing failed
                std::cerr << "Failed to parse the date string." << std::endl;
            }
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "ERROR: Invalid price format: " << token2 << std::endl;
            continue; // Skip this record and continue with the next one
        }
        
        
       
        getline(file, token, ',');
        
        
          
        
        
        }
        
        
        float average = card.average();
        cout << average << endl;
        card.StandardDev(average);

        card.sortDates();
        float average2 = card.average();
        cout << average << endl;
        cout << average2<< endl;

        cin >> token;
    }
    file.close();

    
   

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
