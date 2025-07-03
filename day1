#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    double weight, height;
    int choice;
    
    cout << "Choose units (1=kg/m, 2=lb/in): ";
    cin >> choice;  // FIXED: Capture user choice

    if(choice == 2){
        double lb, inches;
        cout << "Enter weight (lb): ";
        cin >> lb;
        cout << "Enter height (in): ";
        cin >> inches;
        weight = lb * 0.453592;
        height = inches * 0.0254;
        cout << "\nConverting to metric...\n";
    }
    else {
        cout << "Enter weight (kg): ";
        cin >> weight;
        cout << "Enter height (m): ";
        cin >> height;
    }

    double bmi = weight / pow(height, 2);
    cout << fixed << setprecision(1);
    cout << "Your BMI: " << bmi << " - Category: ";

    string category;
    if(bmi < 18.5) category = "Underweight";
    else if (bmi < 25) category = "Normal";
    else if (bmi < 30) category = "Overweight";
    else category = "Obese";
    cout << category << endl;

    // Health tips
    if(category == "Underweight")
        cout << "Tip: Increase calories with healthy fats\n";
    else if(category == "Obese")
        cout << "Tip: Consult a nutritionist\n";
    else if(category == "Overweight")
        cout << "Tip: Increase physical activity\n";

    return 0;
}
