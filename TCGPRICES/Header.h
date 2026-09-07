#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

class PokemonCard {
public:
    string name;

    class Stats {
    public:
        float price;
        tm dateSold;

        // Default constructor for Stats


        // Constructor with arguments
        Stats(float price2, tm dateSold2) : price(price2), dateSold(dateSold2) {}
    };

    vector<Stats> statsCollection;  // An instance of the Stats class

    PokemonCard(string name2 = "") {}

    void AddStats(float price, tm dateSold)
    {

        statsCollection.push_back(Stats(price, dateSold));
    }

    float average() {
        float average = 0;
        for (int i = 0; i < statsCollection.size(); i++)
        {

            average += statsCollection[i].price;


        }
        average = average / statsCollection.size();
        return average;
    }

    void StandardDev(float average)
    {
        // calc Standard Deviation and remove outliers
        float sumation = 0;
        for (int i = 0; i < statsCollection.size(); i++)
        {

          float chugnus = statsCollection[i].price - average;
          chugnus = chugnus * chugnus;
          sumation += chugnus;

        }
        sumation = sqrt(sumation / statsCollection.size()-1);
        cout << sumation << endl;
        
        // calc threshold

        float upperthresh = average + 2 * sumation;
        float lowerthresh = average - 2 * sumation;

        for (auto it = statsCollection.begin(); it != statsCollection.end();) {
            if (it->price < lowerthresh || it->price > upperthresh) {
                it = statsCollection.erase(it);  // Erase the element and get the next iterator
            }
            else {
                ++it;  // Move to the next element
            }
        }


    }
    void sortDates()
    {
        
        for (int j = 0; j < statsCollection.size() - 1; j++) {
            int iMin = j;

            for (int i = j + 1; i < statsCollection.size(); i++) {
                if (mktime(&statsCollection[i].dateSold) < mktime(&statsCollection[iMin].dateSold)) {
                    iMin = i;
                }
            }

            if (iMin != j) {
                swap(statsCollection[j], statsCollection[iMin]);
            }
        }

        for (int i = 0; i < statsCollection.size(); i++) {
            std::stringstream ss;
            ss << std::put_time(&statsCollection[i].dateSold, "%m/%d/%Y");
            std::cout << ss.str() << "  " << statsCollection[i].price << std::endl;
        }
        
        
    }

};
